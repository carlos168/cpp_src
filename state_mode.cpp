#include <stdlib.h>
#include <stdio.h>

class state {
public:
    virtual void doAction(Context context) = 0;
};

class Context {
private:
    State state;
public:
    void setState(State state) { this.state = state;}
    State getState() { return this.state;}
};

class A: public State {
    void doAction(Context context) { context.setState(this); printf("A.doAction()\n");}
    void toString()
};

class B: public State {
    void doAction(Context context) { context.setState(this); printf("B.doAction()\n");}
};

int main()
{
    
    return 0;
}
