/* Name: Arin Santry
*  File: MP4.cpp
*  Date Due: 29 November 2018
*  Desc: Encript and decript text files using a  Vigenère cipher
*        Executable through command line
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function prototypes
char encipher(char key, char plain);
char decipher(char key, char cipher);

// set up file streams
ifstream inputStream;
ofstream outputStream;

int main(int argc, char* argv[])
{
	char ch; // characters of the file to be encripted/decripted

	string option = argv[1];  // option -e (encript) or -d (decript)
	string keyword = argv[2]; // keyword for encription/decription
	string inFile = argv[3];  // input file
	string outFile = argv[4]; // output file

	// open file streams
	inputStream.open(inFile);
	outputStream.open(outFile);

	// explain format if there are not 5 arguments in the command line
	if (argc != 5)
	{
		cout << "format: " << argv[0] << " -option keyPhrase infile outfile\n";
		exit(1);
	}

	// Error if input file could not be opened
	if (inputStream.fail())
	{
		cout << "Could not open input file.\n";
		exit(1);
	}

	// Error if output file could not be opened
	if (outputStream.fail())
	{
		cout << "Could not open output file.\n";
		exit(1);
	}

	int keyChar = 0; // Character of the keyword (0-end of keyword)
	while (true)
	{
		inputStream.get(ch); // Read file character-by-character
		if (inputStream.eof()) break; // Break out of the loop if the file ends
		if (option == "-e") // encription option
		{
			ch = encipher(keyword[keyChar], ch); // encript the character
			outputStream << ch; // write encripted character into output file
		}
		if (option == "-d") // decription option
		{
			ch = decipher(keyword[keyChar], ch); // decript the character
			outputStream << ch; // write decripted character into output file
		}
	
		keyChar++; // increment character location of the keyword
		if (keyChar == keyword.length()) keyChar = 0; // reset character location to 0 when the keyword ends
	}

	outputStream.open(outFile); // open output file

	cout << "Done!" << endl; // Feedback

	// close streams
	inputStream.close();
	outputStream.close();
}

// Function definitions

// encipher - encipher character from the input file (plain)
// Add the ASCII values of the plain character with the key character
// Returns new encripted character
char encipher(char key, char plain)
{
	char enChar;
	enChar = plain + key;
	return enChar;
}

// decipher - decipher character from input file (cipher)
// Subtract ASCII value of key character form cipher character
// Return deciphered characters
char decipher(char key, char cipher)
{
	char deChar;
	deChar = cipher - key;
	return deChar;
}