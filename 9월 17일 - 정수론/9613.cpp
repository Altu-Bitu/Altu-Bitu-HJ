//
// Created by user on 2021-09-22.
//

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a%b == 0) return b;
    return gcd(b, a%b);
}

int main(){
    int arr[101];
    int t,n;
    cin >> t;

    while(t--){
        cin >> n;

        for(int i=0; i<n; i++)
            cin >> arr[i];
        long long sum = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                sum += gcd(arr[i],arr[j]);
            }
        }

        cout << sum << "\n";
    }
    return 0;
}