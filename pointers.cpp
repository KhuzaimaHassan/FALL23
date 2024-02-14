#include<iostream>
using namespace std;
int main ()
{
    int a = 10;
    int *ptr=&a;
    int* ptr2=&a;
    int arr[5]={1,4,3,4,5};
    cout<<endl<<&a<<endl;
    cout<<endl<<ptr<<endl;
    cout<<endl<<*ptr2<<endl;
    cout<<endl<<*(arr+1)<<endl;
    cout<<endl<<arr<<endl;
    cout<<endl<<arr+1<<endl;
    cout<<endl<<1[arr]<<endl;
}
