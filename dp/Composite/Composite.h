//Composite.h
#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_
#include "Component.h"
#include <vector>
using namespace std;
class Composite:public Component
{
public:
	Composite();
	Composite(int i);
	~Composite();
public:
	void Operation();
	void Add(Component* com);
	void Remove(Component* com);
	Component* GetChild(int index);
protected:
private:
	vector<Component*> comVec;
	int mdata;
};
#endif //~_COMPOSITE_H_