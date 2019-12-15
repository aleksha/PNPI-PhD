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
//Programm with string
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
}
```

String class reference: http://www.cplusplus.com/reference/string/string/

Literals
--------

Literals are used to express particular values within the source code of a program.
```c++
// same nuber but in different numerics
76         // decimal
0114       // octal
0x4c       // hexadecimal
...
// literals can ghave types
75         // int
75u        // unsigned int
75l        // long
75ul       // unsigned long 
75lu       // unsigned long
...
// for floating point
3.14159    // 3.14159
6.02e23    // 6.02 x 10^23
1.6e-19    // 1.6 x 10^-19
3.0        // 3.0  
3.14159L   // long double
6.02e23f   // float  
```

Escape codes
------------

Special characters that are difficult or impossible to express otherwise 
in the source code of a program:
 - **\n**	newline
 - **\r**	carriage return
 - **\t**	tab
 - **\v**	vertical tab
 - **\b**	backspace
 - **\f**	form feed (page feed)
 - **\a**	alert (beep)
 - **\'**	single quote (')
 - **\"**	double quote (")
 - **\?**	question mark (?)
 - **\\**	backslash (\)

Typed constant expressions
---------------------------

One can use names instead of the literals or use of preprocessor definitions.

```c++
#include <iostream>
using namespace std;

const double pi = 3.14159;
const char newline = '\n';

#define PI 3.14159
#define NEWLINE '\n'

// Any occurrence of PI in the code is interpreted 3.14159

int main ()
{
  double r=5.0;               // radius
  double circle;

  circle = 2 * pi * r;
  cout << circle;
  cout << newline;

  circle = 2 * PI * r;
  cout << circle;
  cout << NEWLINE;
}
```

Basic I/O
----------

he standard library defines a handful of stream objects that can be used to access 
what are considered the standard sources and destinations of characters 
by the environment where the program runs:
 - **cin**	standard input stream
 - **cout**	standard output stream
 - **cerr**	standard error (output) stream
 - **clog**	standard logging (output) stream

```c++
// i/o example

#include <iostream>
using namespace std;

int main ()
{
  int i;
  cout << "Please enter an integer value: ";
  cin >> i;
  cout << "The value you entered is " << i;
  cout << " and its double is " << i*2 << ".\n";
  return 0;
}
```

Next works, but onsiders spaces (whitespaces, tabs, new-line...) 
as terminating the value being extracted:
```c++
string mystring;
cin >> mystring;
```
One can use **getline()**
```c++
// cin with strings
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string mystr;
  cout << "What's your name? ";
  getline (cin, mystr);
  cout << "Hello " << mystr << ".\n";
  return 0;
}
```

Operators
---------

http://www.cplusplus.com/doc/tutorial/operators/


Statements
----------

 - In short: **statements.md**
 - See also: http://www.cplusplus.com/doc/tutorial/control/

Functions
---------

 - In short: **functions.md**
 - See also: http://www.cplusplus.com/doc/tutorial/functions/
