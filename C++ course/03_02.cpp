#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    char opt;

    cout << "Enter the operands: " << endl;
    cin >> n1 >> n2;

    cout << "Enter the operator :" << endl;
    cin >> opt;

    switch (opt)
    {
    case '+':
        cout << n1 + n2 << endl;
        break;
    case '-':
        if (n1 > n2)
        {
            cout << n1 - n2 << endl;
        }
        else
        {
            cout << n2 - n1 << endl;
        }
        break;
    case '*':
        cout << n1 * n2 << endl;
        break;
    case '/':
        cout << n1 / n2 << endl;
        break;
    default:
        cout << "This operator seems new to me, try choosing from +, -, * and /." << endl;
        break;
    }

    return 0;
}