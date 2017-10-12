#pragma once

#include <fstream>
#include <string>
#include "SearchTree.h"
#include <stack>

SearchTree<Entry<string, string> >* buildBST_fromDatafile(const std::string& filename) {
	std::ifstream f(filename.c_str());
	if (!f)
		throw std::runtime_error("cannot open data file");

	std::string s;

	getline(f, s);
	std::string magic("CPSC131 Project3 raw data file");
	if (!f || !std::equal(magic.begin(), magic.end(), s.begin()))
		throw std::runtime_error("incorrect data file");
	getline(f, s);

	std::string firstName, movie;
	
	SearchTree<Entry<string, string>> *bst = new SearchTree<Entry<string, string>>;

	while (!f.eof())
	{
		getline(f, firstName, ',');
		getline(f, movie);
		if (!f.eof())
		{
			if (movie[movie.length() - 1] == '\r')
				movie.erase(movie.begin() + movie.length() - 1, movie.end());
			bst->insert(firstName, movie);
		}
	}

	f.close();

	return bst;
}

void printInReverseOder(SNode<Entry<string,string> >* node)
{
	stack<Entry<string, string> > *s = new stack<Entry<string, string> >;
	SNode<Entry<string, string> > *current = node;

	while (current != NULL)
	{
		s->push(current->getElem());
		current = current->getnext();
	}

	while (!s->empty())
	{
		cout << s->top().key() << ", ";
		cout << s->top().value() << endl;
		s->pop();
	}
	
	delete s;
	delete current;
}
