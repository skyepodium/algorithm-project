#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define max_int 200000001
using namespace std;

int n = 16;
int stations[1] = {9};
int w = 2;
bool check[max_int];

int main(){

    int idx = 0;
    int size = 1;
    int cur = 1;
    int answer = 0;
    int end;
    end = min(stations[idx] - w, n);

    for(int i=0; i<size; i++){
        end = min(stations[idx] - w, n);

        if(cur < end){
            answer++;
            cur = stations[idx] + w + 1;
            idx++;
        }
        else{
            cur = stations[idx] + w + 1;
            idx++;
        }
    }
    cout << answer << endl;

}