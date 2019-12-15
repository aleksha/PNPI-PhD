Statements
==========


Selection
=========

```c++
if (x > 0){
  cout << "x is positive";
}
else if (x < 0){
  cout << "x is negative";
}
else{
  cout << "x is 0";
}

...

switch (x) {
  case 1:
  case 2:
  case 3:
    cout << "x is 1, 2 or 3";
    break;
  default:
    cout << "x is not 1, 2 nor 3";
  }
```

Loops
=====

```c++
while (expression) { statement } 
...
do { statement } while (condition)
...
for (initialization; condition; increase) { statement }
...
// rannge based loop
string str {"Hello!"};
for (char c : str)
{
  cout << "[" << c << "]";
}
```

Jumps
=====

**break** leaves a loop, even if the condition for its end is not fulfilled. 
It can be used to end an infinite loop, or to force it to end before its natural end. 


**continue** - skips rest part of the loop

**goto** - one shoul avoid to use it

```c++
// goto loop example
#include <iostream>
using namespace std;

int main ()
{
  int n=10;
mylabel:
  cout << n << ", ";
  n--;
  if (n>0) goto mylabel;
  cout << "liftoff!\n";
}
```


