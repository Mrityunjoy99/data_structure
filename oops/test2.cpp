#include <bits/stdc++.h>
using namespace std;

class vehical
{
    int wheels;
    int price;

public:
    vehical()
    {
        cout << "vehicle called" << endl;
        this->wheels = 4;
    }
    void setWheels(int wheels)
    {
        this->wheels = wheels;
    }
    int getWheels()
    {
        return this->wheels;
    }

    void setPrice(int capacity)
    {
        this->price = capacity;
    }
    int getPrice()
    {
        return this->price;
    }

    void func()
    {
        cout << "In base class vehicle" << endl;
    }
    // void setWeight(int weight)
    // {
    //     this->weight = weight;
    // }
    // int getWeight()
    // {
    //     return this->weight;
    // }
};

class car : virtual public vehical
{
    int topSpeed;

public:
    car()
    {
        cout << "car called" << endl;
    }
    void setTopSpeed(int speed)
    {
        this->topSpeed = speed;
    }
    int getTopSpeed()
    {
        return this->topSpeed;
    }
    void func()
    {
        cout << "In derived class car" << endl;
    }
};

class truck : virtual public vehical
{
    int load;

public:
    static int stat;
    truck()
    {
        cout << "truck called" << endl;
    }
    void setLoad(int load)
    {
        this->load = load;
    }
    int getLoad()
    {
        return this->load;
    }
    void func()
    {
        cout << "In derived class truck" << endl;
    }
};

class test:public car,public truck
{
    public:
        test()
        {
            cout << "in test" << endl;
        }
        void func()
        {
            cout << "Test passed" << endl;
        }
};


int truck::stat = 0;
int main()
{
    car c;
    // // c.setWheels(6);
    // c.setPrice(20000);
    // c.setTopSpeed(140);

    c.func();
    // cout << "Wheels : " << c.getWheels() << "\tPrice : " << c.getPrice() << "\tTopSpeed : " << c.getTopSpeed() << endl;

    truck t;
    // t.setWheels(10);
    // t.setPrice(100000);
    // t.setLoad(10);
    // // t.stat = 5;
    t.func();
    // cout << "Wheels : " << t.getWheels() << "\tPrice : " << t.getPrice() << "\tLoad : " << t.getLoad() << endl;
    // truck t;
    // truck::stat = 4;
    cout << truck::stat << endl;
    test te;
    // te.func();
    // cout << te.getWheels() << endl;
}