# LLD (Low-Level Design) Interview Preparation

This directory contains comprehensive examples of design patterns and solutions to common LLD (Low-Level Design) interview problems.

## 📁 Directory Structure

```
lld/
├── patterns/
│   ├── creational/     - Object creation patterns
│   ├── structural/     - Object composition patterns
│   └── behavioral/     - Object collaboration patterns
└── problems/
    ├── parking_lot/
    ├── elevator_system/
    ├── library_management/
    ├── atm_machine/
    └── other_systems/
```

## 🎯 Design Patterns

### Creational Patterns (Object Creation)

#### 1. Singleton Pattern
**Purpose**: Ensure a class has only one instance with global access.

**When to use**:
- Database connections
- Logger instances
- Configuration managers
- Thread pools
- Cache managers

**Implementation**: Bill Pugh Singleton (uses class loader for thread safety)

```java
public class Singleton {
    private Singleton() { }
    
    private static class SingletonHelper {
        private static final Singleton INSTANCE = new Singleton();
    }
    
    public static Singleton getInstance() {
        return SingletonHelper.INSTANCE;
    }
}
```

#### 2. Factory Pattern
**Purpose**: Create objects without specifying their exact classes.

**When to use**:
- Database connection objects (MySQL, PostgreSQL)
- Payment processors (Credit Card, PayPal, Bitcoin)
- Notification services (Email, SMS, Push)
- Document readers (PDF, Word, Excel)

#### 3. Builder Pattern
**Purpose**: Construct complex objects step by step.

**When to use**:
- Creating objects with many optional parameters
- Building immutable objects
- Complex object initialization

```java
User user = new User.Builder("John Doe")
    .email("john@example.com")
    .phone("123-456-7890")
    .age(30)
    .build();
```

#### 4. Prototype Pattern
**Purpose**: Clone complex objects efficiently.

**When to use**:
- Expensive object creation
- Avoiding subclass explosion
- Creating independent copies

### Structural Patterns (Object Composition)

#### 1. Adapter Pattern
**Purpose**: Convert incompatible interfaces.

**When to use**:
- Legacy system integration
- Third-party library adaptation
- Different data format conversions

#### 2. Decorator Pattern
**Purpose**: Add functionality to objects dynamically.

**When to use**:
- Text formatting (bold, italic, underline)
- GUI component enhancement
- Stream wrapping (BufferedInputStream)

#### 3. Facade Pattern
**Purpose**: Provide simplified interface to complex subsystems.

**When to use**:
- Library interfaces
- Complex library simplification
- Workflow orchestration

### Behavioral Patterns (Object Collaboration)

#### 1. Observer Pattern
**Purpose**: Create one-to-many dependencies with automatic notification.

**When to use**:
- Event handling systems
- MVC pattern (Model-View-Controller)
- Real-time data updates
- Stock price monitoring
- Notification systems

**Key Components**:
- Subject: Manages observers and sends notifications
- Observer: Receives notifications
- ConcreteSubject: Sends notifications when state changes
- ConcreteObserver: Updates when notified

#### 2. Strategy Pattern
**Purpose**: Define family of algorithms and make them interchangeable.

**When to use**:
- Different payment methods
- Different sorting algorithms
- Discount calculation strategies
- Compression algorithms
- Encryption methods

```java
ShoppingCart cart = new ShoppingCart();
cart.setPaymentStrategy(new CreditCardPayment());
cart.checkout(100.0);
```

#### 3. State Pattern
**Purpose**: Allow object to change behavior when internal state changes.

**When to use**:
- ATM machine states (idle, authenticating, transacting)
- Elevator states (idle, moving up, moving down)
- Order states (pending, shipped, delivered)
- Traffic light states (red, yellow, green)

#### 4. Command Pattern
**Purpose**: Encapsulate requests as objects.

**When to use**:
- Undo/Redo functionality
- Task scheduling
- HTTP requests
- Event queuing
- Macro recording

## 🏗️ LLD Problems

### 1. Parking Lot System

**Requirements**:
- Multiple parking levels
- Multiple spot types (Compact, Regular, Large, Handicapped)
- Vehicle types (Car, Truck, Motorcycle)
- Spot availability tracking
- Capacity management

**Key Classes**:
- `ParkingLot` (Singleton)
- `Level`
- `ParkingSpot` (Abstract)
- `Vehicle` (Abstract)
- `Ticket`

**Patterns Used**: Singleton, Strategy, Factory

**Time Complexity**:
- Park Vehicle: O(n*m) where n = levels, m = spots per level
- Find Available Spot: O(1) amortized

**Space Complexity**: O(n*m)

### 2. Elevator System

**Requirements**:
- Multiple elevators
- Request queuing
- Optimal elevator selection
- Capacity management
- State transitions

