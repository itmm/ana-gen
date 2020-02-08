@* Hello World.
A small C++ program in |CWEB|. The general layout of a C++ program is

@c
@<includes@>@/
int main() {
	@<print msg@>;
}

@ Now the fragments are following. To print something the program first
includes the declarations.

@<includes@>=
#include <iostream>

@ And the message is send to standard output.

@<print msg@>=
std::cout << "Hello World.\n";

