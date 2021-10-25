#include<iostream>
using namespace std;

class A
{
int x;
public:
A(){cout<<"A()"<<endl;}
A(int i) { x = i;
         cout<<"A(n)"<<endl;
         }
void print() { cout <<"x = "<< x<<endl; }
};

class B: virtual public A
{
public:
B():A(10) { cout<<"B()"<<endl; }
B(int x):A(x) { cout<<"B(n)"<<endl; }
};

class C: virtual public A
{
public:
C():A(10) { cout<<"C()"<<endl; }
C(int x):A(x) { cout<<"C(n)"<<endl; }
};

class D: public B, public C {
  public:
  D():B(),C(){ cout<<"D()"<<endl; }
  D(int x):B(x),C(x){ cout<<"D(n)"<<endl; }
};

int main()
{
	D *d = new D(5);
	d->print();
	return 0;
}
