#! /bin/sh

STR="a b c d e f g h i j k l m n o p q r s t u v w x y z 1 2 3 4 5 6 7 8 9 0 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z Æ Ø Å æ ø å"

for ACT1 in $STR; do
	echo -n "${ACT1} "
	md5 -q -s ${ACT1}
	
	for ACT2 in $STR; do
		echo -n "${ACT1}${ACT2} "
		md5 -q -s ${ACT1}${ACT2}

		for ACT3 in $STR; do
			echo -n "${ACT1}${ACT2}${ACT3} "
			md5 -q -s ${ACT1}${ACT2}${ACT3}
		done
	done
done

