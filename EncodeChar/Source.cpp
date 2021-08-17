#include <iostream>
#include <string>
#include <stdexcept>
#define DEBUG
using namespace std;
// Encodes the character at index i of the string str.
void encodeChar(int i, string& str)
{
	
	int base = static_cast<int>('a');
	if (isupper(str.at(i))) {
		base = static_cast<int>('A');
	}
	char newChar = (static_cast<int>(str.at(i) - base + 3) % 26 + base);
	try
	{
		str.replace(i, 1, 1, newChar);
	}
	catch (out_of_range logErr)
	{
		cout << "No character at position " << i << endl;
	} // end try-catch
} // end encodeChar
// Encodes numChar characters within a string.

void encodeString(int numChar, string& str)
{
	try
	{
		for (int i = numChar - 1; i >= 0; i--) {
			encodeChar(i, str);
		}
	}
	catch (out_of_range logErr)
	{
		cout << "The string does not contain " << numChar << " characters." <<endl;
		cout << logErr.what() << endl;
	} // end try-catch
} // end encodeString

int main()
{
	string str1 = "Sarah";
	encodeString(99, str1);
	cout <<"String after encode: "<< str1;
	return 0;
} // end main