#  For clarity
$Tab = "`t"
 

$Tab + ( 1..22 -join $Tab )
 

ForEach ( $i in 1..22 )
    {
    $(  
        $i
 
        @( "" ) * ( $i - 1 )
 
        #  Calculate
        $i..22 | ForEach { $i * $_ }
 
        #  Combine 
        ) -join $Tab
    }