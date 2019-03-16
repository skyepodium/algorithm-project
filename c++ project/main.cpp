#include <iostream>

using namespace std;

int n, num, base = 0;
char cmd[10];

int main(){
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s", cmd);

        // add
        if(cmd[0] == 'a' && cmd[1] == 'd'){
            scanf("%d", &num);
            base = base | (1<<num);
        }

        // check
        if(cmd[0] == 'c'){
            scanf("%d", &num);
            if(base & (1<<num)) printf("1\n");
            else printf("0\n");
        }

        // remove
        if(cmd[0] == 'r'){
            scanf("%d", &num);
            base = base & ~(1<<num);
        }

        // all
        if(cmd[0] == 'a' && cmd[1] == 'l'){
            base = (1<<21) - 1;
        }

        // empty
        if(cmd[0] == 'e'){
            base = 0;
        }

        if(cmd[0] == 't'){
            scanf("%d", &num);
            if(base & (1<<num)){
                base = base & ~(1<<num);
            }
            else{
                base = base | (1<<num);
            }
        }
    }
}