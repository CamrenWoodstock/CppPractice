/*--------------------------------------------------------------------------+
|	This code sample is about the use of references (rather than pointers) 	|
|	to structs & classes													|
|																			|
|	Jean-Yves Hervé, 2020-02-27												|
+--------------------------------------------------------------------------*/

#include <iostream>
#include <typeinfo>

using namespace std;

#define REF_VERSION		1
#define DEBUG_LEVEL		3

//-----------------------------------------------------------------------
//	Custom data types
//-----------------------------------------------------------------------

//	C-style struct declaration
typedef struct Point 
{
	int x, y;
} Point;

typedef double Number;


//	C++ style (C++ 11 and later struct declaration)
using MyThing = struct 
{
	int x;
	float y;
} ;

using NewNumber = double;

//	This type is borderline silly.  It just serves as illustration of
//	something (but I forgot what).
using DualArray = struct
{
	int sizeA, sizeB;
	int* a;
	float* b;
};

//-----------------------------------------------------------------------
//	Function prototypes
//-----------------------------------------------------------------------
//	C++ supports function overloading
void myFunc(int* a, int* b);

#if REF_VERSION
	void myFunc(int&a, int b);
#else
	void myFunc(int a, int b);
#endif

Point& staleReference(int a, int b);
void someOtherFunc(Point& a, const Point& b);
void someOtherFunc(Point* a, const Point* b);
DualArray someFuncV1(int m, int n);
void** someFuncV2(int m, int n);
MyThing& myFunc(void);

// return value is the int array    float array is an "output" parameter
int*  someFuncV3(int m, int n, float** b);

// int and float arrays are output parameters
void  someFuncV4(int m, int n, int**a, float**b);


//-----------------------------------------------------------------------
//	Function implementations
//-----------------------------------------------------------------------

int main (int argc, const char* argv[]) {

	Number xy = 33;
	
	int arr[3] = {4, 7, 10};
	int bbb[5];
	int* const &rarr = arr;
	int xxx = arr[5];
	int yyy = rarr[7];
	cout << "value of yyy = " << yyy << endl;
	
 	Point p = {100, 20};
 	Point q = {20, -5};
 	someOtherFunc(p, q);
 	someOtherFunc(&p, &q);
 	
 	Point& u = staleReference(3.,5);
 	delete &u;
	
    return 0;
}

MyThing& myFunc(void)
{
	MyThing* p = new MyThing;
	
	return *p;
}



void someOtherFunc(Point& a, const Point& b)
{
	a.x += b.x;
	a.y += b.y;
}

void someOtherFunc(Point* a, const Point* b)
{
	a->x += b->x;
	a->y += b->y;
}


#if REF_VERSION

	void myFunc(int&a, int b) 
	{
		a += b;
	}

#else

	void myFunc(int a, int b)
	{
		a += b;
	}

#endif

int*  someFuncV3(int m, int n, float** b)
{
	int* a = new int[m];
	*b = new float[m+n];


	return a;
}

void**  someFuncV2(int m, int n)
{
	int* a = new int[m];
	float* b = new float[m+n];
	
	void** returnVal = new void*[2];
	returnVal[0] = a;
	returnVal[1] = b;

//	void* returnVal[2] = {a, b};

	return returnVal;
}


DualArray  someFuncV1(int m, int n)
{
	DualArray returnVal = {m, m+n, new int[m], new float[m+n]};

	return returnVal;
}



void myFunc(int* a, int* b) 
{
	*a += ++(*b);
	
	a+= 2;
//	a[4] = 5;
}




// a and b are i/o parameters.  c  is input parameters
void myFunc(int* a, int* b, int c) 
{
	*a += ++(*b) + c;
}


