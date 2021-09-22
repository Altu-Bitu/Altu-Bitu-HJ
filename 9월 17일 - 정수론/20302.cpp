//
// Created by user on 2021-09-22.
//


#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 1000001;
vector <int> prime;
int prime_cnt[MAX];

void isPrime(){
    prime.assign(MAX+1, 0);
    for(int i = 2; i <= MAX; i++) prime[i] = i;

    for(int i = 2; i <= sqrt(MAX); i++) {
        if(prime[i] != i)
            continue;
        for(int j = i*i; j <= MAX; j+=i)
            if(prime[j] == j) prime[j] = i;
    }
}

// 36이면 3*3*2*2 로 나눠서 primeCnt[2]가 2 primeCnt[3]이 2가 됨
void seperateNum(int num)
{
    num = abs(num);
    while(num>1){
        prime_cnt[prime[num]]++;
        num /= prime[num];
    }
}

// 12면 3*2*2가 분자가 되면서, primeCnt[2]를 2번 줄이고, primeCnt[3]을 1번 줄임
void eraseNum(int num){
    num = abs(num);
    while(num>1){
        prime_cnt[prime[num]]--;
        num /= prime[num];
    }
}

int main(){
    int n;
    char op;
    bool is_zero = false;
    cin >> n;

    isPrime(); //omg.....ㅠㅠ

    //처음 수가 들어왔을때
    int num;
    cin >> num;
    if (num == 0)
        is_zero = true;
    seperateNum(num);
    n--;
    cin.ignore(); //입력 공백 무시

    //그 이후
    while(n--){
        cin >> op >> num;
        if (num == 0)
            is_zero = true;
        else{
            switch(op){
                case '*':
                    seperateNum(num);
                    break;
                case '/':
                    eraseNum(num);
                    break;
            }
        }
        cin.ignore(); //입력 공백 무시
    }

    bool ban_mincho = false; //치약인지 민초인지

    //0을 연산에 쓰면 무조건 정수가 됨
    if (is_zero)
        cout << "mint chocolate";
    else {
        //소수카운트가 음수라는건 분자가 살아 있다는 얘기
        for (int i = 2; i <= MAX; i++)
            if (prime_cnt[i] < 0)
                ban_mincho = true;

        if (ban_mincho)
            cout << "toothpaste";
        else
            cout << "mint chocolate";
    }

    return 0;
}