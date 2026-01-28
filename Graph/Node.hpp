#pragma once

#include "Link.hpp"
#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Node
{
private:
	bool oriented;
	unsigned int id;
	unsigned int nextLinkId;
	std::string name;
	std::vector<std::pair<Node*, Link*>> links;
	void linkHelper(Node &node, Link &link);
public:
	void link(Node &node, Link &&link);
	void link(Node &node, Link &&link, bool oriented);
	void unlink(Node &node);
	void unlink(std::pair<Node*, Link*> &node);
	void unlink(unsigned int id);
	void unlink(const std::string &name);
	unsigned int getId() const;
	const std::string &getName() const;
	void setName(const std::string &name);
	void print();
	Node(bool oriented, unsigned int id);
	~Node();
};

#include "Node.tpp"
