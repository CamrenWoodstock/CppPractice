//
//  main.cpp
//  File IO
//
//  Created by Jean-Yves Hervé on 2020-10-18
//

#include <iostream>
#include <fstream>
//
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[]) 
{
	//	I use as input file one of our image files from Prog 02

	//-------------------------------------------------------------
	//	Version 1:  Read rows as strings, converting them to char*
	//-------------------------------------------------------------
	{
		cout << "---------------\nVersion 1\n---------------\n";
		ifstream inFile("image1.img");
		int numRows, numCols;
		inFile >> numCols >> numRows;
	
		//	I allocate an array of rows.  Here I want to use the function
		//	to convert a C++ string to a 0-terminated C string, but that
		//	function returns a pointer to private data.  I cannot simply
		//	copy that pointer.  I need to copy the data.
		char** imageData = new char*[numRows];
	
		//	Now read all the rows as strings
		for (int i=0; i<numRows; i++)
		{
			imageData[i] = new char[numCols+1];

			string s;
			inFile >> s;

			//	copy the data
			strcpy(imageData[i], s.c_str());

			printf("%s\n", imageData[i]);
		}
		cout << "-----" << endl;
		for (int i=0; i<numRows; i++)
		{
			printf("%s\n", imageData[i]);
		}
	
		//	close the file
		inFile.close();
		
		//	Let's write the file back
		ofstream outFile("version1.txt");
		outFile << numCols << " " << numRows << endl;
		for (int i=0; i<numRows; i++)
		{
			outFile << imageData[i] << endl;
		}
		outFile.close();
	}
	
	//-------------------------------------------------------------
	//	Version 2:  Read rows as arrays of char, one char at a time
	//-------------------------------------------------------------
	{
		cout << "\n---------------\nVersion 2\n---------------\n";
		ifstream inFile("image1.img");
		int numRows, numCols;
		inFile >> numCols >> numRows;
	
		//	I allocate an array of rows
		char** imageData = new char*[numRows];

		//	Now read all the rows as arrays of characters
		//	Note that I still add space for the \0 extra character
		for (int i=0; i<numRows; i++)
		{
			imageData[i] = new char[numCols+1];
			for (int j=0; j<numCols; j++)
				inFile >> imageData[i][j];
			//	I don't need to consume the end of line character [uh?]
			//	but I must make sure that my row is 0-terminated
			imageData[i][numCols] = 0x00;

			//	I can still print my row as a C string;
			printf("%s\n", imageData[i]);
		}
	
		//	close the file
		inFile.close();
		
		//	Let's write the file back
		ofstream outFile("version2.txt");
		outFile << numCols << " " << numRows << endl;
		for (int i=0; i<numRows; i++)
		{
			outFile << imageData[i] << endl;
		}
		outFile.close();
	}
	
	
	
	return 0;
}
