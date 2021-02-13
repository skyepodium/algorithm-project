#include <stdio.h>
#include <stdlib.h>
#include <thread>

#pragma warning(disable:4996)
#pragma section("flag_data", read)

char table[45] = { 102, 124, 124, 107, 78, 117, 17, 87, 100, 69, 114, 2, 80, 106, 65, 80, 6, 66, 103, 91, 6, 125, 4, 66, 125, 99, 2, 112, 76, 110, 103, 1, 98, 91, 106, 6, 18, 106, 115, 91, 69, 5, 113, 0, 76 };

char flags[45];

void genFlag(int key1, int key2, int key3) {
    for(int i = 0; i<45; i++) {  
        if (i % 3 == 0)
            flags[i] = table[i] ^ key1;   
        else if (i % 3 == 1)
            flags[i] = table[i] ^ key2;
        else if (i % 3 == 2) {
            flags[i] = table[i] ^ key3;
        }.   
    }
}

int main() {   
    genFlag(34, 53, 49);
    
    printf("%s", flags);    
}
