//
// Created by user on 2021-10-12.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> matrix;

int divide(int row, int col, int size) {
    //Conquer : n의 크기가 1
    if (size == 1) //행렬의 크기가 1일때 종료
        return matrix[row][col]; //그 값만 리턴

    //Divide : 행렬 4등분 하기
    int next_size = size / 2; //가로 세로 반씩 쪼개기
    vector<int> sub_problem; //잘라진 값들 넣어둘 벡터
    //처음값이 8이라면 8->4->2->1 이런식으로 계속 잘라서 최종적으로 리턴받은 두번째로 큰 값만 넣어줌
    for (int i = 0; i <= next_size; i += next_size) {
        for (int j = 0; j <= next_size; j += next_size)
            sub_problem.push_back(divide(row + i, col + j, next_size));
    }

    //Combine : 두번째로 큰 수만 남기기
    sort(sub_problem.begin(), sub_problem.end(), greater<>()); //내림차순 정렬
    return sub_problem[1]; //두번째로 큰 수 리턴
}

/**
 * 1. 행렬 4등분 하기
 * 2. 행렬의 크기가 1이라면 원소 리턴
 * 3. 리턴된 원소 4개 모아서 두번째로 큰 수만 리턴
 */
int main() {
    int n;

    //입력
    cin >> n; //n은 항상 2의 거듭제곱꼴
    matrix.assign(n, vector<int>(n)); //2차원배열생성
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j]; //2차원 배열에 성분 넣어줌
    }

    //연산 & 출력
    cout << divide(0, 0, n); //0,0부터 열심히 나눠준 뒤 2번째로 큰 수 출력
}
