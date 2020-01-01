#include <stdio.h>

/*
 다음 함수는 오름차순으로 정렬된 배열 array에 대해
 시작 인덱스: start, 마지막 인덱스: end 일때
 정수 num의 인덱스를 반드시 찾아줍니다.
 */
int binary_search(int start, int end, int *array, int num){
    int mid = (start + end) / 2;

    if(start <= end){
        if(array[mid] < num){
            /*
            중요1. (어떤 값이 반환될지를 몰라서)
            
            다음 호출 binary_search(mid + 1, end, array, num)은
            mid + 1 ~ end 구간에서 정수 num의 인덱스 번호를 반드시 찾아줍니다.
            그래서 바로 return 합니다.
            */
            return binary_search(mid + 1, end, array, num);
        }
        else if(array[mid] == num){
            /*
            중요2. (언제 끝나야할지를 몰라서)
            
            정수 num을 찾았을때 종료합니다.
            */
            return mid;
        }
        else{
            /*
            중요1. (어떤 값이 반환될지를 몰라서)
            
            다음 호출 binary_search(start, mid - 1, array, num)은
            start ~ mid - 1 구간에서 정수 num의 인덱스 번호를 반드시 찾아줍니다.
            그래서 바로 return 합니다.
            */
            return binary_search(start, mid - 1, array, num);
        }
    }
    else{
        /*
        중요2. (언제 끝나야할지를 몰라서)
        
        시작 인덱스 start가 마지막 인덱스 end보다 커졌는데 못찾으면 종료합니다.
        */
        return -1;
    }
}

int main(){
    int a[10] = {1, 3, 4, 5, 7, 8, 9, 10, 11, 12};
 
    printf("%d\n", binary_search(0, 9, a, 5));
}
