#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    int max_people = 0;
    int people = 0;
    
    int in_people;
    int out_people;
    
    for(int i=0; i<4; i++){
        cin >> out_people;
        cin >> in_people;
        
        people = people + in_people - out_people;
        max_people = max(people, max_people);
    }
    
    cout << max_people << endl;
}
