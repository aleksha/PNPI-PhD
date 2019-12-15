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
  cout << "I'm a C++ program";
}
