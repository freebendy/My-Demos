//Leaf.h

#ifndef _LEAF_H_
#define _LEAF_H_
#include "Component.h"

class Leaf:public Component
{
public:
	Leaf();
	Leaf(int i);
	~Leaf();
	void Operation();
protected:
private:
	int mdata;
};
#endif //~_LEAF_H_