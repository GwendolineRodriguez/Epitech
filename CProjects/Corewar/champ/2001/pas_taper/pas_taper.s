.name           "je suis pas mechant"
.comment        "que quelqu un ose dire que j ai perpom le code"
.extend


debut:  
        sti r1, %:live, %1
        sti r1, %:live2, %1
        sti r1, %:rocket_type, %6
        fork %:loaded
        and     r1, %0, r1
        zjmp %:live2
        
boucle: 
        fork %:debut
                
live:
        live    %15
        zjmp    %:live
                
loaded:
        ld      %:live, r2
        ld      %:live + 4, r3
        fork    %:wall2_jump
        zjmp    %:wall
        
live2:
        live    %15
        fork    %:entre_rocket1
        and     r1, %0, r1
        zjmp    %:live2
                        
wall:
        sti     r1, %:wall_a, %1
        fork    %:entre_rocket2
wall_a:         
        live    %15
        sti     r2, %:live - 4, %-84 
        sti     r3, %:live, %-84
        sti     r2, %:live - 4, %-92 
        sti     r3, %:live, %-92 
        sti     r2, %:live - 4, %-100 
        sti     r3, %:live, %-100
        sti     r2, %:live - 4, %-108 
        sti     r3, %:live, %-108       
	sti     r2, %:live - 4, %-116 
        sti     r3, %:live, %-116
        sti     r2, %:live - 4, %-124 
        sti     r3, %:live, %-124
        sti     r2, %:live - 4, %-132 
        sti     r3, %:live, %-132
        sti     r2, %:live - 4, %-140 
        sti     r3, %:live, %-140
        sti     r2, %:live - 4, %-148 
        sti     r3, %:live, %-148
        sti     r2, %:live - 4, %-156 
        sti     r3, %:live, %-156
        sti     r2, %:live - 4, %-164 
        sti     r3, %:live, %-164
        sti     r2, %:live - 4, %-172 
        sti     r3, %:live, %-172
        sti     r2, %:live - 4, %-180
        sti     r3, %:live, %-180
        sti     r2, %:live - 4, %-188 
        sti     r3, %:live, %-188
        sti     r2, %:live - 4, %-196 
        sti     r3, %:live, %-196
        sti     r2, %:live - 4, %-204 
        sti     r3, %:live, %-204
        sti     r2, %:live - 4, %-212 
        sti     r3, %:live, %-212
        sti     r2, %:live - 4, %-220    
        sti     r3, %:live, %-220
        sti     r2, %:live - 4, %-228 
        sti     r3, %:live, %-228
        sti     r2, %:live - 4, %-236 
        sti     r3, %:live, %-236
        sti     r2, %:live - 4, %-244 
        sti     r3, %:live, %-244
        sti     r2, %:live - 4, %-52 
        sti     r3, %:live, %-252
        sti     r2, %:live - 4, %-260    
        sti     r3, %:live, %-260
        sti     r2, %:live - 4, %-268 
        sti     r3, %:live, %-268
        and     r1, %0, r1
        zjmp    %:wall
        
rocket_type:    
                sti r6, r7, r8
                live %15
                zjmp %300
        
wall2_jump:     sti r1, %:wall2, %1
                zjmp %:wall2
entre_rocket1:
                ld %167 ,r7
                sti r1, %:rocketa1, %1
                sti r1, %:rocketb1, %1
                fork %:rocketb1
        
rocketa1:       
                live %15
rocketb1:               
                live %15
entre_rocket2:  
                ##fork %:rocket2b       
                                        
entre_rocket3:  
                ##fork %:rocket3b
                                        
wall2:
        live    %15
        sti     r1, %:wall2_a, %1
        fork    %:entre_rocket3
wall2_a:                                
        live    %15
        sti     r2, %:live , %298
        sti     r3, %:live + 4, %298
        sti     r2, %:live , %290 
        sti     r3, %:live + 4, %290
        sti     r2, %:live , %282 
        sti     r3, %:live + 4, %282    
        sti     r2, %:live , %274 
        sti     r3, %:live + 4, %274    
        sti     r2, %:live , %256
        sti     r3, %:live + 4, %256
        sti     r2, %:live , %248
        sti     r3, %:live + 4, %248
        sti     r2, %:live , %240 
        sti     r3, %:live + 4, %240
        sti     r2, %:live , %232 
        sti     r3, %:live + 4, %232    
        sti     r2, %:live , %224 
        sti     r3, %:live + 4, %224    
        sti     r2, %:live , %216 
        sti     r3, %:live + 4, %216
        sti     r2, %:live , %204 
        sti     r3, %:live + 4, %204
	sti     r2, %:live , %196	
        sti     r3, %:live + 4, %196    
        sti     r2, %:live , %188 
        sti     r3, %:live + 4, %188
        sti     r2, %:live , %180 
        sti     r3, %:live + 4, %180
        sti     r2, %:live , %172 
        sti     r3, %:live + 4, %172
        sti     r2, %:live , %164 
        sti     r3, %:live + 4, %164
        sti     r2, %:live , %156 
        sti     r3, %:live + 4, %156
        sti     r2, %:live , %148 
        sti     r3, %:live + 4, %148
        sti     r2, %:live , %140 
        sti     r3, %:live + 4, %140
        sti     r2, %:live , %132 
        sti     r3, %:live + 4, %132
        sti     r2, %:live , %124 
        sti     r3, %:live + 4, %124
        sti     r2, %:live , %116 
        sti     r3, %:live + 4, %116
        sti     r2, %:live , %108 
        sti     r3, %:live + 4, %108
        sti     r2, %:live , %100 
        sti     r3, %:live + 4, %100
        sti     r2, %:live , %92 
        sti     r3, %:live + 4, %92
        sti     r2, %:live , %84 
        sti     r3, %:live + 4, %84
        and     r1, %0, r1
        zjmp    %:wall2_a                 