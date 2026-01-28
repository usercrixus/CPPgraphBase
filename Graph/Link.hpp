#pragma once

#include <string>

class Link
{
private:
	/* data */
public:
	unsigned long id;
	std::string name;
	Link();
	Link(const std::string &name);
	Link(const std::string &name, unsigned long id);
	virtual ~Link();
};
