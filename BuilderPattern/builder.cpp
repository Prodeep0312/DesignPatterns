// Question: WHY Builder Design Pattern
// Answer  : Because i want to build an object(plane) and it is compossed of complex 
//           objects(body, engine) step by step.

#include<iostream>
#include<string>
using namespace std;

class Plane{
    string m_plane;
    string m_body;
    string m_engine;

    public:
    Plane(string planeType):m_plane{planeType}{}

    void setBody(string body) {m_body=body;}
    void setEngine(string engine) { m_engine=engine;}
    string getBody(){ return m_body;}
    string getEngine() {return m_engine;}

    void show() {
    	cout << "Plane Type: " <<m_plane << endl
    		 << "Body Type: " <<m_body << endl
    		 << "Engine Type: "<<m_engine << endl << endl;
    }

};

// PlaneBuilder Abstract Class
// Means all builders should have atleast these methods
class PlaneBuilder{
    protected:
    Plane* plane;

    public:
    virtual void getPartsDone()=0;
    virtual void buildBody() =0;
    virtual void buildEngine()=0;
    Plane* getPlane(){ return plane; }
};

// PlaneBuilder concrete class
// knows only how to build Propeller Plane
class PropellerBuilder: public PlaneBuilder {
public:
    void getPartsDone() { plane = new Plane("Propeller Plane"); }
    void buildBody()    { plane->setBody("Propeller Body");   }
    void buildEngine()  { plane->setEngine("Propeller Engine");   }
    
};

// PlaneBuilder concrete class
// Knows only how to build Jet Plane
class JetBuilder: public PlaneBuilder {
public:
    void getPartsDone() { plane = new Plane("Jet Plane"); }
    void buildBody()    { plane->setBody("Jet Body");   }
    void buildEngine()  { plane->setEngine("Jet Engine");   }
   
};

// Defines steps and tells to the builder that build in given order.
class Director{
    PlaneBuilder* builder;
    public:
    Plane* createPlane(PlaneBuilder *builder) {
        builder->getPartsDone();
        builder->buildBody();
        builder->buildEngine();
        return builder->getPlane();
    }

    
};

int main()
{
    Director dr;
    JetBuilder jb;
    PropellerBuilder pb;

   Plane* jet= dr.createPlane(&jb);
   Plane* pro= dr.createPlane(&pb);

   jet->show();
	pro->show();
    
    delete jet;
    delete pro;
}