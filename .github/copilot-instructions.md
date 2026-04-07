<!-- Use this file to provide workspace-specific custom instructions to Copilot. For more details, visit https://code.visualstudio.com/docs/copilot/copilot-customization#_use-a-githubcopilotinstructionsmd-file -->

# DSA Practice Workspace - Copilot Instructions

## Project Overview
This workspace is dedicated to practicing and implementing data structures and algorithms in Java. It includes both DSA (Data Structures & Algorithms) implementations and LLD (Low-Level Design) system design patterns for interview preparation.

## ⚠️ CRITICAL WORKFLOW RULES

**Do NOT perform any git operations without explicit user permission:**
- ❌ Do NOT commit code changes
- ❌ Do NOT push to remote
- ❌ Do NOT create/switch branches
- ❌ Do NOT merge branches
- ❌ Do NOT perform any git pull/fetch operations

**What to do instead:**
- ✅ Make code changes in files (create, edit, delete files as requested)
- ✅ Show exactly what was modified
- ✅ Wait for the user to explicitly request git operations
- ✅ User will provide commands like: "commit this", "push to remote", "git add and commit"

**Exception:** Only run git commands if user explicitly says "commit", "push", "commit and push", "git add", or similar direct git operation requests.

## Workspace Structure
This is a Java-only workspace focused on DSA and LLD interview preparation:
- `java/` - Main Java project directory
  - `src/main/java/dsa/` - Data Structures and Algorithms implementations
    - `datastructures/` - Stack, Queue, LinkedList, etc.
    - `algorithms/` - Searching and sorting algorithms
  - `src/main/java/lld/` - Low-Level Design system design patterns
    - `patterns/` - Design patterns (Creational, Behavioral)
    - `problems/` - LLD interview problems (Parking Lot, Elevator, Library, ATM)
  - `src/test/java/` - JUnit 5 test suites
  - `pom.xml` - Maven configuration
  - `README.md` - Java project documentation

## Coding Standards

### Java Standards (Primary Language)
- Indentation: 4 spaces
- Use PascalCase for class names, camelCase for methods and variables
- Include JavaDoc comments for public classes and methods
- Packages: 
  - DSA implementations: `dsa.datastructures`, `dsa.algorithms.*`
  - LLD implementations: `lld.patterns.*`, `lld.problems.*`
- File organization: One public class per file
- Example DSA: `java/src/main/java/dsa/datastructures/Stack.java`
- Example LLD: `java/src/main/java/lld/problems/parking_lot/ParkingLotSystem.java`

### General Guidelines
- **Comments**: Add clear comments explaining the logic
- **Complexity**: Include time and space complexity notes (O notation)
- **Testing**: Write comprehensive JUnit 5 test cases
- **Naming**: Use clear, descriptive class and method names
- **Code Style**: Follow Java conventions and SOLID principles

