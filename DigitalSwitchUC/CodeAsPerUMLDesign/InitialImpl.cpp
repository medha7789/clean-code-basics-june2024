// hello.cpp file
#include <iostream>
using namespace std;

enum SwitchState{ OFF, LOW, MODERATE, HIGH};

class IContext{
    public:
    virtual void setState(SwitchState nextstate)=0;
};

class IStateHandler{
public:
    virtual void handleState(IContext*context)=0;
};

class OffStateHandler:public IStateHandler
{
public:
    OffStateHandler(){};
    ~OffStateHandler(){};
    void handleOffState()
    {
        cout<<"DigitalSwitch is in off state"<<endl;
    }
    void handleState(IContext* context)
    {
        handleOffState();
        context->setState(SwitchState::LOW);
    }
};
class ModerateStateHandler:public IStateHandler
{
public:
    ModerateStateHandler(){};
    ~ModerateStateHandler(){};
    void handleOffState()
    {
        cout<<"DigitalSwitch is in Moderate state"<<endl;
    }
    void handleState(IContext* context)
    {
        handleOffState();
        context->setState(SwitchState::HIGH);
    }
};
class LowStateHandler:public IStateHandler
{
public:
    LowStateHandler(){};
    ~LowStateHandler(){};
    void handleLowState()
    {
        cout<<"DigitalSwitch is in Low state"<<endl;
    }
    void handleState(IContext* context)
    {
        handleLowState();
        context->setState(SwitchState::LOW);
    }
};
class HighStateHandler:public IStateHandler
{
public:
    HighStateHandler(){};
    ~HighStateHandler(){};
    void handleHighState()
    {
        cout<<"DigitalSwitch is in High state"<<endl;
    }
    void handleState(IContext* context)
    {
        handleHighState();
        context->setState(SwitchState::OFF);
    }
};
class DigitalSwitch:public IContext{
    SwitchState currentState;
    IStateHandler* StateHandlerInstance;
public:
    DigitalSwitch(SwitchState InitState){
        currentState = InitState;
        if(InitState == OFF)
            StateHandlerInstance = new OffStateHandler();
    }
    ~DigitalSwitch(){
        delete StateHandlerInstance;
    }
    void press(){
        cout<<"Digital switch pressed and current state is "<<currentState<<endl;
    }
    SwitchState getState(){
        return currentState;
    }
    void setState(SwitchState nextState){

        switch (nextState)
        {
            case SwitchState::OFF:
               currentState = SwitchState::LOW;
                break;
            case SwitchState::LOW:
                currentState = SwitchState::MODERATE;
                break;
            case SwitchState::MODERATE:
                currentState = SwitchState::HIGH;
                break;
            case SwitchState::HIGH:
                currentState = SwitchState::OFF;
                break;
            default:
                cout<<"Invalid next state"<<endl;
            break;
        } 

    }
};
int main()
{
    cout <<"Digital Switch started"<<endl;
    DigitalSwitch SwitchObj(SwitchState::OFF);
    SwitchObj.press();
    SwitchObj.press();
    return 0;
}
