#include <stdio.h>
#include "fsm.h"
#include "state.h"

LibraryThread::LibraryThread()
{
	init_state = new InitState(this);
	read_state = new ReadState(this);
	state = init_state;
	printf("create LibraryThread, now in InitState\n");
}

void LibraryThread::connect()
{
	state->connect();
}

void LibraryThread::parse()
{
	state->parse();
}

void LibraryThread::close()
{
	state->close();
}

void LibraryThread::normal()
{
	state->normal();
}

void LibraryThread::set_state(State *state)
{
	this->state = state;
}

State *LibraryThread::getInitState()
{
	return init_state;
}

State *LibraryThread::getReadState()
{
	return read_state;
}

int main()
{
	LibraryThread lt;
	lt.connect();
	lt.parse();

	return 0;
}

