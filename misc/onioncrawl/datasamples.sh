mkdir -p datasamples

KEYWORDS="westergaard danish danmark denmark kjaersgaard scharf"

for A in `echo $KEYWORDS`; do
	echo "Getting samples based on the word $A"
	grep -r -i $A data/* > datasamples/$A.out
done

