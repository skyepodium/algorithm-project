#include <iostream>
#include <cmath>
#define max_val 10001
using namespace std;
double const EPSILON = 1e-9;
int n;


struct info {
    double x, y;
    explicit info(double x_ = 0, double y_ = 0) :x(x_), y(y_) {
        
    }
    bool operator ==(const info&rhs)const {
        return x == rhs.x && y == rhs.y;
    }
    bool operator < (const info&rhs)const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }
    info operator +(const info&rhs)const {
        return info(x + rhs.x, y + rhs.y);
    }
    info operator -(const info&rhs)const {
        return info(x - rhs.x, y - rhs.y);
    }
    //* operator는 info 뒤에 곱해야 한다.
    info operator *(double rhs)const {
        return info(rhs*x, rhs*y);
    }
    double norm()const {
        return hypot(x, y);
    }
    info normalize()const {
        return info(x / norm(), y / norm());
    }
    double dot(const info&rhs)const {
        return x * rhs.x + y * rhs.y;
    }
    double cross(const info&rhs)const {
        return x * rhs.y - y * rhs.x;
    }
    info project(const info&rhs)const {
        info r = rhs.normalize();
        return r*r.dot(*this);
    }
};
info a, b, c, d;
double x, y;

int ccw(info r, info p, info q){
    double first = (p.x - r.x) * (q.y - r.y);
    double second = (p.y - r.y) * (q.x - r.x);
    double result = first - second;
    
    if(result > 0) return 1;
    else if(result == 0) return 0;
    else return -1;
}

bool lineIntersection(info a, info b, info c, info d, info&x) {
    double det = (b - a).cross(d - c);
    if (fabs(det) < EPSILON)return false;
    x = a + (b-a)*((c - a).cross(d - c) / det);
    return true;
}
int main(){
    scanf("%d", &n);
    
    for(int test_case=1; test_case<=n; test_case++){
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
        info result;
        if (lineIntersection(a, b, c, d, result)) {
            printf("POINT %.2lf %.2lf\n", result.x, result.y);
        }
        else {
            double ab = ccw(a, b, c)*ccw(a, b, d);
            double cd = ccw(c, d, a)*ccw(c, d, b);
            if (fabs(ab) < EPSILON&&fabs(cd) < EPSILON)
                printf("LINE\n");
            else
                printf("NONE\n");
        }
    }
}
