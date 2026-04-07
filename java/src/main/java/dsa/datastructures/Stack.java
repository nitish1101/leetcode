package dsa.datastructures;

import java.util.ArrayList;
import java.util.List;

/**
 * Stack Data Structure
 * 
 * LIFO (Last In First Out) - Last element added is the first one to be removed
 * Time Complexity:
 *   - Push: O(1)
 *   - Pop: O(1)
 *   - Peek: O(1)
 * Space Complexity: O(n)
 */
public class Stack<T> {
    private List<T> items;

    public Stack() {
        this.items = new ArrayList<>();
    }

    /**
     * Add element to the top of the stack
     */
    public void push(T element) {
        items.add(element);
    }

    /**
     * Remove and return the top element
     */
    public T pop() {
        if (isEmpty()) {
            return null;
        }
        return items.remove(items.size() - 1);
    }

    /**
     * View the top element without removing
     */
    public T peek() {
        if (isEmpty()) {
            return null;
        }
        return items.get(items.size() - 1);
    }

    /**
     * Check if stack is empty
     */
    public boolean isEmpty() {
        return items.isEmpty();
    }

    /**
     * Get the size of the stack
     */
    public int size() {
        return items.size();
    }

    /**
     * Clear the stack
     */
    public void clear() {
        items.clear();
    }

    /**
     * Print all elements
     */
    @Override
    public String toString() {
        return items.toString();
    }
}
