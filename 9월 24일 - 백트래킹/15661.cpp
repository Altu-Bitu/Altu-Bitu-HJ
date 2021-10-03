//
// Created by user on 2021-10-01.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 20; //입력받을 n의 최대값
const int INF = 10e8; //최소값을 갱신해가기 위해 일단 큰값

int n; //입력받을 n명
int answer = INF; //최소값 초기값 넣어두기
int power[SIZE][SIZE]; //능력치 관계
bool is_start[SIZE]; //각 사람이 스타트팀인지 아닌지 저장
int start[SIZE], link[SIZE]; //스타트와 링크 팀에 속하는 사람

//각 팀의 능력치를 계산하는 함수
int calcPower(int arr[], int size) {
    int result = 0; //결과값 0으로 초기값 설정

    //모든 Sij의 합 ex)1,2가 있으면 1,2만 계산해야하므로(2,1까지 계산하면 똑같은 값을 두번 더하게 됨)
    for (int i = 0; i < size; i++) //ex) 1
        {
        for (int j = i + 1; j < size; j++) //ex) 2 이런식으로 순서 정해줌
            result += power[arr[i]][arr[j]] + power[arr[j]][arr[i]]; //ex) S12+S21
    }
    return result; //능력치를 합한거 리턴
}

void backtracking(int cnt, int st) {
    if (cnt == n) //n이면 팀 더 이상 꾸릴 수 x (기저조건)
        return; //호출된 곳으로 리턴
    if (cnt > 0) { //최소 1명이 팀에 있어야 함
        int idx = 0; //링크팀의 시작 인덱스
        for (int i = 0; i < n; i++) {
            if (!is_start[i]) //스타트 팀이 아니라면->링크팀
                link[idx++] = i; //링크팀에 인덱스를 증가시켜가면서 넣어줌
        }
        int diff_value = abs(calcPower(link, idx) - calcPower(start, cnt)); //두 팀의 능력치 차이
        answer = min(answer, diff_value); //차이의 최솟값 저장
    }
    for (int i = st; i < n; i++) //st : 같은 숫자로 이루어진 수열 구분을 위한 시작 인덱스{
        is_start[i] = true; //링크 팀에 속하는 사람 추리기 위해 스타트 팀원 체크
        start[cnt] = i; //스타트 팀에 배치
        backtracking(cnt + 1, i + 1); //인덱스 늘려서 호출
        if (i == 0) //1번 사람이 링크 팀이 됨 -> 어차피 스타트 팀이었던 경우와 값 같음
            return; //그러므로 그냥 리턴
        is_start[i] = false; //다음을 위해 스타트팀원 체크 풀어줌
    }
}

/**
 * [백트래킹 풀이] (84ms)
 * 오름차순 수열을 만드는 것을 활용하여 팀 조합
 * 오름차순 수열을 만들어가는 과정에서 길이가 1이상이 되면 팀배정 완료된 것 (최소 1명 이상이 팀원이므로)
 * 스타트 팀을 꾸려가는 것을 기준으로 풀이, 나머지는 링크 팀에 수동배정
 * ex. n = 4
 * 1 -> 1번 사람이 스타트 팀
 * 1 2 -> 1, 2번 사람이 스타트 팀
 * (생략)
 * 2 3 4 -> 2, 3, 4번 사람이 스타트 팀
 *
 * 팀 배정을 모두 끝낸 후, 능력치 차이 계산
 */

int main() {
    //입력
    cin >> n; //축구를 하기 위해 모인 n명
    for (int i = 0; i < n; i++) //행{
        for (int j = 0; j < n; j++) //열{
            cin >> power[i][j]; //사람 사이의 능력치 관계
        }
    }

    //연산
    backtracking(0, 0); //수열의 인덱스 0부터 시작, 수열 구분을 위해(1,2와 2,1은 사실상 같은거)시작 인덱스 0부터 시작

    //출력
    cout << answer << '\n'; //스타트팀이 능력치와 링크팀의 능력치 차이 최소값

    return 0;
}