//
// Created by user on 2021-09-09.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int sum;
    int num1[10001], num2[10001];
    string s1, s2;
    vector<int> result;

    cin >> s1 >> s2;

    //s1문자열이 제일 길도록 조정
    //덧셈을 할때 긴 문자열인 s1을 기준으로 할 것이기 때문
    if(s1.size() < s2.size())
        swap(s1,s2);

    //s1문자열의 문자를 숫자로 바꿔서 num1배열에 넣어줌. 이때 최상위값이 되는 num[0]은
    //carry되는 숫자를 고려하여 비워둠
    for(int i=0; i< s1.size(); i++)
        num1[i+1] = s1[i]-'0';

    //s2문자열도 마찬가지
    //이때 덧셈에서 자릿수를 맞춰줘야하기 때문에 두 문자열의 길이차이를 더해줌
    //ex) 8765
    //      32  이때 32의 문자열에 두 문자열의 차이인 2를 더해주어 자릿수를 맞추는 개념
    for(int i=0; i< s2.size(); i++)
        num2[i+1+(s1.size()-s2.size())] = s2[i]-'0';

    //맨 끝(작은 자릿수)부터 덧셈 시작
    for (int i=s1.size(); i>0; i--)
    {
        sum = num1[i]+num2[i];
        if(sum >= 10) //만약 carry가 생길경우
        {
            num1[i-1]++; //윗자릿수에 해당하는 곳에 1을 더해줌(num1에 더해주는 것으로 통일)
            sum-=10;
        }
        result.push_back(sum); //그리고 결과값이 될 string의 뒤로 넣어줌

    }

    //최종적으로 덧셈이후에 최상위자릿값에 1이 올라와있다면 1을 먼저 출력해줌
    if (num1[0] != 0)
        cout << 1;

    //맨 끝 자릿수부터 덧셈하여 넣어줬기 때문에 거꾸로 출력
    for (int i= result.size()-1; i>=0; i--)
        cout << result[i];

}
