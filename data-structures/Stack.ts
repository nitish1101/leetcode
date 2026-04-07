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

class Stack<T> {
  private items: T[] = [];

  /**
   * Add element to the top of the stack
   */
  push(element: T): void {
    this.items.push(element);
  }

  /**
   * Remove and return the top element
   */
  pop(): T | undefined {
    return this.items.pop();
  }

  /**
   * View the top element without removing
   */
  peek(): T | undefined {
    return this.items[this.items.length - 1];
  }

  /**
   * Check if stack is empty
   */
  isEmpty(): boolean {
    return this.items.length === 0;
  }

  /**
   * Get the size of the stack
   */
  size(): number {
    return this.items.length;
  }

  /**
   * Clear the stack
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

export default Stack;
