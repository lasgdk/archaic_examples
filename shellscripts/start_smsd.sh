RUNNING=`ps ax | grep smsd | grep -v start_smsd.sh |grep -vc grep`
echo $RUNNING

if [ "$RUNNING" -eq "0" ];then
	echo "Starting smsd.."
	smsd -u smsgw -p smsgw -c localhost -m mysql -d smsgw &
	echo "smsd started"|mail -s "smsd started" lasg@lasg.dk
	logger "smsd started"
else
	echo "smsd already running?"
fi


