//
// Created by user on 2021-09-18.
//

/*
 * 에러가 나는 경우
 * 1. 첫번째가 대문자나 _일 경우
 * 2. 마지막 문자가 _일 경우
 * 3. _가 연속으로 나올 경우
 * ----------------------
 * 4. C인데 대문자가 나올 경우
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
string s;

//C를 바꿈
void ConvertC(){
    while (s.find('_') != string::npos) {
        int pos = s.find('_');
        s.erase(pos,1);
        s[pos] -= ('a' - 'A');
    }
}

//자바를 바꿈
void ConvertJava(){
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < 'a') {
            s.insert(i, "_");
            //"_" 넣은 뒤 인덱스 문자 대문자로 바꿔줌
            s[i+1] += ('a' - 'A');
            i++; //뒤 문자는 이미 대문자로 바꿔줬으니까 인덱스 하나 넘어감
        }
    }
}

int main(){
    bool err = false;
    cin >> s;

    //에러 1, 2 의 경우
    if(s[0]<'a'||s[0]=='_'||s[s.length()-1]=='_')
        err= true;

    //에러 3의 경우
    if (err ==false){
        for(int i=0; i< s.length()-1; i++){
            if(s[i]=='_' && s[i+1]=='_'){
                err=true;
                break;
            }
        }
    }

    //'_'의 유무로 c인지 자바인지 판별
    if(s.find('_')!=string::npos){
        //에러 4의 경우
        for(int i=0; i<s.length();i++){
            if('A'<=s[i] && s[i]<='Z'){
                err = true;
                break;
            }
        }
        ConvertC();
    }
    else
        ConvertJava();

    if(err)
        cout << "Error!";
    else
        cout << s;
}
