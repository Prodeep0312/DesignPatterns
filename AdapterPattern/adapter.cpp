    #include<iostream>
    using namespace std;

    // Target interface (what client expects)
    class Bird{
        public:

        virtual void fly()=0;
    };

    // Existing class (incompatible)

    class Airplane{
        public:
        void startEngine(){
            cout<<"Starting engine .."<<endl;
        }

        void move(){
            cout<<"moving .."<<endl;
        }
    };

        class AirplaneAdapter: public Bird{
        Airplane* m_airplane;

        public:
            AirplaneAdapter(Airplane* airplane): m_airplane(airplane){}

            void fly() override{
                m_airplane->startEngine();
                m_airplane->move();
            }

        };

        //client
        void makeBirdFly(Bird* bird)
        {
            bird->fly();
        }


        int main(){

            Airplane plane;
            AirplaneAdapter adapter(&plane);

            makeBirdFly(&adapter);
            return 0;
        }