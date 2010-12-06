#include <stdio.h>
#include "fsm.h"
#include "state.h"

InitState::InitState(LibraryThread *libthread)
{
        this->libthread = libthread;
}

void InitState::connect()
{
	printf("In connect, go to read\n");
	libthread->set_state(libthread->getReadState());
}

void InitState::parse()
{
	printf("Can't parse while connect state\n");
}

void InitState::close()
{
	printf("Can't close while connect state\n");
}

void InitState::normal()
{
	printf("Can't do normal thing while connect state\n");
}

ReadState::ReadState(LibraryThread *libthread)
{
        this->libthread = libthread;
}

void ReadState::connect()
{
	printf("Can't connect while read state\n");
}

void ReadState::parse()
{
	printf("Parse the request, go back to init state\n");
	libthread->set_state(libthread->getInitState());
}

void ReadState::close()
{
	printf("Can't close while parse state\n");
}

void ReadState::normal()
{
	printf("Can't do normal thing while read state\n");
}
