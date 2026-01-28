#pragma once

#include "Node.hpp"
#include <vector>
#include <algorithm>
#include <stdexcept>

class Graph
{
private:
	unsigned int nextId;
	bool oriented;
	std::vector<Node*> nodes;
public:
	Node& createNode();
	void removeNode(Node& node);
	void print();
	Graph(bool oriented);
	~Graph();
};

#include "Graph.tpp"
