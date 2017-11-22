.name		"bronx killa"
.comment	"gansta's attitude"
.extend

	
	sti	r1, %:live, %1
	sti	r1, %:rocket1, %1
	sti	r1, %:rocket2, %1
	sti	r1, %:live2, %1
debut:	ld	%155, r5
	fork	%:live2
	sti	r1, %:liv, %1
	sti	r1, %:livs, %1

livs:	live	%15	
	fork	%:debut		
liv:
	live	%15
	fork	%:loaded

liv2:
	live	%15
	and	r1, %0, r1
	fork	%:zork

	
live:
	live	%15
	zjmp	%:live

loaded:
	sti	r1, %:write, %1
	sti	r1, %:zork, %1	
	ld	%:live, r2
	ld	%:live + 4, r3
	
write:
	live	%15
	sti	r2, %:live - 4, %-52 
	sti	r3, %:live, %-52
	sti	r2, %:live - 4, %-60 
	sti	r3, %:live, %-60 
	sti	r2, %:live - 4, %-68 
	sti	r3, %:live, %-68
	sti	r2, %:live - 4, %-76 
	sti	r3, %:live, %-76
	sti	r2, %:live - 4, %-84 
	sti	r3, %:live, %-84
	sti	r2, %:live - 4, %-92 
	sti	r3, %:live, %-92 
	sti	r2, %:live - 4, %-100 
	sti	r3, %:live, %-100
	sti	r2, %:live - 4, %-108 
	sti	r3, %:live, %-108
	sti	r2, %:live - 4, %-116 
	sti	r3, %:live, %-116
	sti	r2, %:live - 4, %-124 
	sti	r3, %:live, %-124
	sti	r2, %:live - 4, %-132 
	sti	r3, %:live, %-132
	sti	r2, %:live - 4, %-140 
	sti	r3, %:live, %-140
	sti	r2, %:live - 4, %-148 
	sti	r3, %:live, %-148
	sti	r2, %:live - 4, %-156 
	sti	r3, %:live, %-156
	sti	r2, %:live - 4, %-164 
	sti	r3, %:live, %-164
	sti	r2, %:live - 4, %-172 
	sti	r3, %:live, %-172
	sti	r2, %:live - 4, %-180
	sti	r3, %:live, %-180
	sti	r2, %:live - 4, %-188 
	sti	r3, %:live, %-188
	sti	r2, %:live - 4, %-196 
	sti	r3, %:live, %-196
	sti	r2, %:live - 4, %-204 
	sti	r3, %:live, %-204
	sti	r2, %:live - 4, %-212
	sti	r3, %:live, %-212
	and	r1, %0, r1
	zjmp	%:write

zork:	
	live %15
	zjmp %:zork	

live2:
	live	%15
	fork	%:entree_rocket1
	and	r1, %0, r1
	zjmp	%:live2
	
	zjmp %200
					
entree_rocket1:
	fork	%:rocket2

rocket1:
	live	%15
	fork	%:rocket2b
	ldi	%:fin, %0, r2
	ld	%0, r6
	and	r1, %0, r1
	zjmp	%:fin

rocket2:
	live	%15
	fork	%:rocket2b
	ldi	%:fin, %4, r2
	ld	%4, r6
	and	r1, %0, r1
	zjmp	%:fin

live2:
	live	%15
	fork	%:entree_rocket1
	and	r1, %0, r1
	zjmp	%:live2

rocket1b:
	ldi	%:fin, %0, r2
	ld	%0, r6
	and	r1, %0, r1
	zjmp	%:fin

rocket2b:
	ldi	%:fin, %4, r2
	ld	%4, r6
	and	r1, %0, r1
	zjmp	%:fin

fin:
	sti	r2, r5, r6
	zjmp	%150