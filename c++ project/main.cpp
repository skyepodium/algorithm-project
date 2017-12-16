#include <iostream>
#include <string>

using namespace std;

int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    
    string grade;
    cin >> grade;
    
    if(grade == "A+"){
        cout<<4.3<<endl;
    }else if(grade == "A0"){
        cout<<4.0<<endl;
    }else if(grade == "A-"){
        cout<<3.7<<endl;
    }else if(grade == "B+"){
        cout<<3.3<<endl;
    }else if(grade == "B0"){
        cout<<3.0<<endl;
    }else if(grade == "B-"){
        cout<<2.7<<endl;
    }else if(grade == "C+"){
        cout<<2.3<<endl;
    }else if(grade == "C0"){
        cout<<2.0<<endl;
    }else if(grade == "C-"){
        cout<<1.7<<endl;
    }else if(grade == "D+"){
        cout<<1.3<<endl;
    }else if(grade == "D0"){
        cout<<1.0<<endl;
    }else if(grade == "D-"){
        cout<<0.7<<endl;
    }else{
        cout<<0.0<<endl;
    }

}

