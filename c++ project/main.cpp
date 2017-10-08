#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
#include <math.h>
using namespace std;

int** read_table(int **pDataset, int nVoters, int nElections){
    
    //2차원 배열 동적할당
    pDataset = new int* [nElections];
    
    for(int nIndex = 0; nIndex < nElections; nIndex++){
        pDataset[nIndex] = new int[nVoters];
        //*(pDataset+nIndex) = new int[nVoters];
    }

    //cin을 통해 pDataset에 도표를 입력받는다.
    for(int i=0; i<nElections; i++){
        for(int j=0; j<nVoters; j++){
            cin>>pDataset[i][j];
        }
    }
    
    return pDataset;
}

double* nomalize_T(double *T, int nVoters){

    //T에 1차원 배열 동적할당
    T = new double[nVoters];
    
    //수식 1에 의해 투표자에 대한 신뢰도(trustiness of a voter)를 전부 1로 초기화한다.
    for(int i=0; i < nVoters; i++){
        T[i] = 1;
    }
    
    return T;
}

double** nomalize_rho(double **rho, int **pDataset, int nVoters, int nElections, double *T){

    //rho동적 공간 할당 5*6
    rho = new double* [5];
    
    for(int nIndex = 0; nIndex < 5; nIndex++){
        rho[nIndex] = new double[nElections];
    }
    
    
    //rho 초기화
    for(int i=0; i<5; i++){
        for(int j=0; j<nElections; j++){
            rho[i][j] = 0;
        }
    }
    
    //갯수 체크해서 rho에 넣기
    for(int i=0; i<nElections; i++){
        for(int num=0; num<5; num++){
            for(int j=0; j<nVoters; j++){
                if(pDataset[i][j] == num+1){
                    rho[num][i] = rho[num][i] + 1;
                }
            }
        }
    }

    //제곱값 배열 초기화
    double square_array[6] = {0,0,0,0,0,0};

    //제곱값 배열 계산
    for(int i=0; i<nElections; i++){
        for(int j=0; j<5; j++){
            square_array[i] = square_array[i] + rho[j][i]*rho[j][i];
        }
    }

    //수식 2번 계산
    for(int j=0; j<nElections; j++){
        for(int i=0; i<5; i++){
            rho[i][j] = rho[i][j]*T[i]/sqrt(square_array[j]);
            rho[i][j] = roundf(rho[i][j]*100)/100;
        }
    }
    
    //출력
    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
//            cout<<rho[i][j]<<" ";
            printf("%4.2f ", rho[i][j]);
        }
        cout<<endl;
    }
    
    
    return rho;
}

double* renew_T(double **rho, int **pDataset, int nVoters, int nElections, double *T){

    //1. 먼저 T의 요소를 전부 0으로 바꾼다.
    for(int i=0; i<nVoters; i++){
        T[i] = 0;
    }
    
    //2. 투표자가 투표한 아이템의 신뢰도를 더해 투표자의 신뢰도를 계산한다.
    for(int i=0; i<nVoters; i++){
        for(int j=0; j<nElections; j++){
            T[i] = T[i] + rho[pDataset[j][i] - 1][j];
        }
    }

    return T;
}


int main(){
    //*****
    //1번문제
    //*****
    
    //도표를 넣을 2차원 포인터 변수 pDataset
    int **pDataset;
    //투표자의 수 nVoters, 영화의 수 nElections
    int nVoters, nElections;
    cin>>nVoters>>nElections;
    
    //read_table함수를 통해, pDataset의 2차원 배열을 동적으로 할당하고 다시 받는다.
    pDataset = read_table(pDataset, nVoters, nElections);

    //*****
    //2번문제
    //*****
    
    //투표자에 대한 신뢰도(trustiness of a voter)를 담을 변수 T 선언, 투표자 수는 nVoters, 따라서 T는 1차원 배열이다.
    double *T;
    //nomailize_T함수(1번 수식)를 통해 1차원 배열을 동적할당하고, 투표자에 대한 신뢰도를 전부 1로 초기화한다.
    T = nomalize_T(T, nVoters);
    
    //pli를 담을 2차원 포인터 변수 rho
    double **rho;
    //nomalize_rho함수(2번 수식)을 통해 rho를 초기화한다.
    rho = nomalize_rho(rho, pDataset, nVoters, nElections, T);

    //*****
    //3번문제
    //*****
    
    //투표자에 대한 신뢰도(trustiness of a voter) T갱신
    //투표자에 대한 신뢰도는 투표자가 투표한 아이템의 신뢰도를 더한다.
    T = renew_T(rho, pDataset, nVoters, nElections, T);
    

}


