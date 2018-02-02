#ifndef OBJECTUSINGFSM_H
#define OBJECTUSINGFSM_H
#include "AbstractFiniteStateMachine.h"

enum class EState
{
    STT_OFF = -1, //约定： -1 is the initial state of the fsm
    STT_WALK,
    STT_RUN,
    STT_STOP,
    STT_EAT
};

class ObjectUsingFSM : public FSM::FiniteStateMachine
{
public:
    ObjectUsingFSM(){}

protected:
    void onUpdateState( const int& state ) override
    {
        int i = 0;
        i = i + 1;
    }

    void onBeginState(const int& state ) override
    {
        int i = 0;
        i = i + 1;
    }

    void onEndState( const int& state ) override
    {
        int i = 0;
        i = i + 1;
    }
};

#endif // OBJECTUSINGFSM_H
