# Java DSA Testing with Maven

This directory contains Data Structures and Algorithms implementations in Java with comprehensive test coverage using JUnit 5.

## Prerequisites

1. **Java Development Kit (JDK)** - Version 11 or higher
   ```bash
   # Check Java version
   java -version
   
   # Install via Homebrew (macOS)
   brew install java@11
   ```

2. **Maven** - Build and test framework
   ```bash
   # Check Maven version
   mvn -v
   
   # Install via Homebrew (macOS)
   brew install maven
   ```

## Project Structure

```
java/
├── pom.xml
├── src/
│   ├── main/
│   │   └── java/
│   │       └── dsa/
│   │           ├── datastructures/
│   │           │   ├── Stack.java
│   │           │   └── Queue.java
│   │           └── algorithms/
│   │               ├── searching/
│   │               │   └── BinarySearch.java
│   │               └── sorting/
│   │                   └── BubbleSort.java
│   └── test/
│       └── java/
│           └── dsa/
│               ├── StackTest.java
│               ├── BinarySearchTest.java
│               └── BubbleSortTest.java
```

## Maven Commands

### Run Tests
```bash
cd java

# Run all tests
mvn test

# Run specific test class
mvn test -Dtest=StackTest

# Run specific test method
mvn test -Dtest=StackTest#testPush

# Run tests with verbose output
mvn test -X
```

### Compile Code
```bash
# Compile source code
mvn compile

# Compile including tests
mvn test-compile
```

### Clean Build
```bash
# Clean previous build artifacts
mvn clean

# Clean and compile
mvn clean compile

# Clean and test
mvn clean test
```

### Code Coverage
```bash
# Generate code coverage report
mvn test jacoco:report

# View coverage report
open target/site/jacoco/index.html
```

### Build JAR
```bash
# Create executable JAR
mvn package

# Run JAR
java -cp target/dsa-java-1.0.0.jar com.example.Main
```

## Dependencies

- **JUnit 5** (Jupiter) - Unit testing framework
- **AssertJ** - Fluent assertions for more readable tests
- **JaCoCo** - Code coverage analysis

## Test Coverage

The project includes comprehensive test suites:

- **StackTest** (9 tests)
  - Push/Pop operations
  - Peek functionality
  - Empty stack behavior
  - LIFO ordering
  
- **BinarySearchTest** (12 tests)
  - Recursive and iterative implementations
  - Edge cases (first, middle, last elements)
  - Not found scenarios
  - Parameterized tests

- **BubbleSortTest** (8 tests)
  - Basic sorting
  - Already sorted arrays
  - Reverse sorted arrays
  - Duplicates and negative numbers

## Quick Start

```bash
# Navigate to java directory
cd java

# Clean and run all tests
mvn clean test

# Expected output should show all tests passing
```

## Writing New Tests

Example using JUnit 5:

```java
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class MyTest {
    @Test
    void testSomething() {
        assertEquals(expected, actual);
    }
}
```

### Useful Assertions

```java
assertEquals(expected, actual);
assertNotEquals(unexpected, actual);
assertTrue(condition);
assertFalse(condition);
assertNull(obj);
assertNotNull(obj);
assertThrows(Exception.class, () -> { /* code */ });
assertArrayEquals(expectedArray, actualArray);
```

## Performance Notes

- First Maven run downloads dependencies (~200MB)
- Subsequent runs are much faster with cached dependencies
- Tests compile and run in ~5-10 seconds

## Troubleshooting

**Maven not found:**
```bash
# Make sure Maven is in PATH
export PATH=$PATH:/opt/homebrew/opt/maven/bin

# Or use full path
/opt/homebrew/opt/maven/bin/mvn test
```

**Java version mismatch:**
```bash
# Verify Java version (should be 11+)
java -version

# Set JAVA_HOME if needed
export JAVA_HOME=$(/usr/libexec/java_home -v 11)
```

**Clear Maven cache:**
```bash
rm -rf ~/.m2/repository
mvn clean
```
