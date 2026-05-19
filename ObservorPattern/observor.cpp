#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



//subject
class Car{
    int m_position;
    std::vector<class Observor*> observorList;

    public:
    int getPosition() { return m_position;};

    void setPosition(int pos){
        m_position=pos;
        // notify all observors if state of subject is changed
        notify();
    }
    void notify();

    void attach(Observor* obs) {
        observorList.push_back(obs);
    }

    void detach(Observor* obs) {
        observorList.erase(std::remove(observorList.begin(),observorList.end(),obs),observorList.end());
    }
};


//abstract
class Observor{
    Car* m_car;
    public:
     Observor(Car * car) {
        m_car=car;
        m_car->attach(this);
     }

     virtual void update()=0;
    protected:
    Car* getCar()
    {
        return m_car;
    }

};

void Car::notify()
{
    for (int i=0;i<observorList.size();i++){
        observorList[i]->update();
    }
}

//concrete classes

class LeftObservor: public Observor{
    public:
    LeftObservor(Car* car):Observor(car) {}

    void update()
    {   cout<<"Updated left observor"<<endl;
        int pos= getCar()->getPosition();

        if(pos < 0 )
        {
            cout<<"left side "<<endl;
        }
    }
};

class MiddleObservor: public Observor{
    public:
    MiddleObservor(Car* car):Observor(car) {}

    void update()
    {   cout<<"Updated middle observor"<<endl;
        int pos= getCar()->getPosition();

        if(pos == 0 )
        {
            cout<<"center side "<<endl;
        }
    }
};

class RightObservor: public Observor{
    public:
    RightObservor(Car* car):Observor(car) {}

    void update()
    {   cout<<"Updated right observor"<<endl;
        int pos= getCar()->getPosition();

        if(pos > 0 )
        {
            cout<<"right side "<<endl;
        }
    }
};


int main(){

    Car* car =new Car();

    LeftObservor leftobservor(car);
    MiddleObservor middleobservor(car);
    RightObservor rightobservor(car);

     cout << "hit left right button to drive a car in your city!!! and press break to close" << endl;
 
    char pressedButton;
    bool breakLoop = false;
 
    while(breakLoop == false) {
        cin >> pressedButton;
 
        switch(pressedButton){
            case 108:{ // l -->  pressed for left side
                car->setPosition(-1);
                break;
            }
            case 99:{ // c --> pressed for center
                car->setPosition(0);
                break;
            }
            case 114:{ // r --> pressed for right side
                car->setPosition(1);
                break;
            }
            case 98:{ // b --> pressed for break
                breakLoop = true;
                break;
            }
            default : {
                cout << "please drive carfully!!" << endl;
                break;
            }
        }
    }
    cout << "Byee..." << endl;
    return 0;
}