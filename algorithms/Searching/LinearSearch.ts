/**
 * Linear Search Algorithm
 * 
 * Searches for a target value by examining each element sequentially.
 * Useful for unsorted arrays or small datasets.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

/**
 * Linear search implementation
 * @param arr - Array to search
 * @param target - Value to search for
 * @returns Index of target or -1 if not found
 */
export function linearSearch(arr: number[], target: number): number {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === target) {
      return i;
    }
  }
  return -1;
}

/**
 * Linear search that returns all indices
 * @param arr - Array to search
 * @param target - Value to search for
 * @returns Array of all indices where target is found
 */
export function linearSearchAll(arr: number[], target: number): number[] {
  const indices: number[] = [];

  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === target) {
      indices.push(i);
    }
  }

  return indices;
}
