/*Problem Statement

Given two strings s and t, return true if t is an anagram of s, and return false otherwise.

An anagram is a word or phrase formed by rearranging the letters of another word or phrase, using all the original letters exactly once.*/

/*Time complexity: O(n) where n is the length of the strings. Space complexity: O(1)*/

#include <stdio.h>
#include <string.h>

#define CHAR_COUNT 256

int isAnagram(char s[], char t[])
{
    int count[CHAR_COUNT] = {0};
    int i;

    if (strlen(s) != strlen(t))
        return 0;

    for (i = 0; s[i] && t[i]; i++)
    {
        count[(unsigned char)s[i]]++;
        count[(unsigned char)t[i]]--;
    }

    for (i = 0; i < CHAR_COUNT; i++)
    {
        if (count[i] != 0)
            return 0;
    }

    return 1;
}

int main()
{
    char s[] = "listen";
    char t[] = "silent";

    if (isAnagram(s, t))
        printf("Strings are Anagrams\n");
    else
        printf("Strings are NOT Anagrams\n");

    return 0;
}
