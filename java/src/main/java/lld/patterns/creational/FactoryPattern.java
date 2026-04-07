package lld.patterns.creational;

/**
 * Factory Pattern - Creational Pattern
 * 
 * Purpose: Create objects without specifying their exact classes.
 * 
 * When to use:
 * - Creating different types of database connections (MySQL, PostgreSQL)
 * - Creating different payment processors (Credit Card, PayPal, Bitcoin)
 * - Creating different notification services (Email, SMS, Push)
 */

// Product Interface
interface Animal {
    void makeSound();
    String getType();
}

// Concrete Products
class Dog implements Animal {
    @Override
    public void makeSound() {
        System.out.println("Woof!");
    }
    
    @Override
    public String getType() {
        return "Dog";
    }
}

class Cat implements Animal {
    @Override
    public void makeSound() {
        System.out.println("Meow!");
    }
    
    @Override
    public String getType() {
        return "Cat";
    }
}

class Bird implements Animal {
    @Override
    public void makeSound() {
        System.out.println("Tweet!");
    }
    
    @Override
    public String getType() {
        return "Bird";
    }
}

// Factory Class
class AnimalFactory {
    public static Animal createAnimal(String type) {
        if (type == null) {
            return null;
        }
        
        switch (type.toLowerCase()) {
            case "dog":
                return new Dog();
            case "cat":
                return new Cat();
            case "bird":
                return new Bird();
            default:
                throw new IllegalArgumentException("Unknown animal type: " + type);
        }
    }
}

// Public facade for Factory pattern
public class FactoryPattern {
    public static Animal createAnimal(String type) {
        return AnimalFactory.createAnimal(type);
    }
}
