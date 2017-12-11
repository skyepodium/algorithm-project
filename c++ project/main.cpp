#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    
    if(b==0){
        return a;
    }else{
        return gcd(b, a%b);
    }
    
}


int main() {
    
    int n;
    scanf("%d", &n);
    
    vector<int> dif;

    int first = 0;
    while(n--){
        int a;
        scanf("%d", &a);
        if(first == 0){
            first = a;
        }else{
            dif.push_back(abs(a-first));
            first = a;
        }
    }
    
    
    int result = dif[0];
    
    if(dif.size() > 1){
        result = dif[0];
        for(int i=1; i<dif.size(); i++){
            result = gcd(result, dif[i]);
        }

    }
    
    
    for(int i=2; i<=result/2; i++){
        if(result%i == 0){
            printf("%d ", i);
        }
    }
    printf("%d\n", result);
}

