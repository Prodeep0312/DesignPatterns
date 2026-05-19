#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Spaceship{
    int m_height;
    vector<class Observor*> observorList;

    public:
    int getHeight() { return m_height;}
    void setHeight(int height){
        m_height=height;
        notify();
    }

    void notify();

    void attach(Observor* obs){
        observorList.push_back(obs);
    }

    void detach(Observor* obs){
        observorList.erase(std::remove(observorList.begin(),observorList.end(),obs),observorList.end());
    }


};

class Observor{

    Spaceship* m_spaceship;
    public:
    Observor(Spaceship* spaceship){
        m_spaceship=spaceship;
        m_spaceship->attach(this);
    }
    virtual void update()=0;

    protected:
    Spaceship* getspaceShip(){
        return m_spaceship;
    }
};


void Spaceship::notify(){
    for(int i=0;i<observorList.size();i++)
    {
        observorList[i]->update();
    }
}


class PressureObservor: public Observor{

    public:
    PressureObservor(Spaceship* spaceship ): Observor(spaceship){}

    void update()
    {
        cout<<"Notified Pressure observor"<<endl;
        int height = getspaceShip()->getHeight();
		cout << "Presure Observer Checked!!" << endl;
    }
};

class SpeedObservor: public Observor{

    public:
    SpeedObservor(Spaceship* spaceship ): Observor(spaceship){}

    void update()
    {
        cout<<"Notified Speed observor"<<endl;
        int height = getspaceShip()->getHeight();
		cout << "Speed Observer Checked!!" << endl;
		if(height == 1000){
			getspaceShip()->detach(this);
			cout << "Speed Observer Detached!!" << endl;
		}
    }
};

class TemperatureObservor: public Observor{

    public:
    TemperatureObservor(Spaceship* spaceship ): Observor(spaceship){}

    void update()
    {
        cout<<"Notified Temperature observor"<<endl;
        int height = getspaceShip()->getHeight();
		cout << "Temperature Observer Checked!!" << endl;
    }
};


int main(){
int height;
	cout << "Enter height of rocket OR press 0 to exit" << endl;
	cin >> height;
 
	Spaceship *ship = new Spaceship();
 
	PressureObservor po(ship);
	SpeedObservor so(ship);
	TemperatureObservor to(ship);
 
	while(height) {
		ship->setHeight(height);
		cin >> height;
	}
 
	cout << "Bye....";
}
