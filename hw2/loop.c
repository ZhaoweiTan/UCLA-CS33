//Question 3.60

/*
Short Anwsers 
A.
x is in %r8
n is in %rcx
result is in %rax 
mask is in %rdx 

B. 
result's initial value is 0
mask's initial value is 1

C.
mask 1= 0

D.
mask <<= n's lowest 8 bits 

E.
result |= (x & mask)

F.
*/ 

long loop(long x, long n){
  long result = 0;
  long mask;
  for (mask = 1; mask != 0; mask << n){
    result |= (mask&x);
  }
  return result;
}
