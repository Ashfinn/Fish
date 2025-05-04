import { createInterface } from "readline";

// ----------------------------
// 1. TYPE DEFINITIONS
// ----------------------------

type ValidCommand = "echo" | "type" | "exit";
type CommandHandler = (args: string) => void;
type CommandResult = { command: ValidCommand; args: string };

// ----------------------------
// 2. COMMAND HANDLER REGISTRY
// ----------------------------

const commandRegistry: Record<ValidCommand, CommandHandler> = {
	echo: (args) => console.log(args),
	type: (args) => typeCheck(args),
	exit: () => process.exit(0),
};

// ----------------------------
// 3. INPUT SANITIZATION
// ----------------------------

function sanitizeInput(rawInput: string): string {
	return rawInput.replace(/\s+/g, ' ').trim();
}

// ----------------------------
// 4. COMMAND PARSER (SWITCH-BASED)
// ----------------------------

function parseCommand(input: string): { cmd: ValidCommand; args: string } {
	const [command, ...argsArray] = input.split(' ');
	const args = argsArray.join(' ');

	switch (command as ValidCommand) {
		case "echo":
		case "type":
		case "exit":
			return { cmd: command as ValidCommand, args };
		default:
			throw new Error(`Invalid command: ${command}`);
	}
}

// ----------------------------
// 5. TYPE CHECK FUNCTION
// ----------------------------

function typeCheck(args: string) {
	const typeDef = args.trim();
	if (typeDef === "echo") {
		console.log("echo is a shell builtin");
	} else if (typeDef === "exit") {
		console.log("exit is a shell builtin");
	} else if (typeDef === "type") {
		console.log("type is a shell builtin");
	} else {
		console.log(`${typeDef} not found`);
	}
}

// ----------------------------
// 6. COMMAND EXECUTION WRAPPER
// ----------------------------

function executeCommand(input: string): CommandResult | null {
	const sanitized = sanitizeInput(input);
	if (!sanitized) {
		return null; // Skip empty input
	}
	const { cmd, args } = parseCommand(sanitized);

	commandRegistry[cmd](args);
	return { command: cmd, args };
}

// ----------------------------
// 7. MAIN EXECUTION FLOW
// ----------------------------

const rl = createInterface({
	input: process.stdin,
	output: process.stdout,
});

function prompt() {
	rl.question("$ ", (rawInput) => {
		try {
			const result = executeCommand(rawInput);
			if (result) {
				console.log(); // Add newline for better readability
			}
		} catch (error) {
			console.error(error instanceof Error ? error.message : "An error occurred");
			console.log(); // Add newline after error
		}
		prompt();
	});
}

prompt();