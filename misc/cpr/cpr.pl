#!/usr/bin/perl

if ( scalar ( @ARGV ) <= 6) {

	print "\n\tBrug: ./cpr 1 2 3 4 5 6 koen\n";
	print "\tf.eks. 1 3 0 8 8 0 1 == mand foedt 130880\n";
	print "\tkoen: 1 = mand - 2 = kvinde\n\n";
	exit;

}

@num[0] = $ARGV[0] * 4;
@num[1] = $ARGV[1] * 3;
@num[2] = $ARGV[2] * 2;
@num[3] = $ARGV[3] * 7;
@num[4] = $ARGV[4] * 6;
@num[5] = $ARGV[5] * 5;

$left_test = 0;
$left_tal = "";
$cpr_count = 0;

for ( $x = 0; $x <= 5; $x++) {

	$l_test += @num[$x];
	$l_tal .= "$ARGV[$x]";
}


for ( $a = 0; $a < 10; $a++ ) {
  for ( $b = 0; $b <= 9; $b++ ) {
    for ( $c = 0; $c <= 9; $c++ ) {
	  for ( $d = @ARGV[6]; $d < 10; $d += 2) {
				
	    $r_test = $a * 4;
		$r_test += $b * 3;
		$r_test += $c * 2;
				
		$kontrol_test = 11 - (($l_test + $r_test)%11);
				
		$r_test += $d * 1;
				
		$cpr_test = ($l_test + $r_test)%11;
				
		if ( $cpr_test == 0 ) {
					
		  $r_tal = "";	
		  $r_tal .= $a;
		  $r_tal .= $b;
		  $r_tal .= $c;
		  $r_tal .= $d;
					
		  print "$l_tal - $r_tal ($kontrol_test)";
				
		  $cpr_count += 1;
		    print "\n";
	    }
	  }
	}
  }
  if ( $a == 4 ) { $a = 8 }
}

print "\n I alt: $cpr_count\n";
