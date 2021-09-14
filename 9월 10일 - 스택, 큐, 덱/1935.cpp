//
// Created by user on 2021-09-14.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main() {
    int t;
    cin >> t;

    string func;
    int n;
    string arr;
    deque<int> dq;

    while (t--)
    {
        cin >> func;
        cin >> n;
        cin >> arr;

        //두자리수를 고려해서 string으로 받음
        string temp;
        for(int i=0; i<arr.length(); i++){
            if(arr[i] == '[')
                continue;
            else if ('0' <= arr[i] && arr[i] <='9')
                temp += arr[i];
            else if (arr[i] == ',' || arr[i] == ']') {
                if (!temp.empty()) {
                    dq.push_back(stoi(temp));
                    temp.clear();
                }
            }
        }

        bool isReversed = false; //뒤집혔는지 검사
        bool isError= false; //에러인지 검사

        for(int i=0; i<func.length(); i++)
        {
            //뒤집기 두번 쓰일 수 있어서 *true로 만드는게 아니라 있던걸 반대로 해야함..ㅡㅡ
            if (func[i]=='R')
                isReversed = !isReversed;
            else //'D'일때
            {
                if (dq.empty()) //비어있으면 뺄 게 없어서 에러
                {
                    isError = true;
                    cout << "error\n";
                    break;
                }
                else //비어있지 않고
                    if(isReversed) //뒤집혀있으면
                        dq.pop_back(); //뒤에서 뺌
                    else // 그대로면
                        dq.pop_front(); //앞에서 뺌
            }
        }

        //에러가 안났고
        if (!isError) {
            //뒤집혀있지 않으면
            if (!isReversed) {
                cout << "[";
                while (!dq.empty()) {
                    cout << dq.front(); //앞에서 빼서 출력
                    dq.pop_front();
                    if (!dq.empty())
                        cout << ",";
                }
                cout << "]\n";
            }
            //뒤집혀 있으면
            else
            {
                cout << "[";
                while (!dq.empty()) {
                    cout << dq.back(); //뒤에서 빼서 출력
                    dq.pop_back();
                    if (!dq.empty())
                        cout << ",";
                }
                cout << "]\n";
            }
        }
    }
    return 0;
}
