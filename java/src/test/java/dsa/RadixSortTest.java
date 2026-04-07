package dsa;

import dsa.algorithms.sorting.RadixSort;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Test suite for Radix Sort Algorithm
 */
class RadixSortTest {
    
    @Test
    void testBasicSorting() {
        int[] numbers = {170, 45, 75, 90, 2, 802, 24, 2, 66};
        int[] expected = {2, 2, 24, 45, 66, 75, 90, 170, 802};
        
        RadixSort.sort(numbers);
        assertArrayEquals(expected, numbers);
    }
    
    @Test
    void testSingleElement() {
        int[] numbers = {42};
        int[] expected = {42};
        
        RadixSort.sort(numbers);
        assertArrayEquals(expected, numbers);
    }
    
    @Test
    void testEmptyArray() {
        int[] numbers = {};
        int[] expected = {};
        
        RadixSort.sort(numbers);
        assertArrayEquals(expected, numbers);
    }
    
    @Test
    void testNullArray() {
        // Should not throw exception
        assertDoesNotThrow(() -> RadixSort.sort(null));
    }
    
    @Test
    void testAlreadySorted() {
        int[] numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        RadixSort.sort(numbers);
        assertArrayEquals(expected, numbers);
    }
    
    @Test
    void testReverseSorted() {
        int[] numbers = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int[] expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        RadixSort.sort(numbers);
        assertArrayEquals(expected, numbers);
    }
    
    @Test
    void testDuplicateElements() {
        int[] numbers = {5, 2, 8, 2, 9, 1, 5, 5};
        int[] expected = {1, 2, 2, 5, 5, 5, 8, 9};
        
        RadixSort.sort(numbers);
        assertArrayEquals(expected, numbers);
    }
    
    @Test
    void testAllSameElements() {
        int[] numbers = {7, 7, 7, 7, 7};
        int[] expected = {7, 7, 7, 7, 7};
        
        RadixSort.sort(numbers);
        assertArrayEquals(expected, numbers);
    }
    
    @Test
    void testZeroAndNumbers() {
        int[] numbers = {0, 15, 10, 7, 8, 90, 45, 2, 0};
        int[] expected = {0, 0, 2, 7, 8, 10, 15, 45, 90};
        
        RadixSort.sort(numbers);
        assertArrayEquals(expected, numbers);
    }
    
    @Test
    void testLargeNumbers() {
        int[] numbers = {1000000, 999999, 100, 1, 50000};
        int[] expected = {1, 100, 50000, 999999, 1000000};
        
        RadixSort.sort(numbers);
        assertArrayEquals(expected, numbers);
    }
    
    @Test
    void testTwoElements() {
        int[] numbers = {9, 3};
        int[] expected = {3, 9};
        
        RadixSort.sort(numbers);
        assertArrayEquals(expected, numbers);
    }
    
    @Test
    void testRadixSortMethodReturnsNewArray() {
        int[] numbers = {64, 34, 25, 12, 22, 11, 90};
        int[] original = numbers.clone();
        
        int[] result = RadixSort.radixSort(numbers);
        
        // Original array should not be modified
        assertArrayEquals(original, numbers);
        
        // Result should be sorted
        int[] expected = {11, 12, 22, 25, 34, 64, 90};
        assertArrayEquals(expected, result);
    }
    
    @Test
    void testRadixSortWithNull() {
        assertNull(RadixSort.radixSort(null));
    }
    
    @Test
    void testRadixSortWithEmpty() {
        int[] empty = {};
        int[] result = RadixSort.radixSort(empty);
        assertArrayEquals(empty, result);
    }
    
    @Test
    void testStability() {
        // Test that equal elements maintain relative order
        // When we have numbers with same digits at certain positions,
        // they should maintain relative order
        int[] numbers = {103, 12, 102, 11, 101};
        int[] expected = {11, 12, 101, 102, 103};
        
        RadixSort.sort(numbers);
        assertArrayEquals(expected, numbers);
    }
    
    @Test
    void testRandomOrder() {
        int[] numbers = {37, 73, 29, 16, 82, 44, 11, 58, 67, 91};
        int[] expected = {11, 16, 29, 37, 44, 58, 67, 73, 82, 91};
        
        RadixSort.sort(numbers);
        assertArrayEquals(expected, numbers);
    }
    
    @Test
    void testArrayWithMixedDigits() {
        int[] numbers = {1, 11, 111, 1111, 2, 22, 222, 2222};
        int[] expected = {1, 2, 11, 22, 111, 222, 1111, 2222};
        
        RadixSort.sort(numbers);
        assertArrayEquals(expected, numbers);
    }
}
