#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacts.h"

// Helper function to remove newline characters from strings
void removeNewline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

// Function to add a new contact
void addContact()
{
    FILE *file = fopen("contacts.txt", "a"); // Open in append mode
    if (!file)
    {
        printf("Error opening file!\n");
        return;
    }

    Contact contact;
    printf("Enter name: ");
    fgets(contact.name, MAX_NAME_LENGTH, stdin);
    removeNewline(contact.name); // Clean up the input

    printf("Enter phone number: ");
    fgets(contact.phone, MAX_PHONE_LENGTH, stdin);
    removeNewline(contact.phone);

    // Write the contact to the file in a simple format: name,phone
    fprintf(file, "%s,%s\n", contact.name, contact.phone);
    fclose(file);

    printf("Contact added successfully!\n");
}

// Function to view all contacts
void viewContacts()
{
    FILE *file = fopen("contacts.txt", "r"); // Open in read mode
    if (!file)
    {
        printf("No contacts found!\n");
        return;
    }

    Contact contact;
    char line[100];
    printf("\n--- Contacts List ---\n");
    while (fgets(line, sizeof(line), file))
    {
        // Parse the line assuming it's formatted as "name,phone"
        char *token = strtok(line, ",");
        if (token != NULL)
        {
            strncpy(contact.name, token, MAX_NAME_LENGTH);
            contact.name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
            token = strtok(NULL, "\n");               // Get phone number
            if (token != NULL)
            {
                strncpy(contact.phone, token, MAX_PHONE_LENGTH);
                contact.phone[MAX_PHONE_LENGTH - 1] = '\0';
            }
            printf("Name: %s, Phone: %s\n", contact.name, contact.phone);
        }
    }
    fclose(file);
}

// Function to search for a contact by name
void searchContact()
{
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    removeNewline(searchName);

    FILE *file = fopen("contacts.txt", "r");
    if (!file)
    {
        printf("Error opening file!\n");
        return;
    }

    int found = 0;
    char line[100];
    while (fgets(line, sizeof(line), file))
    {
        // If the line contains the search name, display it
        if (strstr(line, searchName) != NULL)
        {
            printf("Contact found: %s", line);
            found = 1;
        }
    }
    if (!found)
        printf("Contact not found.\n");

    fclose(file);
}

// Function to delete a contact by name
void deleteContact()
{
    char deleteName[MAX_NAME_LENGTH];
    printf("Enter name of the contact to delete: ");
    fgets(deleteName, MAX_NAME_LENGTH, stdin);
    removeNewline(deleteName);

    FILE *file = fopen("contacts.txt", "r");
    if (!file)
    {
        printf("Error opening file!\n");
        return;
    }

    // Temporary file to store contacts that are not deleted
    FILE *temp = fopen("temp.txt", "w");
    if (!temp)
    {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, deleteName) == NULL)
        {
            // Write contacts that do not match the delete name
            fprintf(temp, "%s", line);
        }
        else
        {
            found = 1;
        }
    }
    fclose(file);
    fclose(temp);

    // Replace original file with the temporary file
    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    if (found)
        printf("Contact deleted successfully!\n");
    else
        printf("Contact not found.\n");
}

// Function to update a contact by name
void updateContact()
{
    char updateName[MAX_NAME_LENGTH];
    printf("Enter name of the contact to update: ");
    fgets(updateName, MAX_NAME_LENGTH, stdin);
    removeNewline(updateName);

    FILE *file = fopen("contacts.txt", "r");
    if (!file)
    {
        printf("Error opening file!\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (!temp)
    {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, updateName) != NULL)
        {
            found = 1;
            Contact updatedContact;
            printf("Enter new name: ");
            fgets(updatedContact.name, MAX_NAME_LENGTH, stdin);
            removeNewline(updatedContact.name);

            printf("Enter new phone number: ");
            fgets(updatedContact.phone, MAX_PHONE_LENGTH, stdin);
            removeNewline(updatedContact.phone);

            // Write the updated contact
            fprintf(temp, "%s,%s\n", updatedContact.name, updatedContact.phone);
        }
        else
        {
            // Keep the contact unchanged
            fprintf(temp, "%s", line);
        }
    }
    fclose(file);
    fclose(temp);

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    if (found)
        printf("Contact updated successfully!\n");
    else
        printf("Contact not found.\n");
}
