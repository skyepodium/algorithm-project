#include <iostream>

using namespace std;

int x1, y1, x2, y2, x3, y3;

int ccw(int x1,  int y1, int x2, int y2, int x3, int y3){
    
    int result = 0;
    int first = x1*y2 + x2*y3 + x3*y1;
    int second = x2*y1 + x3*y2 + x1*y3;
    result = first - second;
    if(result > 0){
        return 1;
    }else if(result == 0){
        return 0;
    }else{
        return -1;
    }
}


int main(){
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    printf("%d\n", ccw(x1, y1, x2, y2, x3, y3));
}
