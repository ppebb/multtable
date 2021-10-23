function enforceMin() {
	if (document.getElementById("r").value < 1) {
		document.getElementById("r").value = 1;
	}
	if (document.getElementById("c").value < 1) {
		document.getElementById("c").value = 1;
	}
}

function createMulttable() {
	enforceMin();
	var textDiv = document.getElementById("textDiv");
	var columns = document.getElementById("c").value;
	var rows = document.getElementById("r").value;

	var length = (columns * rows).toString().length + 1;
	var output = "";

	output += appendCharRepeatedly(rows.toString().length + 1, " ");
	output += " |";

	for (var i = 0; i < columns; i++) {
		output += appendCharRepeatedly(length - (i + 1).toString().length, " ");
		output += (i + 1);
	}
	output += "<br>";

	output += appendCharRepeatedly(output.length - 3, "-");
	output += "<br>";

	for (var i = 0; i < rows; i++) {
		output += appendCharRepeatedly(rows.toString().length + 1 - (i + 1).toString().length, " ");
		output += (i + 1) + " |";

		for (var j = 0; j < columns; j++) {
			var currentNumber= ((i + 1) * (j + 1));
			output += appendCharRepeatedly(length - currentNumber.toString().length, " ");
			output += currentNumber;
		}
		if (i + 1 != rows)
			output += "<br>";
	}

	textDiv.innerHTML = output;
}

function appendCharRepeatedly(limiter, char) {
	var string = "";
	for (var i = 0; i < limiter; i++)
		string += char;
	return string;
}
