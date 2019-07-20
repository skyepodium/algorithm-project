#include <iostream>

using namespace std;

int t;
double d, a, b, f, t_hour;

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%lf %lf %lf %lf", &d, &a, &b, &f);
        
        t_hour = d / (a + b);
        
        printf("#%d %lf\n", test_case, t_hour * f);
    }
}
