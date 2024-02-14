#include<iostream>
using namespace std;
class A{
    public:
    void func(){
        cout<<"Function 1"<<endl;
    }
};
class B{
    public:
    void func(){
        cout<<"Function 2"<<endl;
    }
};
class C: public A,public B{
    
};
int main(){
 C one;
 one.A::func();
 one.B::func();
}