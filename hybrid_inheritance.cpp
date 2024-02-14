#include <iostream>
using namespace std;

class A
{
public:
  void func1()
  {
    cout << "inside 1 " << endl;
  }
};
class B : public A
{
public:
  void func2()
  {
    cout << "Inside 2" << endl;
  }
};
class D
{
public:
  void func3()
  {
    cout << "Inside 3" << endl;
  }
};
class C : public A, public D
{
public:
  void func4()
  {
    cout << "Inside 4" << endl;
  }
};
int main()
{
  C one;
  B two;
  one.func1();
  two.func2();
  one.func3();
  one.func4();
}
