//
// Created by user on 2021-11-16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
//상, 좌, 좌상향
int dr[3] = {-1, 0, -1};
int dc[3] = {0, -1, -1};

//역추적
string back(string str1, vector<vector<int>> &path) {
    string result = "";
    int r = n, c = m; //수열 길이들 행, 열에저장
    while (path[r][c] != -1) {
        int d = path[r][c]; //방향 가져옴
        if (d == 2) //좌상향에서 가져온 경우 -> str1[r - 1] == str2[c - 1]
            result += str1[r - 1]; //더해줌
        r += dr[d]; //역추적
        c += dc[d]; //역추적
    }
    reverse(result.begin(), result.end()); //거꾸로 추적했으므로 뒤집어줌
    return result;//리턴
}

//LCS 길이 구하는 함수
int lcs(string str1, string str2, vector<vector<int>> &path) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    //dp벡터
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] != str2[j - 1]) { //두 문자가 서로 다르면
                dp[i][j] = dp[i - 1][j]; //우선 위쪽 값 가져온 것으로 저장
                path[i][j] = 0; //경로(방향) 저장
                if (dp[i][j] < dp[i][j - 1]) { //왼쪽이 더 크다면
                    dp[i][j] = dp[i][j - 1]; //갱신
                    path[i][j] = 1; //경로(방향) 저장
                }
            } else if (str1[i - 1] == str2[j - 1]) { //두 문자가 서로 같다면
                dp[i][j] = dp[i - 1][j - 1] + 1; //길이 저장
                path[i][j] = 2; //경로(방향) 저장
            }
        }
    }
    return dp[n][m]; //LCS 길이 리턴
}

/**
 * 기본 문제: LCS (해당 풀이는 "08. 동적계획법.pdf" 참고)
 *
 * [역추적]
 * - 위쪽, 왼쪽, 좌상향 중 어느 방향에서 왔는지 경로를 저장한 후, 역추적하는 문제
 * - 경로 저장은 dp배열이 갱신될 때 함
 *
 * 해당 풀이는 인덱스를 편하게 관리하기 위해 dp와 path 배열을 (1, 1)부터 시작
 */

int main() {
    string str1, str2;

    //입력
    cin >> str1 >> str2; //최장 공통 부분 수열을 찾을 2 수열
    n = str1.length(); //1의 길이
    m = str2.length(); //2의 길이
    vector<vector<int>> path(n + 1, vector<int>(m + 1, -1)); //그 전 방향 저장

    //연산
    int ans = lcs(str1, str2, path); //lcs
    string result = back(str1, path); //역추적

    //출력
    cout << ans << '\n' << result << '\n'; //답 출력
    return 0;
}