#include <avr/io.h>


.global filterAtIndex
filterAtIndex:
  
  push r21 ;save the sum value
  push r20 
  
  ; replace with your code!
  ; load the input values
  ldi r30, lo8(input1)
  ldi r31, hi8(input1)
  lsl r24 
  rol r25
  add r30,r24
  adc r31,r25
  ld r24,Z+
  ld r25,Z
  
  ;load the filter values
  ldi r26, lo8(fir1)
  ldi r27, hi8(fir1)
  lsl r22
  rol r23
  add r26,r22
  adc r27,r23
  ld r22,X+
  ld r23,X
  
  
  ldi r20, 15
  ldi r21, 0
  
  call qMultiply
  pop r20
  pop r21
  add r20,r24 ;add new sum to the old sum
  adc r21,r25
  mov r24,r20 ;because the function return at r25:r24
  mov r25,r21

  ret

  .global filterLoop
filterLoop:


mov r31, r25 ;didn't work when move to r16:r15 because they are call-saved reg
mov r30, r24

ldi r19,0 ;value of j
ldi r20,0 ;adjust the offset by 2 because for some reason the sum always start at 2
label2:
ldi r18,1
ldi r27,27

cp r27,r19  ; iterates 27 times
breq label1

mov r24,r30
mov r25,r31
sub r24,r19 ;load the sample index
ldi r25, 0
mov r22,r19 ;load the filter index
ldi r23, 0
add r19,r18

push r31
push r30
push r19


call filterAtIndex

pop r19
pop r30
pop r31

mov r20,r24
mov r21,r25 ;save the sum value for next filteratIndex

jmp label2
label1:
mov r24,r20
mov r25,r21

ret
