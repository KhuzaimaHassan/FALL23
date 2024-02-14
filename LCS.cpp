#include <iostream>
#include <string>
using namespace std;
int LCS(const string &X, const string &Y, int i, int j)
{
    if (i == X.length() || j == Y.length())
    {
        return 0;
    }
    if (X[i] == Y[j])
    {
        return 1 + LCS(X, Y, i + 1, j + 1);
    }
    else
    {
        return max(LCS(X, Y, i + 1, j), LCS(X, Y, i, j + 1));
    }
}
int main()
{
    string X = "wildfire";
    string Y = "fireworks";
    int lcsLength = LCS(X, Y, 0, 0);
    cout << "Length of LCS: " << lcsLength << endl;
    return 0;
}
