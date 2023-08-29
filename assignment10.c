// C program to implement the Food
// Ordering System
#include <stdio.h>
#include <string.h>
#include <windows.h>

// Structure to store the
// user details (Signup details)
struct details
{
	char uname[100];
	int age;
	char password[100];
	char email[100];
	char mobile[10];
};

// Structure to store the
// hotels and their food details
struct hotels
{
	char hotel[100];
	char first_food[20];
	char second_food[20];
	char third_food[20];
	char fourth_food[25];
	int first, second, third, fourth;
};

struct hotels m[5];
struct details s[100];

// Function to get the
// input for new account.
void signup();

// Function to check whether
// the account is already
// existed or not
void account_check();

// Function to validate
// all the input fields.
int validate();
void login();
void cart();
void search_by_hotels();
void search_by_food();
void food_order(int food);

// Function to initialize the
// hotels and food
// structure dynamically
void hotel_initialize();
void hotels(int hotel_choice);
int flag = 1, i, j = 0, count = 0, caps = 0;
int small = 0, special = 0, numbers = 0;
int success = 0, x, choice;
char temp_name[100], temp_password1[100];
char temp_password2[100], temp_email[100];
char temp_mobile[100];
int temp_age, total = 0, food_choice, n;
int hotel_choice, search_choice, confirm;
int ch, food, hotel_id;

// Boilerplate Code for the
// Food Ordering System
int main()
{
	while (1)
	{
		printf("\n\n*******Welcome to Food Ordering System***** ");
		printf("\n\n1)SIGNUP\n");
		printf("2)LOGIN\n3)EXIT\n\n");
		printf("Enter your choice:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			signup();
			break;
		}
		case 2:
		{
			login();
			break;
		}
		case 3:
		{
			printf("\n*********Thank you visit again******\n");
			exit(0);
			return 0;
		}
		default:
		{
			printf("\nPlease Enter the valid choice\n");
			break;
		}
		}
	}
}

// Function to create a new
// user for the Food ordering
// system
void signup()
{
	printf("\n\n*****Welcome to signup page****\n");
	printf("\tEnter Your name: ");
	scanf("%s", temp_name);

	printf("\tEnter Your Age: ");
	scanf("%d", &temp_age);

	printf("\tEnter Your Email: ");
	scanf("%s", temp_email);

	printf("\tEnter Password: \n");
	printf("\t(It must contains 8-12 characters including atleast an uppercase a lowercase a number and a special character.)\n");
	printf("\t");
	scanf("%s", temp_password1);

	printf("\tConfirm Password:");
	scanf("%s", temp_password2);

	printf("\nEnter Your Mobile Number: ");
	scanf("%s", temp_mobile);

	// Function Call to validate
	// the user creation
	x = validate();
	if (x == 1)
	{
		account_check();
		login();
	}
}

