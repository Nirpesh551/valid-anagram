#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Function to check if two strings are anagrams
 * 
 * @param s - First string
 * @param t - Second string
 * @return true if anagrams, false otherwise
 */
bool isAnagram(char *s, char *t) {
    // Get lengths of both strings
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    // If lengths don't match, they can't be anagrams
    if (len_s != len_t) {
        return false;
    }
    
    // Array to count frequency of each letter (a-z)
    int count[26] = {0};
    
    // Count characters: increment for s, decrement for t
    for (int i = 0; i < len_s; i++) {
        count[tolower(s[i]) - 'a']++;
        count[tolower(t[i]) - 'a']--;
    }
    
    // Check if all counts are zero (balanced)
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    printf("=== Valid Anagram Checker ===\n\n");
    
    // Test case 1
    printf("Test 1:\n");
    printf("Input: s = \"listen\", t = \"silent\"\n");
    printf("Output: %s\n\n", isAnagram("listen", "silent") ? "True" : "False");
    
    // Test case 2 
    printf("Test 2:\n");
    printf("Input: s = \"rat\", t = \"car\"\n");
    printf("Output: %s\n\n", isAnagram("rat", "car") ? "True" : "False");
    
    // Test case 3 
    printf("Test 3:\n");
    printf("Input: s = \"anagram\", t = \"nagaram\"\n");
    printf("Output: %s\n\n", isAnagram("anagram", "nagaram") ? "True" : "False");
    
    // Test case 4 Different lengths
    printf("Test 4:\n");
    printf("Input: s = \"hello\", t = \"world\"\n");
    printf("Output: %s\n\n", isAnagram("hello", "world") ? "True" : "False");
    
    // Test case 5 Case insensitive
    printf("Test 5:\n");
    printf("Input: s = \"Listen\", t = \"Silent\"\n");
    printf("Output: %s\n\n", isAnagram("Listen", "Silent") ? "True" : "False");
    
    return 0;
}
