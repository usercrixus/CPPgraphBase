#include "Node.hpp"

void Node::linkHelper(Node &node, Link &link)
{
	this->links.emplace_back(&node, &link);
}

void Node::link(Node &node, Link &link)
{
	this->links.emplace_back(&node, &link);
	if (!this->oriented)
		node.linkHelper(*this, link);
}

void Node::link(Node &node, Link &link, bool oriented)
{
	this->links.emplace_back(&node, &link);
	if (!this->oriented && !oriented)
		node.linkHelper(*this, link);
	else if (this->oriented && !oriented)
		throw std::invalid_argument("Cannot create a non oriented link in an oriented graph");
}

void Node::unlink(Node &node)
{
	auto it = this->links.begin();
	while (it != this->links.end())
	{
		if (it->first == &node)
			it = this->links.erase(it);
		else
			++it;
	}
}

void Node::unlink(std::pair<Node*, Link*> &node)
{
	auto it = this->links.begin();
	while (it != this->links.end())
	{
		if (it->first == node.first)
			it = this->links.erase(it);
		else
			++it;
	}
}

void Node::unlink(unsigned int id)
{
	auto it = this->links.begin();
	while (it != this->links.end())
	{
		if (it->second != nullptr && it->second->id == id)
			it = this->links.erase(it);
		else
			++it;
	}
}

void Node::unlink(const std::string &name)
{
	auto it = this->links.begin();
	while (it != this->links.end())
	{
		if (it->second != nullptr && it->second->name == name)
			it = this->links.erase(it);
		else
			++it;
	}
}

void Node::print()
{
	std::cout << this->id << " linked with" << std::endl;
	for (const std::pair<Node*, Link*> &entry : this->links)
	{
		Node* n = entry.first;
		std::cout << "	" << n->id << std::endl;
	}
}

Node::Node(bool oriented, unsigned int id)
{
	this->id = id;
	this->oriented = oriented;
}

Node::~Node()
{
}
