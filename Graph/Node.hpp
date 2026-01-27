#pragma once

#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <iostream>

template<typename Link>
class Node;

template<typename Link>
class Node
{
private:
	bool oriented;
	unsigned int id;
	std::vector<std::pair<Node<Link>*, Link>> links;
	void linkHelper(Node &node, Link &link);
public:
	void link(Node &node, Link &&link);
	void link(Node &node, Link &link, bool oriented);
	void unlink(Node &node);
	void unlink(Node &node, bool bidirectionnal);
	void print();
	Node(bool oriented, unsigned int id);
	~Node();
};

#include "Node.tpp"
