#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a[1001];
//bool check[1001];



int solution(vector<int> &A){
    
    int result =0 ;
    int sum = 0;
    
    for(int i=0; i<A.size()-1; i++){
 
        sum = A[i];
        
        for(int j=i+1; j<A.size(); j++){
            if(A[i]<A[j]){
                sum = sum+A[j];
                cout<<A[j]<<endl;
            }
        }
    }

    
    cout<<sum;
    return result;
}

int main(){
    
    vector<int> A;

    A.push_back(15);
    A.push_back(13);
    A.push_back(5);
    A.push_back(7);
    A.push_back(4);
    A.push_back(10);
    A.push_back(12);
    A.push_back(8);
    A.push_back(2);
    A.push_back(11);
    A.push_back(6);
    A.push_back(9);
    A.push_back(3);
    
    solution(A);
}
