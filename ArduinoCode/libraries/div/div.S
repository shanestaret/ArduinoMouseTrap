.file "div.S"
.text
.global div;declare div as global so it is visible outside

divide:
;long div(int, int);
ldi r21, 0 ;load the counter and set it to 0

subtract:
cp r24, r22 ;comparing the numbers in r24 and r22
brlt finish ;branch if r24 < r22 and go to method 'finish'
sub r24, r22 ;subtract r24 from r22
inc r21 ;increment count by 1
jmp subtract ; go back to the top of the loop and see if we still need to subtract

finish:
ldi r24, r21 ;set r24 (our quotient) equal to the count
lsr r24 ;divide the long by 2
ret