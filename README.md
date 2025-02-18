# Contact Management System

## Description
The **Contact Management System** is a simple command-line program written in **C** that allows users to manage a list of contacts. It demonstrates the use of **file handling**, **dynamic memory allocation**, and **structs** in C programming.

This project supports the following operations:
- Add a new contact
- View all contacts
- Search for a contact by name
- Delete a contact
- Update an existing contact

## Features
1. **Add Contact**: Allows users to add a new contact with a name and phone number.
2. **View Contacts**: Displays all stored contacts.
3. **Search Contact**: Finds and displays contacts by name.
4. **Delete Contact**: Removes a specific contact from the list.
5. **Update Contact**: Modifies an existing contact's details.
6. **File Handling**: Contacts are stored persistently in a `contacts.txt` file.

## How to Use
1. Clone this repository or download the source files.
2. Open a terminal and navigate to the project directory.
3. Compile the program using GCC:
   ```bash
   gcc main.c contacts.c -o ContactManager
   ```
4. Run the compiled program:
   ```bash
   ./ContactManager
   ```
5. Follow the menu options to manage your contacts.

## Example Usage
```
=== Contact Management System ===
1. Add Contact
2. View Contacts
3. Search Contact
4. Delete Contact
5. Update Contact
6. Exit
Enter your choice: 1
Enter name: John Doe
Enter phone number: 1234567890
Contact added successfully!

=== Contact Management System ===
1. Add Contact
2. View Contacts
3. Search Contact
4. Delete Contact
5. Update Contact
6. Exit
Enter your choice: 2

--- Contacts List ---
Name: John Doe, Phone: 1234567890
```

## File Structure
```
📂 Contact-Manager/
 ├── main.c         // Entry point of the program
 ├── contacts.h     // Header file (Function declarations & struct)
 ├── contacts.c     // Implementation file (Function definitions)
 ├── contacts.txt   // File to store contacts persistently
 ├── README.md      // Project documentation
```

## Implementation Details
1. **Struct for Contact**:
   - Each contact is represented by a struct containing `name` and `phone`.
2. **File Handling**:
   - Contacts are stored in a file named `contacts.txt` in a `name,phone` format.
3. **CRUD Operations**:
   - Add, View, Search, Delete, and Update operations are implemented with proper file I/O.

## Requirements
- GCC (GNU Compiler Collection) or any C compiler
- A terminal or command prompt

## Future Enhancements
- Add sorting functionality (e.g., sort contacts alphabetically).
- Add input validation for phone numbers.
- Implement a GUI version of the system.

## License
This project is open-source and available under the MIT License.

---
Happy Coding! 😊

