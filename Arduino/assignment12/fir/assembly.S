#include <avr/io.h>


.global filterAtIndex
filterAtIndex:
  
  push r21
  push r20
  
  ; replace with your code!
  ; load the input values
  ldi r30, lo8(input1)
  ldi r31, hi8(input1)
  lsl r24 
  add r30,r24
  adc r31,r25
  ld r24,Z+
  ld r25,Z
  
  ;load the filter values
  ldi r26, lo8(fir1)
  ldi r27, hi8(fir1)
  lsl r22
  add r26,r22
  adc r27,r23
  ld r22,X+
  ld r23,X
  
  
  ldi r20, 15
  ldi r21, 0
  
  call qMultiply
  

  
  
  pop r20
  pop r21
  add r20,r24
  adc r21,r25
  mov r24,r20
  mov r25,r21

  ret
