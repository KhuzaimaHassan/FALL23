#include <iostream>
#include <vector>

using namespace std;

bool cities[5][5] = {
    {false, true, false, false, false},
    {true, false, true, false, false},
    {false, true, false, false, true},
    {false, true, true, false, false},
    {false, true, true, true, false}};

bool checkCommonNeighbor(int city1, int city2) {
    for (int neighbor = 0; neighbor < 5; neighbor++) {
        if (cities[city1][neighbor] && cities[city2][neighbor]) {
            return true;
        }
    }
    return false;
}

int main() {
    int city1, city2;
    string city[5]={"Khi","Hyd","Jam","Mpk","Kot"};
    cout << "City Map(1 means 'neighbors'):" << endl;
    cout << "\tKhi\tHyd\tJam\tMpk\tKot" << endl;
     for(int i=0; i<5;i++)
    {
       cout<<city[i]<<"\t";
        for(int j=0;j<5;j++)
        {
            cout<<cities[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout << "Enter city 1: ";
    cin >> city1;

    cout << "Enter city 2: ";
    cin >> city2;


    if (checkCommonNeighbor(city1, city2)) {
        cout << "Cities " << city1 << " and " << city2 << " have a common neighbor." << endl;
    } else {
        cout << "Cities " << city1 << " and " << city2 << " do not have a common neighbor." << endl;
    }

    return 0;
}
