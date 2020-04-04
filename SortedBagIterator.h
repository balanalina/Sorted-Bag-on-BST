#pragma once
#include <stack>
#include "BSTNode.h"
#include"SortedBagIterator.h"

class SortedBag;
typedef int TComp;

class SortedBagIterator {
	friend class SortedBag;

private:
	const SortedBag& bag;
	BSTNode* currentNode;
	std::stack <BSTNode*> stack;
	SortedBagIterator(const SortedBag& bag);

public:
	//sets the iterator to the first element of the container
	void first();

	//moves the iterator to the next element
	//throws exception if the iterator is not valid
	void next();

	//checks if the iterator is valid
	bool valid() const;

	//returns the value of the current element from the iterator
	// throws exception if the iterator is not valid
	TComp getCurrent() const;
};
