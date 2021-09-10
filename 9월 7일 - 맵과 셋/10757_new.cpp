//
// Created by user on 2021-09-10.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string s1, s2;
    vector<int> result;
    cin >> s1 >> s2;

    int carry=0;
    int num1 = s1.size();
    int num2 = s2.size();

    while(num1 > 0 || num2 > 0)
    {
        int n1 = 0;
        if(num1>0)
            n1 = s1[--num1]-'0';
        int n2 =0;
        if(num2>0)
            n2 = s2[--num2]-'0';
        int sum = n1+n2+carry;
        carry = sum/10;
        sum%=10;
        result.push_back(sum);
    }

    if (carry > 0)
        result.push_back(1);

    for (int i= result.size()-1; i>=0; i--)
        cout << result[i];

}