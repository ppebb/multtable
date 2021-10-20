quiet
	-- This code is a direct translation of MarauderKnight3's javascript version of multtable --
	Since dogescript compiles to JavaScript, You can use the compiled JavaScript in the HTML webpage which MarauderKnight3 provided.
trained

such enforceMin
    very w is dogeument dose getElementById with "w"
    very h is dogeument dose getElementById with "h"
    rly w giv value < 1
    	dogeument.getElementById("w") giv value is 12;  
    wow
    rly h giv value < 1
        dogeument.getElementById("h") giv value is 12;
    wow
wow

such createTable
    plz enforceMin
    dogeument.getElementById("t") giv innerHTML is ""
    very table is dogeument dose getElementById with "t"
    very cells is []
    very rows is []
    much very i as 0 next i smaller dogeument.getElementById("h") giv value next i bigified
    	rows dose insertRow with i
        cells[i] is []
        much very j as 0 next j smaller dogeument.getElementById("w") giv value next j bigified
    		cells[i][j] is rows[i] dose insertCell with j
            cells[i][j].innerHTML is (i+1) * (j+1);
        wow
    wow
wow

