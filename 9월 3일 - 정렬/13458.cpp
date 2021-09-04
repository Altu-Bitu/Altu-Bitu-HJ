//
// Created by user on 2021-09-04.
//

#include <iostream>

using namespace std;

int main() {
    int n, b, c;
    int arr[1000001]; //최대 방의 개수+1만큼 널널하게 잡기
    long long sum=0; //최대 범위를 고려하여 데이터타입 큰거로

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> b;
    cin >> c;

    for (int i=0; i<n; i++)
    {
        //주감독관은 한명밖에 못들어가므로, 주감독관의 감독량을 빼주고
        //감독관 수에 하나를 더해줌
        arr[i] -= b;
        sum++;

        //주감독관만으로는 배치되지 않은 응시생이 남아있다면
        if(arr[i]>0)
        {
            //그 응시생의 수가 부감독관의 감독량에 나눠떨어지면 그 수만큼만 감독관 수를 늘림
            if(arr[i]%c ==0)
                sum += (arr[i]/c);
            //아니면 한명을 더해줌
            else
                sum += (arr[i]/c)+1;
        }
    }
    cout << sum;
    return 0;

}