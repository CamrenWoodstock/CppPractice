/*--------------------------------------------------------------------------+
|	This code sample is about the difference between C-style and C++-style	|
|	headers, namespaces. and the difference between pointers and references |
|																			|
|	Jean-Yves Hervé, 2020-02-27, rev. 2020-10-19							|
+--------------------------------------------------------------------------*/

// "true" C++ system headers
#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
// C++ wrappers for system C headers
#include <cstdio>
#include <cstring>
////	"pure" system C headers with no existing C++ wrapper
#include <unistd.h>
//	user  headers
#include "myHeader.h"
#include "LinearAlgebra.h"	//	part of namespace linalg
#include "graphics.h"		//	part of namespace graph


//============================================================================
//	Function prototypes
//============================================================================

void swap(int a, int b);
void swap(int* a, int* b);
void myFunc(int&a, int& b);
void myFunc(int* a, int* b);


//============================================================================
//	Part 0:	Namespace
//============================================================================
//	Namespaces allow us to use different "packages" or libraries containing
//	data types with similar names.   For example, throughout my code, I may
//	need to use three different classes all named "vector": One from the standard
//	library of C++, one from a linear algebra library, and one from a computer
//	graphics library (for the little arrow thing).  They would all be named
//	vector, and I could use them all because they belong to different namespaces.

//	I can say that one particular namespace is the "default" one to look for 
//	incase of doubt or ambiguity
using namespace std;

//	Because I wrote "using namespace std" earlier, this vector is an
//	std::vector
vector<int> v;

//	If I want to use the other kinds of vectors, I have to specify
//	their namespace
linalg::vector v1;
graph::vector v3;

//	Note that some authors are very vocal advocating against the use of
//	"using namespace" in any case or circumstance.  I say ¯\_(ツ)_/¯

//============================================================================
//============================================================================


int main (int argc, char * const argv[]) {

	
	//========================================================================
	//	Part I:	Casting
	//========================================================================
	
	//	Casting C-style
    //---------------------
    //	Note that I put braces around this block of code so that the variables
    //	declared inside are local to the block, and I can re-declare an x later
    //	on.
	{
		double x = 12.657;
		int ix = (int) x;
		cout << "x = " << x << "\t\tix = " << ix << endl << endl;

		//	Possible
		int* px = (int*) &x;

		//	The compiler will grouch for questionable stuff
		int* px2 = (int*) ix;

		//	and it should downright reject wrong stuff
		int ix2 = (int) px;
		
		//	...but that's really because of size issues.  When it comes down to it, everything
		//	is an integer, in C/C++.
		long lx2 = (long) px;
	}

    //  Casting in C++
    //---------------------
	{
		double x = 12.657;

		//	Casting old-C++ style. In addition to the C style, C++ also allowed
		int ix1 = int(x);

		//	Casting "new" C++ style.  In general, C++ aims at minimizing the
		//  need for casting, even tends to discouraging it.  However, in System
		//  programming, we need to operate in a hybrid C/C++ world and we will
		//  still need to cast a lot.  You should try as much as possible to
		//  use one of the following 4 operators:
		//      o static_cast<TYPE> is used to force conversions, say, from an
		//          int to a char, or a void* to a char*.  It is also used to
		//			make explicit some casts that the compiler would do implicitly,
		//			such as a regular char* to a const char*.
		//      o dynamic_cast<TYPE>  is mostly used in the context of class 
		//			inheritance, to check where a particular object belongs in
		//			a class hierarchy.
		//		o const_cast<TYPE>  is used to "cast away" the const modifier
		//			imposed by a function's API.  It pretty much should only
		//			be used in last resort, when your code must interface either
		//			with really old legacy code (before const was introduced) 
		//			or really crappy modern code (doesn't use const at all)
		//		o reinterpret_cast<TYPE> is the one you are least likely to encounter.
		//			It is most commonly used for low-level memory operations,
		//			for exemple in drivers working with a bytestream.
		//	You should make efforts to use the new casting style rather than the
		//	old ones:
		//		o With modern IDEs' code autocomplete ability, typing isn't any longer.
		//		o It is easier to search for casts in your code with this syntax.
		//		o The bit of time you think which of the forms you should use makes
		//			you think what exactly you are trying to do.
		int ix2 = static_cast<int>(x);
	}
	
    return 0;
}

