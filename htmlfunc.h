/*
Julie Schneider - Faculty RRCC - Fall 2019, Updated Fall 2021
CSC 161 Backwards Jeopardy Game
*/

#ifndef HTMLFUNC_H
#define HTMLFUNC_H

#define CRT_SECURE_NO_WARNINGS
#define CRT_NONSTDC_NO_WARNINGS
#define NO_CRT_STDIO_INLINE

#include	<fstream>		// ifstream & ofstream
#include	<iostream>		// istream & ostream
#include	<cstdio>		// sprintf_s
#include	<stdio.h>		// C sprintf_s
#include 	<string>		// C++ string class
#include	<cstring>		// C-style string
#include	<cstdlib>

#include	"linklist.h"
#include	"bintree.h"
#include	"question.h"


void	printHTMLindex(LinkList<Record>& categories);

// Takes binary tree of Question objects and prints the HTML page for each Question.

void	printHTMLpages(BinTree<Question>& questionSet, int catCount);

// Takes an Question and prints an HTML page.

void	printHTMLpage(Question item, int& catCount, int& score);

// Misc HTML functions helper functions

void	printHTMLhead(std::ofstream &os, std::string title);
void	printHTMLcontent(std::ofstream& os, LinkList<Record>& categories);
void	printHTMLend(std::ofstream &os);


#endif