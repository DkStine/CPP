#include <iostream>
using namespace std;

int main()
{
    // for (int i = 1; i <= 5; i++)
    // {
    //     for (int j = 1; j <= 4; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }                                    --> Filled Rectangle

    // int rows, columns;
    // cout << "Enter the rows and columns: " << endl;
    // cin >> rows >> columns;

    // for (int i = 1; i <= columns; i++)
    // {
    //     cout << "* ";
    // }
    // cout << endl;

    // for (int i = 1; i <= rows - 2; i++)
    // {
    //     cout << "* ";
    //     for (int i = 1; i <= columns - 2; i++)
    //     {
    //         cout << "  ";
    //     }
    //     cout << "*" << endl;
    // }

    // for (int i = 1; i <= columns; i++)
    // {
    //     cout << "* ";
    // }                                                --> Hollow rectangle

    // int n;
    // cout << "Enter: ";
    // cin >> n;

    // for (int i = n; i >= 1; i--)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // int n;
    // cout << "Enter: ";
    // cin >> n;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n - i; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int k = 1; k <= i; k++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
        
    // }

    int n;
    cout << "Enter: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}