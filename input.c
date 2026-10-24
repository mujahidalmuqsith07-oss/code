#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void toLowerStr(char *s) {
    for(int i = 0; s[i]; i++){
        s[i] = tolower(s[i]);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        char line[100];
        scanf("%s", line);
        
        char line_lower[100];
        strcpy(line_lower, line);
        toLowerStr(line_lower);

        if (strcmp(line_lower, "inf") == 0 || strcmp(line_lower, "+inf") == 0) {
            printf("0\n");
        } else if (strcmp(line_lower, "-inf") == 0) {
            printf("-0\n");
        } else if (strcmp(line_lower, "nan") == 0) {
            printf("NaN\n");
        } else {
            char *endptr;
            double val = strtod(line, &endptr);
            
            if (endptr == line || *endptr != '\0') {
                printf("NaN\n");
            } else {
                if (val == 0.0) {
                    printf("inf\n");
                } else {
                    double res = 1.0 / val;
                    printf("%.10g\n", res);
                }
            }
        }
    }

    return 0;
}
