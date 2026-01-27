#include "Node.hpp"

template<typename Link>
void Node<Link>::linkHelper(Node<Link> &node, Link &link)
{
	this->links.emplace_back(&node, link);
}

template<typename Link>
void Node<Link>::link(Node<Link> &node, Link &&link)
{
	this->links.emplace_back(&node, link);
	if (!this->oriented)
		node.linkHelper(*this, link);
}

template<typename Link>
void Node<Link>::link(Node<Link> &node, Link &link, bool oriented)
{
	this->links.emplace_back(&node, link);
	if (!this->oriented && !oriented)
		node.linkHelper(*this, link);
	else if (this->oriented && !oriented)
		throw std::invalid_argument("Cannot create a non oriented link in an oriented graph");
}

template<typename Link>
void Node<Link>::unlink(Node<Link> &node)
{
	this->links.erase(
		std::remove_if(this->links.begin(), this->links.end(),
			[&node](const std::pair<Node<Link>*, Link> &entry)
			{
				return entry.first == &node;
			}),
		this->links.end());
}

template<typename Link>
void Node<Link>::unlink(Node<Link> &node, bool bidirectionnal)
{
	if (bidirectionnal)
	{
		this->links.erase(
			std::remove_if(this->links.begin(), this->links.end(),
				[&node](const std::pair<Node<Link>*, Link> &entry)
				{
					return entry.first == &node;
				}),
			this->links.end());
		node.unlink(*this);
	}
}

template<typename Link>
void Node<Link>::print()
{
	std::cout << this->id << " linked with" << std::endl;
	for (const std::pair<Node<Link>*, Link> &entry : this->links)
	{
		Node<Link>* n = entry.first;
		std::cout << "	" << n->id << std::endl;
	}
}

template<typename Link>
Node<Link>::Node(bool oriented, unsigned int id)
{
	this->id = id;
	this->oriented = oriented;
}

template<typename Link>
Node<Link>::~Node()
{
}
