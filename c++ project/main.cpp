#include <iostream>
#define max_int 2000001

using namespace std;

int n, num, a[max_int], front = 0, back = 0;
char cmd[5];

int main() {
    scanf("%d", &n);
    
    for(int i=0; i<max_int; i++) a[i] = -1;
    
    for(int i=0; i<n; i++){
        scanf("%s", cmd);
        
        // 1. push
        if(cmd[0] == 'p' && cmd[1] == 'u') {
            scanf("%d", &num);
            a[back++] = num;
        }
        // 2. front
        else if(cmd[0] == 'f') {
            if(front == back) {
                printf("-1\n");
            }
            else {
                printf("%d\n", a[front]);
            }
        }
        // 3. back
        else if(cmd[0] == 'b') {
            if(front == back) {
                printf("-1\n");
            }
            else {
                printf("%d\n", a[back-1]);
            }
        }
        // 4. size
        else if(cmd[0] == 's') {
            printf("%d\n", back - front);
        }
        // 5. empty
        else if(cmd[0] == 'e') {
            if(front == back) {
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }
        else if(cmd[0] == 'p' && cmd[1] == 'o') {
            if(front == back) {
                printf("-1\n");
            }
            else{
                num = a[front];
                a[front] = -1;
                front++;
                
                printf("%d\n", num);
            }
        }
    }
    
}
