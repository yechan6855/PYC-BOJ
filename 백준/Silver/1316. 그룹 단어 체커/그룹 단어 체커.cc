#include <bits/stdc++.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int count = 0;
    for (int i = 0; i < N; i++) {
        char word[101];
        scanf("%s", word);

        int visited[26] = {0};

        int len = strlen(word);
        int j;
        for (j = 0; j < len; j++) {
            if (j > 0 && word[j] != word[j - 1] && visited[word[j] - 'a'] == 1) {
                break;
            }
            visited[word[j] - 'a'] = 1;
        }
        if (j == len) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}