#ifndef _STATE_H
#define _STATE_H

#include "fsm.h"

class State {
public:
	virtual void connect() = 0;
	virtual void parse() = 0;
	virtual void close() = 0;
	virtual void normal() = 0;
};

class InitState : public State {
private:
	class LibraryThread *libthread;
public:
	InitState(LibraryThread *libthread);
	virtual void connect();
	virtual void parse();
	virtual void close();
	virtual void normal();
};

class ReadState : public State {
public:
	ReadState(LibraryThread *libthread);
	virtual void connect();
	virtual void parse();
	virtual void close();
	virtual void normal();
private:
	LibraryThread *libthread;
};

#endif

