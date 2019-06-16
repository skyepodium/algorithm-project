#include <iostream>
#include <vector>
#include <algorithm>
#define max_int 101
#define max_val 1073741824
#define limit_time 32
using namespace std;

int t, n, r, a, b, c, d, c_time;
struct info{
    int ax;
    int ay;
    int bx;
    int by;
    int a_death;
    int b_death;
    int t_death;
};

vector<info> v;
void init(){
    c_time = 0;
    r = max_val;
    v.clear();
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3);
void check_same_position();
void check_one_line();

bool check(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy){
    int f_check = ccw(ax, ay, bx, by, cx, cy)*ccw(ax, ay, bx, by, dx, dy);
    int s_check = ccw(cx, cy, dx, dy, ax, ay)*ccw(cx, cy, dx, dy, bx, by);
    if(f_check == 0 && s_check == 0){
        pair<int, int> p1 = make_pair(ax, ay);
        pair<int, int> p2 = make_pair(bx, by);
        pair<int, int> p3 = make_pair(cx, cy);
        pair<int, int> p4 = make_pair(dx, dy);
        
        if(p1 > p2) swap(p1, p2);
        if(p3 > p4) swap(p3, p4);
        
        return p1 <= p4 && p3 <= p2;
    }
    return f_check <= 0 && s_check <= 0;
}

void check_cross_line(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            int ax = v[i].ax;
            int ay = v[i].ay;
            int bx = v[i].bx;
            int by = v[i].by;
            int a_death = v[i].a_death;
            int b_death = v[i].b_death;
            
            int cx = v[j].ax;
            int cy = v[j].ay;
            int dx = v[j].bx;
            int dy = v[j].by;
            int c_death = v[j].a_death;
            int d_death = v[j].b_death;
            
            if(a_death >= c_time && b_death >= c_time && c_death >= c_time && d_death >= c_time){
                if(check(ax, ay, bx, by, cx, cy, dx, dy)){
                    v[i].a_death = c_time;
                    v[i].b_death = c_time;
                    v[j].a_death = c_time;
                    v[j].b_death = c_time;
                }
            }
        }
    }
}



int main(){
    scanf("%d", &t);

    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);
        
        init();
        
        for(int i=1; i<=n; i++){
            scanf("%d %d %d %d", &a, &b, &c, &d);
            v.push_back({a, b, c, d, limit_time, limit_time, limit_time});
        }
        
        for(int w=0; w<limit_time; w++){
            cout << endl;
            cout << "c_time " << c_time << endl;
            for(int i=0; i<n; i++){
                cout << v[i].ax << " " << v[i].ay << " "<< v[i].bx << " "<<v[i].by << endl;
            }
            cout << endl;
            
            check_same_position();
            
            check_one_line();
            
            check_cross_line();
//            for(int i=0; i<v.size(); i++){
//                int a_death = v[i].a_death;
//                int b_death = v[i].b_death;
//                if(v[i].t_death == limit_time && (a_death < limit_time || b_death < limit_time)){
//                    cout << "asdf" << endl;
//                }
//            }

            int total = n;
            
            for(int i=0; i<v.size(); i++){
                int a_death = v[i].a_death;
                int b_death = v[i].b_death;
                if(v[i].t_death == limit_time && (a_death < limit_time || b_death < limit_time)){
                    v[i].t_death = c_time;
                    total--;
                }
            }
            
            if(total == 0){
                break;
            }
            
            // 이동
            for(int i=0; i<n; i++){
                int t_death = v[i].t_death;
                if(t_death == limit_time){
                    v[i].ax /= 2;
                    v[i].ay /= 2;
                    v[i].bx /= 2;
                    v[i].by /= 2;
                }
            }
            
            if(w==10){
                for(int i=0; i<n; i++){
                    int t_death = v[i].t_death;
                    if(t_death == limit_time){
                        int ax = v[i].ax;
                        int ay = v[i].ay;
                        int bx = v[i].bx;
                        int by = v[i].by;
                        if(ax > 0 && ay <0){
                            v[i].ax = v[i].ax * -1;
                        }
                        if(bx > 0 && by <0){
                            v[i].bx = v[i].bx * -1;
                        }
                    }
                }
            }
            else if(w==20){
                for(int i=0; i<n; i++){
                    int t_death = v[i].t_death;
                    if(t_death == limit_time){
                        int ax = v[i].ax;
                        int ay = v[i].ay;
                        int bx = v[i].bx;
                        int by = v[i].by;
                        if(ax < 0 && ay <0){
                            v[i].ay = v[i].ay * -1;
                        }
                        if(bx < 0 && by <0){
                            v[i].by = v[i].by * -1;
                        }
                    }
                }
            }else if(w==30){
                for(int i=0; i<n; i++){
                    int t_death = v[i].t_death;
                    if(t_death == limit_time){
                        int ax = v[i].ax;
                        int ay = v[i].ay;
                        int bx = v[i].bx;
                        int by = v[i].by;
                        if(ax < 0 && ay > 0){
                            v[i].ax = v[i].ax * -1;
                        }
                        if(bx < 0 && by > 0){
                            v[i].bx = v[i].bx * -1;
                        }
                    }
                }
            }
            
            
            c_time++;
        }
        
        printf("#%d ", test_case);
        for(int i=0; i<v.size(); i++){
            printf("%d ", v[i].t_death);
        }
        printf("\n");
    }
}


