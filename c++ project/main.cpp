#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int age;
string name;

struct info{
    int age;
    string name;
};

vector<info> v;

bool cmp(const info &a, const info &b){
    return a.age < b.age;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin >> age >> name;
        v.push_back({age, name});
    }

    stable_sort(v.begin(), v.end(), cmp);

    for(int i=0; i<n; i++){
        cout << v[i].age << " " << v[i].name << '\n';
    }

}