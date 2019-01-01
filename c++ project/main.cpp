#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> result;
int main(){
    scanf("%d", &n);
    if(n != 0) {
        while (n != 0) {

            if (n % 2 == 0) {
                n = (-n / 2);
                result.push_back(0);
            } else {
                if (n > 0) {
                    n = (-n / 2);
                } else {
                    n = ((-n + 1) / 2);
                }
                result.push_back(1);
            }
        }
        for (int i = (int) result.size() - 1; i >= 0; i--) {
            printf("%d", result[i]);
        }
    }
    else{
        printf("0\n");
    }
}