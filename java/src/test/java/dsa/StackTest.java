package dsa;

import dsa.datastructures.Stack;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Test suite for Stack data structure
 */
class StackTest {
    private Stack<Integer> stack;

    @BeforeEach
    void setUp() {
        stack = new Stack<>();
    }

    @Test
    void testPush() {
        stack.push(1);
        stack.push(2);
        stack.push(3);

        assertEquals(3, stack.size());
    }

    @Test
    void testPop() {
        stack.push(1);
        stack.push(2);
        stack.push(3);

        assertEquals(3, stack.pop());
        assertEquals(2, stack.peek());
        assertEquals(2, stack.size());
    }

    @Test
    void testPeek() {
        stack.push(10);
        stack.push(20);

        assertEquals(20, stack.peek());
        assertEquals(2, stack.size()); // Peek should not remove
    }

    @Test
    void testIsEmpty() {
        assertTrue(stack.isEmpty());

        stack.push(1);
        assertFalse(stack.isEmpty());

        stack.pop();
        assertTrue(stack.isEmpty());
    }

    @Test
    void testSize() {
        assertEquals(0, stack.size());

        stack.push(1);
        assertEquals(1, stack.size());

        stack.push(2);
        assertEquals(2, stack.size());

        stack.pop();
        assertEquals(1, stack.size());
    }

    @Test
    void testClear() {
        stack.push(1);
        stack.push(2);
        stack.push(3);

        stack.clear();
        assertTrue(stack.isEmpty());
        assertEquals(0, stack.size());
    }

    @Test
    void testPopEmpty() {
        assertNull(stack.pop());
    }

    @Test
    void testPeekEmpty() {
        assertNull(stack.peek());
    }

    @Test
    void testLIFOBehavior() {
        int[] values = {1, 2, 3, 4, 5};

        for (int val : values) {
            stack.push(val);
        }

        for (int i = values.length - 1; i >= 0; i--) {
            assertEquals(values[i], stack.pop());
        }
    }
}
