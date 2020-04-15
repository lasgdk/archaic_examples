while (true) do
HUM=`echo $HUM|md5|awk '{print $1}'`
echo -n $HUM
done
