//
// Created by user on 2021-09-25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <pair<string,pair<int,int>>> v;

bool checkBall(vector<int> &num){
    bool flag = true; //답변한거랑 같은지 판별

    for(int i=0; i<v.size();i++){
        int s=0, b=0;
        for(int j=0; j<num.size(); j++){
            for(int k=0; k<3;k++)
            {
                // ex) 123의 1이 v의 i번째 벡터의 첫번째값의 k번째 인덱스와 같은데
                // k도 1인 경우(1**인경우)는 s++
                // k는 1이 아닌 경우(**1, *1*) b++
                if(num[j]==(v[i].first[k]-'0')){
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
            flag =false;
            break;
        }
    }
    return flag;
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
    vector<int> predict;

    //하나하나 다 검사하기 123 124.....
    for(int i=1;i<=9;i++){
            predict.push_back(i);
            for(int j=i+1;j<=9;j++){
                predict.push_back(j);
                for(int k=j+1;k<=9;k++){
                    predict.push_back(k);
                    do
                    {
                        if(checkBall(predict))
                            res++;
                    }while(next_permutation(predict.begin(),predict.end()));
                    //ex){1,2,3}의 모든 순열을 다 돌려보기 123 132 213 ...
                    predict.pop_back();
                }
                predict.pop_back();
            }
            predict.pop_back();
    }
    cout<<res<<"\n";
}