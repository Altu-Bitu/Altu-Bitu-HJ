//
// Created by user on 2021-10-12.
//
#include <iostream>

using namespace std;

string maxNum(string s) {
    string ans = ""; //리턴할 문자열
    string temp = ""; //temp용 문자열
    for (int i = 0; i < s.length(); i++) {
        temp += '0'; //자릿수만큼 0을 더해줌
        if (s[i] == 'K') { //K가 마지막으로 끝나는 십진수 변환
            temp[0] = '5'; //5의 배수로 만들어줌, ex)MK면 temp는 50
            ans += temp; //리턴할 문자열 값에 넣어줌
            temp = ""; //temp 비워줌
        }
    }
    if (temp.length() >= 1) { //K로 끝나지 않았다면 마지막 M모두 1로 변환
        for (int i = 0; i < temp.length(); i++)
            temp[i] = '1'; //자릿수만큼 있었던 0을 1로 변환시켜줌
        ans += temp;//리턴할 문자열에 값을 넣어줌
    }
    return ans; //리턴
}

string minNum(string s) {
    string ans = ""; //리턴할 문자열
    string temp = ""; //temp용 문자열
    char first = '1'; //M묶음의 첫번째에 올 문자
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'M') {
            temp += first; //M이 나오면 일단 묶을거니까 더해줌
            first = '0'; //1이 나왔었으면 그 뒤로는 0이 나와야하기 때문에 0으로 바꿔넣어줌
        } else { //'K' -> 그 전까지 M묶음 변환 더하고, K는 따로 변환
            ans += temp + '5'; //k는 따로 변환하니까 그냥 5더해줌
            temp = ""; //temp비워줌
            first = '1'; //k로 한번 묶음이 짤렸으니까 다음 M묶음을 위해 1로 바꿔줌
        }
    }
    //만약 temp가 비워져있지 않다면
    if (temp.length() >= 1)
        ans += temp;//더해줌
    return ans;//리턴
}

/**
 * [가장 큰 값]
 * 민겸수에서 마지막이 K일 때, K까지 포함하여 십진수로 변환한다
 * K로 끝나지 않는다면 각 M을 모두 하나로 처리한다 (ex. MMM -> 111)
 *
 * [가장 작은 값]
 * K는 무조건 단독으로 변환한다
 * 나머지 M묶음들은 같이 변환한다
 * ex. MMKMM -> 10510
 */

int main() {
    string s; //대문자 M과 K로만 이루어진 민겸수

    //입력
    cin >> s;

    //출력
    cout << maxNum(s) << '\n' << minNum(s) << '\n';

    return 0;
}
