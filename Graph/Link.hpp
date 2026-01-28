#pragma once

#include <string>

class Link
{
private:
	/* data */
public:
	static unsigned int nextId;
	unsigned int id;
	std::string name;
	Link();
	Link(const std::string &name);
	virtual ~Link();
};
