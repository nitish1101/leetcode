package lld.problems.atm_machine;

/**
 * ATM Machine - LLD Problem
 * 
 * Requirements:
 * 1. User authentication
 * 2. Withdrawal
 * 3. Deposit
 * 4. Balance check
 * 5. PIN verification
 * 6. Transaction history
 * 
 * Design:
 * - ATM (singleton)
 * - BankAccount
 * - User
 * - Transaction
 * - ATMState (state pattern)
 * - IdleState, AuthenticatingState, TransactionState
 */

import java.util.*;

class ATM {
    private static ATM instance;
    private Map<String, BankAccount> accounts;
    private BankAccount currentAccount;
    private ATMState state;
    
    private ATM() {
        accounts = new HashMap<>();
        state = new IdleState(this);
    }
    
    public static synchronized ATM getInstance() {
        if (instance == null) {
            instance = new ATM();
        }
        return instance;
    }
    
    public void createAccount(String accountNumber, String pin, double initialBalance) {
        accounts.put(accountNumber, new BankAccount(accountNumber, pin, initialBalance));
    }
    
    public boolean authenticateUser(String accountNumber, String pin) {
        BankAccount account = accounts.get(accountNumber);
        if (account != null && account.validatePin(pin)) {
            currentAccount = account;
            return true;
        }
        return false;
    }
    
    public boolean withdraw(double amount) {
        if (currentAccount == null || !currentAccount.canWithdraw(amount)) {
            return false;
        }
        currentAccount.withdraw(amount);
        return true;
    }
    
    public boolean deposit(double amount) {
        if (currentAccount == null) {
            return false;
        }
        currentAccount.deposit(amount);
        return true;
    }
    
    public double getBalance() {
        return currentAccount != null ? currentAccount.getBalance() : 0;
    }
    
    public void logout() {
        currentAccount = null;
    }
    
    public void setState(ATMState newState) {
        state = newState;
    }
    
    public ATMState getState() {
        return state;
    }
}

interface ATMState {
    void insertCard();
    void authenticateUser(String pin);
    void performTransaction();
}

class IdleState implements ATMState {
    private ATM atm;
    
    public IdleState(ATM atm) {
        this.atm = atm;
    }
    
    @Override
    public void insertCard() {
        atm.setState(new AuthenticatingState(atm));
    }
    
    @Override
    public void authenticateUser(String pin) {
        // Not applicable in idle state
    }
    
    @Override
    public void performTransaction() {
        // Not applicable in idle state
    }
}

class AuthenticatingState implements ATMState {
    private ATM atm;
    
    public AuthenticatingState(ATM atm) {
        this.atm = atm;
    }
    
    @Override
    public void insertCard() {
        // Already in authenticating state
    }
    
    @Override
    public void authenticateUser(String pin) {
        // Authenticate and move to transaction state
        atm.setState(new TransactionState(atm));
    }
    
    @Override
    public void performTransaction() {
        // Not applicable yet
    }
}

class TransactionState implements ATMState {
    private ATM atm;
    
    public TransactionState(ATM atm) {
        this.atm = atm;
    }
    
    @Override
    public void insertCard() {
        // Already authenticated
    }
    
    @Override
    public void authenticateUser(String pin) {
        // Already authenticated
    }
    
    @Override
    public void performTransaction() {
        // Perform transaction and return to idle
        atm.setState(new IdleState(atm));
    }
}

class BankAccount {
    private String accountNumber;
    private String pin;
    private double balance;
    private List<Transaction> transactions;
    
    public BankAccount(String accountNumber, String pin, double initialBalance) {
        this.accountNumber = accountNumber;
        this.pin = pin;
        this.balance = initialBalance;
        this.transactions = new ArrayList<>();
    }
    
    public boolean validatePin(String inputPin) {
        return pin.equals(inputPin);
    }
    
    public boolean canWithdraw(double amount) {
        return balance >= amount && amount > 0;
    }
    
    public void withdraw(double amount) {
        if (canWithdraw(amount)) {
            balance -= amount;
            transactions.add(new Transaction("WITHDRAWAL", amount));
        }
    }
    
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactions.add(new Transaction("DEPOSIT", amount));
        }
    }
    
    public double getBalance() {
        return balance;
    }
    
    public List<Transaction> getTransactionHistory() {
        return new ArrayList<>(transactions);
    }
}

class Transaction {
    private String type;
    private double amount;
    private Date timestamp;
    
    public Transaction(String type, double amount) {
        this.type = type;
        this.amount = amount;
        this.timestamp = new Date();
    }
    
    public String getType() {
        return type;
    }
    
    public double getAmount() {
        return amount;
    }
    
    public Date getTimestamp() {
        return timestamp;
    }
    
    @Override
    public String toString() {
        return type + ": $" + amount + " at " + timestamp;
    }
}

// Public facade for ATM System
public class ATMSystem {
    public static ATM getInstance() {
        return ATM.getInstance();
    }
}
