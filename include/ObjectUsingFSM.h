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

class ObjectUsingFSM : public AbstractFiniteStateMachine<EState>
{
public:
    ObjectUsingFSM(){}

protected:
    void UpdateState( EState t ) override
    {
        int i = 0;
        i = i + 1;
    }

    void BeginState( EState t ) override
    {
        int i = 0;
        i = i + 1;
    }

    void EndState( EState t ) override
    {
        int i = 0;
        i = i + 1;
    }
};

#endif // OBJECTUSINGFSM_H
