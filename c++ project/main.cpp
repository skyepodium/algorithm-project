#include <iostream>

using namespace std;

int main() {

    int a;
    scanf("%d", &a);
    int *p;
    p = new int[a];
    
    for(int i=0; i<a; i++){
        scanf("%d", &p[i]);
    }
    
    int b;
    cin >> b;
    
    for(int i=0; i<b; i++){
        int c;
        scanf("%d", &c);
        bool check = false;
        for(int j=0; j<a; j++){
            if(c==p[j]){
                check = true;
            }
        }
        if(check == true){
            printf("%d\n", 1);
        }else{
            printf("%d\n", 0);
        }
    }
}
