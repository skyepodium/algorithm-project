#include <iostream>

using namespace std;

double a, b;
double result1, result2;
void go1(int idx, double p, int cnt){

    if(idx == 18){

        if(cnt != 2 && cnt !=3 && cnt !=5 && cnt !=7 && cnt != 11 && cnt!= 13 && cnt !=17){
            result1 += p;
        }

        return;
    }

    go1(idx+1, p*a, cnt+1);
    go1(idx+1, p*(1-a), cnt);
}

void go2(int idx, double p, int cnt){

    if(idx == 18){

        if(cnt != 2 && cnt !=3 && cnt !=5 && cnt !=7 && cnt != 11 && cnt!= 13 && cnt !=17){
            result2 += p;
        }

        return;
    }

    go2(idx+1, p*b, cnt+1);
    go2(idx+1, p*(1-b), cnt);
}

int main(){
    a = 12*0.01;
    b = 89*0.01;
    go1(0, 1, 0);
    go2(0, 1, 0);
    cout << (1-result1) * (1-result2) << endl;
    printf("%.16f\n", 1-(result1*result2));
}