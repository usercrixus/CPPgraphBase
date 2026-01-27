#pragma once

#include "Node.hpp"
#include <vector>
#include <algorithm>
#include <stdexcept>

template<typename Link>
class Graph
{
private:
	unsigned int nextId;
	bool oriented;
	std::vector<Node<Link>*> nodes;
public:
	Node<Link>& createNode();
	void removeNode(Node<Link>& node);
	void print();
	Graph(bool oriented);
	~Graph();
};

#include "Graph.tpp"
