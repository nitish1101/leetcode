package dsa.algorithms.sorting;

/**
 * Radix Sort Algorithm - Non-comparative sorting algorithm
 * 
 * Description:
 * Radix sort is a non-comparative integer sorting algorithm that works by
 * distributing elements into buckets according to their individual digits.
 * It sorts numbers digit by digit starting from the least significant digit
 * (LSD) to the most significant digit (MSD).
 * 
 * Time Complexity: O(n*k) where n is the number of elements and k is the number of digits
 * Space Complexity: O(n+k) where k is the range of input (0-9 for decimal digits)
 * 
 * Stable: Yes (maintains relative order of equal elements)
 * In-place: No (requires auxiliary space for counting)
 * 
 * Use Cases:
 * - Sorting large numbers of integers efficiently
 * - Sorting strings
 * - When comparison-based sorts would be too slow
 * - When keys have a fixed number of digits
 */
public class RadixSort {
    
    /**
     * Sorts an array of non-negative integers using Radix Sort (LSD)
     * 
     * @param numbers array of non-negative integers to sort
     */
    public static void sort(int[] numbers) {
        if (numbers == null || numbers.length == 0) {
            return;
        }
        
        // Find the maximum number to know the number of digits
        int max = findMax(numbers);
        
        // Do counting sort for each digit
        // exp is the current digit position (1, 10, 100, etc.)
        for (int exp = 1; max / exp > 0; exp *= 10) {
            countingSort(numbers, exp);
        }
    }
    
    /**
     * Performs counting sort on numbers based on a specific digit position
     * 
     * @param numbers array to sort
     * @param exp the current digit position exponent (1, 10, 100, etc.)
     */
    private static void countingSort(int[] numbers, int exp) {
        int n = numbers.length;
        int[] output = new int[n];
        int[] count = new int[10]; // 0-9 for digits
        
        // Count occurrences of each digit at this position
        for (int i = 0; i < n; i++) {
            int digit = (numbers[i] / exp) % 10;
            count[digit]++;
        }
        
        // Accumulate counts to get positions
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        // Build the output array by placing elements in correct positions
        // Traverse from right to left to maintain stability
        for (int i = n - 1; i >= 0; i--) {
            int digit = (numbers[i] / exp) % 10;
            output[count[digit] - 1] = numbers[i];
            count[digit]--;
        }
        
        // Copy sorted elements back to original array
        for (int i = 0; i < n; i++) {
            numbers[i] = output[i];
        }
    }
    
    /**
     * Finds the maximum element in the array
     * 
     * @param numbers array of numbers
     * @return the maximum number in the array
     */
    private static int findMax(int[] numbers) {
        int max = numbers[0];
        for (int i = 1; i < numbers.length; i++) {
            if (numbers[i] > max) {
                max = numbers[i];
            }
        }
        return max;
    }
    
    /**
     * Sorts an array of non-negative integers and returns the sorted array
     * This is a convenience method that returns a new array
     * 
     * @param numbers array of non-negative integers to sort
     * @return newly sorted array
     */
    public static int[] radixSort(int[] numbers) {
        if (numbers == null || numbers.length == 0) {
            return numbers;
        }
        
        int[] result = numbers.clone();
        sort(result);
        return result;
    }
}
