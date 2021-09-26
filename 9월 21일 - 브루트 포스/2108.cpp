//
// Created by user on 2021-09-25.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n,tmp,sum=0,mode,most=0;
    bool second = false; //최빈값 중 두 번째로 작은 값이 존재하는지
    vector <int> arr; //평균, 중앙값, 범위를 알기 위한 벡터
    vector <int> vec(8001,0); //최빈값을 위한 벡터, 절댓값이 4000이므로 -4000~4000

    cin>>n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        arr.push_back(tmp);
        sum += tmp;
        vec[tmp+4000]++; //최빈값을 위한 값 등장개수 세기
        if (vec[tmp+4000]>most)
            most = vec[tmp+4000]; //최빈값 갱신해주기
    }

    //중앙값 구해야 되니까 정렬
    sort(arr.begin(),arr.end());

    for(int i=-4000; i<4001;i++){
        tmp = i+4000;
        if(vec[tmp]==most){
            mode = i;
            if(second)
                break;
            second=true;
        }
    }

    cout << round(sum/(double)n)<<"\n";
    cout << arr[round(n/2)]<<"\n";
    cout << mode <<"\n";
    cout << arr.back()-arr.front() << "\n";

}