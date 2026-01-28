#include "Link.hpp"

unsigned int Link::nextId = 0;

Link::Link() : id(nextId++), name("")
{
}

Link::Link(const std::string &name) : name(name)
{
	this->id = Link::nextId++;
}

Link::~Link()
{
}
