#include <cstdio>
#include <iostream>
#include <cstring>
char s1[2000000],s2[2000000];
int nxt[2000000];
int main(){
    scanf("%s", s1+1);
    scanf("%s", s2+1);
    nxt[1] = 0;
    int j = 0, len1 = strlen(s1+1), len2 = strlen(s2+1);
    for (int i = 1; i <= len2; ++i){
        while (j > 0 && s2[i+1] != s2[j+1]) j = nxt[j];
        if (s2[i+1] == s2[j+1]) ++j;
        nxt[i+1] = j;
    }
    for (int i = 0; i <= len1; ++i){
        while (j > 0 && s1[i+1] != s2[j+1]) j = nxt[j];
        if (s1[i+1] == s2[j+1]) ++j;
        if (j == len2){
            printf("%d\n", i+1-len2+1);
            j = nxt[j];
        }
    }
    for (int i = 1; i <= len2; ++i)
        printf("%d ", nxt[i]);
    return 0;
}