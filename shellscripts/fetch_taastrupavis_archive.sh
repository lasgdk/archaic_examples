MAX=217
START=209
c=$START

while [ $c -le ${MAX} ];do

	wget -O taastrupavis_large_${c}.pdf "http://www.e-pages.dk/bgmonline_ta/${c}/fullpdf/" 

	c=`expr $c + 1` 

done


