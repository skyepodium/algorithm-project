#include <iostream>

using namespace std;

int test(int a){
    static int b = 1;
    
    int result = a + b;
    b += 1;
       
    printf("static : %d \n", b);
    return result;
}

int main(){
    for(int i=0; i<100; i++){
        int c = test(i);
        printf("%d\n", c);
    }
}





//#include <iostream>
//#include <queue>
//#define max_int 100
//#define max_val 300001
//using namespace std;
//
//
//int d[max_int][max_int], a[max_int][max_int];
//int start_x = 0, start_y = 1;
//int end_x = 3, end_y = 1;
//
//int dx[] = {0, 1, 1, 1, 0};
//int dy[] = {-1, -1, 0, 1, 1};
//
//struct info{
//    int x;
//    int y;
//    int cost;
//};
//
//struct cmp{
//    bool operator()(const info &a, const info &b){
//        return a.cost > b.cost;
//    }
//};
//
//void dijkstra() {
//
//    d[start_x][start_y] = 0;
//    priority_queue<info, vector<info>, cmp> pq;
//    pq.push({start_x, start_y, d[start_x][start_x]});
//
//    while(!pq.empty()){
//        info cur = pq.top();
//        pq.pop();
//        int x = cur.x;
//        int y = cur.y;
//
//        for(int i=0; i<5; i++){
//            int nx = x + dx[i];
//            int ny = y + dy[i];
//            if(nx>=0 && nx<max_int && ny>=0 && ny<max_int){
//
//                int cost = a[nx][ny];
//                int dir_cost = 0;
//                if(i == 0 || i == 4) dir_cost = 5;
//                else if(i ==1 || i == 3) dir_cost = 1;
//                else dir_cost = 0;
//
//                cost += dir_cost;
//
//                if(d[nx][ny] > d[x][y] + cost){
//                    d[nx][ny] = d[x][y] + cost;
//                    pq.push({nx, ny, cost});
//                }
//            }
//        }
//    }
//}
//
//int main() {
//    for(int i=0; i<max_int; i++){
//        for(int j=0; j<max_int; j++){
//            d[i][j] = max_val;
//            a[i][j] = 0;
//        }
//    }
//
//    a[2][1] = max_val;
//
//    dijkstra();
//
//
//
//    printf("%d\n", d[end_x][end_y]);
//
//    for(int i=0; i<10; i++){
//        for(int j=0; j<10; j++){
//            printf("%d ", d[i][j]);
//        }
//        printf("\n");
//    }
//}
