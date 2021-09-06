//
// Created by user on 2021-09-06.
//

#include <iostream>
#include <algorithm>

using namespace std;

//숫자끼리 더해주기
int str_sum(string s){
    int len = s.length();
    int sum =0;
    for(int i=0; i <len; i++){
        //문자열 내 숫자면 아스키코드로 int형으로 바꾸어 더해준다
        if ('0'<=s[i]&&s[i]<='9')
            sum += s[i]-'0';
    }
    return sum;
}


bool cmp (const string& A, const string& B){
    //1번째 조건
    if(A.length() != B.length())
        return A.length()<B.length();

    int asum =str_sum(A);
    int bsum =str_sum(B);
    //2번째 조건
    if (asum != bsum)
        return asum < bsum;
    //3번째 조건
    return A<B;

}
int main() {
    int n;
    cin >> n;
    string str[51];

    for (int i=0; i<n; i++)
        cin >> str[i];

    //정렬
    sort(str, str+n, cmp);

    for (int i=0; i<n; i++)
        cout << str[i] <<"\n";
    return 0;

}