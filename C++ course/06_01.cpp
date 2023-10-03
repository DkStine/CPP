#include <iostream>
#include<math.h>
using namespace std;

int factorial(int n){
    int fact = 1;
    for(int i = n; i > 1; i--){
        fact *= i;
    }
    return fact;
}

void primeNos(int start, int end){
    for(int i = end - 1; i > start; i--){
        bool flag = true;
        for(int j = sqrt(i); j > 1; j--){
            if(i % j == 0){
                flag = false;
                break;
            }
        }
        if(flag == true){
            cout << i << endl;
        }
    }
}

void fibo(int n){
    int t1 = 0, t2 = 1;
    int nextNum;
    
    for(int i = n; i >= 1; i--){
        cout<<t1<<endl;
        nextNum = t1 + t2;
        t1 = t2;
        t2 = nextNum;
    }
}

int nCr(int n, int r){
    return factorial(n)/(factorial(n-r) * factorial(r));
}

int main()
{
    int rows;
    cout<<"Enter the no. of rows: ";
    cin>>rows;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j <= i; j++){
            cout<<nCr(i, j)<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}