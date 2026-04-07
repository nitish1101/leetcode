/**
 * Binary Search Algorithm
 * 
 * Searches for a target value in a sorted array by repeatedly dividing the search space in half.
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) - recursive, O(1) - iterative
 * Prerequisites: Array must be sorted
 */

/**
 * Recursive implementation of binary search
 */
export function binarySearchRecursive(arr: number[], target: number): number {
  function search(left: number, right: number): number {
    if (left > right) return -1;

    const mid = Math.floor((left + right) / 2);

    if (arr[mid] === target) {
      return mid;
    } else if (arr[mid] < target) {
      return search(mid + 1, right);
    } else {
      return search(left, mid - 1);
    }
  }

  return search(0, arr.length - 1);
}

/**
 * Iterative implementation of binary search
 */
export function binarySearchIterative(arr: number[], target: number): number {
  let left = 0;
  let right = arr.length - 1;

  while (left <= right) {
    const mid = Math.floor((left + right) / 2);

    if (arr[mid] === target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}
