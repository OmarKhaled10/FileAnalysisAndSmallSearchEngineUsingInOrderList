/*
 * main.cpp
 *
 *  Created on: May 2, 2021
 *      Author: Omar
 */

#include "inordlist.h"
#include <string.h>
#include <cstring>

int main (int argc, char* argv[])
{
	if (argc == 3)
	{
	inordlist L1;
	string word;
	string k;
	int line=1;
	int separators_bool;
	int chars=0;
	int command_no=0;
	int i=0;
	string s[2];
	string file_name;
	string file_name2;
	file_name=argv[1];
	ifstream file (file_name);
	if (file.is_open())
	{
		while(! file.eof())
		{
			getline(file,k);
			chars+=k.length();
			stringstream iss(k);
			while (iss >> word)
			{
				separators_bool=L1.removing_separators(word);
				if (separators_bool)
				{
					L1.case_insensitivity(word);
					L1.organizinglist(word,line);
				}
			}
			line++;
		}
	}
	else
	{
		cout<<"File not found"<<endl;
	}
//	L1.printlist();

	file_name2=argv[2];
	ifstream file2(file_name2);
	if (file2.is_open())
	{
		while(! file2.eof())
		{
			command_no=0;
			getline(file2,k);
			stringstream iss(k);
			while (iss >> word)
			{
				s[1]="";
				if(command_no > 2)
				{
					cout << "Incorrect number of arguments"<<endl;
					continue;
				}
				s[command_no]=word;
				command_no++;
			}

			if (s[i]=="wordCount")
			{
				if (command_no > 1)
				{
					cout << "Incorrect number of arguments"<<endl;
					continue;
				}
				L1.wordCount();
			}

			else if (s[i]=="distWords")
			{
				if (command_no > 1)
				{
					cout << "Incorrect number of arguments"<<endl;
					continue;
				}
				L1.distWords();
			}
			else if (s[i]=="charCount")
			{
				if (command_no > 1)
				{
					cout << "Incorrect number of arguments"<<endl;
					continue;
				}
				L1.charCount(chars,line);
			}
			else if (s[i]=="frequentWord")
			{
				if (command_no > 1)
				{
					cout << "Incorrect number of arguments"<<endl;
					continue;
				}
				L1.frequentWord();
			}
			else if (s[i]=="countWord")
			{
				if (command_no != 2)
				{
					cout << "Incorrect number of arguments"<<endl;
					continue;
				}
				L1.countWord(s[i+1],1);
			}
			else if (s[i]=="starting")
			{
				if (command_no != 2)
				{
					cout << "Incorrect number of arguments"<<endl;
					continue;
				}
				L1.starting(s[i+1]);
			}
			else if (s[i]=="search")
			{
				if (command_no != 2)
				{
					cout << "Incorrect number of arguments"<<endl;
					continue;
				}
				L1.search(s[i+1]);
			}
			else if (s[i]=="containing")
			{
				if (command_no != 2)
				{
					cout << "Incorrect number of arguments"<<endl;
					continue;
				}
				L1.containing(s[i+1],1,0);
			}
			else
			{
				cout<<"Undefined command"<<endl;
				continue;
			}
		}
	}
	else
	{
		cout<<"File not found"<<endl;
	}

	}
	else
	{
		cout << "Incorrect number of arguments"<<endl;
	}


	return 0;
}

