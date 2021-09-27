//
// Created by user on 2021-09-25.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> triangle;

void chooseTriangle(){
    int n=1;
    while(((n*(n+1))/2)<1000){
        triangle.push_back((n*(n+1))/2);
        n++;
    }
}

bool checkTriangle(int sum) {
    for (int i = 0; i < triangle.size(); i++)
        for (int j = 0; j < triangle.size(); j++)
            for (int k = 0; k < triangle.size(); k++)
                if (triangle[i] + triangle[j] + triangle[k] == sum)
                    return true;
    return false;
}

int main(){
    int t;
    cin >> t;

    //1000보다 작은 삼각수를 미리 모아놓음
    chooseTriangle();

    while(t--){
        int sum;
        cin >> sum;

        cout << checkTriangle(sum) << "\n";
    }
    return 0;
}

