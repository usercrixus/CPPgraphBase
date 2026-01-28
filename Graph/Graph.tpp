#include "Graph.hpp"

Node &Graph::createNode()
{
	this->nodes.push_back(new Node(this->oriented, nextId++));
	return *this->nodes.back();
}

void Graph::removeNode(Node &node)
{
	for (Node *n : this->nodes)
		n->unlink(node);
	typename std::vector<Node *>::iterator it =
		std::find(this->nodes.begin(), this->nodes.end(), &node);
	if (it == this->nodes.end())
		throw std::runtime_error("Trying to delete a non referenced node");
	delete *it;
	this->nodes.erase(it);
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
