#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int line_size = 0;

void hex_to_decimal(string num);

void line1();
void line2();
void line3();
void line4();
void line5();

int main() {
    
    line1();
    line2();
    line3();
    line4();
    line5();
}

void hex_to_decimal(string num){
    int decimal = 0;
    
    int position = 0;
    for (int i = (int)num.size() - 1; i >= 0; i--){
        char ch = num[i];
        
        if (ch >= 48 && ch <= 57){
            decimal += (ch - 48) * pow(16, position);
        }
        else if (ch >= 65 && ch <= 70){
            decimal += (ch - (65 - 10)) * pow(16, position);
        }
        else if (ch >= 97 && ch <= 102){
            decimal += (ch - (97 - 10)) * pow(16, position);
        }
        
        position++;
    }
    
    cout << decimal << endl;
}


void line1(){
    string s1, s2, s3, s4, s5;
    cin >> s1 >> s2 >> s3 >> s4 >> s5;
    cout << s3 << endl;
    cout << s5 << endl;
}

void line2(){
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    hex_to_decimal(s3);
}


void line3(){
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    cout << s4 << endl;
    line_size = stoi(s4);
}

void line4(){
    string s1, s2, s3, s4, s5;
    cin >> s1 >> s2 >> s3 >> s4 >> s5;
}

void line5(){
    string s1, alpha;
    int width, height, duration;

    for(int i=0; i<line_size; i++){
        cin >> s1 >> width >> height >> alpha >> duration;
        
        int result = 0;
        if(alpha == "yes") result = 1;
        else result = 0;
        cout << width << "x" << height << ", "<< duration << ", " << result <<endl;
    }
    
}
