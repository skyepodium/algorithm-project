#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string n;
vector<int> result;

int main(){
    cin >> n;

    int size = (int)n.size();

    int idx = 0;
    int temp = 0;
    for(int i=size-1; i>=0; i--){
        if(idx==3){
            result.push_back(temp);
            temp = 0;
            idx = 0;
        }
        temp = temp + (n[i] - '0') * pow(2, idx);
        idx++;
    }
    result.push_back(temp);
    for(int i=(int)result.size() - 1; i>=0; i--){
        printf("%d", result[i]);
    }
    printf("\n");
}