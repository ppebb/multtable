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
	for (var i = 0; i < document.getElementById("h").value; i++) {
		rows[i] = table.insertRow(i);
		cells[i] = [];
		for (var j = 0; j < document.getElementById("w").value; j++) {
			cells[i][j] = rows[i].insertCell(j);
			cells[i][j].innerHTML = (i+1) * (j+1);
		}
	}
}
