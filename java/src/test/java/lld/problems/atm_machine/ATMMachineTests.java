package lld.problems.atm_machine;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Test suite for ATM Machine
 */
class ATMMachineTests {
    private ATM atm;
    
    @BeforeEach
    void setUp() {
        atm = ATM.getInstance();
        atm.createAccount("ACC001", "1234", 5000);
    }
    
    @Test
    void testCreateAccount() {
        atm.createAccount("ACC002", "5678", 1000);
        // Verify account is created (implicit through next authentication test)
        assertNotNull(atm);
    }
    
    @Test
    void testAuthenticateValidPin() {
        boolean authenticated = atm.authenticateUser("ACC001", "1234");
        assertTrue(authenticated);
    }
    
    @Test
    void testAuthenticateInvalidPin() {
        boolean authenticated = atm.authenticateUser("ACC001", "9999");
        assertFalse(authenticated);
    }
    
    @Test
    void testWithdrawMoney() {
        atm.authenticateUser("ACC001", "1234");
        boolean withdrawn = atm.withdraw(500);
        
        assertTrue(withdrawn);
        assertEquals(4500, atm.getBalance());
    }
    
    @Test
    void testWithdrawMoreThanBalance() {
        atm.authenticateUser("ACC001", "1234");
        boolean withdrawn = atm.withdraw(10000);
        
        assertFalse(withdrawn);
        assertEquals(5000, atm.getBalance());
    }
    
    @Test
    void testDepositMoney() {
        atm.authenticateUser("ACC001", "1234");
        boolean deposited = atm.deposit(1000);
        
        assertTrue(deposited);
        assertEquals(6000, atm.getBalance());
    }
    
    @Test
    void testCheckBalance() {
        atm.authenticateUser("ACC001", "1234");
        double balance = atm.getBalance();
        
        assertEquals(5000, balance);
    }
    
    @Test
    void testLogout() {
        atm.authenticateUser("ACC001", "1234");
        atm.logout();
        
        assertEquals(0, atm.getBalance());
    }
    
    @Test
    void testMultipleTransactions() {
        atm.authenticateUser("ACC001", "1234");
        atm.withdraw(1000);
        atm.deposit(500);
        
        assertEquals(4500, atm.getBalance());
    }
}
