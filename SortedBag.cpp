#include "SortedBag.h"


//O(log2n)
BSTNode* SortedBag::getMinimum(BSTNode *startingRoot) {
	BSTNode *currentNode = this->root;
	BSTNode *minNode = this->root;

	while (currentNode != NULL) {
		minNode = currentNode;
		currentNode = currentNode->getLeft();
	}
	return minNode;
}

SortedBag::SortedBag(Relation r)
{
	this->r = r;
	this->root = NULL;
	this->length = 0;
}
//O(log2n)
void SortedBag::add(TComp e)
{
	BSTNode *current = this->root;
	BSTNode *parent = NULL;

	while (current != NULL) {
		parent = current;
		 if (this->r(e, current->getValue())) {
			current = current->getLeft();
		}
		else {
			current = current->getRight();
		}
	}

	BSTNode *newNode = new BSTNode{ e };
	if (this->root == NULL) {
		this->root = newNode;
	}
	else if (this->r(e, parent->getValue())) {
		parent->setLeft(newNode);
	}
	else {
		parent->setRight(newNode);
	}
	this->length++;
}

//O(log2n)
bool SortedBag::remove(TComp e)
{
	bool removed = false;
	this->root = removeRecursively(this->root, e, removed);
	if (removed)
		this->length--;
	return removed;
}

BSTNode *SortedBag::getMaximum(BSTNode *startingRoot)
{
	BSTNode *currentNode = this->root;
	BSTNode *maxNode = this->root;

	while (currentNode != NULL) {
		maxNode = currentNode;
		currentNode = currentNode->getRight();
	}
	return maxNode;
}

BSTNode *SortedBag::removeRecursively(BSTNode *node, TComp e, bool &removed) {
	if (node == NULL) {
		return node;
	}

	if (e == node->getValue()) {
		removed = true;
		if (node->getLeft() == NULL) {
			BSTNode* right = node->getRight();
			delete node;
			return right;
		}
		else if (node->getRight() == NULL) {
			BSTNode* left = node->getLeft();
			delete node;
			return left;
		}
		else {
			BSTNode *maxNode = this->getMinimum(node->getRight());
			node->setValue(maxNode->getValue());
			node->setLeft(this->removeRecursively(node->getLeft(), maxNode->getValue(), removed));
		}
	}
	else if (this->r(e, node->getValue())) {
		node->setLeft(this->removeRecursively(node->getLeft(), e, removed));
	}
	else {
		node->setRight(this->removeRecursively(node->getRight(), e, removed));
	}
	return node;
}

//O(log2n)
bool SortedBag::search(TComp e) const
{
	auto current = this->root;
	while (current != NULL)
	{
		if (current->getValue() == e)
			return true;
		if (this->r(e, current->getValue())) {
			current = current->getLeft();
		}
		else 
			current = current->getRight();
	}
	return false;
}
//O(log2n)
int SortedBag::nrOccurrences(TComp e) const
{ 
	int count = 0;
	auto current = this->root;

	while (current != NULL) {
		if (current->getValue() == e) {
			count++;
		}
		if (this->r(e, current->getValue())) 
			current = current->getLeft();
		
		else 
			current = current->getRight();
		
	}
	return count;
}
//theta(nlog2n)
void SortedBag::empty()
{
	while (this->root != NULL)
		this->remove(this->root->getValue());
}

//theta(1)
int SortedBag::size() const
{
	return this->length;
}

SortedBagIterator SortedBag::iterator() const
{
	return SortedBagIterator(*this);
}

//theta(1)
bool SortedBag::isEmpty() const
{
	if (this->root == NULL)
		return true;
	return false;
}

SortedBag::~SortedBag()
{
}


