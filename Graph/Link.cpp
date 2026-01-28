#include "Link.hpp"

Link::Link() : id(0), name("")
{
}

Link::Link(const std::string &name) : id(0), name(name)
{
}

Link::Link(const std::string &name, unsigned long id) : id(id), name(name)
{
}

Link::~Link()
{
}
