//
// Created by user on 2021-11-23.
//


#include <iostream>
#include <map>

using namespace std;

map<char, pair<char, char>> tree;

//전위 순회
void preorder(char node) {
    if (node == '.') //자식이 없음
        return; //그냥 리턴
    cout << node; //출력
    preorder(tree[node].first); //왼쪽자식방문
    preorder(tree[node].second); //오른쪽자식방문
}

//중위 순회
void inorder(char node) {
    if (node == '.') //자식이 없음
        return; //그냥 리턴
    inorder(tree[node].first); //왼쪽자식방문
    cout << node; //출력
    inorder(tree[node].second); //오른쪽자식방문
}

//후위 순회
void postorder(char node) {
    if (node == '.') //자식이 없음
        return; //그냥 리턴
    postorder(tree[node].first); //왼쪽자식방문
    postorder(tree[node].second); //오른쪽자식방문
    cout << node; //출력
}

int main() {
    int n;
    char root, left, right;

    //입력
    cin >> n; //이진 트리 노드의 개수
    while (n--) {
        cin >> root >> left >> right; //루트,왼쪽,자식
        tree[root] = make_pair(left, right); //루트에 자식들 넣어줌
    }

    //연산 & 출력
    preorder('A'); //전위순회
    cout << '\n';

    inorder('A'); //중위순회
    cout << '\n';

    postorder('A'); //후위순회
    cout << '\n';
}