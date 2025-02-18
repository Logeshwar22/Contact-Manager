#ifndef CONTACTS_H
#define CONTACTS_H

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

// Structure to store a contact
typedef struct
{
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

// Function declarations
void addContact();
void viewContacts();
void searchContact();
void deleteContact();
void updateContact();

#endif
