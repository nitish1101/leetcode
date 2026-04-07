#!/bin/bash

# DSA Java - Maven Helper Script
# Simplifies common Maven operations

usage() {
    echo "Usage: ./mvn-helper.sh [command]"
    echo ""
    echo "Commands:"
    echo "  test              Run all tests"
    echo "  test-class NAME   Run specific test class (e.g., StackTest)"
    echo "  test-method N.M   Run specific test method (e.g., StackTest#testPush)"
    echo "  coverage          Generate code coverage report"
    echo "  compile           Compile source code"
    echo "  clean             Clean build artifacts"
    echo "  rebuild           Clean and compile"
    echo "  package           Create JAR file"
    echo "  help              Show this help message"
}

case "$1" in
    test)
        echo "Running all tests..."
        mvn clean test
        ;;
    test-class)
        if [ -z "$2" ]; then
            echo "Please provide a test class name"
            echo "Usage: ./mvn-helper.sh test-class ClassName"
            exit 1
        fi
        echo "Running $2 tests..."
        mvn test -Dtest="$2"
        ;;
    test-method)
        if [ -z "$2" ]; then
            echo "Please provide a test method name"
            echo "Usage: ./mvn-helper.sh test-method ClassName#methodName"
            exit 1
        fi
        echo "Running $2..."
        mvn test -Dtest="$2"
        ;;
    coverage)
        echo "Generating coverage report..."
        mvn clean test jacoco:report
        echo "Coverage report generated at: target/site/jacoco/index.html"
        ;;
    compile)
        echo "Compiling source code..."
        mvn compile
        ;;
    clean)
        echo "Cleaning build artifacts..."
        mvn clean
        ;;
    rebuild)
        echo "Cleaning and compiling..."
        mvn clean compile
        ;;
    package)
        echo "Creating JAR package..."
        mvn clean package
        ;;
    help|"")
        usage
        ;;
    *)
        echo "Unknown command: $1"
        usage
        exit 1
        ;;
esac
