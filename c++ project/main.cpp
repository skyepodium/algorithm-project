#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/**
* 주어진 배열이 오름차순인지 검사하는 함수
* @param data
* @param n     데이터의 수
* @return      data[0] ~ data[n-1]이 오름차순이라면 true, else false
*/
bool isOrdered(int data[], int n)
{
    vector<int> a;
    for(int i=0; i<n; i++) a.push_back(data[i]);

    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        if(a[i] != data[i]){
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    int* data;

    scanf("%d", &n);
    data = new int[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    bool result = isOrdered(data, n);

    if (result)
    {
        printf("YES");
    }
    else{
        printf("NO");
    }

    delete[] data;
    return 0;
}