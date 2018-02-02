#ifndef ABSTRACTFINITESTATEMACHINE_H
#define ABSTRACTFINITESTATEMACHINE_H

template<typename T>
class AbstractFiniteStateMachine
{
public:
    AbstractFiniteStateMachine(): m_timeInCurrState(0.0f), m_currState(-1),m_prevState(-1){}

    void SetState( T state )
    {
        EndState( (T)m_currState );
        m_prevState = m_currState;
        m_currState = (int)state;
        m_timeInCurrState = 0.0f;
        BeginState( (T)m_currState );
    }

    void UpdateFSM( float delta_time )
    {
        if( m_currState != -1 ){
            m_timeInCurrState += delta_time;
            UpdateState( (T)m_currState );
        }
    }

    float GetTimeInCurState() { return m_timeInCurrState; }
    T GetState() { return (T)m_currState; }
    T GetPrevState() { return (T)m_prevState; }

protected:
    virtual void BeginState( T state ) = 0;
    virtual void UpdateState( T state ) = 0;
    virtual void EndState( T state ) = 0;

private:
    float m_timeInCurrState;
    int m_currState;
    int m_prevState;
};

#endif // ABSTRACTFINITESTATEMACHINE_H
