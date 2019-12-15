C++ language tips
=================

**C++** is a general-purpose programming language created by Bjarne Stroustrup 
as an extension of the **C** programming language. C++ is designed to be a compiled 
language, meaning that it is generally translated into machine language that can be 
understood directly by the system, making the generated program highly efficient. 
To comple programm from the **example.cpp** file with the **GCC** compiler type:
```bash
g++ example.cpp -o example_program
```
For example **example.cpp** could be:
```c++
// This is simple C++ programm

// Two slashes are use for commentsmy second program in C++

#include <iostream>
// nes beginning with a hash sign are directives read and interpreted by so-callede preprocessor. 
// They are special lines interpreted before the compilation of the program itself begins.
// In this case, the directive #include <iostream>, instructs the preprocessor to include 
// a section of standard C++ code, known as header iostream, that allows to perform I/O operations.

using namespace std;
// The above declaration allows all elements in the standard library  namespace to be accessed
//  in an unqualified manner (without the std:: prefix).

int main ()
// The function named main is a special function in all C++ programs; it is the function called 
// when the program is run. The execution of all C++ programs begins with the main function,
// regardless of where the function is actually located within the code.
{
  cout << "Hello World! ";
  cout << "I'm a C++ program" << endl;
}
```
To run the program
```bash
./example_program
```

Important
---------

 - The C++ language is a "case sensitive" language!

 - C++ uses a number of keywords to identify operations and data descriptions; therefore, 
   dentifiers created by a programmer cannot match these keywords
   (http://www.cplusplus.com/doc/tutorial/variables/). 


```c++
int foo = 0;
auto bar = foo;  // the same as: int bar = foo; 
...
decltype(foo) bar2;  // bar2 has the same type as foo; 
```

Strings in C++
--------------
```c++
// my first string
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string my_string;
  mystring = "This is the initial string content";
  cout << my_string << endl;
  my_string = "Same variable but different string content";
  cout << my_string << endl;
  return 0;
}```
