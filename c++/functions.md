Functions
=========

 - http://www.cplusplus.com/doc/tutorial/functions/

Function is specified by:
 - type of value it returns
 - name
 - arguments

If nothing to return, use **_void_** type.


```c++
string concatenate1 (string a, string b){ return a+b; }
...
string concatenate2 (string& a, string& b)
...
string concatenate3 (const string& a, const string& b)
```

Arguments by reference do not require a copy. 

In the 3rd case there is a guarantee that its reference parameters 
are not going to be modified by this function


Inline functions
----------------

Call of function generally causes a certain overhead (stacking arguments, jumps, etc...), 
and thus for very short functions, it may be more efficient to simply insert the code 
of the function where it is called, instead of performing the process of 
formally calling a function.

```c++
inline string concatenate4 (const string& a, const string& b) {   return a+b; }
```


Deafult value in parameters
```c++
int summa (int a, int b = 5) {   return a+b; }
```

Prototype declatation
----------------------

```c++
// declaring functions prototypes
#include <iostream>
using namespace std;

// Anyway, including a name for each parameter always improves legibility of the declaration.
// but could be   void func(int)
void func (int x);

int main()
{
  ...
  int i;
  func(i);
  ...
  return 0;
}

void func (int x)
{
 ...
}
```

Some notes
----------

If the execution of main ends normally without encountering a return statement the compiler 
assumes the function ends with an implicit return statement:
```c++
return 0;
```

Recursivity is the property that functions have to be called by themselves. It is useful for some tasks.
