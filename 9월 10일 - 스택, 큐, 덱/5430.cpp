//
// Created by user on 2021-09-14.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

deque<int> makeDq(string arr){
    string temp;
    deque<int> dq;

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
    return dq;
}

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

        deque<int> dq = makeDq(arr);

        bool is_reversed = false; //뒤집혔는지 검사
        bool is_error= false; //에러인지 검사

        for(int i=0; i<func.length(); i++)
        {
            //뒤집기 두번 쓰일 수 있어서 *true로 만드는게 아니라 있던걸 반대로 해야함..ㅡㅡ
            if (func[i]=='R')
                is_reversed = !is_reversed;
            else //'D'일때
            {
                if (dq.empty()) //비어있으면 뺄 게 없어서 에러
                {
                    is_error = true;
                    cout << "error\n";
                    break;
                }
                else //비어있지 않고
                    if(is_reversed) //뒤집혀있으면
                        dq.pop_back(); //뒤에서 뺌
                    else // 그대로면
                        dq.pop_front(); //앞에서 뺌
            }
        }

        if(!is_error){
            cout << "[";
            while(!dq.empty()){
                if(is_reversed){
                    cout << dq.back(); //뒤에서 빼서 출력
                    dq.pop_back();
                }
                else {
                    cout << dq.front(); //앞에서 빼서 출력
                    dq.pop_front();
                }
                if (!dq.empty())
                    cout << ",";
            }
            cout << "]\n";
        }
    }
    return 0;
}
