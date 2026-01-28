#include "../Graph/Link.hpp"

class GLink : public Link
{
private:
	/* data */
public:
	unsigned int x;
	GLink();
	explicit GLink(const std::string &name);
	~GLink();
};

GLink::GLink() : Link()
{
}

GLink::GLink(const std::string &name) : Link(name)
{
}

GLink::~GLink()
{
}
