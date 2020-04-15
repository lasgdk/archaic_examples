for ACTUAL in $*
do
FILENAME=$ACTUAL
ORIGINAL=$FILENAME
RESIZED=resized_$ORIGINAL
convert $ORIGINAL -resize 33% $RESIZED &&
echo "Image $ORIGINAL completed."
done
