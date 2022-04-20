/*
 * List.cpp
 *
 *  Created on: May 2, 2021
 *      Author: Omar
 */

#include "inordlist.h"

inordlist::inordlist() {
	// TODO Auto-generated constructor stub
	head = NULL;
}

inordlist::~inordlist() {
	// TODO Auto-generated destructor stub
}

void inordlist::organizinglist(string added_word,int line_arg)
{
	Node *current=head;
	while (current!= NULL)
	{
		if (added_word == current->word)
		{
			if (line_arg == current->line)
			{
				(current->count)++;
				return;
			}
		}
		current=current->next;
	}
	Node *link = new Node();
	link->next=NULL;
	link->word=added_word;
	link->line=line_arg;

	if (head==NULL)
	{
		head=link;
		return;
	}
	if (added_word < head->word)
	{
		link->next=head;
		head=link;
		return;
	}
	Node *previous=head;
	current=head->next;
	while (current != NULL)
	{
		if (added_word < (current->word))
		{
			link->next=current;
			previous->next=link;
			return;
		}
		else
		{
			current=current->next;
			previous=previous->next;
		}
	}
	previous->next=link;
	link->next=NULL;
}

void inordlist::printlist(void)
{
	Node *current=head;
	while(current != NULL)
	{
		cout<<current->word << " "<< current->line<< " "<< current->count <<endl;
		current = current->next;
	}
}

void inordlist::wordCount(void)
{
	Node *current=head;
	int s=0;
	while(current != NULL)
	{
		s+=current->count;
		current=current->next;
	}
	cout<<s << " words"<<endl;
}

void inordlist::distWords(void)
{
	Node *current=head;
	int s=0;
	while(current != NULL)
	{
		if (current->next==NULL)
		{
			s++;
			break;
		}
		if (current->word !=current->next->word)
		{
			s++;
		}
		current=current->next;
	}
	cout<<s << " distinct words"<<endl;
}

void inordlist::charCount(int count,int line_arg)
{
//	Node *current=head;
//	int s=count;
//	int i=0;
//	while(current != NULL)
//	{
//		while ((current->word)[i] != '\0')
//		{
//			i++;
//		}
//		i*=current->count;
//		s+=i;
//		i=0;
//		current=current->next;
//	}
	int z=count+line_arg-2;
	cout<<z << " characters"<<endl;
}

void inordlist::frequentWord(void)
{
	Node *current=head;
	int max=current->count;
	string s[10];
	s[0]=current->word;
	int i=current->count;
	int j=0;
	int first_bool=1;

	while(current != NULL)
	{
		if (current->next==NULL)
		{
			if (i>max)
			{
				s[0]=current->word;
			}
			else if (i==max)
			{
				j++;
				s[j]=current->word;
			}
			break;
		}
		if (current->word == current->next->word)
		{
			i+=current->next->count;
			current=current->next;
			continue;
		}
		if (i>max)
		{
			max=i;
			s[0]=current->word;
			j=0;
		}
		else if (i==max)
		{
			if (first_bool)
			{
				first_bool=0;
				current=current->next;
				i=current->count;
				continue;
			}
			j++;
			s[j]=current->word;
		}
		current=current->next;
		i=current->count;
	}
	cout<<"Most frequent word is: ";
	for (i=0;i<=j;i++)
	{
		if (!((s[i]=="a")||(s[i]=="an")||(s[i]=="the")||(s[i]=="in")||(s[i]=="on")||(s[i]=="of")||(s[i]=="and")||(s[i]=="is")||(s[i]=="are")))
		{
			cout << s[i]<< " ";
		}
	}
	cout<<endl;
}

int inordlist::countWord(string k,int x)
{
	Node *current=head;
	int sum=0;

	while(current != NULL)
	{
		if (current->word == k)
		{
			sum+=current->count;
		}
		current=current->next;
	}
	if (x)
	{
		if (sum==0)
		{
			cout<<"Word not found"<<endl;
		}
		else
		{
			cout<< k <<" is repeated " << sum << " times"<<endl;
		}
		return 0;
	}
	return sum;
}

