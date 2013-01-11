/********************************************************************
	created:	2006/08/04
	filename: 	Command.h
	author:		�
                http://www.cppblog.com/converse/

	purpose:	Commandģʽ����ʾ����
*********************************************************************/

#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
	virtual ~Command() {}

	virtual void Execute() = 0;
};

class Receiver
{
public:
	void Action();
};

class Invoker
{
public:
	Invoker(Command *pCommand);
	~Invoker();

	void Invoke();
private:
	Command *m_pCommand;
};

class ConcreateComand
	: public Command
{
public:
	ConcreateComand(Receiver* pReceiver);
	virtual ~ConcreateComand();

	virtual void Execute();

private:
	Receiver* m_pReceiver;
};

#endif
