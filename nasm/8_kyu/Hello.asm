; https://www.codewars.com/kata/523b4ff7adca849afe000035

SECTION .text
  meow:db "Hello World!", 0
global greet

;  Return "Hello World!"
greet:
  xor rax, meow
  ret