// Function to validate the user
// for signup process
int validate()
{
	// Validate the name
	for (i = 0; temp_name[i] != '\0'; i++)
	{
		if (!((temp_name[i] >= 'a' && temp_name[i] <= 'z') || (temp_name[i] >= 'A' && temp_name[i] <= 'Z')))
		{
			printf("\nPlease Enter the valid Name\n");
			flag = 0;
			break;
		}
	}
	if (flag == 1)
	{
		count = 0;

		// Validate the Email ID
		for (i = 0; temp_email[i] != '\0'; i++)
		{
			if (temp_email[i] == '@' || temp_email[i] == '.')
				count++;
		}
		if (count >= 2 && strlen(temp_email) >= 5)
		{
			// Validating the Password and
			// Check whether it matches
			// with Conform Password
			if (!strcmp(temp_password1,
						temp_password2))
			{
				if (strlen(temp_password1) >= 8 && strlen(temp_password1) <= 12)
				{
					caps = 0;
					small = 0;
					numbers = 0;
					special = 0;
					for (i = 0; temp_password1[i] != '\0';
						 i++)
					{
						if (temp_password1[i] >= 'A' && temp_password1[i] <= 'Z')
							caps++;
						else if (temp_password1[i] >= 'a' && temp_password1[i] <= 'z')
							small++;
						else if (temp_password1[i] >= '0' && temp_password1[i] <= '9')
							numbers++;
						else if (temp_password1[i] == '@' || temp_password1[i] == '&' || temp_password1[i] == '#' || temp_password1[i] == '*')
							special++;
					}
					if (caps >= 1 && small >= 1 && numbers >= 1 && special >= 1)
					{
						// Validating the Input age
						if (temp_age != 0 && temp_age > 0)
						{
							// Validating the Input mobile
							// number
							if (strlen(temp_mobile) == 10)
							{
								for (i = 0; i < 10; i++)
								{
									if (temp_mobile[i] >= '0' && temp_mobile[i] <= '9')
									{
										success = 1;
									}
									else
									{ // loop for error sound
										for (int x = 0; x < 2; x++)
										{
											Beep(523, 800);
										}
										printf("\n\nPlease Enter Valid mobile Number\n\n");
										return 0;
										break;
									}
								}

								// Success is assigned with
								// value 1, Once every
								// inputs are correct.
								if (success == 1)
									return 1;
							}
							else
							{ // loop for error sound
								for (int x = 0; x < 2; x++)
								{
									Beep(523, 800);
								}
								printf("\n\nPlease Enter the 10 digit mobile number\n");
								return 0;
							}
						}
						else
						{ // loop for error sound
							for (int x = 0; x < 2; x++)
							{
								Beep(523, 800);
							}
							printf("\n\nPlease Enter the valid age\n\n");
							return 0;
						}
					}
					else
					{ // loop for error sound
						for (int x = 0; x < 2; x++)
						{
							Beep(523, 800);
						}
						printf("\n\nPlease Enter the strong password,Your password must contain atleast one uppercase,Lowercase, Number and special character\n\n");
						return 0;
					}
				}
				else
				{ // loop for error sound
					for (int x = 0; x < 2; x++)
					{
						Beep(523, 800);
					}
					printf("\nLength of password must be between 8 to 12 characters.\n\n");
					return 0;
				}
			}
			else
			{ // loop for error sound
				for (int x = 0; x < 2; x++)
				{
					Beep(523, 800);
				}
				printf("\nPassword Mismatch\n\n");
				return 0;
			}
		}
		else
		{ // loop for error sound
			for (int x = 0; x < 2; x++)
			{
				Beep(523, 800);
			}
			printf("\nPlease Enter Valid E-Mail\n\n");

			return 0;
		}
	}
}

// Function to check if the account
// already exists or not
void account_check()
{
	for (i = 0; i < 100; i++)
	{
		// Check whether the email
		// and password are already
		// matched with existed account
		if (!(strcmp(temp_email, s[i].email) && strcmp(temp_password1,
													   s[i].password)))
		{
			printf("\n\nAccount Already Existed. Please Login !!\n\n");
			main();
			break;
		}
	}
	// if account does not already
	// existed, it creates a new
	// one with new inputs
	if (i == 100)
	{
		strcpy(s[j].uname, temp_name);
		s[j].age = temp_age;
		strcpy(s[j].password, temp_password1);
		strcpy(s[j].email, temp_email);
		strcpy(s[j].mobile, temp_mobile);
		j++;
		printf("\n\n\nAccount Successfully Created!!\n\n");
	}
}

// Function to Login the users
void login()
{
	printf("\n\n*****Welcome to Login page *******\n\n");

	printf("\tEnter Your Email: ");
	scanf("%s", temp_email);
	printf("\tEnter Your Password: ");
	scanf("%s", temp_password1);
	for (i = 0; i < 100; i++)
	{
		// Check whether the input
		// email is already existed or not
		if (!strcmp(s[i].email, temp_email))
		{
			// Check whether the password
			// is matched with the email or not
			if (!strcmp(s[i].password, temp_password1))
			{
				printf("\n\nWelcome %s, ", s[i].uname);
				printf("Your are successfully logged in\n\n ");
				printf("We Provide two ways of search\n ");
				printf("1) Search By Hotels\n ");
				printf("2) Search by Food\n ");
				printf("3)Exit\n\n");
				printf("Please Enter your choice:");
				scanf("%d", &search_choice);

				// Getting the input whether
				// the user are going to search
				// /Order by hotels or search/
				// order by food.
				switch (search_choice)
				{
				case 1:
				{
					search_by_hotels();
					break;
				}
				case 2:
				{
					search_by_food();
					break;
				}
				case 3:
				{
					// exit(1);
					main();
					return;
				}
				default:
				{
					printf("Please Enter the valid choice\n\n ");
					break;
				}
				}
				break;
			}
			else
			{ // loop for error sound
				for (int x = 0; x < 2; x++)
				{
					Beep(523, 800);
				}
				printf("\n\nInvalid Password! ");
				printf("Please Enter the correct password\n\n");
				main();
				break;
			}
		}
		else
		{ // loop for error sound
			for (int x = 0; x < 2; x++)
			{
				Beep(523, 800);
			}
			printf("\n\nAccount doesn't exist,Please signup!!\n\n ");
			main();
			break;
		}
	}
}

