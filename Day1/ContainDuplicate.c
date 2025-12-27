/*Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int nums[], int size) {
    qsort(nums, size, sizeof(int), compare);

    for (int i = 0; i < size - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int nums[] = {1, 2, 3, 4, 3};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("%s\n", containsDuplicate(nums, size) ? "true" : "false");
    return 0;
}
