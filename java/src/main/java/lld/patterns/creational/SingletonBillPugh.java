package lld.patterns.creational;

/**
 * Bill Pugh Singleton Pattern
 * 
 * Best approach for Singleton pattern - uses class loader mechanism.
 * Thread-safe without synchronization, lazy initialization.
 */
public class SingletonBillPugh {
    private SingletonBillPugh() {
    }
    
    private static class SingletonHelper {
        private static final SingletonBillPugh INSTANCE = new SingletonBillPugh();
    }
    
    public static SingletonBillPugh getInstance() {
        return SingletonHelper.INSTANCE;
    }
}
