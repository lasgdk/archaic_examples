/*
 * code to establish a socket; originally from bzs@bu-cs.bu.edu */ 
int establish(unsigned short portnum) { char myname[MAXHOSTNAME+1]; 
	int s; 
	struct sockaddr_in sa; 
	struct hostent *hp; 
	memset(&sa, 0, sizeof(struct sockaddr_in)); 
	gethostname(myname, MAXHOSTNAME); 
	hp= gethostbyname(myname); 
	if (hp == NULL) 
		return(-1); 
	sa.sin_family= hp->h_addrtype; 
	sa.sin_port= htons(portnum); 
	if ((s= socket(AF_INET, SOCK_STREAM, 0)) < 0) 
		return(-1); 
	if (bind(s,(struct sockaddr *)&sa,sizeof(struct sockaddr_in)) < 0) { 
		close(s); 
		return(-1); 
	} listen(s, 3); 
	return(s); 
} 


/*
 * wait for a connection to occur on a socket created with establish() */ 
int get_connection(int s) { int t; 
	if ((t = accept(s,NULL,NULL)) < 0) 
		return(-1); 
	return(t); 
} 




