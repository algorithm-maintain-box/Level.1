#include <iostream>

using namespace std;

int main(void)
{
    int n;
    int m;
    cin >> n >> m;

    for (auto i = 0; i < m; i++)
    {
        for (auto k = 0; k < n; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}