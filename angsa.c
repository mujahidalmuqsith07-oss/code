#include <stdio.h>
#include <string.h>

char S[2000][1005];   
int cnt[2000][26];    
int len[2000];        

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", S[i]);
        len[i] = strlen(S[i]);
        for (int p = 0; p < len[i]; p++) {
            cnt[i][S[i][p] - 'a']++;
        }
    }

    long long jawab = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {

                if (len[i] != len[j] + len[k]) continue;

                int sama = 1;
                for (int c = 0; c < 26; c++) {
                    if (cnt[i][c] != cnt[j][c] + cnt[k][c]) {
                        sama = 0;
                        break;
                    }
                }
                if (sama) jawab++;
            }
        }
    }

    printf("%lld\n", jawab);
    return 0;
}
