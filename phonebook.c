#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> // For strcpy, strcasecmp, and strcmp 
// Define a structure for a phonebook entry 
struct PhonebookEntry 
{ 
char name[50]; 
char phoneNumber[15]; 
struct PhonebookEntry *next; 
}; 
struct PhonebookEntry *head = NULL; 
// Function to add a new entry to the phonebook 
void addEntry(char name[], char phoneNumber[]) 
{ 
struct PhonebookEntry *newEntry = (struct PhonebookEntry *)malloc(sizeof(struct PhonebookEntry)); 
if (newEntry == NULL) 
{ 
printf("Memory allocation failed!\n"); 
return; 
} 
// Use strcpy to copy the name and phoneNumber 
strcpy(newEntry->name, name); 
strcpy(newEntry->phoneNumber, phoneNumber); 
newEntry->next = head; 
head = newEntry; 
printf("Entry added successfully!\n"); 
} 
// Function to search for an entry by name or phone number (case-insensitive) and print the result 
void searchEntry(char query[]) 
{ 
2
struct PhonebookEntry *current = head; 
int found = 0; 
while (current != NULL) 
{ 
//DO THE SEARCHING HERE 
if (strcasecmp(current->name, query) == 0 || 
strcasecmp(current->phoneNumber, query) == 0) 
{ 
// Case-insensitive comparison for both name and phone number printf("Name: %s\n", current->name); 
printf("Phone Number: %s\n", current->phoneNumber); 
found = 1; 
} 
//Increment the pointer 
current = current->next; 
} 
if (!found) 
{ 
printf("Entry not found!\n"); 
} 
} 
// Function to print all entries in the phonebook 
void printPhonebook() 
{ 
struct PhonebookEntry *current = head; 
if (current == NULL) 
{ 
printf("Phonebook is empty!\n"); 
return; 
} 
printf("Phonebook entries:\n"); 
while (current != NULL) 
{ 
printf("Name: %s\n", current->name); 
printf("Phone Number: %s\n", current->phoneNumber); 
printf("-----------------------------\n"); 
current = current->next; 
2
} 
} 
// Function to delete an entry by name or phone number (case-insensitive) 
void deleteEntry( 
char query[]) 
{ 
struct PhonebookEntry *current = head; 
struct PhonebookEntry *prev = NULL; 
int found = 0; 
while (current != NULL) 
{ 
if (strcasecmp(current->name, query) == 0 || 
strcasecmp(current->phoneNumber, query) == 0) 
{ 
// Case-insensitive comparison for both name and phone number printf("Deleted Entry:\n"); 
printf("Name: %s\n", current->name); 
printf("Phone Number: %s\n", current->phoneNumber); 
if (prev == NULL) 
{ 
head = current->next; 
} 
else 
{ 
prev->next = current->next; 
} 
free(current); 
found = 1; 
break; 
} 
prev = current; 
current = current->next; 
} 
if (!found) 
{ 
printf("Entry not found!\n"); 
} 
2
else 
{ 
printf("Entry deleted successfully!\n"); 
} 
} 
//Modify an entry by name or phone number 
void modify_contact(char query[50]) 
{ 
struct PhonebookEntry * current = head; 
int found = 0; 
while (current != NULL) 
{ 
//DO THE SEARCHING HERE 
if (strcasecmp(current->name, query) == 0 || 
strcasecmp(current->phoneNumber, query) == 0) 
{ 
int a = 0; 
char cn[50]; 
printf("What do you wish to modify :\n1.Name\n2.Phone Number\n3.Both name and phone number\nEnter your choice : "); scanf("%d", &a); 
switch(a) 
{ 
case 1 : 
{ 
printf("Enter the changed name : "); 
scanf("%s", cn); 
strcpy(current->name,cn); 
break; 
} 
case 2 : 
{ 
printf("Enter the changed number : "); 
scanf("%s", cn); 
strcpy(current->phoneNumber,cn); 
break; 
} 
2
case 3 : 
{ 
printf("Enter the changed name : "); 
scanf("%s", cn); 
strcpy(current->name,cn); 
printf("Enter the changed number : "); 
scanf("%s", cn); 
strcpy(current->phoneNumber,cn); 
break; 
} 
} 
found = 1; 
} 
//Increment the pointer 
current = current->next; 
} 
if (!found) 
{ 
printf("Entry not found!\n"); 
} 
} 
int main() 
{ 
int choice; 
char name[50], phoneNumber[15], query[50]; 
while (1) 
{ 
printf("\nPhonebook Menu:\n"); 
printf("1. Add an entry\n"); 
printf("2. Search for an entry by name or phone number\n"); printf("3. Delete an entry by name or phone number\n"); printf("4. Print all entries\n"); 
printf("5. Modify a name or phone number : \n"); printf("6. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
2
switch (choice) 
{ 
case 1: 
printf("Enter name: "); 
scanf("%s", name); 
printf("Enter phone number: "); 
scanf("%s", phoneNumber); 
addEntry(name, phoneNumber); 
break; 
case 2: 
printf("Enter name or phone number to search: "); scanf("%s", query); 
searchEntry(query); 
break; 
case 3: 
printf("Enter name or phone number to delete: "); scanf("%s", query); 
deleteEntry(query); 
break; 
case 4: 
// Print all entries 
printf("\nPhonebook Entries:\n"); 
printPhonebook(); 
break; 
case 5: 
//Modify a name or phone number 
printf("Enter the name or number that you want to modify : "); scanf("%s", query); 
modify_contact(query); 
break; 
case 6: 
// Free memory and exit 
while (head != NULL) 
{ 
struct PhonebookEntry *temp = head; 
head = head->next; 
free(temp); 
} 
return 0; 
default: 
printf("Invalid choice, please try again.\n"); 
2
} 
} 
return 0; 
} 
