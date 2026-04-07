package dsa;

import dsa.algorithms.sorting.BubbleSort;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Test suite for Bubble Sort algorithm
 */
class BubbleSortTest {

    @Test
    void testBasicSort() {
        int[] arr = {5, 2, 8, 1, 9};
        int[] expected = {1, 2, 5, 8, 9};

        BubbleSort.bubbleSort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testAlreadySorted() {
        int[] arr = {1, 2, 3, 4, 5};
        int[] expected = {1, 2, 3, 4, 5};

        BubbleSort.bubbleSort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testReverseSorted() {
        int[] arr = {5, 4, 3, 2, 1};
        int[] expected = {1, 2, 3, 4, 5};

        BubbleSort.bubbleSort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testSingleElement() {
        int[] arr = {5};
        int[] expected = {5};

        BubbleSort.bubbleSort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testEmptyArray() {
        int[] arr = {};
        int[] expected = {};

        BubbleSort.bubbleSort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testDuplicates() {
        int[] arr = {3, 1, 3, 2, 1};
        int[] expected = {1, 1, 2, 3, 3};

        BubbleSort.bubbleSort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testNegativeNumbers() {
        int[] arr = {-5, 3, -1, 2, 0};
        int[] expected = {-5, -1, 0, 2, 3};

        BubbleSort.bubbleSort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testBubbleSortCopy() {
        int[] original = {5, 2, 8, 1, 9};
        int[] originalCopy = original.clone();

        int[] sorted = BubbleSort.bubbleSortCopy(original);

        // Original should not be modified
        assertArrayEquals(originalCopy, original);
        
        // Sorted should be in order
        assertArrayEquals(new int[]{1, 2, 5, 8, 9}, sorted);
    }
}
