#include<iostream>
using namespace std;
int main()
{
    int arr[4][3];
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=3;j++)
     {
        cout<<"Enter element at row "<<i<<" and column "<<j<<": ";
        cin>>arr[i][j];
     }
    }
for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=3;j++)
     {
        cout<<" Element at row "<<i<<" and column "<<j<<": ";
        cout<<arr[i][j];
     }
    }
}