void inordlist::starting(string k)
{
	Node *current=head;
	int starting_bool;
	int i=0;
	int repeat=0;
	int number=0;
	string s;
	while(current != NULL)
	{
		starting_bool=1;
		i=0;
		if (current->next==NULL)
		{
			while(k[i] !='\0')
			{
				if (k[i] != (current->word)[i])
				{
					starting_bool=0;
					break;
				}
				i++;
			}
			if (starting_bool)
			{
				number++;
				s=current->word;
				repeat=countWord(s,0);
				cout<< s <<":"<<" "<<repeat<<"	";
			}
			break;
		}
		if (current->word == current->next->word)
		{
			current=current->next;
			continue;
		}
		while(k[i] !='\0')
		{
			if (k[i] != (current->word)[i])
			{
				starting_bool=0;
				break;
			}
			i++;
		}
		if (starting_bool)
		{
			number++;
			s=current->word;
			repeat=countWord(s,0);
			cout<< s <<":"<<" "<<repeat<<"	";
		}
		current=current->next;
	}
	if (number==0)
	{
		cout<<"Word not found";
	}
		cout<<endl;
}

void inordlist::search(string k)
{
	Node *current=head;
	int length=0;
	string s[20];
	int lines[20];
	int j=0;
	length=containing(k,0,s);
	if (length ==0)
	{
		cout<<"Word not found"<<endl;
		return;
	}
	for (int i=0;i<length;i++)
	{
		current=head;
		while(current != NULL)
		{
			if (current->word == s[i])
			{
				lines[j]=current->line;
				j++;
			}
			current=current->next;
		}
		cout <<s[i]<<":"<< "	"<<"lines ";
		for (int k=0;k<j;k++)
		{
			cout<<lines[k]<<" ";
		}
		j=0;
		cout<<endl;
	}

}

int inordlist::containing(string k,int y,string arr[])
{
	Node *current=head;
	string s;
	string last_word;
	int return_length=0;
	int length=0;
	int length_word=0;
	int i;
	int c=0;
	int count;
	int number=0;
	for (i=0 ; k[i] != '\0';i++)
	{
		length++;
	}
	while(current != NULL)
	{
		s=current->word;
		length_word=0;
		for (i=0 ; s[i] != '\0';i++)
		{
			length_word++;
		}
		i=0;
		for (int j=0 ; length_word>=(j+length) ;j++)
		{
			if((k[i]==s[j]))
			{
				while(k[i]==s[j])
				{
					c++;
					i++;
					j++;
					if (j>=length_word)
					{
						break;
					}
					if (i>=length)
					{
						break;
					}

				}
				if (c == length)
				{
					if (s != last_word)
					{
						last_word=s;
						if (y)
						{
							number++;
							count =countWord(s,0);
							cout << s<<":"<<" "<<count <<"\t";
						}
						else
						{
							arr[return_length]=s;
							return_length++;
						}
					}
				}
				c=0;
			}

		}
		current=current->next;
	}
	if (y)
	{
		if (number ==0)
		{
			cout<<"Word not found";
		}
		cout<<endl;
		return 0;
	}
	return return_length;
}

int inordlist::removing_separators(string &k)
{
	string s="";
	int separators_bool=0;
	int i=0;
	while(k[i]!='\0')
	{
		if (!((k[i]==',')||(k[i]==';')||(k[i]==':')||(k[i]=='&')||(k[i]=='.')||(k[i]=='[')||(k[i]==']')||(k[i]=='{')||(k[i]=='}')||(k[i]=='(')||(k[i]==')')||(k[i]=='"')||(k[i]=='\'')))
		{
			s+=k[i];
			separators_bool=1;
		}
		i++;
	}
	k=s;
	return separators_bool;
}

void inordlist::case_insensitivity(string &k)
{
	int i=0;
	while(k[i] != '\0')
	{
		if ((k[i]>=65) && (k[i]<=90))
		{
			k[i]=k[i]+32;
		}
		i++;
	}
}
