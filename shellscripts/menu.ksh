#!/bin/ksh
select svar in "pwd" "pwd" "dato" "slut"
do
	case $svar in
	"pwd")
		pwd
		;;
	"dato")
		date
		;;
	"slut")
		exit 0
		;;
	*)
		echo "Galt valg!"
		;;
	esac
done

