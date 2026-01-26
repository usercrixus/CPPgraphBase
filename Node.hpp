#include <set>

class Node;

class Node
{
private:
	bool oriented;
	unsigned int id;
	std::set<Node*> links;
	void linkHelper(Node &node);
public:
	void link(Node &node);
	void link(Node &node, bool oriented);
	void unlink(Node &node);
	void unlink(Node &node, bool bidirectionnal);
	void print();
	Node(bool oriented, unsigned int id);
	~Node();
};
