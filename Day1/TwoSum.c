/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

#include <stdio.h>
#include <stdlib.h>

struct NumIndex {
    int value;
    int index;
};

int compare(const void* a, const void* b) {
    return ((struct NumIndex*)a)->value - ((struct NumIndex*)b)->value;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int size = sizeof(nums) / sizeof(nums[0]);

    struct NumIndex arr[size];

    // Store value and index
    for (int i = 0; i < size; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    // Sort array
    qsort(arr, size, sizeof(struct NumIndex), compare);

    // Two pointers
    int left = 0, right = size - 1;

    while (left < right) {
        int sum = arr[left].value + arr[right].value;

        if (sum == target) {
            printf("Indices: %d, %d\n", arr[left].index, arr[right].index);
            return 0;
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    printf("No solution found\n");
    return 0;
}
