#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//시간 복잡도: O(nk)
//공간 복잡도: O(n)
//사용한 알고리즘: 반복문
//사용한 자료구조: 큐

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n, k;
        cin >> n >> k;
        
        queue<int> q;
        for(int i=1; i<=n; i++){
            q.push(i);
        }
        
        while(q.size()>2){
            
            q.pop();
            
            for(int i=0; i<k-1; i++){
                q.push(q.front());
                q.pop();
            }
            
        }
        vector<int> v;
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }
        
        if(v[0] < v[1]){
            cout << v[0] <<" "<<v[1] << endl;
        }else{
            cout << v[1] <<" "<<v[0] << endl;
        }

    }
}
