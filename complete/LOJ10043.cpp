#include <cstdio>
#include <cstring>
#include <iostream>
char s1[1100], s2[1100];
int nxt[1100];
int main() {
    while (1) {
        scanf("%s%s", s1 + 1, s2 + 1);
        // printf("%c\n", s1[1]);
        int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
        if (s1[1] == '#' && len1 == 1) break;
        nxt[0] = nxt[1] = 0;
        for (int i = 1, j = 0; i <= len2; ++i) {
            while (j > 0 && s2[i + 1] != s2[j + 1]) j = nxt[j];
            if (s2[i + 1] == s2[j + 1]) ++j;
            nxt[i + 1] = j;
        }
        int cnt = 0;
        for (int i = 0, j = 0; i <= len1; ++i) {
            while (j > 0 && s1[i + 1] != s2[j + 1]) j = nxt[j];
            if (s1[i + 1] == s2[j + 1]) ++j;
            if (j == len2) {
                ++cnt;
                j = 0;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}