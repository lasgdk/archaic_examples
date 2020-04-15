Elevator Control System
An elevator simulator
Version 0.1, 2007-02-14
Copyright Lars Sommer, larss@es.aau.dk

This is made for fun, and is NOT a part of any project.
This should be made in C, with use of fifos, shared memory and so,
 but I'm not a programmer (just a dirty hacker), so I'll start 
 with lame shell script and plain files.

Files:

queue_req:
id	level	up/dn	to	req_time

queue_run:
id 	from	to	in_time

complete_log:
id 	from	to	req_time	in_time	out_time

register_id:
next_id
