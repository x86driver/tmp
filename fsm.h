#ifndef _LIBRARY_THREAD_H
#define _LIBRARY_THREAD_H

#include "state.h"

class State;
class InitState;
class ReadState;

class LibraryThread : public State { // for consist interface
public:
	LibraryThread();
	void connect();
	void parse();
	void close();
	void normal();
	void set_state(State *state);
	State *getInitState();
	State *getReadState();
private:
	State *init_state;
	State *read_state;
	State *state;
};

#endif

