package lld.patterns.behavioral;

import java.util.ArrayList;
import java.util.List;

/**
 * Observer Pattern - Behavioral Pattern
 * 
 * Purpose: Define a one-to-many dependency between objects so that when one object 
 * changes state, all dependents are notified automatically.
 * 
 * When to use:
 * - Event handling systems
 * - Real-time data updates
 * - MVC pattern (Model-View-Controller)
 * - Stock price updates
 * - Notification systems
 */

// Observer Interface
interface Observer {
    void update(String notification);
}

// Subject Interface
interface Subject {
    void attach(Observer observer);
    void detach(Observer observer);
    void notifyObservers();
}

// Concrete Subject
class StockPriceImpl implements Subject {
    private double price;
    private List<Observer> observers = new ArrayList<>();
    
    public void setPrice(double newPrice) {
        if (newPrice != this.price) {
            this.price = newPrice;
            notifyObservers();
        }
    }
    
    public double getPrice() {
        return price;
    }
    
    @Override
    public void attach(Observer observer) {
        if (!observers.contains(observer)) {
            observers.add(observer);
        }
    }
    
    @Override
    public void detach(Observer observer) {
        observers.remove(observer);
    }
    
    @Override
    public void notifyObservers() {
        for (Observer observer : observers) {
            observer.update("Stock price changed to: $" + price);
        }
    }
}

// Concrete Observers
class StockPortfolio implements Observer {
    private String name;
    
    public StockPortfolio(String name) {
        this.name = name;
    }
    
    @Override
    public void update(String notification) {
        System.out.println(name + " received update: " + notification);
    }
}

class TradingAlgorithm implements Observer {
    @Override
    public void update(String notification) {
        System.out.println("Trading Algorithm received: " + notification);
    }
}

// Public facade for Observer pattern examples
public class ObserverPattern {
    public static Subject createStockPrice() {
        return new StockPriceImpl();
    }
    
    public static Observer createStockPortfolio(String name) {
        return new StockPortfolio(name);
    }
    
    public static Observer createTradingAlgorithm() {
        return new TradingAlgorithm();
    }
}
