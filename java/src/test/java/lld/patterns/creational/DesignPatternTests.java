package lld.patterns.creational;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Test suite for Design Patterns
 */
class DesignPatternTests {
    
    @Test
    void testSingletonInstance() {
        SingletonBillPugh instance1 = SingletonBillPugh.getInstance();
        SingletonBillPugh instance2 = SingletonBillPugh.getInstance();
        
        assertSame(instance1, instance2, "Should return the same instance");
    }
    
    @Test
    void testFactoryPattern() {
        Animal dog = AnimalFactory.createAnimal("dog");
        Animal cat = AnimalFactory.createAnimal("cat");
        Animal bird = AnimalFactory.createAnimal("bird");
        
        assertNotNull(dog);
        assertNotNull(cat);
        assertNotNull(bird);
        assertEquals("Dog", dog.getType());
        assertEquals("Cat", cat.getType());
        assertEquals("Bird", bird.getType());
    }
    
    @Test
    void testFactoryInvalidType() {
        assertThrows(IllegalArgumentException.class, () -> {
            AnimalFactory.createAnimal("invalid");
        });
    }
    
    @Test
    void testBuilderPattern() {
        User user = new User.Builder("John Doe")
                .email("john@example.com")
                .phone("123-456-7890")
                .age(30)
                .build();
        
        assertEquals("John Doe", user.getName());
        assertEquals("john@example.com", user.getEmail());
        assertEquals("123-456-7890", user.getPhone());
        assertEquals(30, user.getAge());
    }
    
    @Test
    void testBuilderWithMinimalFields() {
        User user = new User.Builder("Jane Doe")
                .email("jane@example.com")
                .build();
        
        assertEquals("Jane Doe", user.getName());
        assertEquals("jane@example.com", user.getEmail());
        assertEquals("", user.getPhone());
        assertEquals(0, user.getAge());
    }
}
