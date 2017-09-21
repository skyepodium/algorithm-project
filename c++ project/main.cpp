#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <time.h>
using namespace std;

double FindClosesetPoint(double array[], int size, double target, double &closestPT);

int main(){
    const int size = 5;
    double pSameple[size] = {0.3, 0.6, 0.1, 0.4, 0.8};
    
    double target;
    cout<<"0에서 1까지의 double형 숫자를 하나 입력해주세요: ";
    cin>>target;
 
    double diff, closesetPt;
    diff = FindClosesetPoint(pSameple, size, target, closesetPt);
    
}

double FindClosesetPoint(double array[], int size, double target, double &closestPT){
    
    double diff;
    for(int i=0; i< size; i++){
        array[i];
    }
    return diff;
}

