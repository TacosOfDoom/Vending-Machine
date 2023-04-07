// Kevin, Program 7 Implementation

#include <stdio.h> //for printf and scanf
#include<ctype.h> //for tolower function

//function prototypes:

void Greeting(void);
//welcome the user to purchasing app

void ViewBalance(double balance);
//display the current account balance

char OptionListPtr(char* choicePtr);    //new
//display the program options and get the users selection

double ProcessOption(char choice, double balance); //new
//input: the user's choice
//Display a message based on the user’s choice
//call the Display Menu function if the user selects ‘S’ or ‘s’

void DisplayMenu();
//display the item options and prices
//ask, get, and return the item number

void OrderPricePtr(double* pricePtr);
//input: a double (balance) and a double (price) by copy
//return 1 if the balance is enough to cover the price
//return 0 if it is not enough

int CheckForEnoughMoney(double balance, double price);
//return 1 if the balance is enough to cover the price
//return 0 if it is not enough

double Reload(double balance);
//reload the account balance

int main()
{
    char choiceInMain;
    FILE* inPtr, * outPtr; //for input & output
    double balanceInMain;

    Greeting();     //greet the user

    inPtr = fopen("accountBalance.txt", "r");   //connect to file
    printf("\nGetting the balance from file\n\n");
    fscanf(inPtr, "%lf", &balanceInMain);

    ViewBalance(balanceInMain);

    //printf("\nThe balance is %.2f\n", balanceInMain);   //test to see if it works

    OptionListPtr(&choiceInMain);    //call OptionList
    choiceInMain = tolower(choiceInMain);       //change the choiceInMain to lowercase //UPDATE

    while (choiceInMain != 'q')        //while loop
    {
        balanceInMain = ProcessOption(choiceInMain, balanceInMain);        //call ProcessOption and pass the choiceInMain
        OptionListPtr(&choiceInMain);    //call OptionList
        choiceInMain = tolower(choiceInMain);       //change the choiceInMain to lowercase //UPDATE

    }

	printf("\nSaving the balance to the file\n\n");
	outPtr = fopen("accountBalance.txt", "w");   //connect to file
	fscanf(outPtr, "%f", &balanceInMain);

	printf("\nHave a great day!\n\n");

	fclose(inPtr);
	fclose(outPtr);

    return 0;
}
void Greeting(void)
{
    printf("Welcome to the Coffee Express\n");
    printf("We serve delicious coffee and snacks! ");

    return;
}

void ViewBalance(double balance)
//display the current account balance
{
    printf("\n\nYour current balance is $%.2f", balance);     //tells the user their balance

    return;
}

char OptionListPtr(char* choicePtr)
//display the program options and get the users selection
{

    /*display the program options, get, and return the option
	('S', 'O', 'B', 'A', 'Q')*/

    printf("\n\n********************************************************");
    printf("\nWhat would you like to do?");
    printf("\nPlease select from the following options:");
    printf("\n'S' to view the snack and beverages available for purchase");
    printf("\n'O' to order coffee or a snack");
    printf("\n'B' to view your account balance");
    printf("\n'A' to add money to your account");
    printf("\n'Q' to Quit");

    printf("\n\nEnter your selection: ");
    scanf(" %c", choicePtr);


}

double ProcessOption(char choice, double balance)
//input: the user's choice
//Display a message based on the user’s choice
//call the Display Menu function if the user selects ‘S’ or ‘s’

