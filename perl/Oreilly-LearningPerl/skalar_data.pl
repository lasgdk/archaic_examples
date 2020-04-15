#!/usr/bin/perl

#Talrepræsentationer
print 0101 ." ";	#Oktal repræsentation
print 0x41 ."\n";	#Hexadecimal repræsentation
print '0101'." ";	#En string 0101
print '0x41'."\n";	#En string 0x41
print 9.82e-9." ";
print -2.127e24."\n";

#Single quoted strings
print 'hest\'en\n';	#hest'en\n, uden en newline
print 'linje-
skift
';

#Double quoted strings
#Her er meget mere kontrol via \
print "Her er\ttab, og\nlinjeskift.\n";
print "Man kan godt skrive \"\\\" backslash\n";
print "Og ASCII-værdier som \x41 og \101\n";

#chop og chomp
#chop fjerner sidste char i en string. 
#chomp fjerner den kun hvis det er en newline, eller hvad $/ er sat til.

