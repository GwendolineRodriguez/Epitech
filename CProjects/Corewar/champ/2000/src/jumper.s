#debut du mega truc qu'il est trop dur a faire

.name "Jumper !"
	.comment "en fait C forker !"

gobepc:	st r1,:buff
	st r6,-4
	ld :buff,r1
debut:	ld %0,r7
	zjmp %:suite

goboucle0:	live %66
		ldi %-5,r3,r1
		sti r1,%-173,r3
		add r3,r4,r3
		xor r5,r3,r6
		zjmp %:finboucle0
		ld %0,r7
		zjmp %:goboucle0
finboucle0:	xor r3,r3,r3
		zjmp %-207

buff:	st r1,r1	
		
suite:	sti r1,%:livel,%1
livel:	live %66
	sti r2,%:debut,%-60
	ld %4,r4
	st r2,512
go:	ld %48,r5
	sti r1,%:goboucle0,%1
	sti r1,%:goboucle1,%1
	sti r1,%:live0,%1
	sti r1,%:live1,%1
	sti r1,%:live2,%1
	sti r1,%:live3,%1
	sti r1,%:live4,%1
live0:	live %66
live1:	live %66
live2:	live %66
live3:	live %66
live4:	live %66
	zjmp %:live0
	xor r3,r3,r3
	sti r1,%:livex,%1
livex:	live %66
	fork %:live0
	sti r1,%:boucle,%1
	sti r1,%:boucle,%9
	sti r1,%:boucle,%17
	sti r1,%:boucle,%25
	
boucle:	live %66
	fork %:goboucle0
	live %66
	fork %:boucle
	live %66
	fork %:goboucle1
	live %66
	zjmp %:goboucle0
goboucle1:	live %66
		ldi %-5,r3,r1
		sti r1,%147,r3
		add r3,r4,r3
		xor r5,r3,r6
		zjmp %:finboucle1
		ld %0,r7
		zjmp %:goboucle1
finboucle1:	xor r3,r3,r3
		zjmp %113
#boost:	ld %12,r2
#	ld %3,r3
#	ld %4,r4
#	ld %5,r7

#	ldi %:ecriture,%-1,r9
#	sti r1,%:live1,%1
#live1:	live %66
#	sti r1,%:fork0,%1
#	sti r1,%:fork1,%1
#	sti r1,%:fork2,%1
#	sti r1,%:wait,%1
#	sti r1,%:master,%1
#	sti r1,%:numero1,%1
#	sti r1,%:numero2,%1
#	sti r1,%:live,%-4
#	ld %0,r5
#vazy:	ldi %:live,%-2,r6
#numero1:	live %66
#		ld %3,r3
#		ld %68436,r2
##		ldi %:live,%-2,r6
#liven1:	live %66
#	fork %:ready
#	sti r9,%:ecriture,%-1
#fork1:	live %66
#numero2:	live %66
#		ld %6,r3
#		ld %1409680135,r6
##		ldi %:tampon,%1,r6
#liven2:	live %66
#	fork %:ready
#fork2:	live %66
#master:		live %66
#		ld %0,r3
#		ld %16777216,r6
##		ldi %:master,%0,r6	
#livem:	live %42
#	fork %:vazy
#fork0:	live %66
#	add r5,r5,r5
#	sti r6,r3,%:ecriture
#	zjmp %:ecriture

#tampon:	sti r6,r3,r5
#live:	sti r1,r5,r5

#ready:	ld %0,r5
#	sti r6,r3,%:ecriture
#	zjmp %:ecriture
#wait:	live %66
#	zjmp %:ecriture

#ecriture:	zjmp %:wait









