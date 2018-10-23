#include <iostream>

using namespace std;

int t, n;
char cmd[2];

char box[9][9];
char c_box[9][9];
char cube[6][3][3];
int f_box[4];

void init(){
    for(int k=0; k<6; k++){
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){

                if(k==0) cube[k][i][j] = 'w';
                else if(k==1) cube[k][i][j] = 'y';
                else if(k==2) cube[k][i][j] = 'r';
                else if(k==3) cube[k][i][j] = 'o';
                else if(k==4) cube[k][i][j] = 'g';
                else cube[k][i][j] = 'b';

            }
        }
        
    }
}

int center = -1;
void to_nine(){
    
    for(int k=0; k<4; k++){

        if(k==0){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    box[i][j+3] = cube[f_box[k]][i][j];
                }
            }
        }
        
        else if(k==1){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    box[i+3][j] = cube[f_box[k]][i][j];
                }
            }
        }
        
        else if(k==2){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    box[i+3][j+6] = cube[f_box[k]][i][j];
                }
            }
        }

        else {
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    box[i+6][j+3] = cube[f_box[k]][i][j];
                }
            }
        }
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            box[i+3][j+3] = cube[center][i][j];
        }
    }

}

void copy_nine(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            c_box[i][j] = box[i][j];
        }
    }
}

void from_nine(){
    
    for(int k=0; k<4; k++){
        
        if(k==0){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cube[f_box[k]][i][j] = box[i][j+3];
                }
            }
        }
        
        else if(k==1){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cube[f_box[k]][i][j] = box[i+3][j];
                }
            }
        }
        
        else if(k==2){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cube[f_box[k]][i][j] = box[i+3][j+6];
                }
            }
        }
        
        else {
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cube[f_box[k]][i][j] = box[i+6][j+3];
                }
            }
        }
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cube[center][i][j] = box[i+3][j+3];
        }
    }
    
}

void swipe_nine(){
    copy_nine();
    
    box[2][2] = c_box[6][2];

    box[2][3] = c_box[5][2];
    box[2][4] = c_box[4][2];
    box[2][5] = c_box[3][2];

    box[2][6] = c_box[2][2];

    box[3][6] = c_box[2][3];
    box[4][6] = c_box[2][4];
    box[5][6] = c_box[2][5];

    box[6][6] = c_box[2][6];
    
    box[6][5] = c_box[3][6];
    box[6][4] = c_box[4][6];
    box[6][3] = c_box[5][6];

    box[6][2] = c_box[6][6];

    box[5][2] = c_box[6][5];
    box[4][2] = c_box[6][4];
    box[3][2] = c_box[6][3];

    
    box[3][3] = c_box[5][3];
    box[3][4] = c_box[4][3];
    box[3][5] = c_box[3][3];

    box[4][5] = c_box[3][4];
    box[5][5] = c_box[3][5];
    box[5][4] = c_box[4][5];

    box[5][3] = c_box[5][5];
    box[4][3] = c_box[5][4];

    from_nine();
}

char temp[3][3];

void swipe(int num){
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            temp[i][j] = cube[num][i][j];
        }
    }
    
    cube[num][0][0] = temp[2][0];
    cube[num][0][1] = temp[1][0];
    cube[num][0][2] = temp[0][0];

    cube[num][1][2] = temp[0][1];
    cube[num][2][2] = temp[0][2];
    cube[num][2][1] = temp[1][2];

    cube[num][2][0] = temp[2][2];
    cube[num][1][0] = temp[2][1];

}

void swipe_white(){
    swipe(0);
}

void swipe_yellow(){
    swipe(1);
}

void swipe_red(){
    swipe(2);
}

void swipe_orange(){
    swipe(3);
}

void swipe_green(){
    swipe(4);
}

void swipe_blue(){
    swipe(5);
}



int main(){
    scanf("%d", &t);
    
    while(t--){
        
        //1. 큐브 초기화
        init();
        
        //2. 명령을 입력받는다.
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%s", cmd);
            
            if(cmd[0] == 'w'){
                center = 0;
                //9*9에 복사
                f_box[0] = 3;
                f_box[1] = 4;
                f_box[2] = 5;
                f_box[3] = 1;
                to_nine();
                
                
                if(cmd[1] == '+'){
                    swipe_nine();
                }
                else{
                    int a = 3;
                    while(a--) swipe_nine();
                }
                
            }
            
            else if(cmd[0] == 'L'){
                
                center = 4;

                //9*9에 복사
                f_box[0] = 3;
                f_box[1] = 1;
                f_box[2] = 0;
                f_box[3] = 2;
                
                for(int i=0; i<3; i++)swipe_orange();
                for(int i=0; i<1; i++)swipe_red();
                
                to_nine();
                
                if(cmd[1] == '+'){
                    swipe_nine();
                }
                else{
                    int a = 3;
                    while(a--) swipe_nine();
                }

            }
            
            else if(cmd[0] == 'b'){
                
                center = 5;
                
                //9*9에 복사
                f_box[0] = 3;
                f_box[1] = 0;
                f_box[2] = 1;
                f_box[3] = 2;
                
                for(int i=0; i<1; i++)swipe_orange();
                for(int i=0; i<3; i++)swipe_red();
                
                to_nine();
                
                if(cmd[1] == '+'){
                    swipe_nine();
                }
                else{
                    int a = 3;
                    while(a--) swipe_nine();
                }
                
            }
            
            else if(cmd[0] == 'o'){
                
                center = 3;
                
                //9*9에 복사
                f_box[0] = 1;
                f_box[1] = 4;
                f_box[2] = 5;
                f_box[3] = 0;
                
                for(int i=0; i<2; i++)swipe_yellow();
                swipe_green();
                for(int i=0; i<3; i++)swipe_green();
                
                to_nine();
                
                if(cmd[1] == '+'){
                    swipe_nine();
                }
                else{
                    int a = 3;
                    while(a--) swipe_nine();
                }
                
            }
            
            else if(cmd[0] == 'r'){
                
                center = 2;
                
                //9*9에 복사
                f_box[0] = 0;
                f_box[1] = 4;
                f_box[2] = 5;
                f_box[3] = 1;
                
                for(int i=0; i<3; i++)swipe_green();
                swipe_blue();
                for(int i=0; i<2; i++)swipe_yellow();
                
                to_nine();
                
                if(cmd[1] == '+'){
                    swipe_nine();
                }
                else{
                    int a = 3;
                    while(a--) swipe_nine();
                }
                
            }
            
            else if(cmd[0] == 'y'){
                
                center = 1;
                
                //9*9에 복사
                f_box[0] = 3;
                f_box[1] = 5;
                f_box[2] = 4;
                f_box[3] = 2;
                
                for(int i=0; i<2; i++)swipe_orange();
                for(int i=0; i<2; i++)swipe_red();
                
                to_nine();
                
                if(cmd[1] == '+'){
                    swipe_nine();
                }
                else{
                    int a = 3;
                    while(a--) swipe_nine();
                }
                
            }
            
        }
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                printf("%c", cube[0][i][j]);
            }
            printf("\n");
        }
        
        
    }
    
    
}
