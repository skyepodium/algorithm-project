#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

long long int a[1000001];

int main(){

    set<int> s;
    
    s.insert(20);
    s.insert(30);
    s.insert(10);
    
    int a = s.find(22);
    cout << a <<endl;
}
