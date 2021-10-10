//
// Created by user on 2021-10-08.
//

#include <iostream>

using namespace std;

/*
 * 요철있는 막대기를 접는다고 치면
 * ^-^^---^-
 * 이거는
 * -v--    (up)
 *      |
 * ^-^^   (down)
 * 이런식으로 중간에 공중을 띄워주는 놈이 센터에 있어야하고(즉, 홀수여야함)
 * 센터를 중심으로 각각의 in out특성이 반대여야함
 */

bool checkInOut(string in_out, int start, int end){
    if (start>=end){
        return true;
    }

    int down=start;
    int up=end;

    //cout << down << " " << up << "\n";

    while(down<up){
        if(in_out[down++] == in_out[up--]){
            return false;
        }
    }

    return checkInOut(in_out, start, up-1); //절반씩 접접
}

int main(){
    bool res=false;
    int t;
    cin >> t;

    while(t--){
        string in_out;
        cin >> in_out;

        if(in_out.size() %2==0){
            cout << "NO\n";
            continue;
        }

        res = checkInOut(in_out,0, in_out.size()-1);
        if(res)
            cout<< "YES\n";
        else cout<< "NO\n";
    }
    return 0;
}