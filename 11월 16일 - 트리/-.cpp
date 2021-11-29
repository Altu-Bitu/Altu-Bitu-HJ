//
// Created by user on 2021-11-23.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//트리의 정점 수
int nodeCnt(int node) {
    int cnt = 1; //갯수 초기화
    for (int i = 0; i < tree[node].size(); i++)
        cnt += nodeCnt(tree[node][i]); //더해나가기
    return cnt; //개수 리턴
}

//리프 노드의 수
int leafCnt(int node) {
    if (tree[node].empty())
        return 1; //비어있으면 1리턴

    int cnt = 0; //갯수 초기화
    for (int i = 0; i < tree[node].size(); i++)
        cnt += leafCnt(tree[node][i]); //더해나가기
    return cnt; //리턴
}

//트리의 높이
int treeHeight(int node) {
    int height = 0; //높이 초기화
    for (int i = 0; i < tree[node].size(); i++)
        height = max(height, treeHeight(tree[node][i]));
    //트리 높이 갱신
    return height + 1; //높이 리턴
}

int main() {
    //입력
    tree.assign(6, vector<int>(0)); //tree 할당
    tree[1] = {2, 3, 4}; //값 넣어주기
    tree[4] = {5}; //값 넣어주기

    //연산 & 출력
    cout << "[Tree info]\n";
    cout << "Nodes : " << nodeCnt(1) << '\n';
    cout << "Leaf Nodes : " << leafCnt(1) << '\n';
    cout << "Height : " << treeHeight(1) << '\n';
}