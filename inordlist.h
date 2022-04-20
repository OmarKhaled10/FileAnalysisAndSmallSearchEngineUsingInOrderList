/*
 * List.h
 *
 *  Created on: May 2, 2021
 *      Author: Omar
 */

#ifndef inordlist_H_
#define inordlist_H_

#include <iostream>
#include <fstream>
#include <string>
#include<bits/stdc++.h>
#include <assert.h>

using namespace std;


class inordlist {
private:
	struct Node
	{
		string word;
		int line;
		int count=1;
		Node *next;
	};
public:
	inordlist();
	void organizinglist(string added_word,int line_arg);
	int removing_separators(string &k );
	void case_insensitivity(string &k);
	void wordCount(void);
	void distWords(void);
	void printlist(void);
	void charCount(int count,int line_arg);
	void frequentWord(void);
	int countWord(string k,int x);
	void starting(string k);
	int containing(string k,int y,string arr[]);
	void search(string k);
	virtual ~inordlist();
	Node* head;

};

#endif /* inordlist_H_ */
