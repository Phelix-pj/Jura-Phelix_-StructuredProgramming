#include<stdio.h>

float balance = 500.00;
const int correctpin = 1234;

int login();
void showMenu();
void checkBalance();
void deposit(float amount);
void withdraw(float amount);


int main(){
    if (!login()){
        return 0;
    }
    int choice;
    float amount;

    while(1) {
        showMenu();
        printf("ENTER YOUR CHOICE:");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            checkBalance();
            break;
        case 2:
            printf("ENTER AMOUNT TO DEPOSIT:");
            scanf("%f", &amount);
            deposit(amount);
            break;
        case 3:
            printf("ENTER AMOUNT TO WITHDRAW:");
            scanf("%f", &amount);
            withdraw(amount);
            break;
        case 4:
            printf("EXITING ... Thank you for using ATM!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
int login(){
    int pin;
    int attempts = 3;

    while (attempts>0){
        printf("Enter your PIN:");
        scanf("%d", &pin);

        if (pin==correctpin){
            printf("Login successful!\n\n");
            return 1;
        }else{
            attempts--;
            printf("Incorrrect PIN. Attempts left:%d\n",attempts);
        }
    }
    printf("Maximum attempts exceeded. Access denied.\n");
    return 0;
}
void showMenu(){
    printf("\n     ATM MENU     \n");
    printf("1.Check balance \n");
    printf("2.Deposit Money\n");
    printf("3.Withdraw Money\n");
    printf("4.Exit\n");
    printf("            \n");
}
void checkBalance(){
    printf("Your current balance is: $%.2f\n", balance);
}
void deposit(float amount){
    if (amount<=0){
        printf("Deposit amount must be positive.\n");

    }
    balance +=amount;
    printf("Successfully deposited $%.2f\n", amount);
    printf("New balance:$%.2f", balance);
}
void withdraw (float amount){
    if(amount < 0 ){
        printf("Withdraw amount must be positive.\n");

    }
    if (amount > balance){
        printf("Insufficient balance.\n");
        return 0;
    }
    balance -=amount;
    printf("Successfully withdrew $%.2f\n", amount);
    printf("Remaining balance: $%.2f", balance );

    return 0;
}


