#include <iostream>
#include <algorithm>

#define max_val 2147483647

using namespace std;

int n;
int cur[3];
int min_array[3];
int max_array[3];

int min_array2[3];
int max_array2[3];

int main(){
    scanf("%d", &n);
    
    for(int i=0; i<3; i++){
        scanf("%d", &cur[i]);
        min_array[i] = cur[i];
        max_array[i] = cur[i];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &cur[j]);
            
        }
        
        min_array2[0] = min(min_array[0], min_array[1]) + cur[0];
        min_array2[1] = min(min_array[0], min(min_array[1], min_array[2])) + cur[1];
        min_array2[2] = min(min_array[1], min_array[2]) + cur[2];

        max_array2[0] = max(max_array[0], max_array[1]) + cur[0];
        max_array2[1] = max(max_array[0], max(max_array[1], max_array[2])) + cur[1];
        max_array2[2] = max(max_array[1], max_array[2]) + cur[2];
        
        for(int j=0; j<3; j++){
            min_array[j] = min_array2[j];
            max_array[j] = max_array2[j];
        }
    }
    
    printf("%d %d\n", max(max_array[0], max(max_array[1], max_array[2])), min(min_array[0], min(min_array[1], min_array[2])));
    
}
