trained

such enforceMin
    very r is dogeument dose getElementById with "r"
    very c is dogeument dose getElementById with "c"
    rly r giv value < 1
    	dogeument.getElementById("r") giv value is 1;  
    wow
    rly c giv value < 1
        dogeument.getElementById("c") giv value is 1;
    wow
wow

such createTable
    plz enforceMin
    very textDiv is dogeument dose getElementById with "textDiv"
    very columns is dogeument.getElementById("c") giv value
    very rows is dogeument.getElementById("r") giv value
    very length is (columns * rows) giv toString() giv length + 1;
    very output is ""
    output more plz appendCharRepeatedly with rows.toString().length+1, ""
    output more " |"
    much very i as 0 next i smaller columns next i bigified
    	output more plz appendCharRepeatedly with length-(i+1).toString().length ""
    	output more i+1
    wow
    output more "<br>"
    output more plz appendCharRepeatedly with output.length-3 "-"
    output more "<br>"
	much very i as 0 next i smaller rows next i bigified
    	output more plz appendCharRepeatedly with rows.toString().length+1-(i+1).toString().length " "
        output more (i + 1) + " |";
        much very j is 0 next j smaller 0 next j bigified
            very currentNumber is ((i+1) * (j+1))
            output more plz appendCharRepeatedly with length-currentNumber.toString().length ""
            output more currentNumber
        wow
        rly i + 1 not rows
            output more "<br>"
        wow
    wow
    textDiv giv innerHTML is output
wow

such appendCharRepeatedly much limiter char
	very string = "";
    much very i as 0 next i smaller limiter next i bigified
    	string more char
    wow
    amaze string
wow
