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
	Node& createNode(const std::string &name);
	Node& createNode();
	int removeNode(Node& node);
	int removeNode(unsigned int id);
	int removeNode(const std::string &name);
	std::vector<Node*> getNodeByName(const std::string &name) const;
	Node* getNodeById(unsigned int id) const;
	void print();
	Graph(bool oriented);
	~Graph();
};

#include "Graph.tpp"
