package lld.problems.library_management;

import java.util.*;

/**
 * Library Management System - LLD Problem
 * 
 * Requirements:
 * 1. Books and members
 * 2. Borrowing and returning books
 * 3. Book availability tracking
 * 4. Fine calculation
 * 5. Book reservations
 * 6. Different book types
 * 
 * Design:
 * - Library (singleton)
 * - Book and BookCopy
 * - Member
 * - BorrowRecord
 * - Reservation
 * - LibrarianActions
 */

class Library {
    private static Library instance;
    private Map<String, Book> books;
    private Map<String, Member> members;
    private List<BorrowRecord> borrowRecords;
    
    private Library() {
        books = new HashMap<>();
        members = new HashMap<>();
        borrowRecords = new ArrayList<>();
    }
    
    public static synchronized Library getInstance() {
        if (instance == null) {
            instance = new Library();
        }
        return instance;
    }
    
    public void addBook(String isbn, Book book) {
        books.put(isbn, book);
    }
    
    public void registerMember(String memberId, Member member) {
        members.put(memberId, member);
    }
    
    public boolean borrowBook(String memberId, String isbn) {
        if (!members.containsKey(memberId) || !books.containsKey(isbn)) {
            return false;
        }
        
        Member member = members.get(memberId);
        Book book = books.get(isbn);
        
        if (!book.isAvailable()) {
            return false;
        }
        
        BookCopy copy = book.getAvailableCopy();
        if (copy == null) {
            return false;
        }
        
        BorrowRecord record = new BorrowRecord(member, copy);
        borrowRecords.add(record);
        member.addBorrowRecord(record);
        copy.setBorrowed(true);
        
        return true;
    }
    
    public boolean returnBook(String memberId, String isbn) {
        Member member = members.get(memberId);
        if (member == null) {
            return false;
        }
        
        BorrowRecord record = member.findBorrowRecord(isbn);
        if (record == null) {
            return false;
        }
        
        record.setReturnDate(new Date());
        record.getBookCopy().setBorrowed(false);
        
        double fine = record.calculateFine();
        if (fine > 0) {
            member.addFine(fine);
        }
        
        return true;
    }
    
    public double getMemberFine(String memberId) {
        Member member = members.get(memberId);
        return member != null ? member.getTotalFine() : 0;
    }
}

class Book {
    private String isbn;
    private String title;
    private String author;
    private BookType type;
    private List<BookCopy> copies;
    
    public Book(String isbn, String title, String author, BookType type) {
        this.isbn = isbn;
        this.title = title;
        this.author = author;
        this.type = type;
        this.copies = new ArrayList<>();
    }
    
    public void addCopy() {
        copies.add(new BookCopy(isbn, copies.size() + 1));
    }
    
    public boolean isAvailable() {
        return copies.stream().anyMatch(copy -> !copy.isBorrowed());
    }
    
    public BookCopy getAvailableCopy() {
        return copies.stream()
                .filter(copy -> !copy.isBorrowed())
                .findFirst()
                .orElse(null);
    }
}

class BookCopy {
    private String isbn;
    private int copyNumber;
    private boolean isBorrowed;
    
    public BookCopy(String isbn, int copyNumber) {
        this.isbn = isbn;
        this.copyNumber = copyNumber;
        this.isBorrowed = false;
    }
    
    public String getIsbn() {
        return isbn;
    }
    
    public boolean isBorrowed() {
        return isBorrowed;
    }
    
    public void setBorrowed(boolean borrowed) {
        isBorrowed = borrowed;
    }
}

class Member {
    private String memberId;
    private String name;
    private String email;
    private List<BorrowRecord> borrowRecords;
    private double totalFine;
    
    public Member(String memberId, String name, String email) {
        this.memberId = memberId;
        this.name = name;
        this.email = email;
        this.borrowRecords = new ArrayList<>();
        this.totalFine = 0;
    }
    
    public void addBorrowRecord(BorrowRecord record) {
        borrowRecords.add(record);
    }
    
    public BorrowRecord findBorrowRecord(String isbn) {
        return borrowRecords.stream()
                .filter(r -> r.getBookCopy().getIsbn().equals(isbn) && r.getReturnDate() == null)
                .findFirst()
                .orElse(null);
    }
    
    public void addFine(double fine) {
        totalFine += fine;
    }
    
    public double getTotalFine() {
        return totalFine;
    }
}

class BorrowRecord {
    private Member member;
    private BookCopy bookCopy;
    private Date borrowDate;
    private Date returnDate;
    private static final int BORROW_LIMIT_DAYS = 14;
    private static final double LATE_FEE_PER_DAY = 1.0;
    
    public BorrowRecord(Member member, BookCopy bookCopy) {
        this.member = member;
        this.bookCopy = bookCopy;
        this.borrowDate = new Date();
        this.returnDate = null;
    }
    
    public Date getReturnDate() {
        return returnDate;
    }
    
    public void setReturnDate(Date returnDate) {
        this.returnDate = returnDate;
    }
    
    public BookCopy getBookCopy() {
        return bookCopy;
    }
    
    public double calculateFine() {
        if (returnDate == null) {
            return 0;
        }
        
        long diffTime = returnDate.getTime() - borrowDate.getTime();
        long diffDays = diffTime / (1000 * 60 * 60 * 24);
        
        if (diffDays > BORROW_LIMIT_DAYS) {
            return (diffDays - BORROW_LIMIT_DAYS) * LATE_FEE_PER_DAY;
        }
        
        return 0;
    }
}

enum BookType {
    FICTION, NON_FICTION, REFERENCE, EDUCATIONAL
}

// Public facade for Library Management System
public class LibrarySystem {
    public static Library getInstance() {
        return Library.getInstance();
    }
}
