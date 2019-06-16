#include <iostream>
#include <vector>
#include <cmath>
#define max_int 101
#define limit_time 32
using namespace std;
typedef pair<double, double> pi;

int t, n, c_time;
double q, w, e, r;

struct info{
    double ax;
    double ay;
    double bx;
    double by;
    int t_death;
};
vector<info> v;

void init(){
    v.clear();
}

int ccw(pi a, pi b, pi c) {
    double r = a.first*b.second + b.first*c.second + c.first*a.second;
    r -= a.second*b.first + b.second*c.first + c.second*a.first;
    if (r > 0) return 1;
    if (r < 0) return -1;
    return 0;
}

void check_same_position();
void check_one_line();

double cross(pi a, pi b, pi c, pi d) {
    double r1 = ccw(a,b,c)*ccw(a,b,d);
    double r2 = ccw(c,d,a)*ccw(c,d,b);
    if (!r1 && !r2) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return c<=b && a<=d;
    }
    return r1<=0 && r2<=0;
}

void check_cross_line();

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);
        
        // 0. init
        init();
        
        // 1. insert
        for(int i=0; i<n; i++){
            scanf("%lf %lf %lf %lf", &q, &w, &e, &r);
            v.push_back({q, w, e, r, limit_time});
        }
        
        //2. for loop 0 ~ 31
        for(c_time=0; c_time<limit_time; c_time++){
//            cout << c_time << endl;
//            for(int i=0; i<n; i++){
//                cout << v[i].ax << " " << v[i].ay << " " << v[i].bx << " " << v[i].by << " " << v[i].t_death << endl;
//            }
//            cout << endl;
            
            // 1) check_same_position
            check_same_position();
//            cout << "check_same_position c_time " << c_time << endl;
//            for(int i=0; i<n; i++){
//                cout << v[i].t_death << endl;
//            }
//            cout << endl;
            
            // 2) check_one_line
            check_one_line();
//            cout << "check_one_line c_time" << c_time << endl;
//            for(int i=0; i<n; i++){
//                cout << v[i].t_death << endl;
//            }
//            cout << endl;

            // 3) check_cross_line
            check_cross_line();
//            cout << "check_cross_line" << endl;
//            for(int i=0; i<n; i++){
//                cout << v[i].t_death << endl;
//            }
//            cout << endl;

            // 4) check_remain
            int total_cnt = n;
            for(int i=0; i<n; i++){
                if(v[i].t_death != limit_time){
                    total_cnt--;
                }
            }
            if(total_cnt == 0) break;
            
            // 5) move
            for(int i=0; i<n; i++){
                if(v[i].t_death == limit_time){
                    int ax = v[i].ax;
                    int ay = v[i].ay;
                    int bx = v[i].bx;
                    int by = v[i].by;
                    ax /= 2;
                    ay /= 2;
                    bx /= 2;
                    by /= 2;
                    v[i].ax = ax;
                    v[i].ay = ay;
                    v[i].bx = bx;
                    v[i].by = by;
                }
            }
            
            if(c_time == 10){
                for(int i=0; i<n; i++){
                    if(v[i].t_death == limit_time){
                        int ax = v[i].ax;
                        int ay = v[i].ay;
                        int bx = v[i].bx;
                        int by = v[i].by;
                        
                        if(ax > 0 && ay < 0){
                            v[i].ax *= -1;
                        }
                        
                        if(bx > 0 && by < 0){
                            v[i].bx *= -1;
                        }
                    }
                }
            }else if(c_time == 20){
                for(int i=0; i<n; i++){
                    if(v[i].t_death == limit_time){
                        int ax = v[i].ax;
                        int ay = v[i].ay;
                        int bx = v[i].bx;
                        int by = v[i].by;
                        
                        if(ax < 0 && ay < 0){
                            v[i].ay *= -1;
                        }
                        
                        if(bx < 0 && by < 0){
                            v[i].by *= -1;
                        }
                    }
                }
            }else if(c_time == 30){
                for(int i=0; i<n; i++){
                    if(v[i].t_death == limit_time){
                        int ax = v[i].ax;
                        int ay = v[i].ay;
                        int bx = v[i].bx;
                        int by = v[i].by;
                        
                        if(ax < 0 && ay > 0){
                            v[i].ax *= -1;
                        }
                        
                        if(bx < 0 && by > 0){
                            v[i].bx *= -1;
                        }
                    }
                }
            }
            
        }
        
        // output
        printf("#%d ", test_case);
        for(int i=0; i<n; i++){
            printf("%d ", v[i].t_death);
        }
        printf("\n");
    }
}