**Key Classes**:
- `ElevatorSystem` (Singleton)
- `Elevator`
- `Floor`
- `Request`
- `Direction` (Enum)

**Patterns Used**: Singleton, Observer, State

**Key Algorithm**: SCAN algorithm for elevator scheduling

### 3. Library Management System

**Requirements**:
- Books and copies
- Member management
- Borrowing and returning
- Fine calculation
- Book reservations

**Key Classes**:
- `Library` (Singleton)
- `Book`
- `BookCopy`
- `Member`
- `BorrowRecord`

**Patterns Used**: Singleton, Observer

**Rules**:
- Borrow limit: 14 days
- Late fee: $1.0 per day
- Max books per member: configurable

### 4. ATM Machine

**Requirements**:
- User authentication
- Withdrawal and deposit
- Balance checking
- Transaction history
- State management

**Key Classes**:
- `ATM` (Singleton)
- `BankAccount`
- `User`
- `Transaction`
- `ATMState` (Interface)

**Patterns Used**: Singleton, State, Strategy

**State Transitions**:
- Idle → Authenticating → Transaction → Idle

### 5. Online Shopping System

**Requirements**:
- Shopping cart
- Product inventory
- Order management
- Payment processing
- Order tracking

**Use Cases**:
- Add/remove items from cart
- Apply coupon codes
- Multiple payment methods
- Order history

### 6. Vending Machine

**Requirements**:
- Item management
- Coin handling
- Change calculation
- Inventory tracking
- State management

**Challenges**:
- Insufficient coins for change
- Out of stock items
- Coin jam handling
- Invalid amount handling

### 7. Traffic Light System

**Requirements**:
- Traffic light states
- Timed transitions
- Exception handling
- Coordination in grid

**State Machine**:
- Red (30s) → Green (25s) → Yellow (5s) → Red

## 🧪 Testing

Run all LLD tests:
```bash
cd java
mvn test -Dtest=*Tests
```

Run specific test:
```bash
mvn test -Dtest=ParkingLotTests
mvn test -Dtest=ElevatorSystemTests
mvn test -Dtest=LibraryManagementTests
mvn test -Dtest=ATMMachineTests
mvn test -Dtest=DesignPatternTests
```

Generate coverage report:
```bash
mvn test jacoco:report
open target/site/jacoco/index.html
```

## 📚 Interview Tips

### Before Coding (5-10 minutes)
1. **Ask clarifying questions**
   - How many users/items/parking spots?
   - What's the scale?
   - Main use cases?
   - Any constraints?

2. **Discuss requirements**
   - Functional vs non-functional
   - Single vs multi-threaded?
   - Persistence needed?

3. **Propose architecture**
   - List main components
   - Show relationships
   - Discuss patterns

### During Coding (30-40 minutes)
1. **Start simple**
   - Create basic classes
   - Add core functionality
   - Make it work first

2. **Add complexity**
   - Thread safety
   - Error handling
   - Edge cases

3. **Optimize**
   - Review time/space complexity
   - Remove redundancies
   - Improve readability

### After Coding (5-10 minutes)
1. **Test thoroughly**
   - Happy path scenarios
   - Edge cases
   - Error scenarios

2. **Discuss improvements**
   - How would you scale?
   - Handle failures?
   - Add new features?

3. **Reflection**
   - SOLID principles followed?
   - Design patterns used appropriately?
   - Code quality and readability?

## 📊 Key Metrics to Discuss

**Scalability**:
- How to handle 1M parking spots?
- How to scale to multiple parking lots?
- Distributed system considerations?

**Performance**:
- Time complexity of core operations
- Space complexity considerations
- Caching opportunities

**Reliability**:
- Transaction handling
- Failure scenarios
- Recovery mechanisms

**Maintainability**:
- Code organization
- Pattern usage
- Extension points

## 🔗 Related Topics

- Observer vs Pub-Sub
- Singleton vs Monostate
- Strategy vs Policy vs Template Method
- State vs Strategy
- Adapter vs Decorator vs Facade
- Composition vs Inheritance

## 📖 Resources

- Design Patterns: Elements of Reusable Object-Oriented Software (Gang of Four)
- Head First Design Patterns
- Refactoring.Guru Design Patterns
- Baeldung Design Pattern Tutorials

## 🎓 Learning Path

1. **Week 1**: Master Singleton, Factory, Builder patterns
2. **Week 2**: Master Observer, Strategy, State patterns
3. **Week 3**: Solve Parking Lot and Elevator System
4. **Week 4**: Solve Library Management and ATM Machine
5. **Week 5**: Additional problems and refinement

---

**Last Updated**: 7 April 2026

Happy Learning! 🚀
