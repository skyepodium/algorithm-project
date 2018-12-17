#include <iostream>

using namespace std;

int n;
int tree[26][2];

void pre_order(char node){
    if(node == '.') return;
    
    cout << node;
    pre_order(tree[node-'A'][0]);
    pre_order(tree[node-'A'][1]);
}

void in_order(char node){
    if(node == '.') return;
    
    in_order(tree[node-'A'][0]);
    cout << node;
    in_order(tree[node-'A'][1]);
}

void post_order(char node){
    if(node == '.') return;
    
    post_order(tree[node-'A'][0]);
    post_order(tree[node-'A'][1]);
    cout << node;
}

int main(){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        char a, b, c;
        cin >> a >> b >> c;
        tree[a-'A'][0] = b;
        tree[a-'A'][1] = c;
    }
    
    pre_order('A');
    cout << endl;
    in_order('A');
    cout << endl;
    post_order('A');
    cout << endl;

}
