#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string num;
        cin >> num;
        
        bool is_possible = true;

        
        int month = (num[4] - 48) * 10 + (num[5] - 48);
        
        if(month <= 0 || month >= 13) is_possible = false;
        
        int day = (num[6] - 48) * 10 + (num[7] - 48);
        
        if(month == 1){
            if(day<1 || day > 31) is_possible = false;
        }

        if(month == 2){
            if(day<1 || day > 28) is_possible = false;
        }

        if(month == 3){
            if(day<1 || day > 31) is_possible = false;
        }

        if(month == 4){
            if(day<1 || day > 30) is_possible = false;
        }

        if(month == 5){
            if(day<1 || day > 31) is_possible = false;
        }

        if(month == 6){
            if(day<1 || day > 30) is_possible = false;
        }

        if(month == 7){
            if(day<1 || day > 31) is_possible = false;
        }

        if(month == 8){
            if(day<1 || day > 31) is_possible = false;
        }

        if(month == 9){
            if(day<1 || day > 30) is_possible = false;
        }

        if(month == 10){
            if(day<1 || day > 31) is_possible = false;
        }

        if(month == 11){
            if(day<1 || day > 30) is_possible = false;
        }

        if(month == 12){
            if(day<1 || day > 31) is_possible = false;
        }

        cout << "#" << test_case << " ";
        if(is_possible){
            for(int i=0; i<4; i++){
                cout << num[i];
            }
            cout << "/";
            for(int i=4; i<6; i++){
                cout << num[i];
            }
            cout << "/";
            for(int i=6; i<8; i++){
                cout << num[i];
            }
            cout << endl;
        }else{
            cout << -1 << endl;
        }
        
        
    }
    return 0;
}
