#include <iostream>
#include <cmath>
#define max_val 10001
#define EPSILON 1e-9
using namespace std;

int n;
struct info {
    double x, y;
};
double cross(info a, info b){
    return a.x * b.y - a.y * b.x;
}

info operator * (info a, double val){
    return {a.x * val, a.y * val};
}

info operator + (info a, info b) {
    return {b.x + a.x, b.y + a.y};
}

info operator - (info a, info b) {
    return {a.x - b.x, a.y - b.y};
}

info a, b, c, d, result;
double x, y;

double ccw(const info&r, const info&p, const info&q) {
    return cross(p - r, q - r);
}

bool lineIntersection(info a, info b, info c, info d, info&x) {
    double det = cross(b - a, d - c);
    if (fabs(det) < EPSILON)return false;
    x = a + (b-a)*(cross(c - a, d - c) / det);
    return true;
}
int main(){
    scanf("%d", &n);
    
    for(int test_case=1; test_case<=n; test_case++){
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
        if (lineIntersection(a, b, c, d, result)) {
            printf("POINT %.2lf %.2lf\n", result.x, result.y);
        }
        else {
            double ab = ccw(a, b, c)*ccw(a, b, d);
            double cd = ccw(c, d, a)*ccw(c, d, b);
            if (fabs(ab) < EPSILON && fabs(cd) < EPSILON)
                printf("LINE\n");
            else
                printf("NONE\n");
        }
    }
}
