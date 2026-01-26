#include "Node.hpp"
#include <stdexcept>
#include <iostream>

void Node::linkHelper(Node &node)
{
	this->links.insert(&node);
}

void Node::link(Node &node)
{
	this->links.insert(&node);
	if (!this->oriented)
		node.linkHelper(*this);
}

void Node::link(Node &node, bool oriented)
{
	this->links.insert(&node);
	if (!this->oriented && !oriented)
		node.linkHelper(*this);
	else if (this->oriented && !oriented)
		throw std::invalid_argument("Cannot create a non oriented link in an oriented graph");
}

void Node::unlink(Node &node)
{
	this->links.erase(&node);
}

void Node::unlink(Node &node, bool bidirectionnal)
{
	if (bidirectionnal)
	{
		this->links.erase(&node);
		node.unlink(*this);
	}
}

void Node::print()
{
	std::cout << this->id << " linked with" << std::endl;
	for (Node* n : this->links)
		std::cout << "	" << n->id << std::endl;
}

Node::Node(bool oriented, unsigned int id)
{
	this->id = id;
	this->oriented = oriented;
}

Node::~Node()
{
}
