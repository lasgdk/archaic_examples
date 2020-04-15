grep -o -h "<.*\@.*>" * | grep -o "\@.*>" | sed s/"\@"/\"\@/ | sed s/">"/\",/ | sort | uniq > new_adr.txt


