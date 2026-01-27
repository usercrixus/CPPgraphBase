#include "Graph.hpp"

template<typename Link>
Node<Link> &Graph<Link>::createNode()
{
	this->nodes.push_back(new Node<Link>(this->oriented, nextId++));
	return *this->nodes.back();
}

template<typename Link>
void Graph<Link>::removeNode(Node<Link> &node)
{
	for (Node<Link> *n : this->nodes)
		n->unlink(node);
	typename std::vector<Node<Link> *>::iterator it =
		std::find(this->nodes.begin(), this->nodes.end(), &node);
	if (it == this->nodes.end())
		throw std::runtime_error("Trying to delete a non referenced node");
	delete *it;
	this->nodes.erase(it);
}

template<typename Link>
void Graph<Link>::print()
{
	for (Node<Link> *n : this->nodes)
		n->print();
}

template<typename Link>
Graph<Link>::Graph(bool oriented)
{
	this->nextId = 0;
	this->oriented = oriented;
}

template<typename Link>
Graph<Link>::~Graph()
{
	for (Node<Link> *node : this->nodes)
	{
		delete node;
	}
}
