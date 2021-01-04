#include <iostream>
#include <algorithm>
#include <vector>

#define max_int 1000001

/*
    시간 복잡도: O(nlogn)
    공간 복잡도: O(n)
    사용한 알고리즘: 좌표압축, STL SORT
    사용한 자료구조: 배열
*/

using namespace std;

int n, num, origin_idx, new_idx, result[max_int];

struct info {
    int num, origin_idx;
};
vector<info> v;

bool cmp(const info& a, const info& b) {
    if (a.num == b.num) {
        return a.origin_idx < b.origin_idx;
    }
    else return a.num < b.num;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        v.push_back({ num, i });
    }

    sort(v.begin(), v.end(), cmp);

    new_idx = 0;
    for (int i = 0; i < v.size(); i++) {
        info cur = v[i];
        num = cur.num;
        origin_idx = cur.origin_idx;

        result[origin_idx] = new_idx;

        while (i < n && num == v[i + 1].num) {
            i++;
            info next_num = v[i];
            origin_idx = next_num.origin_idx;
            result[origin_idx] = new_idx;
        }
        new_idx++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");
}
