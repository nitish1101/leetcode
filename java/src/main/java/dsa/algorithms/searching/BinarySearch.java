package dsa.algorithms.searching;

/**
 * Binary Search Algorithm
 * 
 * Searches for a target value in a sorted array by repeatedly dividing 
 * the search space in half.
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) - recursive, O(1) - iterative
 * Prerequisites: Array must be sorted
 */
public class BinarySearch {

    /**
     * Recursive implementation of binary search
     */
    public static int binarySearchRecursive(int[] arr, int target) {
        return search(arr, target, 0, arr.length - 1);
    }

    private static int search(int[] arr, int target, int left, int right) {
        if (left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            return search(arr, target, mid + 1, right);
        } else {
            return search(arr, target, left, mid - 1);
        }
    }

    /**
     * Iterative implementation of binary search
     */
    public static int binarySearchIterative(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
}
