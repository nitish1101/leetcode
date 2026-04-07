package lld.patterns.behavioral;

/**
 * Strategy Pattern - Behavioral Pattern
 * 
 * Purpose: Define a family of algorithms, encapsulate each one, and make them interchangeable.
 * 
 * When to use:
 * - Different payment methods
 * - Different sorting algorithms
 * - Different discount calculation strategies
 * - Different encryption algorithms
 */

// Strategy Interface
interface PaymentStrategy {
    boolean pay(double amount);
    String getPaymentMethod();
}

// Concrete Strategies
class CreditCardPayment implements PaymentStrategy {
    private String cardNumber;
    
    public CreditCardPayment(String cardNumber) {
        this.cardNumber = cardNumber;
    }
    
    @Override
    public boolean pay(double amount) {
        System.out.println("Paid $" + amount + " using Credit Card ending in " + 
                          cardNumber.substring(cardNumber.length() - 4));
        return true;
    }
    
    @Override
    public String getPaymentMethod() {
        return "Credit Card";
    }
}

class PayPalPayment implements PaymentStrategy {
    private String email;
    
    public PayPalPayment(String email) {
        this.email = email;
    }
    
    @Override
    public boolean pay(double amount) {
        System.out.println("Paid $" + amount + " using PayPal account: " + email);
        return true;
    }
    
    @Override
    public String getPaymentMethod() {
        return "PayPal";
    }
}

class BitcoinPayment implements PaymentStrategy {
    private String walletAddress;
    
    public BitcoinPayment(String walletAddress) {
        this.walletAddress = walletAddress;
    }
    
    @Override
    public boolean pay(double amount) {
        System.out.println("Paid " + amount + " BTC to wallet: " + walletAddress);
        return true;
    }
    
    @Override
    public String getPaymentMethod() {
        return "Bitcoin";
    }
}

// Context
class ShoppingCart {
    private PaymentStrategy paymentStrategy;
    
    public void setPaymentStrategy(PaymentStrategy strategy) {
        this.paymentStrategy = strategy;
    }
    
    public boolean checkout(double amount) {
        if (paymentStrategy == null) {
            throw new IllegalStateException("Payment strategy not set");
        }
        return paymentStrategy.pay(amount);
    }
}

// Public facade for Strategy pattern
public class StrategyPattern {
    public static ShoppingCart createCart() {
        return new ShoppingCart();
    }
    
    public static PaymentStrategy createCreditCardPayment(String cardNumber) {
        return new CreditCardPayment(cardNumber);
    }
    
    public static PaymentStrategy createPayPalPayment(String email) {
        return new PayPalPayment(email);
    }
    
    public static PaymentStrategy createBitcoinPayment(String walletAddress) {
        return new BitcoinPayment(walletAddress);
    }
}
