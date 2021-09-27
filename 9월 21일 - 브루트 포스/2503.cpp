//
// Created by user on 2021-09-25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <pair<string,pair<int,int>>> v;

bool checkBall(string &num){
    for(int i=0; i<v.size();i++){
        int s=0, b=0;
        for(int j=0; j<num.size(); j++){
            for(int k=0; k<3;k++)
            {
                // ex) 123의 1이 v의 i번째 벡터의 첫번째값의 k번째 인덱스와 같은데
                // k도 1인 경우(1**인경우)는 s++
                // k는 1이 아닌 경우(**1, *1*) b++
                if(num[j]==v[i].first[k]){
                    if(j==k)
                        s++;
                    else
                        b++;
                    break;
                }
            }
        }
        // 만약 주어진 스트라이크나 볼값에 맞지 않는다면 답이 아니므로 false
        if ((s !=v[i].second.first)|| (b!=v[i].second.second))
        {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >>n ;

    while(n--){
        string c;
        int s,b;
        cin >> c >> s >> b;

        v.push_back({c, {s,b}});
    }

    long long res =0;

    for(int i=123; i<=987; i++){
        string predict = to_string(i);
        if(predict[0]=='0'||predict[1]=='0'||predict[2]=='0'||predict[0]==predict[1]||predict[1]==predict[2]||predict[2]==predict[0]){
            continue;
        }
        if(checkBall(predict)){
            res++;
        }
    }
    cout<<res<<"\n";
}