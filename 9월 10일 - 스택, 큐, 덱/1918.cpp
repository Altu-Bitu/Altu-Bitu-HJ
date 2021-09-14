//
// Created by user on 2021-09-14.
//
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{

    string str;
    cin >> str;
    string result;
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        //피연산자는 바로 문자열에
        if ('A' <= str[i] && str[i] <= 'Z')
            result += str[i];
        //연산자는 4가지 경우
        else
        {
            switch (str[i])
            {
                //1. 앞 괄호면 일단 스택에 넣음
                case '(':
                    s.push(str[i]);
                    break;
                //2. 곱하기 나누기는 스택이 비어있지 않고 스택의 탑이 자신들보다 우선순위가 낮지 않으면 결과 문자열에 넣음
                case '*':
                case '/':
                    while (!s.empty() && (s.top() == '*' || s.top() == '/'))
                    {
                        result += s.top();
                        s.pop();
                    }
                    //while문에 해당 안되거나 while문이 끝나면 스택에 넣음
                    s.push(str[i]);
                    break;
                //3. 더하기 빼기는 스택이 비어있지 않고 스택의 탑이 앞괄호가 아니면 결과 문자열에 넣음
                case '+':
                case '-':
                    while (!s.empty() && s.top() != '(')
                    {
                        result += s.top();
                        s.pop();
                    }
                    //while문에 해당 안되거나 while문이 끝나면 스택에 넣음
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

    cout << result << "\n";

    return 0;

}




