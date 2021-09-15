//
// Created by user on 2021-09-14.
//
#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

string makeResult(string str, map<char,int> mp)
{
    string result;
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        //피연산자
        if ('A' <= str[i] && str[i] <= 'Z')
        {
            result += str[i];
            continue;
        }
        //연산자
        else
        {
            switch (str[i])
            {
                //1. 앞 괄호면 일단 스택에 넣음
                case '(':
                    s.push(str[i]);
                    break;
                case '*':
                case '/':
                case '+':
                case '-':
                    while (!s.empty() && mp[s.top()] <= mp[str[i]])
                    {
                        result += s.top();
                        s.pop();
                    }
                    s.push(str[i]);
                    break;
                    //4. 뒷괄호면 앞괄호가 나올때까지 결과 문자열에 넣음
                case ')':
                    while (!s.empty() && s.top() != '(')
                    {
                        result += s.top();
                        s.pop();
                    }
                    //앞괄호도 빼줌
                    s.pop();
                    break;
            }
        }
    }
    //다 돌고도 스택이 안비어 있으면 남은 것들을 결과에 넣어줌
    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }

    return result;
}

int main()
{

    string str;
    cin >> str;
    //우선순위 map
    map<char,int> mp;
    mp['*']=1;
    mp['/']=1;
    mp['+']=2;
    mp['-']=2;

    cout << makeResult(str,mp) << "\n";

    return 0;

}




