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

class Queue<T> {
  private items: T[] = [];

  /**
   * Add element to the end (rear) of the queue
   */
  enqueue(element: T): void {
    this.items.push(element);
  }

  /**
   * Remove and return element from the front
   */
  dequeue(): T | undefined {
    return this.items.shift();
  }

  /**
   * View the front element without removing
   */
  peek(): T | undefined {
    return this.items[0];
  }

  /**
   * Check if queue is empty
   */
  isEmpty(): boolean {
    return this.items.length === 0;
  }

  /**
   * Get the size of the queue
   */
  size(): number {
    return this.items.length;
  }

  /**
   * Clear the queue
   */
  clear(): void {
    this.items = [];
  }

  /**
   * Print all elements
   */
  print(): void {
    console.log(this.items.toString());
  }
}

export default Queue;
