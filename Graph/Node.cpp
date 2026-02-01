#include "Node.hpp"

void Node::linkHelperGenerateId(Node &node, Link &link)
{
	link.id = (static_cast<unsigned long>(this->id) << 32)
		| static_cast<unsigned long>(this->nextLinkId);
	++this->nextLinkId;
	this->links.emplace_back(&node, &link);
}

void Node::linkHelper(Node &node, Link &link)
{
	this->links.emplace_back(&node, &link);
}

void Node::link(Node &node, Link &link)
{
	this->linkHelperGenerateId(node, link);
	if (!this->oriented)
		node.linkHelper(*this, link);
}

std::vector<std::pair<Node*, Link*>>::iterator Node::unlinkHelper(std::vector<std::pair<Node*, Link*>>::iterator it)
{
	Node* other = it->first;
	Link* link = it->second;
	std::vector<std::pair<Node*, Link*>>::iterator next = this->links.erase(it);
	if (!this->oriented && other != nullptr)
	{
		auto oit = other->links.begin();
		while (oit != other->links.end())
		{
			if (oit->first == this && oit->second == link)
				oit = other->links.erase(oit);
			else
				++oit;
		}
	}
	return next;
}

void Node::unlink(Node &node)
{
	auto it = this->links.begin();
	while (it != this->links.end())
	{
		if (it->first == &node)
			it = this->unlinkHelper(it);
		else
			++it;
	}
}

void Node::unlink(const std::pair<Node*, Link*> &node)
{
	auto it = this->links.begin();
	while (it != this->links.end())
	{
		if (it->first == node.first)
			it = this->unlinkHelper(it);
		else
			++it;
	}
}

void Node::unlink(unsigned long id)
{
	auto it = this->links.begin();
	while (it != this->links.end())
	{
		if (it->second != nullptr && it->second->id == id)
			it = this->unlinkHelper(it);
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
			it = this->unlinkHelper(it);
		else
			++it;
	}
}

unsigned int Node::getId() const
{
	return this->id;
}

const std::string &Node::getName() const
{
	return this->name;
}

const std::vector<std::pair<Node *, Link *>> &Node::getLinks() const
{
	return (this->links);
}

void Node::setName(const std::string &name)
{
	this->name = name;
}

void Node::print()
{
	std::cout << "Node " << this->id;
	if (!this->name.empty())
		std::cout << " (" << this->name << ")";
	std::cout << " linked with" << std::endl;
	for (const std::pair<Node*, Link*> &entry : this->links)
	{
		Node* n = entry.first;
		Link* l = entry.second;
		std::cout << "	";
		if (n)
		{
			std::cout << "Node " << n->id;
			if (!n->name.empty())
				std::cout << " (" << n->name << ")";
		}
		else
		{
			std::cout << "Node <null>";
		}
		if (l)
		{
			std::cout << " via Link " << l->id;
			if (!l->name.empty())
				std::cout << " (" << l->name << ")";
		}
		else
		{
			std::cout << " via Link <null>";
		}
		std::cout << std::endl;
	}
}

Node::Node(bool oriented, unsigned int id, const std::string &name)
{
	this->nextLinkId = 0;
	this->id = id;
	this->oriented = oriented;
	this->name = name;
}

Node::~Node()
{
}
