//
// Created by user on 2021-09-18.
//

#include <iostream>
#include <cstring>

using namespace std;

bool visited[21];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M;
    cin >> M;

    for(int i=0; i<M; i++)
    {
        int n;
        string s;
        cin >> s;

        if(s=="add")
        {
            cin >> n;
            visited[n]=true;
        }
        else if(s=="remove")
        {
            cin >> n;
            visited[n]=false;
        }
        else if(s=="check")
        {
            cin >> n;
            cout << visited[n] << "\n";
            /*if (visited[n])
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
            */
        }
        else if (s=="toggle")
        {
            cin >> n;
            visited[n] =!visited[n];
            /*
            if (visited[n])
                visited[n]=false;
            else
                visited[n]=true;
            */
        }
        else if (s=="all")
            memset(visited, true, sizeof(visited));
        else
            memset(visited, false, sizeof(visited));
    }
    return 0;
}