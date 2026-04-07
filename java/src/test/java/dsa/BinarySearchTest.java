package dsa;

import dsa.algorithms.searching.BinarySearch;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Test suite for Binary Search algorithm
 */
class BinarySearchTest {
    private int[] sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    @Test
    void testRecursiveSearchAtBeginning() {
        assertEquals(0, BinarySearch.binarySearchRecursive(sortedArray, 1));
    }

    @Test
    void testRecursiveSearchInMiddle() {
        assertEquals(4, BinarySearch.binarySearchRecursive(sortedArray, 9));
    }

    @Test
    void testRecursiveSearchAtEnd() {
        assertEquals(9, BinarySearch.binarySearchRecursive(sortedArray, 19));
    }

    @Test
    void testRecursiveSearchNotFound() {
        assertEquals(-1, BinarySearch.binarySearchRecursive(sortedArray, 10));
        assertEquals(-1, BinarySearch.binarySearchRecursive(sortedArray, 0));
        assertEquals(-1, BinarySearch.binarySearchRecursive(sortedArray, 20));
    }

    @Test
    void testIterativeSearchAtBeginning() {
        assertEquals(0, BinarySearch.binarySearchIterative(sortedArray, 1));
    }

    @Test
    void testIterativeSearchInMiddle() {
        assertEquals(4, BinarySearch.binarySearchIterative(sortedArray, 9));
    }

    @Test
    void testIterativeSearchAtEnd() {
        assertEquals(9, BinarySearch.binarySearchIterative(sortedArray, 19));
    }

    @Test
    void testIterativeSearchNotFound() {
        assertEquals(-1, BinarySearch.binarySearchIterative(sortedArray, 10));
        assertEquals(-1, BinarySearch.binarySearchIterative(sortedArray, 0));
        assertEquals(-1, BinarySearch.binarySearchIterative(sortedArray, 20));
    }

    @Test
    void testSingleElement() {
        int[] arr = {5};
        assertEquals(0, BinarySearch.binarySearchRecursive(arr, 5));
        assertEquals(-1, BinarySearch.binarySearchRecursive(arr, 3));
    }

    @Test
    void testEmptyArray() {
        int[] arr = {};
        assertEquals(-1, BinarySearch.binarySearchIterative(arr, 5));
    }

    @Test
    void testBothImplementationsSameResults() {
        int[] testTargets = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 0, 20, 10};

        for (int target : testTargets) {
            assertEquals(
                BinarySearch.binarySearchRecursive(sortedArray, target),
                BinarySearch.binarySearchIterative(sortedArray, target),
                "Results differ for target: " + target
            );
        }
    }

    @ParameterizedTest
    @ValueSource(ints = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19})
    void testAllElementsFound(int target) {
        int result = BinarySearch.binarySearchIterative(sortedArray, target);
        assertTrue(result >= 0, "Element " + target + " should be found");
        assertEquals(target, sortedArray[result]);
    }
}
