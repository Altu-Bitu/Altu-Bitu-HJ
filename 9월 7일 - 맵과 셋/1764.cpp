//
// Created by user on 2021-09-09.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace  std;

int main() {
    map<string, int> word;
    vector<string> v;

    int n,m;
    cin >> n >> m;

    //전체 문자열을 쭉 탐색
    for (int i=0; i<n+m; i++){
        string str;
        cin >> str;
        word[str]++; //문자열이 나올때마다 그 문자열의 map second를 증가시킴
        if(word[str]>1) //만약 중복된 문자열이라면 듣도 보도 못한 문자열이므로
            v.push_back(str); //벡터에 넣어줌
    }
    sort(v.begin(), v.end()); //정렬~
    cout << v.size() << "\n"; //몇개인지 출력
    for(int i=0; i<v.size(); i++)
        cout << v[i] << "\n"; //문자열 출력

    return 0;
}
