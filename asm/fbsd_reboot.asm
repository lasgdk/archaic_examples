;Lars Sommer, 2006-04-20
global _start
_start:
xor eax,eax
push eax 
mov al,0x37 
int 0x80 
