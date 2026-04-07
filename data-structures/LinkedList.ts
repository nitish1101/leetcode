/**
 * LinkedList Data Structure
 * 
 * A linear data structure where elements are stored in nodes, and each node points to the next.
 * Time Complexity:
 *   - Access: O(n)
 *   - Search: O(n)
 *   - Insertion: O(1) - at beginning, O(n) - at position
 *   - Deletion: O(1) - at beginning, O(n) - at position
 * Space Complexity: O(n)
 */

class Node<T> {
  constructor(
    public data: T,
    public next: Node<T> | null = null
  ) {}
}

class LinkedList<T> {
  private head: Node<T> | null = null;
  private size: number = 0;

  /**
   * Insert element at the beginning
   */
  insertAtBeginning(element: T): void {
    const newNode = new Node(element);
    newNode.next = this.head;
    this.head = newNode;
    this.size++;
  }

  /**
   * Insert element at the end
   */
  insertAtEnd(element: T): void {
    const newNode = new Node(element);

    if (this.head === null) {
      this.head = newNode;
    } else {
      let current = this.head;
      while (current.next !== null) {
        current = current.next;
      }
      current.next = newNode;
    }
    this.size++;
  }

  /**
   * Delete element at the beginning
   */
  deleteAtBeginning(): T | undefined {
    if (this.head === null) return undefined;

    const removed = this.head.data;
    this.head = this.head.next;
    this.size--;
    return removed;
  }

  /**
   * Get element at index
   */
  getAt(index: number): T | undefined {
    let current = this.head;
    let count = 0;

    while (current !== null && count < index) {
      current = current.next;
      count++;
    }

    return current ? current.data : undefined;
  }

  /**
   * Get the size of linked list
   */
  getSize(): number {
    return this.size;
  }

  /**
   * Check if list is empty
   */
  isEmpty(): boolean {
    return this.size === 0;
  }

  /**
   * Print the entire list
   */
  print(): T[] {
    const elements: T[] = [];
    let current = this.head;

    while (current !== null) {
      elements.push(current.data);
      current = current.next;
    }

    return elements;
  }

  /**
   * Reverse the linked list
   */
  reverse(): void {
    let prev: Node<T> | null = null;
    let current = this.head;

    while (current !== null) {
      const next = current.next;
      current.next = prev;
      prev = current;
      current = next;
    }

    this.head = prev;
  }
}

export default LinkedList;
