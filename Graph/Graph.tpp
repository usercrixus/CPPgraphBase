#include "Graph.hpp"

Node &Graph::createNode()
{
	this->nodes.push_back(new Node(this->oriented, nextId++));
	return *this->nodes.back();
}

int Graph::removeNode(Node &node)
{
	auto it = this->nodes.begin();
	while (it != this->nodes.end() && *it != &node)
		++it;
	if (it == this->nodes.end())
		throw std::runtime_error("Trying to delete a non referenced node");
	for (Node *n : this->nodes)
		n->unlink(node);
	delete *it;
	this->nodes.erase(it);
	return (1);
}

int Graph::removeNode(unsigned int id)
{
	Node *node = getNodeById(id);
	if (node == nullptr)
		throw std::runtime_error("Trying to delete a non referenced node");
	removeNode(*node);
	return (1);
}

int Graph::removeNode(const std::string &name)
{
	std::vector<Node*> matches = getNodeByName(name);
	if (matches.empty())
		throw std::runtime_error("Trying to delete a non referenced node");
	int size = 0;
	for (Node *n : matches)
		size += removeNode(*n);
	return (size);
}

std::vector<Node*> Graph::getNodeByName(const std::string &name) const
{
	std::vector<Node*> result;
	auto it = this->nodes.begin();
	while (it != this->nodes.end())
	{
		if ((*it)->getName() == name)
			result.push_back(*it);
		++it;
	}
	return result;
}

Node* Graph::getNodeById(unsigned int id) const
{
	auto it = this->nodes.begin();
	while (it != this->nodes.end())
	{
		if ((*it)->getId() == id)
			return *it;
		++it;
	}
	return nullptr;
}

void Graph::print()
{
	for (Node *n : this->nodes)
		n->print();
}

Graph::Graph(bool oriented)
{
	this->nextId = 0;
	this->oriented = oriented;
}

Graph::~Graph()
{
	for (Node *node : this->nodes)
	{
		delete node;
	}
}
