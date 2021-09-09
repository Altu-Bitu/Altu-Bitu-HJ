//
// Created by user on 2021-09-09.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace  std;

int main()
{
    int n, m;
    cin >> n >> m;

    map<string, bool> word;

    //받은 문자열을 map에 저장해서 나온 문자열은 true로
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        word[str] = true;
    }

    int count = 0; //나왔던 문자열이 다시 나온 횟수

    //문자열을 받아봤더니 true면 이미 나왔던 문자열이므로 count++
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if (word[str])
            count++;
    }

    cout << count;

    return 0;
}
