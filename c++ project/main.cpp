#include <iostream>

using namespace std;

int main()
{
    int player[5];
    for(int i=0; i<5; i++){
        player[i] = 0;
    }
    
    bool check[3];
    for(int i=0; i<3; i++){
        check[i] = false;
    }
    
    for(int i=0; i < 5; i++){
        cin >> player[i];
        check[player[i]-1] = true;
    }
    
    int num_cnt = 0;
    int num_blank = 0;
    for(int i=0; i<3; i++){
        if(check[i] == true) num_cnt++;
        else num_blank = i+1;
    }
    
    int winner = 0;
    int winner_num = 0;
    if(num_cnt == 3 || num_cnt == 1) winner = 0;
    else{
        if(num_blank == 1) winner_num = 3;
        else if(num_blank == 2) winner_num = 1;
        else winner_num = 2;
        
        for(int i=0; i<5; i++){
            if(winner_num == player[i]) winner++;
        }
    }
    
    cout << winner << endl;
    return 0;
}


