.name "zork"
.comment "just a basic living prog"
.extend
		
l2:	sti	r1,%:live,%0x1
	and	r1,%0,r1
live:	live	%1
	zjmp	%:live

.code 42 DE AD C0 DE 12 34 61 34 61 23 61


