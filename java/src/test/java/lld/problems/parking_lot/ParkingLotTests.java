package lld.problems.parking_lot;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Test suite for Parking Lot System
 */
class ParkingLotTests {
    private ParkingLotSystem parkingLot;
    
    @BeforeEach
    void setUp() {
        parkingLot = new ParkingLotSystem();
        // Initialize levels
        parkingLot.addLevel(new Level(1, 10));
        parkingLot.addLevel(new Level(2, 10));
    }
    
    @Test
    void testParkCar() {
        Car car = new Car("ABC123", false);
        assertTrue(parkingLot.parkVehicle(car));
    }
    
    @Test
    void testParkMultipleVehicles() {
        Car car = new Car("ABC123", false);
        Motorcycle bike = new Motorcycle("BIKE456");
        
        assertTrue(parkingLot.parkVehicle(car));
        assertTrue(parkingLot.parkVehicle(bike));
    }
    
    @Test
    void testUnparkVehicle() {
        Car car = new Car("ABC123", false);
        parkingLot.parkVehicle(car);
        
        assertTrue(parkingLot.unparkVehicle(car));
    }
    
    @Test
    void testAvailableSpots() {
        int initialSpots = parkingLot.getAvailableSpots();
        
        Car car = new Car("ABC123", false);
        parkingLot.parkVehicle(car);
        
        assertEquals(initialSpots - 1, parkingLot.getAvailableSpots());
    }
    
    @Test
    void testHandicappedParkingSpot() {
        Car handicappedCar = new Car("HANDI123", true);
        assertTrue(parkingLot.parkVehicle(handicappedCar));
    }
    
    @Test
    void testTruckParkingSize() {
        Truck truck = new Truck("TRUCK123");
        assertTrue(parkingLot.parkVehicle(truck));
    }
}
