#include <stdexcept>
#include "SortedBagIterator.h"
#include"SortedBag.h"

SortedBagIterator::SortedBagIterator(const SortedBag& bag) : bag(bag), currentNode(NULL), stack{ std::stack<BSTNode*>{} } {
	this->first();
}

void SortedBagIterator::first() {
	this->currentNode = this->bag.root;
	this->stack = std::stack<BSTNode*>{};
	while (this->currentNode != NULL) {
		this->stack.push(this->currentNode);
		this->currentNode = this->currentNode->getLeft();
	}

	if (this->stack.empty() == false) {
		this->currentNode = stack.top();
	}
	else {
		this->currentNode = NULL;
	}
}

void SortedBagIterator::next() {
	if (!valid())
		throw std::runtime_error("");

	BSTNode* node = stack.top();
	stack.pop();

	if (node->getRight() != NULL) {
		node = node->getRight();
		while (node != NULL) {
			this->stack.push(node);
			node = node->getLeft();
		}
	}

	if (this->stack.empty() == false) {
		this->currentNode = this->stack.top();
	}
	else {
		this->currentNode = NULL;
	}
}

bool SortedBagIterator::valid() const {
	return this->currentNode != NULL;
}

TComp SortedBagIterator::getCurrent() const {
	if (!this->valid())
		throw std::runtime_error("");
	return this->currentNode->getValue();
}