#include <iostream>
using namespace std;

int main()
{
    int money;

    cout<<"Enter the money you have: ";
    cin>>money;

    if (money > 5000)
    {
        cout<<"Go with Neha\n";
    }
    else
    {
        cout<<"Go with Sneha\n";
    }

    return 0;
}