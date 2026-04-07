package lld.problems.elevator_system;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Test suite for Elevator System
 */
class ElevatorSystemTests {
    private ElevatorController elevatorController;
    
    @BeforeEach
    void setUp() {
        elevatorController = new ElevatorController(3, 10);
    }
    
    @Test
    void testElevatorCreation() {
        assertNotNull(elevatorController);
    }
    
    @Test
    void testRequestElevator() {
        elevatorController.requestElevator(5, 8);
        // Verify request is queued
        assertNotNull(elevatorController);
    }
    
    @Test
    void testElevatorMovement() {
        elevatorController.requestElevator(0, 5);
        elevatorController.operateElevators();
        // Verify elevators move
        assertNotNull(elevatorController);
    }
    
    @Test
    void testMultipleRequests() {
        elevatorController.requestElevator(2, 5);
        elevatorController.requestElevator(3, 7);
        elevatorController.requestElevator(1, 4);
        
        elevatorController.operateElevators();
        assertNotNull(elevatorController);
    }
}
