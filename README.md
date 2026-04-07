# Data Structures and Algorithms Practice

A comprehensive workspace for practicing and mastering data structures and algorithms.

## 📁 Project Structure

```
infiniti/
├── java/                 # Java-based DSA and LLD implementations
│   ├── src/main/java/
│   │   ├── dsa/          # Data Structures and Algorithms (Java)
│   │   │   ├── datastructures/
│   │   │   └── algorithms/
│   │   └── lld/          # Low-Level Design (System Design)
│   │       ├── patterns/      # Design Patterns
│   │       └── problems/      # LLD Interview Problems
│   ├── src/test/java/    # Test suites (JUnit 5)
│   ├── pom.xml          # Maven configuration
│   └── README.md        # Java project guide
└── README.md            # This file
```

## 🚀 Getting Started

### Prerequisites
- Java (v11+) with Maven (v3.6+) for Java DSA and LLD
- Python (v3.7+) for Python implementations (optional)

### Setup

**Java (DSA & LLD):**
```bash
cd java

# Run all tests with Maven
mvn clean test

# Run specific test class
mvn -Dtest=StackTest test

# Generate code coverage report
mvn test jacoco:report
```

## 📚 DSA (Data Structures & Algorithms)

### Data Structures
- **Stack** - LIFO data structure with push/pop/peek operations
- **Queue** - FIFO data structure with enqueue/dequeue operations
- **Linked List** - Sequential data structure with dynamic sizing
- Arrays & Strings
- Trees (Binary, BST, AVL, etc.)
- Graphs
- Hash Tables
- Heaps
- Tries

### Algorithms
- **Searching**
  - Binary Search (recursive & iterative)
  - Linear Search
- **Sorting**
  - Bubble Sort
  - Merge Sort
  - Quick Sort (optional)
- Graph Algorithms (BFS, DFS, Dijkstra, etc.)
- Dynamic Programming
- Greedy Algorithms
- Divide & Conquer
- Backtracking

## 🏗️ LLD (Low-Level Design)

Prepare for system design interviews with comprehensive LLD implementations.

### Design Patterns

**Creational Patterns:**
- Singleton (Bill Pugh pattern for thread-safe lazy initialization)
- Factory Pattern (object creation without exposing logic)
- Builder Pattern (complex object construction)

**Behavioral Patterns:**
- Observer Pattern (event handling and notifications)
- Strategy Pattern (algorithm encapsulation)

### System Design Problems

**Implemented Interview Problems:**
1. **Parking Lot System** - Multi-level parking with vehicle types
   - Components: ParkingLot, Level, ParkingSpot (types), Vehicle
   - Features: Spot allocation, capacity tracking, multi-level support

2. **Elevator System** - Distributed elevator management
   - Components: ElevatorSystem, Elevator, Floor, Request, Direction
   - Features: Request queuing, optimal elevator selection, capacity management

3. **Library Management** - Book and member management
   - Components: Library, Book, BookCopy, Member, BorrowRecord
   - Features: Book availability, fine calculation, transaction history

4. **ATM Machine** - Banking system with state management
   - Components: ATM, BankAccount, User, Transaction, ATMState
   - Features: Authentication, withdrawal/deposit, balance tracking, state pattern

## 🧪 Testing

Each implementation includes comprehensive test cases.

**Java:**
```bash
cd java
mvn clean test
```

## 📊 Test Coverage

**Current Status:**
- **Total Tests**: 77 passing ✅
- **DSA Tests**: 47 tests
  - Stack: 9 tests
  - Queue: 9 tests
  - Binary Search: 21 tests
  - Bubble Sort: 8 tests
- **LLD Tests**: 30 tests
  - Design Patterns: 5 tests
  - Parking Lot System: 6 tests
  - Elevator System: 4 tests
  - Library Management: 6 tests
  - ATM Machine: 9 tests
- **Code Coverage**: 73%

## 📖 Learning Approach

1. **Understand** - Learn the concept and theory
2. **Implement** - Code the data structure or algorithm
3. **Test** - Verify with test cases
4. **Optimize** - Analyze and improve complexity
5. **Apply** - Solve problems using the learned concept

## 🎯 Interview Preparation

### LLD Interview Tips
1. **Clarify Requirements** - Ask questions about scale, constraints, use cases
2. **Design Architecture** - Sketch system components and relationships
3. **Code Implementation** - Write clean, well-structured code
4. **Handle Edge Cases** - Consider thread safety, error handling
5. **Discuss Trade-offs** - Scalability vs complexity vs maintainability

### SOLID Principles
- **S**ingle Responsibility - One reason to change
- **O**pen/Closed - Open for extension, closed for modification
- **L**iskov Substitution - Subtypes must be substitutable
- **I**nterface Segregation - Client-specific interfaces
- **D**ependency Inversion - Depend on abstractions

## ✅ Checklist for Each Implementation

- [ ] Theory understood and noted
- [ ] Implementation completed
- [ ] Time complexity: O(?)
- [ ] Space complexity: O(?)
- [ ] Test cases written
- [ ] All tests passing
- [ ] Code reviewed and optimized

## 🔗 Resources

- LeetCode for DSA problems
- GeeksforGeeks for theory
- System Design Interview resources
- YouTube for visual explanations
- [java/README.md](java/README.md) - Java project setup and Maven commands

---

**Last Updated**: 8 April 2026
