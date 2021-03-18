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
//	Custom Data Types 
//============================================================================
//	Struct works just as in C, but in addition we can now aso define functions
//	for structs.  For all purposes, a C++ struct is the same thing as a class,
//	the only difference being that in a struct, members are public by default,
//	while they are private by default in a class, but it is possible to
//	override the default behavior for both.
//	In practice, people *tend* to think of and use structs mostly as storage
//	data types, with all members public, and classes as "action-oriented"
//	data types, but you cannot count on that
//
//	Also, in C++ "typedef", while still defined/working, is superseded by "using"
using MyType = struct  
{
	int x;					//
	int y;					//	all public (by default)
	int sumTerms(void);		//
	
};

using MyClass = class
{
	int x;					//
	int y;					//	all private (by default)		
	int sumTerms(void);		//
	
};


//============================================================================
//	Function prototypes
//============================================================================

void swap(int a, int b);
void swap(int* a, int* b);
void myFunc(int&a, int& b);
void myFunc(int* a, int* b);

using namespace std;


//============================================================================
//	References vs. Pointers
//============================================================================


int main (int argc, char *const argv[]) 
{
	//	shuts off warning mabout arguments or variables not used.
	(void) argc;
	(void) argv;
	
	
	int a = 123;
	int b = 67;

	int &ref1 = a;
	cout << "a = " << a << endl;
	cout << "ref = " << ref1 << endl << endl;

	ref1 = 54;
	ref1 = b;

	cout << "a = " << a << endl;
	cout << "ref = " << ref1 << endl << endl;

	//--------------------------------
	//	Lots of things not to do!
	//--------------------------------
	
	//	A reference must be initialized
	int &invalid;

	//	A reference is relative to a variable (or part of an object or array),
	//	not relative to data
	int &invalid2 = 3;

	//	a reference is not a pointer
	int &ref2 = &a;

	//	but this works
	int* pa = &a;
	int* &ref3 = pa;
	*ref3 = 20;
	
	//	This too
	int av[] = {8, 12, -6, 43};
	int &ref5 = av[2];

	//	No
	int* &ref6 = a;
	int* &ref7 = av;

	//	References work with any data type.
	MyType zz = {45, -12};
	MyType &yy = zz;
	yy.x = 34;

	//	As stated above, a reference is relative to a variable, not data
	MyType &xx = {23, 27};

	//	what about this?
	int* const &ref4 = &a;
	*ref4 = 55;

	//	const references don't care much about type, even if the size of the data are not
	//		the same.  Note that this is not a binary map but a conversion.
	const double &ref8 = a;
	//	of course, it's a const ref, so I cannot modify the value
	//ref8 = 1.5;
	cout << "a = " << a << endl;
	cout << "ref8 = " << ref8 << endl << endl;

	//	what if the variable we are referring to is itself const?
	const int ca = 1234;
	const int &refca1 = ca;
	const int* const &refpca1 = &ca;

	//	Reference vs. pointer as arguments to a function
	//--------------------------------------------------
	int u = 6, v =12;
	swap(u, v);
	swap(&u, &v);
	
    return 0;
}

void swap(int* x, int* y) 
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//	This does nothing, so it is bad code
// void swap(int a, int b) 
// {
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }


void swap(int& x, int& y) 
{
	int temp = x;
	x = y;
	y = temp;
}

