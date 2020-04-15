#!/usr/bin/perl

@testarray = ('test1','test2',3);
print join(' ',@testarray)."\n";
#test1 test2 3
print join('-',@testarray)."\n";
#test1-test2-3
print join ('.',@testarray[0],@testarray[2])."\n";
#test1.3

$teststring="Hej ve-rd-en";
@stringsplitted=split(/ /,$teststring);
print @stringsplitted[0]."\n";
#Hej

@stringsplitted2=split(/-/,$teststring);
print @stringsplitted2[2]."\n";
#en
print join('',@stringsplitted2)."\n";
#Hej verden