{
    double price;
    int enough = 0;

	if (choice == 's')
	{
        printf("\n----------------------------------");
        printf("\nDisplay the menu");
        DisplayMenu();
	}
	else if (choice == 'o')
	{
        printf("\n----------------------------------");
        //printf("\n\nComplete the order an of item if theres enough money");

        ViewBalance(balance);

        DisplayMenu();

        ViewBalance(balance);

        OrderPricePtr(&price);
        //printf("\nprice in process option function is $%.2f \n", price); //tested order price

        enough = CheckForEnoughMoney(balance, price);       //CheckForEnoughMoney function call
        printf("\n----------------------------------");
       // printf("\nthe value of enough is %d\n", enough);  //test enough value
        printf("\n----------------------------------");

        while(enough == 0)    //make a purchase if there is enough money
            {

                printf("\nThe price of the item is $%.2f \n", price);
                balance = Reload(balance);
                ViewBalance(balance);
                enough = CheckForEnoughMoney(balance, price);

                return balance;

            }
        if (price != 0)  //make a purchase if there is enough money
            {

                balance = balance - price;  //Gets New Balance
                ViewBalance(balance);

                return balance;
            }

	}
	else if (choice == 'b')
	{
        printf("\n----------------------------------");
        //printf("\n\nto view the account balance");
        //view balance function prog 7

        ViewBalance(balance);
	}
	else if (choice == 'a')
	{
        printf("\n----------------------------------");
        //printf("\n\nto add money to your account");
        //add money function prog 7
        ViewBalance(balance);
        balance = Reload(balance);
        ViewBalance(balance);

	}
	else if (choice == 'q')
	{
        printf("\n----------------------------------");
        printf("\n\nto Quit the program");
	}
	else
	{
		printf("\n----------------------------------\n");
		printf("\n\nThat is not a valid option\n");
	}

	return balance;
}

void DisplayMenu()
{
    //display beverage/food options and prices

    printf("\n\n-----------------------------------------");
    printf("\nHere are the coffee and snack options:");
    printf("\n1. Hot coffee           $2.35");
    printf("\n2. Iced coffee          $2.35");
    printf("\n3. Hot Latte            $4.68");
    printf("\n4. Iced Latte           $4.68");
    printf("\n5. Butter Croissant     $3.50");
    printf("\n6. Almond Croissant     $4.50");
    printf("\n7. Blueberry Muffin Top $3.25");


    return;
}


void OrderPricePtr(double* pricePtr)
//input: a double (balance) and a double (price) by copy
//return 1 if the balance is enough to cover the price
//return 0 if it is not enough
{
    double price;       //declare variable
    int itemNumber;

    printf("\n\nEnter your selection: ");
    scanf("%d", &itemNumber);

    if (itemNumber == 1)    //Gets the users selection and returns the price
    {
        printf("\nYou selected Hot coffee, the price is $2.35");
        *pricePtr = 2.35;
    }
    else if (itemNumber == 2)
    {
        printf("\nYou selected Iced coffee, the price is $2.35");
        *pricePtr = 2.35;
    }
    else if (itemNumber == 3)
    {
        printf("\nYou selected Hot Latte, the price is $4.68");
        *pricePtr = 4.68;
    }
    else if (itemNumber == 4)
    {
        printf("\nYou selected Iced Latte, the price is $4.68");
        *pricePtr = 4.68;
    }
    else if (itemNumber == 5)
    {
        printf("\nYou selected Butter Croissant, the price is $3.50");
        *pricePtr = 3.50;
    }
    else if (itemNumber == 6)
    {
        printf("\nYou selected Almond Croissant, the price is $4.50");
        *pricePtr = 4.50;
    }
    else if (itemNumber == 7)
    {
        printf("\nYou selected Blueberry Muffin Top, the price is $3.25");
        *pricePtr = 3.25;
    }
    else
    {
        printf("Number Entered is Invalid");
        *pricePtr = 0;
    }

    return price;

}

int CheckForEnoughMoney(double balance, double price)
//return 1 if the balance is enough to cover the price
//return 0 if it is not enough
{
    if (balance >= price)       //return 1 if the balance is enough to cover the price
    {
        return 1;
    }

    else        //return 0 if it is not enough
    {
        printf("\n\nYou don't have enough money for the purchase\n");

        return 0;
    }

}

double Reload(double balance)
//reload the account balance
{
    double addedAmount;     //declare variable
    printf("\n----------------------------------\n");
    printf("\nHow much would you like to add? ");     //ask and get amount
    scanf("%lf", &addedAmount);

    balance = balance + addedAmount;        //add amount to balance

    return balance;     //return the new balance
}






