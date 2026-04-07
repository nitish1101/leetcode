import { binarySearchRecursive, binarySearchIterative } from '../algorithms/Searching/BinarySearch';

/**
 * Test suite for Binary Search algorithm
 */
describe('Binary Search', () => {
  const sortedArray = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19];

  describe('Recursive Implementation', () => {
    test('should find element at the beginning', () => {
      expect(binarySearchRecursive(sortedArray, 1)).toBe(0);
    });

    test('should find element in the middle', () => {
      expect(binarySearchRecursive(sortedArray, 9)).toBe(4);
    });

    test('should find element at the end', () => {
      expect(binarySearchRecursive(sortedArray, 19)).toBe(9);
    });

    test('should return -1 for element not in array', () => {
      expect(binarySearchRecursive(sortedArray, 10)).toBe(-1);
      expect(binarySearchRecursive(sortedArray, 0)).toBe(-1);
      expect(binarySearchRecursive(sortedArray, 20)).toBe(-1);
    });

    test('should work with single element array', () => {
      expect(binarySearchRecursive([5], 5)).toBe(0);
      expect(binarySearchRecursive([5], 3)).toBe(-1);
    });

    test('should work with empty array', () => {
      expect(binarySearchRecursive([], 5)).toBe(-1);
    });
  });

  describe('Iterative Implementation', () => {
    test('should find element at the beginning', () => {
      expect(binarySearchIterative(sortedArray, 1)).toBe(0);
    });

    test('should find element in the middle', () => {
      expect(binarySearchIterative(sortedArray, 9)).toBe(4);
    });

    test('should find element at the end', () => {
      expect(binarySearchIterative(sortedArray, 19)).toBe(9);
    });

    test('should return -1 for element not in array', () => {
      expect(binarySearchIterative(sortedArray, 10)).toBe(-1);
      expect(binarySearchIterative(sortedArray, 0)).toBe(-1);
      expect(binarySearchIterative(sortedArray, 20)).toBe(-1);
    });

    test('should work with single element array', () => {
      expect(binarySearchIterative([5], 5)).toBe(0);
      expect(binarySearchIterative([5], 3)).toBe(-1);
    });

    test('should work with empty array', () => {
      expect(binarySearchIterative([], 5)).toBe(-1);
    });
  });

  describe('Both Implementations', () => {
    test('should return same results', () => {
      const testCases = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 0, 20, 10];

      testCases.forEach((target) => {
        expect(binarySearchRecursive(sortedArray, target)).toBe(
          binarySearchIterative(sortedArray, target)
        );
      });
    });
  });
});
