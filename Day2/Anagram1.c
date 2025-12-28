/*Problem Statement

Given two strings s and t, return true if t is an anagram of s, and return false otherwise.

An anagram is a word or phrase formed by rearranging the letters of another word or phrase, using all the original letters exactly once.*/

/*Time complexity: O(n log n) where n is the length of the strings. Space complexity: O(1)*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

int isAnagram(char s[], char t[])
{
    if (strlen(s) != strlen(t))
        return 0;

    qsort(s, strlen(s), sizeof(char), compare);
    qsort(t, strlen(t), sizeof(char), compare);

    return strcmp(s, t) == 0;
}

int main()
{
    char s[] = "race";
    char t[] = "care";

    if (isAnagram(s, t))
        printf("Strings are Anagrams\n");
    else
        printf("Strings are NOT Anagrams\n");

    return 0;
}
