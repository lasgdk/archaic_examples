while [ true ]
do
	clear
	ps ax|grep onioncrawl.sh|grep -v grep
	sleep 300
done

