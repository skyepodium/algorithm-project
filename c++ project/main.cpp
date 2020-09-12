#include <string>
#include <vector>
#include <iostream>


using namespace std;

bool checkVal(char a) {
    bool result = false;
    
    if(a>=97 && a <=122) {
        result = true;
    } else if(a>=48 && a<=57) {
        result = true;
    } else if(a==45){
        result = true;
    } else if(a==95) {
        result = true;
    } else if(a==46) {
        result = true;
    }
    
    return result;
}

string solution(string new_id) {
    string answer = "";
    
    int size = (int)new_id.size();
    
    // 1단계
    string first = "";
    for(int i=0; i<size; i++) {
        char a = new_id[i];
        
        if(a >= 65 && a <=90) {
            a += 32;
        }
        first += a;
    }
    
    cout << "first " << first << endl;
    // 2단계
    string second = "";
    for(int i=0; i<size; i++){
        if(checkVal(first[i])) {
            second += first[i];
        }
    }
    cout << "second " << second << endl;

    
    // 3단계
    bool isDot = false;
    string third = "";
    for(int i=0; i<(int)second.size(); i++){
        char cur = second[i];

        bool flag = true;
        if(cur == 46) {
            if(isDot) {
                flag = false;
            } else {
                isDot = true;
            }
        }else{
            isDot = false;
        }

        if(flag){
            third += cur;
        }
    }
    cout << "third " << third << endl;
    
    // 4단계
    string forth = "";
    for(int i=0; i<third.size(); i++) {
        bool flag = true;
        if(i==0 || i== third.size() - 1) {
            if(third[i] == 46) flag = false;
        }
        if(flag) forth += third[i];
    }
    cout << "forth " << forth << endl;

    
    // 5단계
    string fifth = "";
    if(forth.size() == 0) {
        fifth += "a";
    } else{
        fifth = forth;
    }
    
    cout << "fifth " << fifth << endl;

    // 6단계
    string sixth = "";
    if(fifth.size() >= 16){
        for(int i=0; i<15; i++){
            bool flag = true;
            if(i == 14) {
                if(fifth[i] == 46) {
                    flag = false;
                }
            }
            
            if(flag) sixth += fifth[i];
        }
    }else{
        sixth = fifth;
    }
    cout << "sixth " << sixth << endl;

    
    string seventh = "";
    if(sixth.size() <= 2) {
        
        if(sixth.size() == 1) {
            seventh = sixth;
            for(int i=0; i<2; i++){
                seventh += seventh[0];
            }
        }
        else if(sixth.size() == 2) {
            seventh = sixth;
            seventh += seventh[1];
        }

    }else{
        seventh = sixth;
    }
    cout << "seventh " << seventh << endl;

    
    answer = seventh;
    return answer;
}

int main (){
    string result = "";
    
    result = solution("z-+.^.");
    
    cout << result << endl;
}
