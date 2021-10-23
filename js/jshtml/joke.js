function enforceMin() {
	if (document.getElementById("w").value < 1) {
		document.getElementById("w").value = 12;
	}
	if (document.getElementById("h").value < 1) {
		document.getElementById("h").value = 12;
	}
}

function createTable() {
	enforceMin();
	if (document.getElementById("w").value == "69" && document.getElementById("h").value == "69") {
		document.getElementById("e").innerHTML = "sex";
	} else {
		document.getElementById("e").innerHTML = "";
	}
	document.getElementById("t").innerHTML = "";
	var table = document.getElementById("t");
	var rows = [];
	var cells = [];
	for (var i = 0; i - 2 < document.getElementById("h").value; i++) {
		rows[i] = table.insertRow(i);
		cells[i] = [];
		for (var j = 0; j - 2 < document.getElementById("w").value; j++) {
			cells[i][j] = rows[i].insertCell(j);
			if (i == 0 && j == 0 || i == 1 && j == 1) { }
			else if (i == 1) {
				var dashes = "";
				for (k = 0; k < (Math.max(1, j - 1) * document.getElementById("h").value).toString().length; k++) { dashes += "-"; }
				cells[i][j].innerHTML = dashes;
			}
			else if (j == 1) { cells[i][j].innerHTML = "|"; }
			else if (i == 0) { cells[i][j].innerHTML = j - 1; }
			else if (j == 0) { cells[i][j].innerHTML = i - 1; }
			else { cells[i][j].innerHTML = (i - 1) * (j - 1); }
		}
	}
}
