#include <iostream>
#include <vector>
#include <algorithm>

#define  max_int 41
using namespace std;

int n, s;
int a[max_int];
vector<int> first, second;
struct info{
    int val;
    int cnt;
};
vector<info> third;

bool cmp(const info &a, const info &b){
    return a.val < b.val;
}

void go(int idx, int end, int sum, vector<int> &v){
    if(idx == end){
        v.push_back(sum);
        return;
    }
    go(idx+1, end, sum + a[idx], v);
    go(idx+1, end, sum, v);
}

int binary_search(int num){
    int start = 0;
    int end = third.size() - 1;
    int ret = 0;
    while(start <= end){
        int mid = (start + end) / 2;
        if(third[mid].val == num){
            ret = third[mid].cnt;
            break;
        }
        else if(third[mid].val < num){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ret;
}

int main(){
    scanf("%d %d", &n, &s);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    go(0, n/2, 0, first);
    go(n/2, n, 0, second);

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    int cnt = 1;
    int cur = second[0];
    for(int i=1; i<(int)second.size(); i++){
        if(second[i] != cur){
            third.push_back({cur, cnt});
            cnt = 1;
            cur = second[i];
        }
        else{
            cnt++;
        }
        if(i == (int)second.size() - 1){
            third.push_back({cur, cnt});
        }
    }
    sort(third.begin(), third.end(), cmp);

    int result = 0;
    for(int i=0; i<(int)first.size(); i++){
        int num = s - first[i];
        result += binary_search(num);
    }

    if(s == 0) result--;
    printf("%d\n", result);

}