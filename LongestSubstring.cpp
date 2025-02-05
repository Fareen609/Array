#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int max_length = 0;
    int start = 0; 
    int seen[256] = {0};

    for (int end = 0; end < n; end++) {
        while (seen[s[end]] > 0) {
            seen[s[start]]--;
            start++;
        }
        seen[s[end]]++;
        int current_length = end - start + 1;
        if (current_length > max_length) {
            max_length = current_length;
        }
    }
    
    return max_length;
}

int main() {
    char s[] = "abcabcbb";
    printf("Length of longest substring without repeating characters: %d\n", lengthOfLongestSubstring(s));
    return 0;
}

