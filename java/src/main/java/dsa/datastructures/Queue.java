package dsa.datastructures;

import java.util.ArrayList;
import java.util.List;

/**
 * Queue Data Structure
 * 
 * FIFO (First In First Out) - First element added is the first one to be removed
 * Time Complexity:
 *   - Enqueue: O(1)
 *   - Dequeue: O(1)
 *   - Peek: O(1)
 * Space Complexity: O(n)
 */
public class Queue<T> {
    private List<T> items;

    public Queue() {
        this.items = new ArrayList<>();
    }

    /**
     * Add element to the end (rear) of the queue
     */
    public void enqueue(T element) {
        items.add(element);
    }

    /**
     * Remove and return element from the front
     */
    public T dequeue() {
        if (isEmpty()) {
            return null;
        }
        return items.remove(0);
    }

    /**
     * View the front element without removing
     */
    public T peek() {
        if (isEmpty()) {
            return null;
        }
        return items.get(0);
    }

    /**
     * Check if queue is empty
     */
    public boolean isEmpty() {
        return items.isEmpty();
    }

    /**
     * Get the size of the queue
     */
    public int size() {
        return items.size();
    }

    /**
     * Clear the queue
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