// Function to implement the Hotel
// initializer
void hotel_initialize()
{
	// Initializing the structure
	// with Aarya_bhavan hotel and
	// some foods name and
	// their respective costs.
	strcpy(m[1].hotel, "Zaika");
	strcpy(m[1].first_food, "chicken tikka");
	strcpy(m[1].second_food, "Pizza");
	strcpy(m[1].third_food, "Manchurian");
	strcpy(m[1].fourth_food, "Pasta");
	m[1].first = 70;
	m[1].second = 100;
	m[1].third = 95;
	m[1].fourth = 50;

	// Initializing the structure with
	// Banu_Hotel and some foods name
	// and their respective costs.
	strcpy(m[2].hotel, "Barbeque nation");
	strcpy(m[2].first_food, "Chicken roll");
	strcpy(m[2].second_food, "Paneer roll");
	strcpy(m[2].third_food, "Chicken_Rice");
	strcpy(m[2].fourth_food, "Dosa");
	m[2].first = 15;
	m[2].second = 75;
	m[2].third = 80;
	m[2].fourth = 50;

	// Initializing the structure with
	// SR_Bhavan hotel and some foods
	// name and their respective costs.
	strcpy(m[3].hotel, "Momonation");
	strcpy(m[3].first_food, "Egg roll");
	strcpy(m[3].second_food, "Prawn");
	strcpy(m[3].third_food, "Faloda");
	strcpy(m[3].fourth_food, "Burger");
	m[3].first = 90;
	m[3].second = 120;
	m[3].third = 35;
	m[4].fourth = 50;
}

// Function to implement the search
// by hotels
void search_by_hotels()
{
	hotel_initialize();
	printf(""
		   "\n\nPlease Choose the");
	printf("hotels\n\n1) %s\n2) %s\n3) %s",
		   m[1].hotel,
		   m[2].hotel, m[3].hotel);
	printf("\n4) Exit\n\nPlease ");
	printf("select the hotel\t");
	scanf("%d", &hotel_choice);
	if (hotel_choice > 4)
	{
		printf("Please Enter the valid choice\n\n");
		search_by_hotels();
	}
	else if (hotel_choice == 4)
		// exit(1);
		login();
	else
		hotels(hotel_choice);
}

// Function to implement the hotel
void hotels(int hotel_choice)
{
	total = 0;
	while (1)
	{
		// Displays the list of
		// foods available in
		// selected hotel
		printf("\n\nList of foods available");

		printf("in %s\n\n1) %s\tRs: %d\n2)",
			   m[hotel_choice].hotel,
			   m[hotel_choice].first_food,
			   m[hotel_choice].first);

		printf("%s\tRs: %d\n3) %s\tRs: %d\n4)",
			   m[hotel_choice].second_food,
			   m[hotel_choice].second,
			   m[hotel_choice].third_food,
			   m[hotel_choice].third);

		printf("Cart\n5) Exit\n\nPlease Enter");
		printf("Your Choice\t");
		scanf("%d", &food_choice);

		// Get the input for no
		// of foods to calculate
		// the total amount
		if (food_choice == 1)
		{
			printf("Please Enter the count of %s\t",
				   m[hotel_choice].first_food);
			scanf("%d", &n);
			total = total + (n * m[hotel_choice].first);
		}
		else if (food_choice == 2)
		{
			printf("Please Enter the Count");
			printf("of %s\t",
				   m[hotel_choice].second_food);
			scanf("%d", &n);
			total = total + (n * m[hotel_choice].second);
		}
		else if (food_choice == 3)
		{
			printf("Please Enter the Count");
			printf("of %s\t",
				   m[hotel_choice].third_food);
			scanf("%d", &n);
			total = total + (n * m[hotel_choice].third);
		}

		// Once the user, completed their
		// order, they can go to cart
		// by giving choice as 4.
		else if (food_choice == 4)
		{
			cart();
		}
		else if (food_choice == 5)
		{
			login();
		}
		else
		{
			printf("Please Enter the valid Choice\n\n");
		}
	}
}

