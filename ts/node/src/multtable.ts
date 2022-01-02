/* multtable.ts (adapted from js/jshtml/multtable.js)
 * Tomat (https://github.com/Steviegt6)
 * Main multtable utilities, can be plugged in and used as needed (see index.ts for implementation)
 */

function createMulttable(columnSize: number, rowSize: number): string {
  // [columnSize, rowSize] = enforceMin(columnSize, rowSize);

  var length: number = (columnSize * rowSize).toString().length + 1;
  var retVal: string = "";

  retVal += appendMany(rowSize.toString().length + 1, " ");
  retVal += " |";

  for (var c: number = 0; c < columnSize; c++) {
    retVal += appendMany(length - (c + 1).toString().length, " ");
    retVal += c + 1;
  }

  retVal += "\n";
  retVal += appendMany(retVal.length, "-");
  retVal += "\n";

  for (var r: number = 0; r < rowSize; r++) {
    retVal += appendMany(
      rowSize.toString().length + 1 - (r + 1).toString().length,
      " "
    );

    retVal += r + 1 + " |";

    for (var c: number = 0; c < columnSize; c++) {
      var currentNumber = (r + 1) * (c + 1);

      retVal += appendMany(length - currentNumber.toString().length, " ");
      retVal += currentNumber;
    }

    if (r + 1 != rowSize) retVal += "\n";
  }

  return retVal;
}

// Functionally replaced in index.ts, uncomment for safety in the function itself
/*function enforceMin(
  columns: number,
  rows: number
): [columns: number, rows: number] {
  if (columns < 1) {
    columns = 1;
    if (rows < 1) {
      rows = 1;
    }
  }

  return [columns, rows];
}*/

function appendMany(count: number, str: string): string {
  var retVal = "";
  for (var i = 0; i < count; i++) retVal += str;
  return retVal;
}

export { /*enforceMin,*/ createMulttable, appendMany as appendCharRepeatedly };
