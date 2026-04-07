package dsa.algorithms.sorting;

/**
 * Bubble Sort Algorithm
 * 
 * Simple sorting algorithm that repeatedly steps through the list, 
 * compares adjacent elements, and swaps them if they are in the wrong order.
 * 
 * Time Complexity: O(n²) average and worst case, O(n) best case
 * Space Complexity: O(1) - sorts in place
 * Stable: Yes - maintains relative order of equal elements
 */
public class BubbleSort {

    /**
     * Bubble sort implementation
     */
    public static void bubbleSort(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n; i++) {
            boolean swapped = false;

            // Last i elements are already in place
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }

            // If no swaps occurred, array is already sorted
            if (!swapped) {
                break;
            }
        }
    }

    /**
     * Get a copy of the sorted array without modifying the original
     */
    public static int[] bubbleSortCopy(int[] arr) {
        int[] copy = arr.clone();
        bubbleSort(copy);
        return copy;
    }
}
