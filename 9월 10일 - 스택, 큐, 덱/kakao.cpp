//
// Created by user on 2021-09-14.
//
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;

    for(int i=0; i<moves.size();i++){
        //board는 0부터 시작이므로 1 빼줌(moves[i]는 1부터 기재)
        int col = moves[i]-1;
        for(int j=0; j<board.size();j++){
            if(board[j][col] != 0) //인형이 있으면
            {
                //그리고 그 인형이 알고보니 스택탑이랑 같으면
                if(!s.empty()&&s.top()==board[j][col])
                {
                    //폭파시키고 답에 두 개(새로들어간 애+원래있던 애) 넣어줌
                    s.pop();
                    answer +=2;
                }
                //아니면 그냥 스택에 넣어줌
                else
                    s.push(board[j][col]);
                board[j][col]=0; //빼낸 인형자리에는 0넣어주기
                break;
            }
        }
    }
    return answer;
}
