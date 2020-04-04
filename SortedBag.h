#pragma once
#include"BSTNode.h"
#include"SortedBagIterator.h"



typedef int TComp;

typedef TComp TElem;

typedef bool(*Relation)(TComp, TComp);



class SortedBag {

	friend class SortedBagIterator;

private:
	BSTNode* root;
	Relation r;
	int length;


public:

	//constructor

	SortedBag(Relation r);

	BSTNode* getMinimum(BSTNode *startingRoot);

	//adds an element to the sorted bag

	void add(TComp e);

	BSTNode* removeRecursively(BSTNode *node, TComp e, bool &removed);

	//removes one occurrence of an element from a sorted bag

	//returns true if an element was removed, false otherwise (if e was not part of the sorted bag)

	bool remove(TComp e);


	BSTNode* getMaximum(BSTNode *startingRoot);

	//checks if an element is in the sorted bag

	bool search(TComp e) const;

	void empty();

	//returns the number of occurrences for an element in the sorted bag

	int nrOccurrences(TComp e) const;



	//returns the number of elements from the sorted bag

	int size() const;



	//returns an iterator for this sorted bag

	SortedBagIterator iterator() const;



	//checks if the sorted bag is empty

	bool isEmpty() const;



	//destructor

	~SortedBag();

};