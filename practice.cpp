#include <iostream>
using namespace std;
int main()
{
    int inputs;
    cout<<"Enter number of students: ";
    cin>>inputs;

    int oneDarr[inputs];
    for(int i=0;i<inputs;i++)
    {

        cout<<"Enter marks for "<<i+1<<" student: ";
        cin>>oneDarr[i];

        }

   cout<<"\nPrinting 1D array\n";
   for(int j=0;j<inputs;j++)
    {

        cout<<" marks of "<<j+1<<" student: ";
        cout<<oneDarr[j]<<endl;

        }
    }




