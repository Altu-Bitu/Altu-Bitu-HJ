//
// Created by user on 2021-09-22.
//

#include <iostream>

using namespace std;

int factorial(int num){
    if(num==1 || num ==0)
        return 1;
    return factorial(num-1)*num;
}
int main (){
    int n,k;
    cin >> n >> k;
    cout << factorial(n) / (factorial(k)* factorial(n-k));
    return 0;
}