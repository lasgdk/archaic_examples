for ACTUAL in $*
do
FILENAME=$ACTUAL
ORIGINAL=$FILENAME
RESIZED=resized_$ORIGINAL
WATERMARKED=watermarked_$RESIZED
WATERMARK=watermark1.png
convert $ORIGINAL -resize 25% $RESIZED &&
composite -gravity south -geometry +0+10 $WATERMARK $RESIZED $WATERMARKED &&
rm $RESIZED &&
echo "Image $ORIGINAL completed."
done
