#include <stdio.h> 
#include<stdlib.h>  
#include<string.h> 
struct Account { 
int accountNumber;
int pin; 
float balance; 
}; 
void createAccount(struct Account accounts[], int *numAccounts) { printf("Enter account number: ");
scanf("%d", &accounts[*numAccounts].accountNumber);  printf("Set your 4-digit PIN: "); 
scanf("%d", &accounts[*numAccounts].pin); 
printf("Enter initial balance: "); 
scanf("%f", &accounts[*numAccounts].balance);  (*numAccounts)++;
printf("Account created successfully.\n"); 
} int validatePIN(struct Account accounts[], int numAccounts, int  accountNumber, int enteredPIN) { 
for (int i = 0; i < numAccounts; i++) { 
if (accounts[i].accountNumber == accountNumber && accounts[i].pin == enteredPIN) { 
return i; // Return the index of the matched account
}  
} 
return -1; // Return -1 if account or PIN is not found } 
void displayBalance(struct Account accounts[], int index) {
printf("Account Balance: $%.2f\n", accounts[index].balance); } void withdraw(struct Account accounts[], int index, float  
amount) { 
if (amount > 0 && amount <= accounts[index].balance) { accounts[index].balance -= amount; 
printf("Withdrawal successful. Remaining balance: $%.2f\n", accounts[index].balance);
} else { 
printf("Invalid withdrawal amount or insufficient funds.\n"); }  
} 
void deposit(struct Account accounts[], int index,float amount) { 
int deposit; 
printf("\n ENTER THE AMOUNT TO DEPOSIT:");
scanf("%lu", &deposit); 
amount = amount + deposit; 
printf("YOUR BALANCE IS %lu", amount); 
} 
int main() { 
struct Account accounts[10]; // Assuming a maximum of 10 accounts int numAccounts = 0;
int choice, accountNumber, enteredPIN, accountIndex; float amount; 
do { 
printf("\n1. Create Account\n2. Perform Transaction\n3. Exit\n"); printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) {
case 1: createAccount(accounts,  &numAccounts); 
break; 
case 2: 
printf("Enter account number: "); scanf("%d", &accountNumber); printf("Enter your 4-digit PIN: ");
scanf("%d", &enteredPIN); accountIndex = validatePIN(accounts,  numAccounts, accountNumber, 
enteredPIN); 
if (accountIndex != -1) { 
int transactionChoice;
printf("\n1. Balance Inquiry\n2. Withdraw\n3.Deposit"); printf("Enter your choice: "); 
scanf("%d", &transactionChoice);  
switch (transactionChoice) { 
case 1: 
displayBalance(accounts, accountIndex);
break; 
case 2: 
printf("Enter withdrawal amount: "); scanf("%f", &amount); 
withdraw(accounts, accountIndex, amount); break; 
case 3: 
printf("Enter amount to deposit:");
scanf("%d",&deposit); 
deposit(accounts, accountIndex, amount); break; 
default: 
printf("Invalid choice.\n"); 
} 
} else { 
printf("Invalid account number or PIN.\n");
} 
break; 
case 4: printf("Exiting ATM system.  Goodbye!\n"); 
break; 
default: 
printf("Invalid choice. Please try again.\n"); }
} while (choice != 4); 