## Development Guidelines
- Implement one data structure or algorithm per file
- Include complexity analysis in comments
- Add test cases before or alongside implementation
- Use consistent indentation (4 spaces for Java)
- Follow DRY (Don't Repeat Yourself) principle

## File Organization Rules

### Java Project Structure
- Data structures: `java/src/main/java/dsa/datastructures/{Name}.java`
- DSA algorithms: `java/src/main/java/dsa/algorithms/{category}/{Name}.java`
- Design patterns: `java/src/main/java/lld/patterns/{type}/{Name}.java`
- LLD problems: `java/src/main/java/lld/problems/{problem_name}/{ClassName}.java`
- Tests: `java/src/test/java/{package}/{ComponentName}Test.java`
- Build: Maven with `pom.xml` configuration

## Testing Frameworks

### Java
- Framework: JUnit 5 (Jupiter)
- Build Tool: Maven
- Commands:
  - `cd java && mvn test` - Run all tests
  - `mvn test -Dtest=StackTest` - Run specific test
  - `mvn clean test` - Clean and test
  - `mvn test jacoco:report` - Generate coverage report

## Automation Instructions for Java DSA Setup

When the user requests "setup Java testing" or "setup maven for java testing", follow this checklist:

### 1. Create Directory Structure
Create these directories:
- `java/src/main/java/dsa/datastructures/`
- `java/src/main/java/dsa/algorithms/searching/`
- `java/src/main/java/dsa/algorithms/sorting/`
- `java/src/test/java/dsa/`

### 2. Create pom.xml
Include:
- Maven Compiler Plugin (Java 11)
- JUnit 5 (Jupiter, Engine, Params)
- AssertJ dependency
- JaCoCo for code coverage
- Surefire plugin for test execution

### 3. Implement Data Structures
Create in `java/src/main/java/dsa/datastructures/`:
- **Stack.java**: Generic class with push(), pop(), peek(), isEmpty(), size(), clear()
- **Queue.java**: Generic class with enqueue(), dequeue(), peek(), isEmpty(), size(), clear()
- **LinkedList.java** (optional): With insertAtBeginning(), insertAtEnd(), deleteAtBeginning(), reverse()

### 4. Implement Common Algorithms
Searching algorithms in `java/src/main/java/dsa/algorithms/searching/`:
- **BinarySearch.java**: Both recursive and iterative implementations

Sorting algorithms in `java/src/main/java/dsa/algorithms/sorting/`:
- **BubbleSort.java**: In-place sorting with swap optimization
- **MergeSort.java**: Divide and conquer approach
- **QuickSort.java** (optional)

### 5. Create Test Classes
For each implementation, create corresponding Test class in `java/src/test/java/dsa/`:
- Use `@BeforeEach` for setup
- Use `@Test` for test methods
- Use `@ParameterizedTest` with `@ValueSource` for multiple test cases
- Include assertions for:
  - Basic operations
  - Edge cases (empty, single element)
  - Null/boundary conditions
  - Behavior verification (LIFO for Stack, FIFO for Queue)

### Example Test Structure:
```java
package dsa;

import dsa.datastructures.Stack;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class StackTest {
    private Stack<Integer> stack;

    @BeforeEach
    void setUp() {
        stack = new Stack<>();
    }

    @Test
    void testPush() {
        stack.push(1);
        assertEquals(1, stack.size());
    }
    // ... more tests
}
```

### 6. Create Helper Files
- **mvn-helper.sh**: Shell script with commands for test, compile, coverage, clean
- **java/README.md**: Instructions for Maven commands and test execution

### 7. Verify Setup
Run: `mvn clean test` from the java directory to ensure all tests pass

## Testing Standards for Java

When creating Java test classes, follow these patterns:

### Test Method Naming
- Use descriptive names: `testPushAddsElement`, `testPopRemovesElement`
- Format: `test{Operation}{Condition}{Expected}`

### Test Organization
- Use `@BeforeEach` to initialize test objects
- Use `@Test` for individual test methods
- Use `@ParameterizedTest` for testing multiple values

### Assertions to Use
- `assertEquals(expected, actual)` - For equality
- `assertTrue(condition)` - For boolean conditions
- `assertNull(obj)` - For null checks
- `assertArrayEquals(expected, actual)` - For arrays
- `assertThrows(Exception.class, () -> {...})` - For exception testing

## Git Conventions
**CRITICAL: Only perform git operations (commit, push, pull, merge) when explicitly requested by the user. Do not automatically commit or push code changes.**

- Commit messages should reference the data structure or algorithm being added
- Example: "feat: Add Binary Search Tree implementation with insert and search"
- For Java: "feat(java): Add Stack data structure with JUnit 5 tests"
- For multiple files: "feat: Add BubbleSort and MergeSort with comprehensive test coverage"

### Required Permissions
- **Committing code**: User must explicitly request with "commit", "save changes", or similar phrasing
- **Pushing code**: User must explicitly request with "push", "push to remote", "push to github", or similar phrasing
- **Creating/switching branches**: User must explicitly request git branch operations
- **Merging branches**: User must explicitly request merge operations
- Default behavior: Make code changes and show what was modified, but wait for explicit permission before any git operations

## LLD (Low-Level Design) - Interview Preparation

### Workspace Structure for LLD
```
java/src/main/java/lld/
├── patterns/
│   ├── creational/      (Singleton, Factory, Builder, Prototype)
│   ├── structural/      (Adapter, Decorator, Facade, Proxy, Bridge)
│   └── behavioral/      (Observer, Strategy, Command, State, Template)
└── problems/
    ├── parking_lot/     (Vehicle types, parking spots, levels, payment)
    ├── elevator_system/ (Elevator dispatcher, state management, scheduling)
    ├── library_management/ (Books, members, borrowing, fines)
    ├── atm_machine/     (Authentication, transactions, state machine)
    └── other_systems/   (Traffic Light, Vending Machine, etc.)
```

### LLD Design Patterns

#### Creational Patterns
1. **Singleton** - Used in: Database connections, Logger, Configuration Manager, ATM
   - Implement using: Bill Pugh Singleton (thread-safe, lazy initialization)
   
2. **Factory Pattern** - Used in: Creating different types of objects without exposing creation logic
   - Implement using: Static factory methods or factory classes
   
3. **Builder Pattern** - Used in: Complex object creation with many optional fields
   - Implement using: Fluent builder with return this pattern
   
4. **Prototype** - Used in: Cloning complex objects
   - Implement using: Cloneable interface and clone() method

#### Behavioral Patterns
1. **Observer Pattern** - Used in: Event handling, MVC, real-time updates
   - Implement using: Subject interface with attach/detach/notify methods
   
2. **Strategy Pattern** - Used in: Different payment methods, sorting algorithms, discounts
   - Implement using: Strategy interface with different implementations
   
3. **State Pattern** - Used in: ATM machine states, Elevator states, Order states
   - Implement using: State interface with concrete state classes
   
4. **Command Pattern** - Used in: Undo/Redo, Task scheduling, HTTP requests
   - Implement using: Command interface with execute method

### LLD Problem Solving Approach

#### Step 1: Clarify Requirements
- Ask about scale and capacity
- Understand core use cases
- Identify constraints and limitations
- Discuss read/write ratio

#### Step 2: Design System Architecture
- List main components/classes
- Identify relationships and dependencies
- Define the main entities
- Sketch the architecture

#### Step 3: Design Core Classes
- Class diagrams showing relationships
- Define public methods and attributes
- Use proper access modifiers (private, public, protected)
- Implement inheritance when appropriate (extends/implements)

#### Step 4: Handle Key Scenarios
- Thread safety where needed
- Error handling
- Edge cases
- Scalability considerations

#### Step 5: Implement and Test
- Write clean, well-commented code
- Follow SOLID principles:
  - **S**ingle Responsibility - One reason to change
  - **O**pen/Closed - Open for extension, closed for modification
  - **L**iskov Substitution - Subtypes must be substitutable
  - **I**nterface Segregation - Many client-specific interfaces
  - **D**ependency Inversion - Depend on abstractions, not concretions
- Write comprehensive test cases

### Common LLD Problems & Solutions

#### 1. Parking Lot System
- Components: ParkingLot, Level, ParkingSpot, Vehicle, Ticket
- Patterns: Singleton (ParkingLot), Strategy (different spot types)
- Key features: Spot allocation, capacity tracking, multi-level support

#### 2. Elevator System
- Components: ElevatorSystem, Elevator, Floor, Request
- Patterns: Singleton (ElevatorSystem), Observer (floor requests), State (elevator states)
- Key features: Request queuing, optimal elevator selection, capacity management

#### 3. Library Management
- Components: Library, Book, Member, BorrowRecord, Reservation
- Patterns: Singleton (Library), Observer (reservations)
- Key features: Book availability, fine calculation, transaction history

#### 4. ATM Machine
- Components: ATM, BankAccount, User, Transaction
- Patterns: Singleton (ATM), State (ATM states), Strategy (transaction types)
- Key features: Authentication, withdrawal/deposit, balance tracking

#### 5. Online Shopping System
- Components: ShoppingCart, Product, Order, Payment
- Patterns: Strategy (payment methods), Observer (order status)
- Key features: Cart management, inventory tracking, order processing

#### 6. Vending Machine
- Components: VendingMachine, Item, Coin, Selection
- Patterns: State (machine states), Strategy (payment methods)
- Key features: Inventory management, coin handling, change calculation

#### 7. Traffic Light System
- Components: TrafficLight, Road, Intersection
- Patterns: State (light states), Observer (vehicle detection)
- Key features: State transitions, timing, coordination

### LLD Coding Standards

**Java LLD Code:**
- Use proper package naming: `lld.patterns.*` and `lld.problems.*`
- Use access modifiers appropriately (private preferred)
- Create interfaces for contracts
- Use abstract classes for common implementations
- Implement toString() for debugging
- Add comprehensive JavaDoc for complex logic

**Example Class Structure:**
```java
package lld.problems.parking_lot;

public class ParkingLot {
    private static ParkingLot instance;  // Singleton
    private List<Level> levels;
    
    private ParkingLot() {  // Private constructor
    }
    
    public static synchronized ParkingLot getInstance() {  // Thread-safe
        if (instance == null) {
            instance = new ParkingLot();
        }
        return instance;
    }
}
```

### Testing LLD Implementations

- Test individual components
- Test interactions between components
- Test edge cases and error scenarios
- Verify patterns are correctly implemented
- Check for thread safety if multi-threaded
- Validate state transitions

### LLD Interview Tips

1. **Clarify before coding** - Ask questions for 5-10 minutes
2. **Draw diagrams** - Class, sequence, and deployment diagrams
3. **Start simple** - Add complexity only when asked
4. **Use design patterns** - Show knowledge of patterns
5. **Handle concurrency** - Consider thread safety
6. **Write clean code** - Comments, clear naming, proper structure
7. **Test thoroughly** - Show test cases during implementation
8. **Discuss trade-offs** - Scalability vs complexity vs maintainability
9. **Consider extensibility** - Make it easy to add new features
10. **Explain decisions** - Why you chose certain patterns or approaches
