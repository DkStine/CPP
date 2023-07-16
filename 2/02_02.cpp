#include <iostream>
using namespace std;

int main()
{
    int mom_amount;
    int fat_amount;

    cout<<"Enter amount given by father: ";
    cin>>fat_amount;
    cout<<"Enter amount given by mother: ";
    cin>>mom_amount;

    cout<<"The total amount is: "<<fat_amount + mom_amount<<"\n";

    return 0;
}