void check_same_position(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            
            double ax = v[i].ax;
            double ay = v[i].ay;
            double bx = v[i].bx;
            double by = v[i].by;
            int f_death = v[i].t_death;
            
            double cx = v[j].ax;
            double cy = v[j].ay;
            double dx = v[j].bx;
            double dy = v[j].by;
            int s_death = v[j].t_death;
            
            if(f_death >= c_time && s_death >= c_time){
                if(ax == cx && ay == cy){
                    v[i].t_death = c_time;
                    v[j].t_death = c_time;
                }
                
                if(ax == dx && ay == dy){
                    v[i].t_death = c_time;
                    v[j].t_death = c_time;
                }
                
                if(bx == cx && by == cy){
                    v[i].t_death = c_time;
                    v[j].t_death = c_time;
                }
                
                if(bx == dx && by == dy){
                    v[i].t_death = c_time;
                    v[j].t_death = c_time;
                }
            }
        }
    }
}

void check_one_line() {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            
            double ax = v[i].ax;
            double ay = v[i].ay;
            double bx = v[i].bx;
            double by = v[i].by;
            int f_death = v[i].t_death;
            
            double cx = v[j].ax;
            double cy = v[j].ay;
            double dx = v[j].bx;
            double dy = v[j].by;
            int s_death = v[j].t_death;
            
            if(f_death >= c_time && s_death >= c_time){
                double d_x = fabs(bx - ax);
                double d_y = fabs(by - ay);
                double delta = d_y / d_x;
                double bias = ay - delta*ax;
                
                if(delta*cx+bias == cy){
                    if(ax > bx) swap(ax, bx);
                    if(ay > by) swap(ay, by);
                    if(cx>=ax && cx<=bx && cy>=ay && cy<=by){
                        v[i].t_death = c_time;
                        v[j].t_death = c_time;
                    }
                }
                
                d_x = abs(bx - ax);
                d_y = abs(by - ay);
                delta = d_y / d_x;
                bias = ay - delta*ax;
                
                if(delta*dx+bias == dy){
                    if(ax > bx) swap(ax, bx);
                    if(ay > by) swap(ay, by);
                    if(dx>=ax && dx<=bx && dy>=ay && dy<=by){
                        v[i].t_death = c_time;
                        v[j].t_death = c_time;
                    }
                }

                d_x = abs(dx - cx);
                d_y = abs(dy - cy);
                delta = d_y / d_x;
                bias = cy - delta*cx;
                
                if(delta*ax+bias == ay){
                    if(cx > dx) swap(cx, dx);
                    if(cy > dy) swap(cy, dy);
                    if(ax>=cx && ax<=dx && ay>=cy && ay<=dy){
                        v[i].t_death = c_time;
                        v[j].t_death = c_time;
                    }
                }
                
                d_x = abs(dx - cx);
                d_y = abs(dy - cy);
                delta = d_y / d_x;
                bias = cy - delta*cx;
                
                if(delta*bx+bias == by){
                    if(cx > dx) swap(cx, dx);
                    if(cy > dy) swap(cy, dy);
                    if(bx>=cx && bx<=dx && by>=cy && by<=dy){
                        v[i].t_death = c_time;
                        v[j].t_death = c_time;
                    }
                }
            }
        }
    }
}

void check_cross_line() {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            
            double ax = v[i].ax;
            double ay = v[i].ay;
            double bx = v[i].bx;
            double by = v[i].by;
            int f_death = v[i].t_death;
            
            double cx = v[j].ax;
            double cy = v[j].ay;
            double dx = v[j].bx;
            double dy = v[j].by;
            int s_death = v[j].t_death;
            
            if(f_death >= c_time && s_death >= c_time){
                if(cross(make_pair(ax, ay), make_pair(bx, by), make_pair(cx, cy), make_pair(dx, dy))){
                    v[i].t_death = c_time;
                    v[j].t_death = c_time;
                }
            }
        }
    }
}
