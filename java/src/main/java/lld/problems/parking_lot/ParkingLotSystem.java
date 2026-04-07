package lld.problems.parking_lot;

/**
 * Parking Lot System - LLD Problem
 * 
 * Requirements:
 * 1. Multiple parking levels
 * 2. Multiple types of parking spots (Compact, Regular, Large, Handicapped)
 * 3. Multiple vehicle types (Car, Truck, Motorcycle)
 * 4. Parking rate calculation
 * 5. Available spot tracking
 * 
 * Design:
 * - ParkingLot (singleton)
 * - Level
 * - ParkingSpot (abstract)
 * - CompactSpot, RegularSpot, LargeSpot, HandicappedSpot
 * - Vehicle (abstract)
 * - Car, Truck, Motorcycle
 * - Ticket
 * - ParkingRate
 */

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

class ParkingLot {
    private static ParkingLot instance;
    private List<Level> levels;
    
    private ParkingLot() {
        levels = new ArrayList<>();
    }
    
    public static synchronized ParkingLot getInstance() {
        if (instance == null) {
            instance = new ParkingLot();
        }
        return instance;
    }
    
    public void addLevel(Level level) {
        levels.add(level);
    }
    
    public boolean parkVehicle(Vehicle vehicle) {
        for (Level level : levels) {
            if (level.parkVehicle(vehicle)) {
                return true;
            }
        }
        return false;
    }
    
    public boolean unparkVehicle(Vehicle vehicle) {
        for (Level level : levels) {
            if (level.unparkVehicle(vehicle)) {
                return true;
            }
        }
        return false;
    }
    
    public int getAvailableSpots() {
        return levels.stream().mapToInt(Level::getAvailableSpots).sum();
    }
}

class Level {
    private int floor;
    private List<ParkingSpot> spots;
    
    public Level(int floor, int totalSpots) {
        this.floor = floor;
        spots = new ArrayList<>();
        initializeSpots(totalSpots);
    }
    
    private void initializeSpots(int totalSpots) {
        int compact = totalSpots / 3;
        int regular = totalSpots / 3;
        int large = totalSpots / 6;
        int handicapped = totalSpots - compact - regular - large;
        
        for (int i = 0; i < compact; i++) {
            spots.add(new CompactSpot(i, floor));
        }
        for (int i = 0; i < regular; i++) {
            spots.add(new RegularSpot(i + compact, floor));
        }
        for (int i = 0; i < large; i++) {
            spots.add(new LargeSpot(i + compact + regular, floor));
        }
        for (int i = 0; i < handicapped; i++) {
            spots.add(new HandicappedSpot(i + compact + regular + large, floor));
        }
    }
    
    public boolean parkVehicle(Vehicle vehicle) {
        for (ParkingSpot spot : spots) {
            if (spot.canFitVehicle(vehicle) && spot.park(vehicle)) {
                return true;
            }
        }
        return false;
    }
    
    public boolean unparkVehicle(Vehicle vehicle) {
        for (ParkingSpot spot : spots) {
            if (spot.unpark(vehicle)) {
                return true;
            }
        }
        return false;
    }
    
    public int getAvailableSpots() {
        return (int) spots.stream().filter(spot -> !spot.isOccupied()).count();
    }
}

abstract class ParkingSpot {
    protected int spotId;
    protected int floor;
    protected boolean isOccupied;
    protected Vehicle parkedVehicle;
    protected LocalDateTime parkedTime;
    
    public ParkingSpot(int spotId, int floor) {
        this.spotId = spotId;
        this.floor = floor;
        this.isOccupied = false;
    }
    
    public abstract boolean canFitVehicle(Vehicle vehicle);
    
    public boolean park(Vehicle vehicle) {
        if (isOccupied || !canFitVehicle(vehicle)) {
            return false;
        }
        isOccupied = true;
        parkedVehicle = vehicle;
        parkedTime = LocalDateTime.now();
        return true;
    }
    
    public boolean unpark(Vehicle vehicle) {
        if (!isOccupied || !parkedVehicle.equals(vehicle)) {
            return false;
        }
        isOccupied = false;
        parkedVehicle = null;
        parkedTime = null;
        return true;
    }
    
    public boolean isOccupied() {
        return isOccupied;
    }
}

class CompactSpot extends ParkingSpot {
    public CompactSpot(int spotId, int floor) {
        super(spotId, floor);
    }
    
    @Override
    public boolean canFitVehicle(Vehicle vehicle) {
        return vehicle.getSize() == VehicleSize.COMPACT;
    }
}

class RegularSpot extends ParkingSpot {
    public RegularSpot(int spotId, int floor) {
        super(spotId, floor);
    }
    
    @Override
    public boolean canFitVehicle(Vehicle vehicle) {
        return vehicle.getSize() != VehicleSize.LARGE;
    }
}

class LargeSpot extends ParkingSpot {
    public LargeSpot(int spotId, int floor) {
        super(spotId, floor);
    }
    
    @Override
    public boolean canFitVehicle(Vehicle vehicle) {
        return true;
    }
}

class HandicappedSpot extends ParkingSpot {
    public HandicappedSpot(int spotId, int floor) {
        super(spotId, floor);
    }
    
    @Override
    public boolean canFitVehicle(Vehicle vehicle) {
        return vehicle.isHandicapped();
    }
}

enum VehicleSize {
    COMPACT, REGULAR, LARGE
}

abstract class Vehicle {
    protected String licensePlate;
    protected VehicleSize size;
    protected boolean isHandicapped;
    
    public Vehicle(String licensePlate, VehicleSize size, boolean isHandicapped) {
        this.licensePlate = licensePlate;
        this.size = size;
        this.isHandicapped = isHandicapped;
    }
    
    public VehicleSize getSize() {
        return size;
    }
    
    public boolean isHandicapped() {
        return isHandicapped;
    }
    
    public String getLicensePlate() {
        return licensePlate;
    }
}

class Car extends Vehicle {
    public Car(String licensePlate, boolean isHandicapped) {
        super(licensePlate, VehicleSize.COMPACT, isHandicapped);
    }
}

class Truck extends Vehicle {
    public Truck(String licensePlate) {
        super(licensePlate, VehicleSize.LARGE, false);
    }
}

class Motorcycle extends Vehicle {
    public Motorcycle(String licensePlate) {
        super(licensePlate, VehicleSize.COMPACT, false);
    }
}

// Public facade for Parking Lot System
public class ParkingLotSystem {
    private static ParkingLot parkingLot = ParkingLot.getInstance();
    
    public static ParkingLot getInstance() {
        return parkingLot;
    }
    
    public static void addLevel(Level level) {
        parkingLot.addLevel(level);
    }
    
    public static boolean parkVehicle(Vehicle vehicle) {
        return parkingLot.parkVehicle(vehicle);
    }
    
    public static boolean unparkVehicle(Vehicle vehicle) {
        return parkingLot.unparkVehicle(vehicle);
    }
    
    public static int getAvailableSpots() {
        return parkingLot.getAvailableSpots();
    }
}