void search_by_food()
{
	total = 0;
	// Initialize all the
	// hotels and their foods
	hotel_initialize();
	while (1)
	{
		printf("\n\nPlease choose the ");
		printf("food\n\n1) %s\t%d\n2) %s\t%d",
			   m[1].first_food, m[1].first,
			   m[1].second_food, m[1].second);

		printf("\n3) %s\t%d\n4) %s\t%d\n",
			   m[1].third_food, m[1].third,
			   m[2].first_food, m[2].first);

		printf("5) %s\t%d\n6) %s\t%d\n",
			   m[2].second_food, m[2].second,
			   m[2].third_food, m[2].third);

		printf("7) %s\t%d\n8) %s\t%d\n",
			   m[3].first_food, m[3].first,
			   m[3].second_food, m[3].second);

		printf("9) %s\t%d\n10) Cart\n",
			   m[3].third_food,
			   m[3].third);
		printf("11) Exit");
		printf("\nPlease Enter Your Choice\t");
		scanf("%d", &food);
		if (food > 11)
		{
			printf("Please Enter the valid choice\n\n");
			search_by_food();
		}
		// Moves to the cart
		// functionality
		else if (food == 10)
			cart();
		else if (food == 11)
			// exit(1);
			login();
		// Call food_order functionality
		// to get the no of foods and
		// to calculate the total
		// amount of the order.
		else
			food_order(food);
	}
}

// Function to implement the food
// order functionality
void food_order(int food)
{
	if (food >= 1 && food <= 3)
		hotel_id = 1;
	else if (food >= 4 && food <= 6)
		hotel_id = 2;
	else
		hotel_id = 3;
	if ((food % 3) == 1)
	{
		printf("Please Enter the count of %s\t",
			   m[hotel_id].first_food);
		scanf("%d", &n);
		total = total + (n * m[hotel_id].first);
	}
	else if ((food % 3) == 2)
	{
		printf("Please Enter the count of %s\t",
			   m[hotel_id].second_food);
		scanf("%d", &n);
		total = total + (n * m[hotel_id].second);
	}
	else if ((food % 3) == 0)
	{
		printf("Please Enter the count of %s\t",
			   m[hotel_id].third_food);
		scanf("%d", &n);
		total = total + (n * m[hotel_id].third);
	}
}

// Function to implement the cart
void cart()
{
	printf("\n\n\n\n******Cart******");
	printf("\nYour Total Order");
	printf("Amount is: %d\n", total);
	printf("\n\nDo You wish to order (y=1/n=0): ");
	scanf("%d", &ch);
	if (ch == 1)
	{
		
		Beep(300, 1000);
		Beep(200, 1000);
		Beep(100, 1000);
		Beep(50, 1000);
		printf("\n\nThank You for your order !! Your Food is on the way. \n Welcome again !!\n\n");
		// exit(1);
		return;
	}
	else if (ch == 0)
	{
		printf("Do You want to exit = -1 or Go back = 0");
		scanf("%d", &confirm);
		if (confirm == -1)
		{
			printf("\n\n Oops! Your order is cancelled !! \n Exiting \n Thank You visit again!\n");
			// exit(1);
			login();
		}
		else
		{
			
			Beep(300, 1000);
			Beep(200, 1000);
			Beep(100, 1000);
			Beep(50, 1000);
			printf("\n\nThank You.\n\n");
			login();
		}
	}
	else
	{
		printf("\n\nPlease Enter the correct choice\n\n");
		cart();
	}
}