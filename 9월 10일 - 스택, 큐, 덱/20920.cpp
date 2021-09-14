//
// Created by user on 2021-09-14.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n,m;
vector <string> word;
map <string,int> mp;
string w;

bool cmp(string a, string b) {
    //빈도 수
    if (mp[a] != mp[b]) {
        return mp[a] > mp[b];
    }
    //단어 길이
    if (a.size() != b.size()) {
        return a.size() > b.size();
    }
    //사전 순
    return a < b;
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> w;
        if(w.size() < m) continue; //단어 길이가 m보다 짧으면 밑의 if문 측정 필요X
        if (mp.find(w) == mp.end()) //첨보는 단어면 단어장에 넣어줌
        {
            mp[w] = 0;
            word.push_back(w);
        }
        mp[w]++; //빈도수 측정
    }

    sort(word.begin(), word.end(), cmp);

    for(int i=0; i < word.size(); i++){
        cout << word[i] << "\n";
    }
}