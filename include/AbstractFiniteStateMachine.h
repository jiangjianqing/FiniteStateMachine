#ifndef ABSTRACTFINITESTATEMACHINE_H
#define ABSTRACTFINITESTATEMACHINE_H

#include <map>


namespace FSM {

using namespace std;

class FiniteStateMachine;

class State
{
public:
    State();
    virtual ~State();
    virtual bool handle(const FiniteStateMachine* machine,const int& prevStateId,const int& StateId) = 0;
};

class FiniteStateMachine
{
public:
    FiniteStateMachine(): m_timeInCurrState(0.0f), m_currStateId(-1),m_prevStateId(-1){}

    void setState( int stateId )
    {
        if(stateId == m_currStateId){
            //cout<<"curent state is "<<stateId<<"doesn't transfrom state"<<endl;
            return;
        }

        auto it =  m_mapStates.find(stateId);
        if(it != m_mapStates.end()){//找到state
            State* state = it->second;
            if(!state->handle(this,m_currStateId,stateId)){//不允许状态改变
                return;
            }
        }

        onEndState(m_currStateId);
        m_prevStateId = m_currStateId;
        m_currStateId = stateId;
        m_timeInCurrState = 0.0f;
        onBeginState( m_currStateId );
    }

    void updateFSM( float delta_time )
    {
        if( m_currStateId != -1 ){
            m_timeInCurrState += delta_time;
            onUpdateState(m_currStateId );
        }
    }

    float getTimeInCurState() { return m_timeInCurrState; }
    int getState() { return m_currStateId; }
    int getPrevState() { return m_prevStateId; }

protected:
    virtual void onBeginState( const int& stateId ) = 0;
    virtual void onUpdateState( const int&  stateId ) = 0;
    virtual void onEndState( const int&  stateId ) = 0;

private:
    float m_timeInCurrState;
    int m_currStateId;
    int m_prevStateId;

    map<int,State*> m_mapStates;


};

}// end of namespace FSM

#endif // ABSTRACTFINITESTATEMACHINE_H
