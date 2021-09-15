//
// Created by user on 2021-09-14.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    stack<int> map[board.size()];

    for(int j=0; j<board.size(); j++){
        for (int i=board.size()-1; i>=0; i--){
            if(board[i][j]) map[j].push(board[i][j]);
            else break;
        }
    }

    for(int i=0; i<moves.size();i++){
        //board는 0부터 시작이므로 1 빼줌(moves[i]는 1부터 기재)
        int col = moves[i]-1;

        if(!map[col].empty()){
            int pick = map[col].top();
            map[col].pop();

            if(s.empty()){
                s.push(pick);
                continue;
            }
            if(s.top() == pick){
                s.pop();
                answer += 2;
            }
            else
                s.push(pick);
        }
    }
    return answer;
}
int main() {
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {0, 0, 1, 0, 3},
                                 {0, 2, 5, 0, 1},
                                 {4, 2, 4, 4, 2},
                                 {3, 5, 1, 3, 1}};
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};
    cout << solution(board, moves);
}