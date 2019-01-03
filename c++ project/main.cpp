#include <iostream>
#include <vector>

#define max_int 27
using namespace std;

int n;
char a, b, c;
vector<char> v[max_int];

void preorder(int node){
    if(node + 'A' == '.') return;

    printf("%c", node + 'A');
    preorder(v[node][0]);
    preorder(v[node][1]);
}

void inorder(int node){
    if(node + 'A' == '.') return;

    inorder(v[node][0]);
    printf("%c", node + 'A');
    inorder(v[node][1]);
}

void postorder(int node){
    if(node + 'A' == '.') return;

    postorder(v[node][0]);
    postorder(v[node][1]);
    printf("%c", node + 'A');
}


int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        v[a-'A'].push_back(b-'A');
        v[a-'A'].push_back(c-'A');
    }

    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);

}