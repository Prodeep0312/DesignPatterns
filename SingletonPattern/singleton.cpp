#include<iostream>
using namespace std;

class GameSettings{
    //static var
    static GameSettings* instance;
    int m_height;
    int m_width;
    int m_brightness;

    //private constructor
    GameSettings():m_height(900),m_width(1600),m_brightness(40){}

    public:
    //static public function
    static GameSettings* getinstance(){
        if(instance == nullptr){
            instance=new GameSettings();
        }
        return instance;
    }
    //getters setters
    void setHeight(int height){
        m_height=height;
    }
    
    void setWidth(int width){
        m_width=width;
    }

    void setBrightness(int brightness){
        m_brightness=brightness;
    }

    int getHeight(){ return m_height;}
    int getWidth(){ return m_width;}
    int getBrightness(){ return m_brightness;}

    void display(){
        cout<<"Displaying game settings..."<<endl;
        cout<<"Height: "<<m_height<<endl;;
        cout<<"Width: "<<m_width<<endl;
        cout<<"Brightness: "<<m_brightness<<endl;
    }


};

GameSettings* GameSettings::instance = nullptr;


void anotherFunction(){
     GameSettings* settings=GameSettings::getinstance();
     settings->display();
     settings->setBrightness(10);
}
int main(){
    GameSettings* settings=GameSettings::getinstance();
    settings->display();
    settings->setBrightness(100);

    anotherFunction();

    settings->display();
    return 0;
}