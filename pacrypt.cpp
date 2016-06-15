/*
	PolyAlpha
	A Poly Alphabetic Cipher encrypting machine
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#define INCLUDED_STDFIO
using namespace std;

#define string_buffer_size 1024

int strlen(char* k)
{
	int c=0;
	while(k[c]!=0)
	{
		c++;
	}
	return c;
}

int main()
{
	char key[string_buffer_size];
	char path[string_buffer_size];
	int mainchoice;

	cout << "------------------------------------------------------------" << endl;
	cout << "PolyAlphabetic enCRYPTion v1.1" << endl;
	cout << "Copyright (c) 2016 Naveen Venkat | All Rights Reserved" << endl;
	cout << "Visit: serverprocessor.wordpress.com/pacrypt to learn more" << endl;
	cout << "------------------------------------------------------------" << endl;

	do
	{
		cout << endl;
		cout << "Main: " << endl << "1. Encrypt\n2. Decrypt\n3. Print\n4. Exit\n\n";
		cout << "Select (1-4): ";

		cin>>mainchoice;
		cin.ignore();

		if(mainchoice==4)
		{
			return 0;
		}
		else if(mainchoice==1)
		{
			cout << "Enter source file path: ";
			gets(path);
			ifstream fin(path, ifstream::in);
		
			while(fin.fail())
			{
				cout << "ERROR: File could not be opened. Did you enter the correct path?" << endl;
				cout << "Enter source file path: ";
				gets(path);
				fin.open(path, ifstream::in);
			}
		
			cout << "DONE" << endl;
		
			cout << "Enter destination file path: ";
			gets(path);
			ofstream fout(path, ofstream::out);
		
			while(fout.fail())
			{	
				cout << "ERROR: File could not be opened. Did you enter the correct path?" << endl;
				cout << "Enter destination file path: ";
				gets(path);
				fout.open(path, ofstream::out);
			}
		
			cout << "DONE" << endl;
		
			cout << "Enter Passkey (for security, enter a mix of chars, symbols & no.): ";
			gets(key);
		
			char ch;
			int i=0; int n = strlen(key);
			while(!fin.eof())
			{
				fin.get(ch);
				if(!fin.eof())
				{
					ch+=key[(i++)%n];
					fout.put(ch);
				}
			}
		
			fin.close();
			fout.close();
			cout << "DONE ENCRYPTING! " << i << " Bytes translated!" <<endl;
		}
		else if(mainchoice==2)
		{
			cout << "Enter source file path: ";
			gets(path);
			ifstream fin(path, ifstream::in);
		
			while(fin.fail())
			{
				cout << "ERROR: File could not be opened. Did you enter the correct path?" << endl;
				cout << "Enter source file path: ";
				gets(path);
				fin.open(path, ifstream::in);
			}
		
			cout << "DONE" << endl;
		
			cout << "Enter destination file path: ";
			gets(path);
			ofstream fout(path, ofstream::out);
		
			while(fout.fail())
			{	
				cout << "ERROR: File could not be opened. Did you enter the correct path?" << endl;
				cout << "Enter destination file path: ";
				gets(path);
				fout.open(path, ofstream::out);
			}
		
			cout << "DONE" << endl;
		
			cout << "Enter Passkey: ";
			gets (key);
		
			char ch;
			int i=0; int n = strlen(key);
			while(!fin.eof())
			{
				fin.get(ch);
				if(!fin.eof())
				{
					ch-=key[(i++)%n];
					fout.put(ch);
				}
			}
		
			fin.close();
			fout.close();
			cout << "DONE DECRYPTING! " << i << " Bytes translated!" <<endl;
		}
		else if(mainchoice==3)
		{
			cout << "Enter source file path: ";
			gets(path);
			char ch;
			ifstream fin(path, ifstream::in);
			while(fin.fail())
			{
				cout << "ERROR: File could not be opened. Did you enter the correct path?" << endl;
				cout << "Enter source file path: ";
				gets(path);
				ifstream fin(path, ifstream::in);
			}
			cout << endl << "-- BEGIN --" << endl;
			while(!fin.eof())
			{
				fin.get(ch);
				if(!fin.eof())
				{
					cout << ch;
				}
			}
			cout << endl << "-- END --" << endl;
		}
		cin.clear();
	}while(mainchoice!=4 && (mainchoice==1 || mainchoice==2 || mainchoice==3));

	return 0;
}

/*
	CHANGELOG
	
	v1.1:
	- improved stability and reduced infinite looping at file open/close calls
	- used fail() instead of bad() - fail works on linux machines as expected

	v1.0:
	- basic version
*/