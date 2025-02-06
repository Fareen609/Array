#include <stdio.h>
#include <stdbool.h>
bool isMatch(char *s, char *p) {
    if (*p == '\0') {
        return *s == '\0';
    }
    bool firstMatch = (*s != '\0' && (*s == *p || *p == '.'));
    if (*(p + 1) == '*') {
        return (isMatch(s, p + 2) || (firstMatch && isMatch(s + 1, p)));
    } else {
        return firstMatch && isMatch(s + 1, p + 1);
    }
}

int main() {
    char s1[] = "aa";
    char p1[] = "a";
    printf("Test 1: %s\n", isMatch(s1, p1) ? "true" : "false");  

    char s2[] = "aa";
    char p2[] = "a*";
    printf("Test 2: %s\n", isMatch(s2, p2) ? "true" : "false");  

    char s3[] = "mississippi";
    char p3[] = "mis*is*p*.";
    printf("Test 3: %s\n", isMatch(s3, p3) ? "true" : "false"); 

    return 0;
}

