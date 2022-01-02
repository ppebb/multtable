import { createMulttable } from "./multtable.js";
import * as readLine from "readline";

const lineReader = readLine.createInterface({
  input: process.stdin,
  output: process.stdout,
});

// Awaiting function to prompt the user for their input.
function prompt(promptText: string): Promise<string> {
  return new Promise((resolve) => {
    lineReader.question(promptText, resolve);
  });
}

// Enforce async function.
(async (): Promise<void> => {
  var columnSize: number = 10;
  var rowSize: number = 10;

  columnSize = parseWithFallback(await prompt("Enter column count (10): "));
  rowSize = parseWithFallback(await prompt("Enter row count (10): "));

  process.stdout.write(createMulttable(columnSize, rowSize));

  lineReader.close();
})();

function parseWithFallback(input: string): number {
  if (input === null || input.match(/^ *$/) !== null) {
    input = "10";
  }

  var retVal: number = parseInt(input);

  if (retVal === NaN) {
    process.stdout.write("Failed to parse value, falling back to 10.\n");
  }

  if (retVal < 1) {
    process.stdout.write("Parse value was less than 1, falling back to 1.\n");
    retVal = 1;
  }

  return retVal;
}
