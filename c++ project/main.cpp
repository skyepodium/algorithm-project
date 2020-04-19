#include <iostream>

using namespace std;

int wheel[5], move_dir[5], k, wheel_num, dir, temp_num, is_first_one, is_last_one, result;
char wheel_string[10];

int string_to_int() {
    
    int result = 0;


    for(int i=0; i<8; i++){
        int square_cnt = 7-i;
        int num = wheel_string[i] - '0';
        result += num << square_cnt;
    }
    
    return result;
}

void wheel_rotate(int wheel_num, int dir){
    
    if(dir == 0) return;
    
    // 시계방향
    if(dir == 1) {
        temp_num = wheel[wheel_num] >> 1;
        
        if(wheel[wheel_num] & 1) is_last_one = 1;
        else is_last_one = 0;
        
        wheel[wheel_num] = temp_num & 255;
        
        if(is_last_one) wheel[wheel_num] = wheel[wheel_num] | 128;
    }
    // 반시계 방향
    else{
        temp_num = wheel[wheel_num] << 1;
        
        if(wheel[wheel_num] & 128) is_first_one = 1;
        else is_first_one = 0;

        wheel[wheel_num] = temp_num & 255;

        if(is_first_one) wheel[wheel_num] = wheel[wheel_num] | 1;
    }
}

void right_check() {
    int c_dir = dir;
    for(int i=wheel_num+1; i<=4; i++){
        int c_wheel_num = i;
        int l_wheel_num = i-1;
        int c_wheel_is_one = 0;
        int l_wheel_is_one = 0;

        if(wheel[l_wheel_num] & 32) l_wheel_is_one = 1;
        if(wheel[c_wheel_num] & 2) c_wheel_is_one = 1;

        
        if(c_wheel_is_one != l_wheel_is_one){
            c_dir *= -1;
            move_dir[c_wheel_num] = c_dir;
        }
        else{
            break;
        }
    }
}

void left_check() {
    int c_dir = dir;
    for(int i=wheel_num-1; i>=1; i--){
        int c_wheel_num = i;
        int r_wheel_num = i+1;
        int c_wheel_is_one = 0;
        int r_wheel_is_one = 0;

        if(wheel[c_wheel_num] & 32) c_wheel_is_one = 1;
        if(wheel[r_wheel_num] & 2) r_wheel_is_one = 1;

        if(c_wheel_is_one != r_wheel_is_one){
            c_dir *= -1;
            move_dir[c_wheel_num] = c_dir;
        }
        else{
            break;
        }
    }
}

int main(){
    
    for(int i=1; i<=4; i++) {
        scanf("%s", wheel_string);
        
        int num = string_to_int();
        wheel[i] = num;
    }
   
    scanf("%d", &k);
        
    for(int i=1; i<=k; i++){
        scanf("%d %d", &wheel_num, &dir);

        for(int i=1; i<=4; i++) move_dir[i] = 0;
        
        move_dir[wheel_num] = dir;

        left_check();
        
        right_check();
        
        for(int i=1; i<=4; i++){
            wheel_rotate(i, move_dir[i]);
        }
    }
    
    for(int i=1; i<=4; i++){
        if(wheel[i] & 128){
            result += 1 << (i-1);
        }
    }
    
    printf("%d\n", result);
}
