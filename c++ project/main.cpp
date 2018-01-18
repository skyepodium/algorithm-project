#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for(int i=0; i<n; i++){
        v[i] = i+1;
    }
    
    do{
        for(int i=0; i<n; i++){
            printf("%d ", v[i]);
        }
        printf("\n");
        
    }while(next_permutation(v.begin(), v.end()));
}
