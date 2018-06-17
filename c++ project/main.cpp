#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

//Implement this class
//Please use stack only

stack<int> first;
stack<int> second;

class Queue {
public:
    /*
     * Description: ENQUEUE가 입력되면, first 스택에 값을 넣는다.
     * Time complexity:O(1)
     * Space complexity:O(n)
     */
    void enqueue(int v) {
        first.push(v);
    }
    
    /*
     * Description:
     * Time complexity:O(n^2)
     * Space complexity:O(n)
     */
    int dequeue() {
        
        //first 스택의 모든 값을 second 스택으로 거꾸로 옮김
        while(!first.empty()){
            int num = first.top();
            first.pop();
            second.push(num);
        }
        
        int result = 0;
        result = second.top();
        second.pop();
        
        //second 스택의 모든 값을 first 스택으로 거꾸로 옮김
        while(!second.empty()){
            int num = second.top();
            second.pop();
            first.push(num);
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    Queue queue;
    string line;
    getline(cin, line);
    int count = stoi(line);
    for (int i = 0; i < count; ++i) {
        getline(cin, line);
        stringstream ss(line);
        string token;
        getline(ss, token, ' ');
        if (token == "ENQUEUE") {
            getline(ss, token, ' ');
            queue.enqueue(stoi(token));
        } else if (token == "DEQUEUE") {
            cout<<queue.dequeue()<<endl;
        }
    }
}