int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    int temp = x1*y2 + x2*y3 + x3*y1;
    temp = temp - y1*x2-y2*x3-y3*x1;
    
    if(temp > 0) return 1;
    else if(temp < 0) return -1;
    else return 0;
}

void check_same_position() {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            int ax = v[i].ax;
            int ay = v[i].ay;
            int bx = v[i].bx;
            int by = v[i].by;
            int a_death = v[i].a_death;
            int b_death = v[i].b_death;

            int cx = v[j].ax;
            int cy = v[j].ay;
            int dx = v[j].bx;
            int dy = v[j].by;
            int c_death = v[j].a_death;
            int d_death = v[j].b_death;

            if(a_death >= c_time && c_death >= c_time){
                if(ax==cx && ay==cy){
                    v[i].a_death = c_time;
                    v[j].a_death = c_time;
                }
            }
            
            if(a_death >= c_time && d_death >= c_time){
                if(ax==dx && ay==dy){
                    v[i].a_death = c_time;
                    v[j].b_death = c_time;
                }
            }

            if(b_death >= c_time && c_death >= c_time){
                if(bx==cx && by==cy){
                    v[i].b_death = c_time;
                    v[j].a_death = c_time;
                }
            }

            if(b_death >= c_time && d_death >= c_time){
                if(bx==dx && by==dy){
                    v[i].b_death = false;
                    v[j].b_death = false;
                }
            }
        }
    }
}

void check_one_line(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            int ax = v[i].ax;
            int ay = v[i].ay;
            int bx = v[i].bx;
            int by = v[i].by;
            int a_death = v[i].a_death;
            int b_death = v[i].b_death;
            
            int cx = v[j].ax;
            int cy = v[j].ay;
            int dx = v[j].bx;
            int dy = v[j].by;
            bool c_death = v[j].a_death;
            bool d_death = v[j].b_death;
            
            if(a_death >= c_time && b_death >= c_time && c_death >= c_time){
                int d_x = abs(bx - ax);
                int d_y = abs(by - ay);
                double delta = (double)d_y / d_x;
                double bias = ay - delta*ax;
                
                if(delta*cx+bias == cy){
                    if(ax > bx) swap(ax, bx);
                    if(ay > by) swap(ay, by);
                    if(cx>=ax && cx<=bx && cy>=ay && cy<=by){
                        v[i].a_death = c_time;
                        v[i].b_death = c_time;
                        v[j].a_death = c_time;
                    }
                }
            }
            
            if(a_death >= c_time && b_death >= c_time && d_death >= c_time){
                int d_x = abs(bx - ax);
                int d_y = abs(by - ay);
                double delta = (double)d_y / d_x;
                double bias = ay - delta*ax;
                
                if(delta*dx+bias == dy){
                    if(ax > bx) swap(ax, bx);
                    if(ay > by) swap(ay, by);
                    if(dx>=ax && dx<=bx && dy>=ay && dy<=by){
                        v[i].a_death = c_time;
                        v[i].b_death = c_time;
                        v[j].b_death = c_time;
                    }
                }
            }
            
            if(c_death >= c_time && d_death >= c_time && a_death >= c_time){
                int d_x = abs(dx - cx);
                int d_y = abs(dy - cy);
                double delta = (double)d_y / d_x;
                double bias = cy - delta*cx;
                
                if(delta*ax+bias == ay){
                    if(cx > dx) swap(cx, dx);
                    if(cy > dy) swap(cy, dy);
                    if(ax>=cx && ax<=dx && ay>=cy && ay<=dy){
                        v[j].a_death = c_time;
                        v[j].b_death = c_time;
                        v[i].a_death = c_time;
                    }
                }
            }
            
            if(c_death >= c_time && d_death >= c_time && b_death >= c_time){
                int d_x = abs(dx - cx);
                int d_y = abs(dy - cy);
                double delta = (double)d_y / d_x;
                double bias = cy - delta*cx;
                
                if(delta*bx+bias == by){
                    if(cx > dx) swap(cx, dx);
                    if(cy > dy) swap(cy, dy);
                    if(bx>=cx && bx<=dx && by>=cy && by<=dy){
                        v[j].a_death = c_time;
                        v[j].b_death = c_time;
                        v[i].b_death = c_time;
                    }
                }
            }
        }
    }
}
