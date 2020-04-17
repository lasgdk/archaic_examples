#Line numbers
#Et eksempel der smider linjenumre på en fil
#Og til sidst skriver antal linjer

BEGIN { linje = 0 }
{
print linje,"  ",$0;
linje++;
}
END { print "Antal linjer i filen", FILENAME linje }

