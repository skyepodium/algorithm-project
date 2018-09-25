#include <iostream>
#include <cstring>
#define max_int 100001

using namespace std;

char word1[max_int];
char word2[max_int];

int main(){
    
    scanf("%s", word1);
    scanf("%s", word2);
    
    int size = (int)strlen(word1);
    
    //&
    for(int i=0; i<size; i++){
        if(word1[i]-'0' & word2[i]-'0') printf("1");
        else printf("0");
    }
    printf("\n");

    //|
    for(int i=0; i<size; i++){
        if(word1[i]-'0' | word2[i]-'0') printf("1");
        else printf("0");
    }
    printf("\n");

    //^
    for(int i=0; i<size; i++){
        if(word1[i]-'0' ^ word2[i]-'0') printf("1");
        else printf("0");
    }
    printf("\n");
    
    //~A
    for(int i=0; i<size; i++){
        if(!(word1[i]-'0')) printf("1");
        else printf("0");
    }
    printf("\n");

    //~B
    for(int i=0; i<size; i++){
        if(!(word2[i]-'0')) printf("1");
        else printf("0");
    }
    printf("\n");

    
}
