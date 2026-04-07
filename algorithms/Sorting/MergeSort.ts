/**
 * Merge Sort Algorithm
 * 
 * Divide and conquer algorithm that divides the array into halves, recursively sorts them,
 * and merges them back together.
 * 
 * Time Complexity: O(n log n) - all cases
 * Space Complexity: O(n) - requires additional space for merging
 * Stable: Yes - maintains relative order of equal elements
 */

/**
 * Merge sort implementation
 */
export function mergeSort(arr: number[]): number[] {
  if (arr.length <= 1) return arr;

  const mid = Math.floor(arr.length / 2);
  const left = arr.slice(0, mid);
  const right = arr.slice(mid);

  return merge(mergeSort(left), mergeSort(right));
}

/**
 * Helper function to merge two sorted arrays
 */
function merge(left: number[], right: number[]): number[] {
  const result: number[] = [];
  let leftIndex = 0;
  let rightIndex = 0;

  while (leftIndex < left.length && rightIndex < right.length) {
    if (left[leftIndex] <= right[rightIndex]) {
      result.push(left[leftIndex++]);
    } else {
      result.push(right[rightIndex++]);
    }
  }

  return result.concat(left.slice(leftIndex)).concat(right.slice(rightIndex));
}
