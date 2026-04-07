package lld.patterns.creational;

/**
 * Singleton Pattern - Creational Pattern
 * 
 * Purpose: Ensure a class has only one instance and provide a global point of access to it.
 * 
 * When to use:
 * - Database connections
 * - Logging
 * - Configuration managers
 * - Thread pools
 * - Cache managers
 */

// Eager Initialization (Thread-safe but creates instance on class load)
class SingletonEager {
    private static final SingletonEager INSTANCE = new SingletonEager();
    
    private SingletonEager() {
        // Private constructor prevents instantiation
    }
    
    public static SingletonEager getInstance() {
        return INSTANCE;
    }
}

// Public facade for Singleton pattern
public class SingletonPattern {
    public static SingletonEager getEagerInstance() {
        return SingletonEager.getInstance();
    }
}
