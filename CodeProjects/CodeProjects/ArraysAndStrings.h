#include<iostream>
#include <conio.h>
#include<string>

using namespace std;
class ArraysAndStrings
{
	
#pragma region CheckIfStringHasUniqueCharacters
private:
bool hasUniqueCharacters(string s)
{
	bool asciiSet [256];
	for(int i=0;i<256;i++)
		asciiSet[i] = false;

	for(int i = 0; i< s.length() ;i++)
		if (asciiSet[s[i]] == true) 
			return false;
		else
			asciiSet[s[i]] = true;
	return true;
	
}
public:
void CheckIfStringHasUniqueCharactersControlFunction()
{
	string s;
	cout<<"Test if a string has unique characters. Enter a test string \n";
	getline(cin, s);
	if (hasUniqueCharacters(s))
		cout<<"\n All characters unique.";
	else
		cout<<"\n Found duplicates.";

}

#pragma endregion

#pragma region ReverseCStyleString
private:
void reverseString(char* s)
{
	char* beg = s;
	char* end = s;
	while(*end!='\0')
		end++;
	end--;
	while (beg<end)
	{
		char temp = *beg;
		*beg = *end;
		*end = temp;
		beg++;end--;
	}

}
public:
void ReverseAStringControlFunction()
{
	string s;
	cout<<"Reverse a string. Enter a test string \n";
	getline(cin,s);
	
	//convert to c string and call the function..
	reverseString((char*)s.c_str());
	cout<<"\nReverse string is\n"<<s;
}



#pragma endregion

#pragma region RemoveDuplicateCharactersFromStringWithoutAdditionalBuffer


#pragma endregion

#pragma region CheckIfTwoStringsAreAnagramsOrNot

private:
bool checkIfAnagrams(string x, string y)
{
	if (x.length() !=y.length())
		return false;

	int asciiSet[256];
	for (int i =0;i<256;i++)
		asciiSet[i] = 0;

	for (int i=0;i<x.length();i++)
	{
		asciiSet[x[i]]++;
		asciiSet[y[i]]--;
	}

	for (int i=0;i<256;i++)
		if(asciiSet[i]!=0)
			return false;

	return true;
}

public:
void CheckIfAnagramsControlFunction()
{
	string x,y;
	cout<<"\nTest to check if to strings are anagrams. Enter first string...\n";
	getline(cin,x);
	cout<<"\nEnter second string...\n";
	getline(cin,y);

	if (checkIfAnagrams(x,y))
		cout<<"\nStrings are anagrams!!";
	else
		cout<<"\nStrings are not anagrams...";
}

#pragma endregion

#pragma region ReplaceSpaceInStringWith%20

string ReplaceSpaceWith20(char* s, int length )
{
	int count = 0;
	
	for(int i=0;i<length;i++)
		if (s[i] == ' ')
			count++;
	int newlength = length + (count *2);
	
	int cur = newlength;

	s[newlength] = '\0';
	for(int i = length; i>=0;i--)
	{
		if (s[i]==' ')
		{
			s[cur] = '0';cur--;
			s[cur] = '2';cur--;
			s[cur] = '%';cur--;
		}
		else
		{
			s[cur] = s[i]; 
		    cur--;			
		}
	}
	string ret(s);
	return ret;
}

public:
void ReplaceSpaceWith20ControlFunction()
{
	string s;
	cout<<"\nReplace spaces in string with %20. Enter first string...\n";
	getline(cin,s);
	
	string newString = ReplaceSpaceWith20((char*)s.c_str(),s.length());
	cout<<"\nNew string is..\n"<<newString;
}

#pragma endregion

};