# Library Management System

A simple C++ application for managing books in a library. This system allows administrators to add books, view available books, borrow and return books. It also includes basic authentication to restrict access to the system.

## Features

- **Admin Authentication**: Secured access with a password (`admin123`).
- **Book Management**:
  - Add books to the library.
  - Display all books in the library.
  - Borrow books (Mark a book as borrowed).
  - Return borrowed books.
- **Persistence**: Books are saved and loaded from a text file (`books.txt`).

## Prerequisites

- A C++ compiler (e.g., GCC or MSVC).
- A text editor or IDE (e.g., Visual Studio Code, CLion).

## Files

- `main.cpp`: Main C++ file with the implementation of the Library Management System.
- `books.txt`: Text file to store the list of books in the library.

## How to Use

1. **Clone or download** the repository.
2. **Build the project**:
   - If using a command-line compiler, run:
     ```bash
     g++ main.cpp -o main
     ```
3. **Run the program**:
   - Execute the compiled binary:
     ```bash
     main
     ```
4. **Authentication**: 
   - When prompted, enter the admin password: `admin123`.
5. **Library Management**:
   - Choose options from the menu:
     1. Add a new book to the library.
     2. Display all available books.
     3. Borrow a book (mark as borrowed).
     4. Return a borrowed book.
     5. Exit the program.

6. **Books are saved in `books.txt`**:
   - The list of books, along with their availability status, is stored and retrieved from this file.

## Example Interaction

```bash
Enter admin password: admin123
Authentication successful.

Library Management System:
1. Add Book
2. Display Books
3. Borrow Book
4. Return Book
5. Exit
Enter your choice: 1
Enter book title: The_Great_Gatsby
Enter book author: F_Scott_Fitzgerald
Book added successfully.

Library Management System:
1. Add Book
2. Display Books
3. Borrow Book
4. Return Book
5. Exit
Enter your choice: 2
Title: The_Great_Gatsby, Author: F_Scott_Fitzgerald, Status: Available
```

## Data Format for `books.txt`

The `books.txt` file stores the list of books in the following format:

```Book_Title Author_Name Is_Borrowed```


Where:
- **Book_Title**: The title of the book (spaces replaced by underscores).
- **Author_Name**: The name of the author (spaces replaced by underscores).
- **Is_Borrowed**: A `0` (for available) or `1` (for borrowed) indicating the availability status of the book.
