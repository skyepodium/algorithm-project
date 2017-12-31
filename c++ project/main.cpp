#include <iostream>
#include <string>
#include <math.h>

using namespace std;

double grade_array[13] = {4.3, 4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 1.3, 1.0, 0.7, 0.0};

double cal_result(double num, string grade){
    
    double sum = 0;
    
    if(grade == "A+"){
        sum = num*grade_array[0];
    }else if(grade == "A0"){
        sum = num*grade_array[1];
    }else if(grade == "A-"){
        sum = num*grade_array[2];
    }else if(grade == "B+"){
        sum = num*grade_array[3];
    }else if(grade == "B0"){
        sum = num*grade_array[4];
    }else if(grade == "B-"){
        sum = num*grade_array[5];
    }else if(grade == "C+"){
        sum = num*grade_array[6];
    }else if(grade == "C0"){
        sum = num*grade_array[7];
    }else if(grade == "C-"){
        sum = num*grade_array[8];
    }else if(grade == "D+"){
        sum = num*grade_array[9];
    }else if(grade == "D0"){
        sum = num*grade_array[10];
    }else if(grade == "D-"){
        sum = num*grade_array[11];
    }else{
        sum = num*grade_array[12];
    }
    
    
    return sum;
}


int main(){
    
    string name, grade;
    int n;
    double num;
    
    cin >> n;

    double result = 0;
    double sum_num = 0;

    while(n--){
        
        cin >> name >> num >> grade;
        result = result + cal_result(num, grade);
        sum_num += num;
    }
    
    printf("%.2f\n", round((result/sum_num)*100)/100);
}
