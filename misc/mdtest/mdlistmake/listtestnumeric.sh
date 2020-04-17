#! /bin/sh

STR="1 2 3 4 5 6 7 8 9 0"

for ACT1 in $STR; do
	echo -n "${ACT1} "
	md5 -q -s ${ACT1}
	
	for ACT2 in $STR; do
		echo -n "${ACT1}${ACT2} "
		md5 -q -s ${ACT1}${ACT2}

		for ACT3 in $STR; do
			echo -n "${ACT1}${ACT2}${ACT3} "
			md5 -q -s ${ACT1}${ACT2}${ACT3}

			for ACT4 in $STR; do
				echo -n "${ACT1}${ACT2}${ACT3}${ACT4} "
				md5 -q -s ${ACT1}${ACT2}${ACT3}${ACT4}

#				for ACT5 in $STR; do
#					echo -n "${ACT1}${ACT2}${ACT3}${ACT4}${ACT5} "
#					md5 -q -s ${ACT1}${ACT2}${ACT3}${ACT4}${ACT5}
#				done
			done
		done
	done
done

