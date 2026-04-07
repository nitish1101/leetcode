package lld.patterns.creational;

/**
 * Builder Pattern - Creational Pattern
 * 
 * Purpose: Construct complex objects step by step.
 * 
 * When to use:
 * - Creating objects with many optional parameters
 * - Building immutable objects
 * - Creating objects with complex initialization logic
 * 
 * Example: Creating a User with multiple optional fields
 */

class User {
    private final String name;
    private final String email;
    private final String phone;
    private final String address;
    private final int age;
    
    private User(Builder builder) {
        this.name = builder.name;
        this.email = builder.email;
        this.phone = builder.phone;
        this.address = builder.address;
        this.age = builder.age;
    }
    
    public static class Builder {
        private final String name; // Required
        private String email = "";
        private String phone = "";
        private String address = "";
        private int age = 0;
        
        public Builder(String name) {
            this.name = name;
        }
        
        public Builder email(String email) {
            this.email = email;
            return this;
        }
        
        public Builder phone(String phone) {
            this.phone = phone;
            return this;
        }
        
        public Builder address(String address) {
            this.address = address;
            return this;
        }
        
        public Builder age(int age) {
            this.age = age;
            return this;
        }
        
        public User build() {
            return new User(this);
        }
    }
    
    @Override
    public String toString() {
        return "User{" +
                "name='" + name + '\'' +
                ", email='" + email + '\'' +
                ", phone='" + phone + '\'' +
                ", address='" + address + '\'' +
                ", age=" + age +
                '}';
    }
    
    public String getName() { return name; }
    public String getEmail() { return email; }
    public String getPhone() { return phone; }
    public String getAddress() { return address; }
    public int getAge() { return age; }
}

// Public facade for Builder pattern
public class BuilderPattern {
    public static User createUser(String name, String email, String phone, int age) {
        return new User.Builder(name)
                .email(email)
                .phone(phone)
                .age(age)
                .build();
    }
}

// Usage Example:
// User user = new User.Builder("John Doe")
//     .email("john@example.com")
//     .phone("123-456-7890")
//     .age(30)
//     .build();
