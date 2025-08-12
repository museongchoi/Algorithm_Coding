#include <iostream>
#include <string>
using namespace std;

int main()
{
    string textlist[101];
    string a;
    int n = 0;

    while (true)
    {
        if (!getline(cin, a))
        {
            break;
        }
        textlist[n] = a;
        n++;
    }

    cout << n << endl;

    for (int i = 1; i < n; i++)
    {
        cout << textlist[i] << "\n";
    }
    return 0;
}