//context.h
#ifndef _CONTEXT_H_
#define _CONTEXT_H_
class State;
class Context
{
public:
	Context();
	Context(State* state);
	~Context();
	void OprationInterface();
	void OperationChangState();
protected:
private:
	friend class State; //表明在State类中可以访问Context类的private字段
	bool ChangeState(State* state);
private:
	State* _state;
};
#endif //~_CONTEXT_H_