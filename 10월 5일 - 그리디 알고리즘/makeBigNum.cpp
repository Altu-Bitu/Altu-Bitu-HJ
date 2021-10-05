//
// Created by user on 2021-10-05.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//앞에서 제일 큰 수를 찾으면 지나온 길은 거들떠보지 않는 시스템..
string solution(string number, int k)
{
    string answer = "";
    int size = number.length();
    int idx = -1; //두번째 for문에서 idx를 늘려가면서 돌려면 -1이어야 함

    for (int i = 0; i < size - k; i++)
    {
        char max = 0;
        //앞부분에서 찾다가 점점 뒤로 늘려나가기
        //인덱스는 한번 돌 때 제일 큰 수에서 고정
        for (int j = idx+1; j <= k + i; j++)
        {
            if (max < number[j])
            {
                idx = j;
                max = number[j];
            }
        }
        //인덱스 순서대로 큰 수 이므로 두번째 포문 돌고 얻은 큰수를 미리 더해줌
        //어짜피 뒤에꺼가 더 커도 뒤에 와야함
        answer += max;
    }
    return answer;
}

int main(){
    string s;
    int k;
    cin >> s >> k;

    cout << solution(s,k) << "\n";
    return 0;
}