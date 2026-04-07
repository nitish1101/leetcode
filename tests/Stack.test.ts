import Stack from '../data-structures/Stack';

/**
 * Test suite for Stack data structure
 */
describe('Stack Data Structure', () => {
  let stack: Stack<number>;

  beforeEach(() => {
    stack = new Stack<number>();
  });

  describe('Basic Operations', () => {
    test('should push elements onto the stack', () => {
      stack.push(1);
      stack.push(2);
      stack.push(3);

      expect(stack.size()).toBe(3);
    });

    test('should pop elements from the stack', () => {
      stack.push(1);
      stack.push(2);
      stack.push(3);

      expect(stack.pop()).toBe(3);
      expect(stack.pop()).toBe(2);
      expect(stack.size()).toBe(1);
    });

    test('should peek at the top element', () => {
      stack.push(10);
      stack.push(20);

      expect(stack.peek()).toBe(20);
      expect(stack.size()).toBe(2); // Peek should not remove
    });

    test('should return undefined for empty stack operations', () => {
      expect(stack.pop()).toBeUndefined();
      expect(stack.peek()).toBeUndefined();
    });
  });

  describe('Stack Properties', () => {
    test('should correctly identify empty stack', () => {
      expect(stack.isEmpty()).toBe(true);

      stack.push(1);
      expect(stack.isEmpty()).toBe(false);

      stack.pop();
      expect(stack.isEmpty()).toBe(true);
    });

    test('should return correct size', () => {
      expect(stack.size()).toBe(0);

      stack.push(1);
      expect(stack.size()).toBe(1);

      stack.push(2);
      expect(stack.size()).toBe(2);

      stack.pop();
      expect(stack.size()).toBe(1);
    });

    test('should clear the stack', () => {
      stack.push(1);
      stack.push(2);
      stack.push(3);

      stack.clear();
      expect(stack.isEmpty()).toBe(true);
      expect(stack.size()).toBe(0);
    });
  });

  describe('LIFO Behavior', () => {
    test('should maintain LIFO order', () => {
      const values = [1, 2, 3, 4, 5];

      values.forEach((val) => stack.push(val));

      values.reverse().forEach((val) => {
        expect(stack.pop()).toBe(val);
      });
    });
  });
});
