#include <iostream>
#include <vector>
#include <algorithm>
#define max_int 200001
using namespace std;

int n, color, size, color_start[max_int], color_end[max_int], result[max_int], size_cnt[max_int], color_cnt[max_int];
struct info{
    int num;
    int color;
    int size;
};

bool size_cmp(const info &a, const info &b){
    if(a.size == b.size) return a.color < b.color;
    return a.size < b.size;
}

bool color_cmp(const info &a, const info &b){
    if(a.color == b.color) return a.size < b.size;
    return a.color < b.color;
}

vector<info> s, c;

int lower_bound(int start_point, int end_point, int size){
    int start = start_point;
    int end = end_point;
    int mid = 0;
    
//    cout << start << " " << end << " " << size << endl;
    
    while(start <= end){
        mid = (start + end) / 2;
        
        if(c[mid].size < size){
            start = mid + 1;
        }
        else if(c[mid].size == size){
            end = mid - 1;
        }
        else{
            end = mid - 1;
        }
    }
    
    return end + 1;
}

int size_lower_bound(int start_point, int end_point, int size){
    int start = start_point;
    int end = end_point;
    int mid = 0;
    
    while(start <= end){
        mid = (start + end) / 2;
        
        if(s[mid].size < size){
            start = mid + 1;
        }
        else if(s[mid].size == size){
            end = mid - 1;
        }
        else{
            end = mid - 1;
        }
    }
    
    return end + 1;
}

int main(){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d %d", &color, &size);
        s.push_back({i, color, size});
        c.push_back({i, color, size});
    }
    
    sort(s.begin(), s.end(), size_cmp);
    sort(c.begin(), c.end(), color_cmp);
    
    int cur_color = -1;
    for(int i=0; i<n; i++){
        if(c[i].color != cur_color){
            color_end[cur_color] = i-1;
            cur_color = c[i].color;
            color_start[cur_color] = i;
        }
        
        if(i == n-1){
            color_end[cur_color] = i;
        }
    }
    
    int c_cur = 0, s_cur = 0;
    for(int i=0; i<n; i++){
        c_cur += c[i].size;
        color_cnt[i] = c_cur;

        s_cur += s[i].size;
        size_cnt[i] = s_cur;
    }
    
    for(int i=0; i<n; i++){
        info cur = s[i];
        int num = cur.num;
        int color = cur.color;
        int size = cur.size;

        int color_point = lower_bound(color_start[color], color_end[color], size);
        int size_point = size_lower_bound(0, n, size);
        int no_cnt = color_cnt[color_point - 1] - color_cnt[color_start[color] - 1];
//        cout << color_cnt[color_point] << " "<< color_cnt[color_start[color]] << endl;
//        cout << "size "<<size << " " << size_cnt[size_point - 1] << endl;
//        cout << "no_cnt " << no_cnt << endl;
//        cout << endl;

        result[num] = size_cnt[size_point - 1] - no_cnt;
    }
    
    for(int i=0; i<n; i++){
        printf("%d\n", result[i]);
    }
}
