//
// Created by user on 2021-09-14.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int alphabet[26]; //알파벳

int main(void)
{
    int N;
    cin >> N;
    string str;
    cin >> str;

    //입력 알파벳 배열에 저장 ex) 1이면 alphabet[0]
    for (int i = 0; i < N; i++)
        cin >> alphabet[i];

    stack<double> s;
    for (int i = 0; i < str.length(); i++)
    {
        //연산자일 경우
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            //피연산자 두 개를 빼줌
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();

            //연산자 종류에 따라 계산해줌. 이때 먼저 뺀 a가 사실은 식 상으로는 뒤에 있는 것 주의
            switch (str[i])
            {
                case '+':
                    s.push(b + a);
                    break;
                case '-':
                    s.push(b - a);
                    break;
                case '*':
                    s.push(b * a);
                    break;
                case '/':
                    s.push(b / a);
                    break;
            }
        }
        //피연산자 일 경우 문자열을 int형으로 바꿔서 넣어줌
        else
            s.push(alphabet[str[i] - 'A']);
    }

    double result = s.top();
    //소숫점 2자리 고정
    cout << fixed;
    cout.precision(2);
    cout << result << "\n";

    return 0;

}
