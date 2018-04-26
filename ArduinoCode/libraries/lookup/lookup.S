.file "lookup.S" ; file name
.text ; declaring this section as our text section
.global encode ; declare encode as global so it is visible outside

encode: 

lookupIncrement: ; increments specific counter based on bait that was used or reset if wanted
cpi r24, 4 ; checking if first time through
breq setup ; if first time through, then set memory location for cheese counter to a value of 0

cpi r24, 3 ; checking if user indicates they want to reset counters
breq lookupReset ; resetting counters

cpi r24, 0 ; checking if bait indicates peanut butter
breq incrementButter ; if bait indicates peanut butter, increment peanut butter counter

cpi r24, 1 ; checking if bait indicates jerky
breq incrementBeef ; if bait indicates jerky, increment jerky counter

cpi r24, 2 ; checking if bait indicates cheese
breq incrementCheese ; if bait indicates cheese, increment beef jerky counter

incrementButter: ; adds one to peanut butter counter
inc r29 ; adds 1 to the register keeping track of how many times a mouse was caught using peanut butter
mov r24, r29 ; copies the value of the peanut butter counter into the register we are returning
ret ; returns r24 with the new peanut butter counter value

incrementBeef: ; adds one to beef jerky counter
inc r17 ; adds 1 to the register keeping track of how many times a mouse was caught using jerky
mov r24, r17 ; copies the value of the jerky counter into the register we are returning
ret ; returns r24 with the new beef jerky counter value

incrementCheese: ; adds one to cheese counter
lds r18, 0xFF00 ; load r18 with the contents of address FF00
inc r18 ; adds 1 to the register keeping track of how many times a mouse was caught using cheese
sts 0xFF00, r18 ; store new value of r18 in address FF00
mov r24, r18 ; copies the value of the cheese counter into the register we are returning
ret ; returns r24 with the new cheese counter value

lookupReset: ; resets all counters to 0
ldi r29, 0 ; peanut butter bait counter
ldi r17, 0 ; beef jerky bait counter
jmp setup ; move to setup so that the memory address for the cheese counter can be properly cleared again

setup:
clr r27 ; set r27 (register we aren't using) to 0 so that can be copied to memory location FF00
sts 0xFF00, r27 ; set address FF00 equal to value in r27 (0)
mov r24, r24 ; setting r24 to 0
ret ; returns r24 with 0 as the value of r24 is not important, just that FF00 was set to 0