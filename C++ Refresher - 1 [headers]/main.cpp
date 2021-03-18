//	Back to C++
//	1. Headers

//	1. Load first the "pure" C++ system headers
//	Please note that you shouldn't include the file extension for these headers.
#include <iostream>		//	for basic I/O
//	There exists a file <iostream.h>, and that most likely <iostream>
//	just loads that file, but iostream may also define some macros and constants
#include <string>		//	different from the C <string.h>

//	2. Next, load C++ "wrapper" headers for regular C system headers, when they exist.
//	These will have a c prefix and again no extension.  
#include <cstdio>
#include <cstring>	//	this is for C strings
//	Again, many of these headers simply load the corresponding .h file, but they
//	may also define some macros, so load them rather that directly <stdio.h>

//	3. Next, you load the system C headers for which there is no C++ wrapper
#include <unistd.h>

//	4. finally, your "user" headers (if any)
#include "myHeader.h"


int main(int argc, char* argv[])
{
	//	Now we can use booleans and constants
	bool isOK = false;
	
	const int MY_CONST = 1234;
	
	//	and C++ strings too.
	std::string s = "CSC412";
	std::string t = s + " --> Hello";

	int x = isOK ? MY_CONST : MY_CONST*2;
	
	//	And of course, we have cout
	std::cout << "x = " << x << std::endl;
	std::cout << t << std::endl;
	
	//	Don't forget that all standard output is buffered.  So, if you are
	//	printing out for debugging, force a flush of the buffer after a cout
	// 	if you are planning to see where you crash based on what was printed out (or not)
	std::cout << std::flush;
	
	return 0;
}
