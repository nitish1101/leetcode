package lld.problems.library_management;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Test suite for Library Management System
 */
class LibraryManagementTests {
    private Library library;
    
    @BeforeEach
    void setUp() {
        library = Library.getInstance();
        
        // Add books
        Book book1 = new Book("ISBN001", "The Great Gatsby", "F. Scott Fitzgerald", BookType.FICTION);
        book1.addCopy();
        book1.addCopy();
        library.addBook("ISBN001", book1);
        
        // Register members
        Member member1 = new Member("M001", "John Doe", "john@example.com");
        library.registerMember("M001", member1);
    }
    
    @Test
    void testBorrowBook() {
        boolean borrowed = library.borrowBook("M001", "ISBN001");
        assertTrue(borrowed);
    }
    
    @Test
    void testBorrowNonExistentBook() {
        boolean borrowed = library.borrowBook("M001", "ISBN999");
        assertFalse(borrowed);
    }
    
    @Test
    void testBorrowBookByNonExistentMember() {
        boolean borrowed = library.borrowBook("M999", "ISBN001");
        assertFalse(borrowed);
    }
    
    @Test
    void testReturnBook() {
        library.borrowBook("M001", "ISBN001");
        boolean returned = library.returnBook("M001", "ISBN001");
        assertTrue(returned);
    }
    
    @Test
    void testGetMemberFine() {
        double fine = library.getMemberFine("M001");
        assertEquals(0, fine);
    }
    
    @Test
    void testMultipleBorrows() {
        library.borrowBook("M001", "ISBN001");
        Book book2 = new Book("ISBN002", "1984", "George Orwell", BookType.FICTION);
        book2.addCopy();
        library.addBook("ISBN002", book2);
        
        boolean borrowed2 = library.borrowBook("M001", "ISBN002");
        assertTrue(borrowed2);
    }
}
