package lld.problems.elevator_system;

import java.util.*;

/**
 * Elevator System - LLD Problem
 * 
 * Requirements:
 * 1. Multiple elevators
 * 2. Multiple floors
 * 3. Up/Down requests
 * 4. Elevator capacity
 * 5. Current location and direction
 * 6. Queue management
 * 
 * Design:
 * - ElevatorSystem (singleton)
 * - Elevator
 * - Floor
 * - Request
 * - Direction enum
 * - ElevatorDispatcher
 */

class ElevatorSystem {
    private static ElevatorSystem instance;
    private List<Elevator> elevators;
    private int totalFloors;
    
    private ElevatorSystem(int numElevators, int totalFloors) {
        this.totalFloors = totalFloors;
        elevators = new ArrayList<>();
        for (int i = 0; i < numElevators; i++) {
            elevators.add(new Elevator(i + 1, totalFloors));
        }
    }
    
    public static synchronized ElevatorSystem getInstance(int numElevators, int totalFloors) {
        if (instance == null) {
            instance = new ElevatorSystem(numElevators, totalFloors);
        }
        return instance;
    }
    
    public void requestElevator(int fromFloor, int toFloor) {
        Request request = new Request(fromFloor, toFloor);
        Elevator bestElevator = findBestElevator(request);
        
        if (bestElevator != null) {
            bestElevator.addRequest(request);
        }
    }
    
    private Elevator findBestElevator(Request request) {
        Elevator bestElevator = elevators.get(0);
        int minDistance = Integer.MAX_VALUE;
        
        for (Elevator elevator : elevators) {
            int distance = Math.abs(elevator.getCurrentFloor() - request.getFromFloor());
            if (distance < minDistance) {
                minDistance = distance;
                bestElevator = elevator;
            }
        }
        
        return bestElevator;
    }
    
    public void operateElevators() {
        for (Elevator elevator : elevators) {
            elevator.moveToNextFloor();
        }
    }
    
    public void displayStatus() {
        for (Elevator elevator : elevators) {
            System.out.println(elevator);
        }
    }
}

class Elevator {
    private int id;
    private int currentFloor;
    private Direction direction;
    private Queue<Request> upRequests;
    private Queue<Request> downRequests;
    private int capacity;
    private int currentLoad;
    private int totalFloors;
    
    public Elevator(int id, int totalFloors) {
        this.id = id;
        this.currentFloor = 0;
        this.direction = Direction.UP;
        this.upRequests = new PriorityQueue<>();
        this.downRequests = new PriorityQueue<>(Comparator.reverseOrder());
        this.capacity = 10;
        this.currentLoad = 0;
        this.totalFloors = totalFloors;
    }
    
    public void addRequest(Request request) {
        if (currentLoad >= capacity) {
            return;
        }
        
        if (request.getToFloor() > currentFloor) {
            upRequests.offer(request);
        } else {
            downRequests.offer(request);
        }
        currentLoad++;
    }
    
    public void moveToNextFloor() {
        if (direction == Direction.UP) {
            if (!upRequests.isEmpty()) {
                Request nextRequest = upRequests.peek();
                if (currentFloor == nextRequest.getFromFloor()) {
                    currentLoad--;
                    upRequests.poll();
                } else if (currentFloor == nextRequest.getToFloor()) {
                    currentFloor++;
                } else {
                    currentFloor++;
                }
            } else if (!downRequests.isEmpty()) {
                direction = Direction.DOWN;
                currentFloor--;
            } else {
                currentFloor++;
                if (currentFloor >= totalFloors) {
                    currentFloor = totalFloors - 1;
                }
            }
        } else {
            if (!downRequests.isEmpty()) {
                Request nextRequest = downRequests.peek();
                if (currentFloor == nextRequest.getFromFloor()) {
                    currentLoad--;
                    downRequests.poll();
                } else if (currentFloor == nextRequest.getToFloor()) {
                    currentFloor--;
                } else {
                    currentFloor--;
                }
            } else if (!upRequests.isEmpty()) {
                direction = Direction.UP;
                currentFloor++;
            } else {
                currentFloor--;
                if (currentFloor < 0) {
                    currentFloor = 0;
                }
            }
        }
    }
    
    public int getCurrentFloor() {
        return currentFloor;
    }
    
    @Override
    public String toString() {
        return "Elevator{" +
                "id=" + id +
                ", currentFloor=" + currentFloor +
                ", direction=" + direction +
                ", load=" + currentLoad + "/" + capacity +
                '}';
    }
}

enum Direction {
    UP, DOWN
}

class Request implements Comparable<Request> {
    private int fromFloor;
    private int toFloor;
    
    public Request(int fromFloor, int toFloor) {
        this.fromFloor = fromFloor;
        this.toFloor = toFloor;
    }
    
    public int getFromFloor() {
        return fromFloor;
    }
    
    public int getToFloor() {
        return toFloor;
    }
    
    @Override
    public int compareTo(Request other) {
        return Integer.compare(this.fromFloor, other.fromFloor);
    }
}

// Public facade for Elevator System
public class ElevatorController {
    private static ElevatorSystem instance;
    private int numElevators;
    private int totalFloors;
    
    public ElevatorController(int numElevators, int totalFloors) {
        this.numElevators = numElevators;
        this.totalFloors = totalFloors;
        instance = ElevatorSystem.getInstance(numElevators, totalFloors);
    }
    
    public void requestElevator(int fromFloor, int toFloor) {
        instance.requestElevator(fromFloor, toFloor);
    }
    
    public void operateElevators() {
        instance.operateElevators();
    }
    
    public void displayStatus() {
        instance.displayStatus();
    }
}
