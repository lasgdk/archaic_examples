#Copy all sites from cookies.txt to hostperm, so they cannot set cookies again.
#After this, you should check out hostperm, and remove lines with friendly sites

# cp hostperm.1 hostperm.1.backup 

cut -d "	" -f 1 cookies.txt | sed s/www.// | sed s/"^\."// | grep -v "^#" | grep -v "^ " | sort | uniq | sed s/^/"host	cookie	2	"/ >> hostperm.1

sort hostperm.1|uniq > hostperm.1


