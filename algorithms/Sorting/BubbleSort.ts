/**
 * Bubble Sort Algorithm
 * 
 * Simple sorting algorithm that repeatedly steps through the list, compares adjacent elements,
 * and swaps them if they are in the wrong order.
 * 
 * Time Complexity: O(n²) average and worst case, O(n) best case
 * Space Complexity: O(1) - sorts in place
 * Stable: Yes - maintains relative order of equal elements
 */

export function bubbleSort(arr: number[]): number[] {
  const result = [...arr]; // Create a copy to avoid mutating the original
  const n = result.length;

  for (let i = 0; i < n; i++) {
    let swapped = false;

    // Last i elements are already in place
    for (let j = 0; j < n - i - 1; j++) {
      if (result[j] > result[j + 1]) {
        // Swap
        [result[j], result[j + 1]] = [result[j + 1], result[j]];
        swapped = true;
      }
    }

    // If no swaps occurred, array is already sorted
    if (!swapped) break;
  }

  return result;
}

/**
 * Optimized bubble sort with early termination
 */
export function bubbleSortOptimized(arr: number[]): number[] {
  const result = [...arr];
  const n = result.length;

  for (let i = 0; i < n - 1; i++) {
    let swapped = false;

    for (let j = 0; j < n - i - 1; j++) {
      if (result[j] > result[j + 1]) {
        [result[j], result[j + 1]] = [result[j + 1], result[j]];
        swapped = true;
      }
    }

    if (!swapped) break;
  }

  return result;
}
