#ifndef __TOYFACTORY__
#define __TOYFACTORY__
#include<iostream>
#include "object.cpp"
using namespace std;

#endif

class ToyFactory{

    public:
    static Toy* createToy(int type){
        Toy* toy=nullptr;

        switch (type)
        {
        case 1:
            toy=new Car;
            break;
        case 2:
            toy=new Bike;
            break;
        case 3:
            toy=new Plane;
            break;
        default:
            cout << "invalid toy type please re-enter type" << endl;
			return nullptr;
        }

        toy->prepareParts();
	    toy->combineParts();
	    toy->assembleParts();
	    toy->applyLabel();
	
	return toy;
    }
};
