/*
	Name: Christian Carnate
	Class: ITT-310 - Programming for Security Professionals
	Due Date: December 17, 2023
	Project Name: Are You Smarter Than a 5th Grader?
	Description: This is a C console-based game based on the TV game show "Are You Smarter Than a 5th Grader?"
*/

//Include necessary header files
#include <stdio.h> //Standard input and output library
#include <stdlib.h> //Standard C library
#include <stdbool.h> //Standard boolean library
#include <windows.h> //Standard Windows library

//Declare necessary functions
void entry(); //Starts the program and verifies the player's information
void end_program(); //Exits the program
void game_over(); //Displays the game over screen
void victory(); //Displays the victory screen
void how_to_play(); //Displays information on how to play the game
void menu(); //Displays the main menu
int game(); //Starts the main game code
int random_int(int min, int max); //Selects a random integer between a range

//Declare a structure to contain question details
struct question_details {
	char question_text[1024];
	char answer_text[1024];
	char grade_level[1024];
	char subject[1024];
};

//Declare boolean values to check if the player has answered a question at each grade level
bool firstGradeAnswered_question1 = false;
bool firstGradeAnswered_question2 = false;
bool secondGradeAnswered_question1 = false;
bool secondGradeAnswered_question2 = false;
bool thirdGradeAnswered_question1 = false;
bool thirdGradeAnswered_question2 = false;
bool fourthGradeAnswered_question1 = false;
bool fourthGradeAnswered_question2 = false;
bool fifthGradeAnswered_question1 = false;
bool fifthGradeAnswered_question2 = false;
bool sixthGradeAnswered_question1 = false;
bool sixthGradeAnswered_question2 = false;

//Declare questions for each grade level as members of type questions_details
//Grade 1
struct question_details question1_grade1;
struct question_details question2_grade1;
struct question_details question3_grade1;
struct question_details question4_grade1;
struct question_details question5_grade1;
struct question_details question6_grade1;
//Grade 2
struct question_details question1_grade2;
struct question_details question2_grade2;
struct question_details question3_grade2;
struct question_details question4_grade2;
struct question_details question5_grade2;
struct question_details question6_grade2;
//Grade 3
struct question_details question1_grade3;
struct question_details question2_grade3;
struct question_details question3_grade3;
struct question_details question4_grade3;
struct question_details question5_grade3;
struct question_details question6_grade3;
//Grade 4
struct question_details question1_grade4;
struct question_details question2_grade4;
struct question_details question3_grade4;
struct question_details question4_grade4;
struct question_details question5_grade4;
struct question_details question6_grade4;
//Grade 5
struct question_details question1_grade5;
struct question_details question2_grade5;
struct question_details question3_grade5;
struct question_details question4_grade5;
struct question_details question5_grade5;
struct question_details question6_grade5;
//Grade 6
struct question_details question1_grade6;
struct question_details question2_grade6;
struct question_details question3_grade6;
struct question_details question4_grade6;
struct question_details question5_grade6;
struct question_details question6_grade6;

//Definition of main function
void main() {
	system("cls"); //Clears the console
	printf("Loading game...");
	Sleep(1500); //Sleeps for 1500 ms
	entry(); //Calls the entry function start player verification
}

//Definition of entry function
void entry() {
	char fname[1024];
	char lname[1024];

	system("cls"); //Clears the console

	printf("-------------------------------------------------------\n\n");
	printf("                  SYSTEM VERIFICATION\n");
	printf("\n-------------------------------------------------------\n\n");
	printf("Please enter your full name: ");

	scanf_s("%s %s", &fname, 1024, &lname, 1024); //Asks the player to input a first and last name

	if (strcmp(fname, "Christian") == 0) { //Compares string fname to my first name
		if (strcmp(lname, "Carnate") == 0) { //Compares string lname to my last name
			printf("\nVerification successful. Loading game...");
			Sleep(1500); //Sleeps for 1500 ms
			menu(); //Calls the menu function if input matches my full name
		}
		else { //If input does not match my last name
			printf("\nVerification failed! Please try again.");
			Sleep(1500); //Sleeps for 1500 ms
			entry(); //Calls the entry function again
		}
	}
	else { //If input does not match my first name
		printf("\nVerification failed! Please try again.");
		Sleep(1500); //Sleeps for 1500 ms
		entry(); //Calls the entry function again
	}
}

//Definition of end_program function
void end_program() {
	system("cls"); //Clears the console
	printf("Thanks for playing!\n\n");
	printf("Exiting the game...\n");
	Sleep(1500); //Sleeps for 1500 ms
	exit(0); //Force quits the program
}

void game_over() {
	char return_to_menu[1024];

	system("cls"); //Clears the console

	printf("-------------------------------------------------------\n\n");
	printf("Sorry, you are NOT smarter than a 5th grader.\n\n");
	printf("-------------------------------------------------------\n\n");
	printf("Would you like to play again? Enter 'Yes' or 'No': ");

	scanf_s("%s", &return_to_menu, 1024); //Asks the player to input "Yes" or "No"

	if (strcmp(return_to_menu, "Yes") == 0) { //Compares string return_to_menu to string "Yes"
		printf("\nRestarting game...");
		Sleep(1500); //Sleeps for 1500 ms
		game(); //If input is "Yes," calls the game function
	}
	else if (strcmp(return_to_menu, "No") == 0) { //Compares string return_to_menu to string "No"
		printf("\nReturning to menu...");
		Sleep(1500); //Sleeps for 1500 ms
		menu(); //If input is "No," calls the menu function
	}
	else { //If string return_to_menu is neither "Yes" or "No"
		printf("\nIncorrect input. Please try again.");
		Sleep(1500); //Sleeps for 1500 ms
		game_over(); //Calls the game_over function again
	}
}

void victory() {
	char return_to_menu[1024];

	system("cls"); //Clears the console

	printf("-------------------------------------------------------\n\n");
	printf("Congratulations! You ARE smarter than a 5th grader!\n\n");
	printf("-------------------------------------------------------\n\n");
	printf("Would you like to play again? Enter 'Yes' or 'No': ");

	scanf_s("%s", &return_to_menu, 1024); //Asks the player to input "Yes" or "No"

	if (strcmp(return_to_menu, "Yes") == 0) { //Compares string return_to_menu to string "Yes"
		//Resets boolean values to false
		firstGradeAnswered_question1 = false;
		firstGradeAnswered_question2 = false;
		secondGradeAnswered_question1 = false;
		secondGradeAnswered_question2 = false;
		thirdGradeAnswered_question1 = false;
		thirdGradeAnswered_question2 = false;
		fourthGradeAnswered_question1 = false;
		fourthGradeAnswered_question1 = false;
		fifthGradeAnswered_question1 = false;
		fifthGradeAnswered_question2 = false;
		sixthGradeAnswered_question1 = false;
		sixthGradeAnswered_question2 = false;
		printf("\nRestarting game...");
		Sleep(1500); //Sleeps for 1500 ms
		game(); //If input is "Yes," calls the game function
	}
	else if (strcmp(return_to_menu, "No") == 0) { //Compares string return_to_menu to string "No"
		printf("\nReturning to menu...");
		Sleep(1500); //Sleeps for 1500 ms
		menu(); //If input is "No," calls the menu function
	}
	else { //If string return_to_menu is neither "Yes" or "No"
		printf("\nIncorrect input. Please try again.");
		Sleep(1500); //Sleeps for 1500 ms
		victory(); //Calls the victory function again
	}
}

//Definition of how_to_play function
void how_to_play() {
	char return_to_menu[1024];

	system("cls"); //Clears the console

	printf("-------------------------------------------------------\n\n");
	printf("'Are You Smarter Than a 5th Grader?' is a quiz game\n");
	printf("that is based on the premise that adults generally do\n");
	printf("not remember knowledge from elementary grade school\n");
	printf("because it is rarely used in adult life. You are tasked\n");
	printf("with answering questions ranging in difficulty from 1st\n");
	printf("grade to 6th grade. If you successfully answer all\n");
	printf("questions, then you ARE smarter than a 5th grader.\n\n");
	printf("To play, select a grade level and question number. Once\n");
	printf("a grade level and question number have been selected,\n");
	printf("a question will be presented to you. Answer the\n");
	printf("question to the best of your ability. Keep in mind that\n");
	printf("answers ARE case-sensitive. If you answer correctly,\n");
	printf("then you continue on with the game. If you answer\n");
	printf("incorrectly, then you are eliminated and are deemed NOT\n");
	printf("smarter than a 5th grader.\n\n");
	printf("Disclaimer: This C console-based program is limited in\n");
	printf("functionality. There are no cheats, which is present in\n");
	printf("the real-life game.\n\n");
	printf("-------------------------------------------------------\n\n");
	printf("Enter '1' to return to the main menu: ");

	scanf_s("%s", &return_to_menu, 1024); //Asks the player to input "1"

	if (strcmp(return_to_menu, "1") == 0) { //Compares string return_to_menu to string "1"
		printf("\nLoading menu...");
		Sleep(1500); //Sleeps for 1500 ms
		menu(); //If input is "1," calls the menu function again
	}
	else { //If input is not "1"
		printf("\nIncorrect input. Please try again.");
		Sleep(1500); //Sleeps for 1500 ms
		how_to_play(); //Calls the how_to_play function again
	}
}

//Definition of menu function
void menu() {
	char menu_choice[1024];

	system("cls"); //Clears the console

	printf("-------------------------------------------------------\n\n");
	printf("   Welcome to 'Are You Smarter Than a 5th Grader?'\n\n");
	printf("-------------------------------------------------------\n\n");
	printf("[1] Play\n");
	printf("[2] How to play\n");
	printf("[3] Exit game\n\n");
	printf("Choose an option: ");

	scanf_s("%s", &menu_choice, 1024); //Asks the player to choose option 1, 2, or 3

	if (strcmp(menu_choice, "1") == 0) { //Compares string menu_choice to string "1"
		printf("\nLoading game...");
		Sleep(1500); //Sleeps for 1500 ms
		game(); //If input is "1," calls the game function to start the game
	}
	else if (strcmp(menu_choice, "2") == 0) {//Compares string menu_choice to string "2"
		printf("\nLoading gameplay instructions...");
		Sleep(1500); //Sleeps for 1500 ms
		how_to_play(); //If input is "2," calls the how_to_play function to display gameplay details
	}
	else if (strcmp(menu_choice, "3") == 0) { //Compares string menu_choice to string "3"
		end_program(); //if input is "3," calls the end_program function
	}
	else { //If input is neither "1", "2", or "3"
		printf("\nNot a valid option. Please try again.");
		Sleep(1500); //Sleeps for 1500 ms
		menu(); //Calls the menu function again
	}
}

//Definition of game function
int game() {
	char grade_level[1024];
	char answer[1024];

	system("cls"); //Clears the console

	//Checks if all grade levels have been completed
	if (firstGradeAnswered_question1 && firstGradeAnswered_question2 && secondGradeAnswered_question1 && secondGradeAnswered_question2 && thirdGradeAnswered_question1 && thirdGradeAnswered_question2 && fourthGradeAnswered_question1 && fourthGradeAnswered_question2 && fifthGradeAnswered_question1 && fifthGradeAnswered_question2 && sixthGradeAnswered_question1 && sixthGradeAnswered_question2) {
		victory(); //Calls the victory function
	}

	printf("-------------------------------------------------------\n\n");
	printf("Select a grade level and question number by inputting\nthe correct number. Answers for each question ARE\ncase-sensitive.\n");
	if (!firstGradeAnswered_question1) { //Checks if bool firstGradeAnswered_question1 is false
		printf("\n[1]  1st Grade | Question 1");
	}
	if (!firstGradeAnswered_question2) { //Checks if bool firstGradeAnswered_question2 is false
		printf("\n[2]  1st Grade | Question 2");
	}
	if (!secondGradeAnswered_question1) { //Checks if bool secondGradeAnswered_question1 is false
		printf("\n[3]  2nd Grade | Question 1");
	}
	if (!secondGradeAnswered_question2) { //Checks if bool secondGradeAnswered_question2 is false
		printf("\n[4]  2nd Grade | Question 2");
	}
	if (!thirdGradeAnswered_question1) { //Checks if bool thirdGradeAnswered_question1 is false
		printf("\n[5]  3rd Grade | Question 1");
	}
	if (!thirdGradeAnswered_question2) { //Checks if bool thirdGradeAnswered_question1 is false
		printf("\n[6]  3rd Grade | Question 2");
	}
	if (!fourthGradeAnswered_question1) { //Checks if bool fourthGradeAnswered_question1 is false
		printf("\n[7]  4th Grade | Question 1");
	}
	if (!fourthGradeAnswered_question2) { //Checks if bool fourthGradeAnswered_question1 is false
		printf("\n[8]  4th Grade | Question 2");
	}
	if (!fifthGradeAnswered_question1) { //Checks if bool fifthGradeAnswered_question1 is false
		printf("\n[9]  5th Grade | Question 1");
	}
	if (!fifthGradeAnswered_question2) { //Checks if bool fifthGradeAnswered_question2 is false
		printf("\n[10] 5th Grade | Question 2");
	}
	if (!sixthGradeAnswered_question1) { //Checks if bool sixthGradeAnswered_question1 is false
		printf("\n[11] 6th Grade | Question 1");
	}
	if (!sixthGradeAnswered_question2) { //Checks if bool sixthGradeAnswered_question2 is false
		printf("\n[12] 6th Grade | Question 2");
	}
	printf("\n\n-------------------------------------------------------\n\n");
	printf("Select a grade level and question number: ");

	scanf_s("%s", &grade_level, 1024); //Asks the player to choose a grade level and question number

	if (strcmp(grade_level, "1") == 0) { //Compares string grade_level to string "1"
		if (!firstGradeAnswered_question1) { //Checks if bool firstGradeAnswered_question1 is false
			int question_number = random_int(1,3); //Selects a random integer between range [1,3]
			if (question_number == 1) { //If random question number is "1"
				system("cls"); //Clears the console

				//Defines question 1 of grade 1
				strcpy_s(question1_grade1.question_text, sizeof question1_grade1.question_text, "What is the capital of the state of Hawaii?");
				strcpy_s(question1_grade1.answer_text, sizeof question1_grade1.answer_text, "Honolulu");
				strcpy_s(question1_grade1.grade_level, sizeof question1_grade1.grade_level, "1st Grade");
				strcpy_s(question1_grade1.subject, sizeof question1_grade1.subject, "Geography");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question1_grade1.grade_level, question1_grade1.subject);
				printf("%s", question1_grade1.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question1_grade1.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					firstGradeAnswered_question1 = true; //Sets bool firstGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 2) { //If random question number is "2"
				system("cls"); //Clears the console

				//Defines question 2 of grade 1
				strcpy_s(question2_grade1.question_text, sizeof question2_grade1.question_text, "Which planet is closest to the sun?");
				strcpy_s(question2_grade1.answer_text, sizeof question2_grade1.answer_text, "Mercury");
				strcpy_s(question2_grade1.grade_level, sizeof question2_grade1.grade_level, "1st Grade");
				strcpy_s(question2_grade1.subject, sizeof question2_grade1.subject, "Planetary Science");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question2_grade1.grade_level, question2_grade1.subject);
				printf("%s", question2_grade1.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question2_grade1.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					firstGradeAnswered_question1 = true; //Sets bool firstGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else {
					printf("\nIncorrect answer!"); //If the answer is incorrect
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 3) { //If random question number is "3"
				system("cls"); //Clears the console

				//Defines question 3 of grade 1
				strcpy_s(question3_grade1.question_text, sizeof question3_grade1.question_text, "Which country bombed Pearl Harbor on December 7, 1941?");
				strcpy_s(question3_grade1.answer_text, sizeof question3_grade1.answer_text, "Japan");
				strcpy_s(question3_grade1.grade_level, sizeof question3_grade1.grade_level, "1st Grade");
				strcpy_s(question3_grade1.subject, sizeof question3_grade1.subject, "World History");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question3_grade1.grade_level, question3_grade1.subject);
				printf("%s", question3_grade1.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question3_grade1.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					firstGradeAnswered_question1 = true; //Sets bool firstGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else { //If random int is not in correct range
				game(); //Reboots the game
			}
		}
		else { //If bool firstGradeAnswered_question1 is true
			printf("\nNot a valid option. Please try again.");
			Sleep(1500); //Sleeps for 1500 ms
			game(); //Calls the game function again
		}
	}
	else if (strcmp(grade_level, "2") == 0) { //Compares string grade_level to string "2"
		if (!firstGradeAnswered_question2) { //Checks if bool firstGradeAnswered_question2 is false
			int question_number = random_int(4,6); //Selects a random integer between range [1,3]
			if (question_number == 4) { //If random question number is "4"
				system("cls"); //Clears the console

				//Defines question 4 of grade 1
				strcpy_s(question4_grade1.question_text, sizeof question4_grade1.question_text, "How many weeks are in a year?\n\nType ONLY digit(s) WITHOUT punctuation.");
				strcpy_s(question4_grade1.answer_text, sizeof question4_grade1.answer_text, "52");
				strcpy_s(question4_grade1.grade_level, sizeof question4_grade1.grade_level, "1st Grade");
				strcpy_s(question4_grade1.subject, sizeof question4_grade1.subject, "Mathematics");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question4_grade1.grade_level, question4_grade1.subject);
				printf("%s", question4_grade1.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question4_grade1.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					firstGradeAnswered_question2 = true; //Sets firstGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 5) { //If random question number is "5"
				system("cls"); //Clears the console

				//Defines question 5 of grade 1
				strcpy_s(question5_grade1.question_text, sizeof question5_grade1.question_text, "Which genre of literature consists of stories that are\ncompletely made up?\n\nType your answer WITHOUT any capitalization.");
				strcpy_s(question5_grade1.answer_text, sizeof question5_grade1.answer_text, "fiction");
				strcpy_s(question5_grade1.grade_level, sizeof question5_grade1.grade_level, "1st Grade");
				strcpy_s(question5_grade1.subject, sizeof question5_grade1.subject, "Literature");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question5_grade1.grade_level, question5_grade1.subject);
				printf("%s", question5_grade1.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question5_grade1.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					firstGradeAnswered_question2 = true; //Sets firstGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else {
					printf("\nIncorrect answer!"); //If the answer is incorrect
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 6) { //If random question number is "6"
				system("cls"); //Clears the console

				//Defines question 6 of grade 1
				strcpy_s(question6_grade1.question_text, sizeof question6_grade1.question_text, "How many stars are on the American flag?\n\nType ONLY digit(s) WITHOUT punctuation.");
				strcpy_s(question6_grade1.answer_text, sizeof question6_grade1.answer_text, "50");
				strcpy_s(question6_grade1.grade_level, sizeof question6_grade1.grade_level, "1st Grade");
				strcpy_s(question6_grade1.subject, sizeof question6_grade1.subject, "Civics");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question6_grade1.grade_level, question6_grade1.subject);
				printf("%s", question6_grade1.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question6_grade1.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					firstGradeAnswered_question2 = true; //Sets firstGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else { //If random int is not in correct range
				game(); //Reboots the game
			}
		}
		else { //If bool firstGradeAnswered_question2 is true
			printf("\nNot a valid option. Please try again.");
			Sleep(1500); //Sleeps for 1500 ms
			game(); //Calls the game function again
		}
	}
	else if (strcmp(grade_level, "3") == 0) { //Compares string grade_level to string "3"
		if (!secondGradeAnswered_question1) { //Checks if bool secondGradeAnswered_question1 is false
			int question_number = random_int(1,3); //Selects a random integer between range [1,3]
			if (question_number == 1) { //If random question number is "1"
				system("cls"); //Clears the console

				//Defines question 1 of grade 2
				strcpy_s(question1_grade2.question_text, sizeof question1_grade2.question_text, "What is the superlative form of the adjective 'big'?\n\nType your answer WITHOUT any capitalization.");
				strcpy_s(question1_grade2.answer_text, sizeof question1_grade2.answer_text, "biggest");
				strcpy_s(question1_grade2.grade_level, sizeof question1_grade2.grade_level, "2nd Grade");
				strcpy_s(question1_grade2.subject, sizeof question1_grade2.subject, "Grammar");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question1_grade2.grade_level, question1_grade2.subject);
				printf("%s", question1_grade2.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question1_grade2.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					secondGradeAnswered_question1 = true; //Sets secondGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 2) { //If random question number is "2"
				system("cls"); //Clears the console

				//Defines question 2 of grade 2
				strcpy_s(question2_grade2.question_text, sizeof question2_grade2.question_text, "What is the common name for the chemical compound\n'H2O'?\n\nType your answer WITHOUT capitalized letters.");
				strcpy_s(question2_grade2.answer_text, sizeof question2_grade2.answer_text, "water");
				strcpy_s(question2_grade2.grade_level, sizeof question2_grade2.grade_level, "2nd Grade");
				strcpy_s(question2_grade2.subject, sizeof question2_grade2.subject, "Chemistry");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question2_grade2.grade_level, question2_grade2.subject);
				printf("%s", question2_grade2.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question2_grade2.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					secondGradeAnswered_question1 = true; //Sets secondGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else {
					printf("\nIncorrect answer!"); //If the answer is incorrect
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 3) { //If random question number is "3"
				system("cls"); //Clears the console

				//Defines question 3 of grade 2
				strcpy_s(question3_grade2.question_text, sizeof question3_grade2.question_text, "What is the Arabic numeral for the Roman numeral 'XIX'?\n\nType ONLY digit(s) WITHOUT punctuation.");
				strcpy_s(question3_grade2.answer_text, sizeof question3_grade2.answer_text, "19");
				strcpy_s(question3_grade2.grade_level, sizeof question3_grade2.grade_level, "2nd Grade");
				strcpy_s(question3_grade2.subject, sizeof question3_grade2.subject, "Mathematics");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question3_grade2.grade_level, question3_grade2.subject);
				printf("%s", question3_grade2.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question3_grade2.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					secondGradeAnswered_question1 = true; //Sets secondGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else { //If random int is not in correct range
				game(); //Reboots the game
			}
		}
		else { //If bool secondGradeAnswered_question1 is true
			printf("\nNot a valid option. Please try again.");
			Sleep(1500); //Sleeps for 1500 ms
			game(); //Calls the game function again
		}
	}
	else if (strcmp(grade_level, "4") == 0) { //Compares string grade_level to string "4"
		if (!secondGradeAnswered_question2) { //Checks if bool secondGradeAnswered_question2 is false
			int question_number = random_int(4,6); //Selects a random integer between range [4,6]
			if (question_number == 4) { //If random question number is "4"
				system("cls"); //Clears the console

				//Defines question 4 of grade 2
				strcpy_s(question4_grade2.question_text, sizeof question4_grade2.question_text, "Identify the adverb in this sentence:\nSarah danced beautifully at her recital.");
				strcpy_s(question4_grade2.answer_text, sizeof question4_grade2.answer_text, "beautifully");
				strcpy_s(question4_grade2.grade_level, sizeof question4_grade2.grade_level, "2nd Grade");
				strcpy_s(question4_grade2.subject, sizeof question4_grade2.subject, "Grammar");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question4_grade2.grade_level, question4_grade2.subject);
				printf("%s", question4_grade2.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question4_grade2.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					secondGradeAnswered_question2 = true; //Sets secondGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 5) { //If random question number is "5"
				system("cls"); //Clears the console

				//Defines question 5 of grade 2
				strcpy_s(question5_grade2.question_text, sizeof question5_grade2.question_text, "Fill in the blank:\nThe first __ amendments to the Constitution are called\nthe Bill of Rights.\n\nType ONLY digit(s) WITHOUT punctuation.");
				strcpy_s(question5_grade2.answer_text, sizeof question5_grade2.answer_text, "10");
				strcpy_s(question5_grade2.grade_level, sizeof question5_grade2.grade_level, "2nd Grade");
				strcpy_s(question5_grade2.subject, sizeof question5_grade2.subject, "Civics");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question5_grade2.grade_level, question5_grade2.subject);
				printf("%s", question5_grade2.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question5_grade2.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					secondGradeAnswered_question2 = true; //Sets secondGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else {
					printf("\nIncorrect answer!"); //If the answer is incorrect
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 6) { //If random question number is "6"
				system("cls"); //Clears the console

				//Defines question 6 of grade 2
				strcpy_s(question6_grade2.question_text, sizeof question6_grade2.question_text, "Fill in the blank:\nNorth America consists of the United States, Canada,\nand _______.");
				strcpy_s(question6_grade2.answer_text, sizeof question6_grade2.answer_text, "Mexico");
				strcpy_s(question6_grade2.grade_level, sizeof question6_grade2.grade_level, "2nd Grade");
				strcpy_s(question6_grade2.subject, sizeof question6_grade2.subject, "Geography");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question6_grade2.grade_level, question6_grade2.subject);
				printf("%s", question6_grade2.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question6_grade2.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					secondGradeAnswered_question2 = true; //Sets secondGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else { //If random int is not in correct range
				game(); //Reboots the game
			}
		}
		else { //If bool secondGradeAnswered_question2 is true
			printf("\nNot a valid option. Please try again.");
			Sleep(1500); //Sleeps for 1500 ms
			game(); //Calls the game function again
		}
	}
	else if (strcmp(grade_level, "5") == 0) { //Compares string grade_level to string "5"
		if (!thirdGradeAnswered_question1) { //Checks if bool thirdGradeAnswered_question1 is false
			int question_number = random_int(1,3); //Selects a random integer between range [1,3]
			if (question_number == 1) { //If random question number is "1"
				system("cls"); //Clears the console

				//Defines question 1 of grade 3
				strcpy_s(question1_grade3.question_text, sizeof question1_grade3.question_text, "How many legs does an insect have?\n\nType ONLY digit(s) WITHOUT punctuation.");
				strcpy_s(question1_grade3.answer_text, sizeof question1_grade3.answer_text, "6");
				strcpy_s(question1_grade3.grade_level, sizeof question1_grade3.grade_level, "3rd Grade");
				strcpy_s(question1_grade3.subject, sizeof question1_grade3.subject, "Animal Science");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question1_grade3.grade_level, question1_grade3.subject);
				printf("%s", question1_grade3.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question1_grade3.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					thirdGradeAnswered_question1 = true; //Sets thirdGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 2) { //If random question number is "2"
				system("cls"); //Clears the console

				//Defines question 2 of grade 3
				strcpy_s(question2_grade3.question_text, sizeof question2_grade3.question_text, "Fill in the blank:\nThe formula used to find the hypotenuse of a right\ntriangle is called the ___________ theorem.");
				strcpy_s(question2_grade3.answer_text, sizeof question2_grade3.answer_text, "Pythagorean");
				strcpy_s(question2_grade3.grade_level, sizeof question2_grade3.grade_level, "3rd Grade");
				strcpy_s(question2_grade3.subject, sizeof question2_grade3.subject, "Mathematics");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question2_grade3.grade_level, question2_grade3.subject);
				printf("%s", question2_grade3.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question2_grade3.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					thirdGradeAnswered_question1 = true; //Sets thirdGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else {
					printf("\nIncorrect answer!"); //If the answer is incorrect
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 3) { //If random question number is "3"
				system("cls"); //Clears the console

				//Defines question 3 of grade 3
				strcpy_s(question3_grade3.question_text, sizeof question3_grade3.question_text, "Which country invented the first fireworks in the 7th\ncentury?");
				strcpy_s(question3_grade3.answer_text, sizeof question3_grade3.answer_text, "China");
				strcpy_s(question3_grade3.grade_level, sizeof question3_grade3.grade_level, "3rd Grade");
				strcpy_s(question3_grade3.subject, sizeof question3_grade3.subject, "World History");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question3_grade3.grade_level, question3_grade3.subject);
				printf("%s", question3_grade3.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question3_grade3.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					thirdGradeAnswered_question1 = true; //Sets thirdGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else { //If random int is not in correct range
				game(); //Reboots the game
			}
		}
		else { //If bool thirdGradeAnswered_question1 is true
			printf("\nNot a valid option. Please try again.");
			Sleep(1500); //Sleeps for 1500 ms
			game(); //Calls the game function again
		}
	}
	else if (strcmp(grade_level, "6") == 0) { //Compares string grade_level to string "6"
		if (!thirdGradeAnswered_question2) { //Checks if bool thirdGradeAnswered_question2 is false
			int question_number = random_int(4,6); //Selects a random integer between range [4, 6]
			if (question_number == 4) { //If random question number is "4"
				system("cls"); //Clears the console

				//Defines question 4 of grade 3
				strcpy_s(question4_grade3.question_text, sizeof question4_grade3.question_text, "Which term refers to the use of obvious exaggeration\nin literature?\n\nType your answer WITHOUT capitalization.");
				strcpy_s(question4_grade3.answer_text, sizeof question4_grade3.answer_text, "hyperbole");
				strcpy_s(question4_grade3.grade_level, sizeof question4_grade3.grade_level, "3rd Grade");
				strcpy_s(question4_grade3.subject, sizeof question4_grade3.subject, "Literature");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question4_grade3.grade_level, question4_grade3.subject);
				printf("%s", question4_grade3.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question4_grade3.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					thirdGradeAnswered_question2 = true; //Sets thirdGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 5) { //If random question number is "5"
				system("cls"); //Clears the console

				//Defines question 5 of grade 3
				strcpy_s(question5_grade3.question_text, sizeof question5_grade3.question_text, "Identify the direct object in this sentence:\nProfessor Farris gave us an exam today.");
				strcpy_s(question5_grade3.answer_text, sizeof question5_grade3.answer_text, "exam");
				strcpy_s(question5_grade3.grade_level, sizeof question5_grade3.grade_level, "3rd Grade");
				strcpy_s(question5_grade3.subject, sizeof question5_grade3.subject, "Grammar");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question5_grade3.grade_level, question5_grade3.subject);
				printf("%s", question5_grade3.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question5_grade3.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					thirdGradeAnswered_question2 = true; //Sets thirdGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else {
					printf("\nIncorrect answer!"); //If the answer is incorrect
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 6) { //If random question number is "6"
				system("cls"); //Clears the console

				//Defines question 6 of grade 3
				strcpy_s(question6_grade3.question_text, sizeof question6_grade3.question_text, "What type of clouds are present during severe weather,\nsuch as storms, floods, tornadoes, and hail?\n\nType your answer WITHOUT capitalization.");
				strcpy_s(question6_grade3.answer_text, sizeof question6_grade3.answer_text, "cumulonimbus");
				strcpy_s(question6_grade3.grade_level, sizeof question6_grade3.grade_level, "3rd Grade");
				strcpy_s(question6_grade3.subject, sizeof question6_grade3.subject, "Earth Science");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question6_grade3.grade_level, question6_grade3.subject);
				printf("%s", question6_grade3.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question6_grade3.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					thirdGradeAnswered_question2 = true; //Sets thirdGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else { //If random int is not in correct range
				game(); //Reboots the game
			}
		}
		else { //If bool thirdGradeAnswered_question2 is true
			printf("\nNot a valid option. Please try again.");
			Sleep(1500); //Sleeps for 1500 ms
			game(); //Calls the game function again
		}
	}
	else if (strcmp(grade_level, "7") == 0) { //Compares string grade_level to string "7"
		if (!fourthGradeAnswered_question1) { //Checks if bool fourthGradeAnswered_question1 is false
			int question_number = random_int(1,3); //Selects a random integer between range [1,3]
			if (question_number == 1) { //If random question number is "1"
				system("cls"); //Clears the console

				//Defines question 1 of grade 4
				strcpy_s(question1_grade4.question_text, sizeof question1_grade4.question_text, "Which ancient civilization created the wheel?");
				strcpy_s(question1_grade4.answer_text, sizeof question1_grade4.answer_text, "Sumer");
				strcpy_s(question1_grade4.grade_level, sizeof question1_grade4.grade_level, "4th Grade");
				strcpy_s(question1_grade4.subject, sizeof question1_grade4.subject, "Ancient History");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question1_grade4.grade_level, question1_grade4.subject);
				printf("%s", question1_grade4.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question1_grade4.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					fourthGradeAnswered_question1 = true; //Sets fourthGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 2) { //If random question number is "2"
				system("cls"); //Clears the console

				//Defines question 2 of grade 4
				strcpy_s(question2_grade4.question_text, sizeof question2_grade4.question_text, "Spell the word meaning the opposite of the word\n'permanent.'\n\nType your answer WITHOUT capitalized letters.");
				strcpy_s(question2_grade4.answer_text, sizeof question2_grade4.answer_text, "temporary");
				strcpy_s(question2_grade4.grade_level, sizeof question2_grade4.grade_level, "4th Grade");
				strcpy_s(question2_grade4.subject, sizeof question2_grade4.subject, "Spelling");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question2_grade4.grade_level, question2_grade4.subject);
				printf("%s", question2_grade4.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question2_grade4.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					fourthGradeAnswered_question1 = true; //Sets fourthGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else {
					printf("\nIncorrect answer!"); //If the answer is incorrect
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 3) { //If random question number is "3"
				system("cls"); //Clears the console

				//Defines question 3 of grade 4
				strcpy_s(question3_grade4.question_text, sizeof question3_grade4.question_text, "Which continent is also a country?");
				strcpy_s(question3_grade4.answer_text, sizeof question3_grade4.answer_text, "Australia");
				strcpy_s(question3_grade4.grade_level, sizeof question3_grade4.grade_level, "4th Grade");
				strcpy_s(question3_grade4.subject, sizeof question3_grade4.subject, "Geography");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question3_grade4.grade_level, question3_grade4.subject);
				printf("%s", question3_grade4.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question3_grade4.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					fourthGradeAnswered_question1 = true; //Sets fourthGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else { //If random int is not in correct range
				game(); //Reboots the game
			}
		}
		else { //If bool fourthGradeAnswered_question1 is true
			printf("\nNot a valid option. Please try again.");
			Sleep(1500); //Sleeps for 1500 ms
			game(); //Calls the game function again
		}
	}
	else if (strcmp(grade_level, "8") == 0) { //Compares string grade_level to string "8"
		if (!fourthGradeAnswered_question2) { //Checks if bool fourthGradeAnswered_question2 is false
			int question_number = random_int(4,6); //Selects a random integer between range [4,6]
			if (question_number == 4) { //If random question number is "4"
				system("cls"); //Clears the console

				//Defines question 4 of grade 4
				strcpy_s(question4_grade4.question_text, sizeof question4_grade4.question_text, "How many degrees are in a triangle?\n\nType ONLY digit(s) WITHOUT punctuation.");
				strcpy_s(question4_grade4.answer_text, sizeof question4_grade4.answer_text, "180");
				strcpy_s(question4_grade4.grade_level, sizeof question4_grade4.grade_level, "4th Grade");
				strcpy_s(question4_grade4.subject, sizeof question4_grade4.subject, "Mathematics");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question4_grade4.grade_level, question4_grade4.subject);
				printf("%s", question4_grade4.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question4_grade4.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					fourthGradeAnswered_question2 = true; //Sets fourthGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 5) { //If random question number is "5"
				system("cls"); //Clears the console

				//Defines question 5 of grade 4
				strcpy_s(question5_grade4.question_text, sizeof question5_grade4.question_text, "What term refers to the tendency of an object at rest\nto remain at rest and an object in motion to stay in\nmotion unless acted on by an outside force?\n\nType your answer WITHOUT capitalization.");
				strcpy_s(question5_grade4.answer_text, sizeof question5_grade4.answer_text, "inertia");
				strcpy_s(question5_grade4.grade_level, sizeof question5_grade4.grade_level, "4th Grade");
				strcpy_s(question5_grade4.subject, sizeof question5_grade4.subject, "Physics");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question5_grade4.grade_level, question5_grade4.subject);
				printf("%s", question5_grade4.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question5_grade4.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					fourthGradeAnswered_question2 = true; //Sets fourthGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else {
					printf("\nIncorrect answer!"); //If the answer is incorrect
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 6) { //If random question number is "6"
				system("cls"); //Clears the console

				//Defines question 6 of grade 4
				strcpy_s(question6_grade4.question_text, sizeof question6_grade4.question_text, "Fill in the blank:\nNapoleon Bonaparte suffered his final defeat in 1815\nat the Battle of ________.");
				strcpy_s(question6_grade4.answer_text, sizeof question6_grade4.answer_text, "Waterloo");
				strcpy_s(question6_grade4.grade_level, sizeof question6_grade4.grade_level, "4th Grade");
				strcpy_s(question6_grade4.subject, sizeof question6_grade4.subject, "World History");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question6_grade4.grade_level, question6_grade4.subject);
				printf("%s", question6_grade4.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question6_grade4.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					fourthGradeAnswered_question2 = true; //Sets fourthGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else { //If random int is not in correct range
				game(); //Reboots the game
			}
		}
		else { //If bool fourthGradeAnswered_question2 is true
			printf("\nNot a valid option. Please try again.");
			Sleep(1500); //Sleeps for 1500 ms
			game(); //Calls the game function again
		}
	}
	else if (strcmp(grade_level, "9") == 0) { //Compares string grade_level to string "9"
		if (!fifthGradeAnswered_question1) { //Checks if bool fifthGradeAnswered_question1 is false
			int question_number = random_int(1,3); //Selects a random integer between range [1,3]
			if (question_number == 1) { //If random question number is "1"
				system("cls"); //Clears the console

				//Defines question 1 of grade 5
				strcpy_s(question1_grade5.question_text, sizeof question1_grade5.question_text, "Which subatomic particle of the atom has a negative\ncharge?\n\nType your answer WITHOUT capitalized letters.");
				strcpy_s(question1_grade5.answer_text, sizeof question1_grade5.answer_text, "electron");
				strcpy_s(question1_grade5.grade_level, sizeof question1_grade5.grade_level, "5th Grade");
				strcpy_s(question1_grade5.subject, sizeof question1_grade5.subject, "Physics");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question1_grade5.grade_level, question1_grade5.subject);
				printf("%s", question1_grade5.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question1_grade5.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					fifthGradeAnswered_question1 = true; //Sets fifthGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 2) { //If random question number is "2"
				system("cls"); //Clears the console

				//Defines question 2 of grade 5
				strcpy_s(question2_grade5.question_text, sizeof question2_grade5.question_text, "How many yards are in TWO miles?\n\nType ONLY digit(s) WITHOUT punctuation.");
				strcpy_s(question2_grade5.answer_text, sizeof question2_grade5.answer_text, "3520");
				strcpy_s(question2_grade5.grade_level, sizeof question2_grade5.grade_level, "5th Grade");
				strcpy_s(question2_grade5.subject, sizeof question2_grade5.subject, "Mathematics");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question2_grade5.grade_level, question2_grade5.subject);
				printf("%s", question2_grade5.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question2_grade5.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					fifthGradeAnswered_question1 = true; //Sets fifthGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else {
					printf("\nIncorrect answer!"); //If the answer is incorrect
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 3) { //If random question number is "3"
				system("cls"); //Clears the console

				//Defines question 3 of grade 5
				strcpy_s(question3_grade5.question_text, sizeof question3_grade5.question_text, "In what year was the Bill of Rights ratified?");
				strcpy_s(question3_grade5.answer_text, sizeof question3_grade5.answer_text, "1791");
				strcpy_s(question3_grade5.grade_level, sizeof question3_grade5.grade_level, "5th Grade");
				strcpy_s(question3_grade5.subject, sizeof question3_grade5.subject, "U.S. History");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question3_grade5.grade_level, question3_grade5.subject);
				printf("%s", question3_grade5.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question3_grade5.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					fifthGradeAnswered_question1 = true; //Sets fifthGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else { //If random int is not in correct range
				game(); //Reboots the game
			}
		}
		else { //If bool fifthGradeAnswered_question1 is true
			printf("\nNot a valid option. Please try again.");
			Sleep(1500); //Sleeps for 1500 ms
			game(); //Calls the game function again
		}
	}
	else if (strcmp(grade_level, "10") == 0) { //Compares string grade_level to string "10"
		if (!fifthGradeAnswered_question2) { //Checks if bool fifthGradeAnswered_question2 is false
			int question_number = random_int(4,6); //Selects a random integer between range [4,6]
			if (question_number == 4) { //If random question number is "4"
				system("cls"); //Clears the console

				//Defines question 4 of grade 5
				strcpy_s(question4_grade5.question_text, sizeof question4_grade5.question_text, "Fill in the blank:\nThe island of Great Britain consists of England,\nScotland, and _____.");
				strcpy_s(question4_grade5.answer_text, sizeof question4_grade5.answer_text, "Wales");
				strcpy_s(question4_grade5.grade_level, sizeof question4_grade5.grade_level, "5th Grade");
				strcpy_s(question4_grade5.subject, sizeof question4_grade5.subject, "Geography");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question4_grade5.grade_level, question4_grade5.subject);
				printf("%s", question4_grade5.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question4_grade5.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					fifthGradeAnswered_question2 = true; //Sets fifthGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 5) { //If random question number is "5"
				system("cls"); //Clears the console

				//Defines question 5 of grade 5
				strcpy_s(question5_grade5.question_text, sizeof question5_grade5.question_text, "What is the subordinating conjunction in this sentence?\nThey lost the game because they did not practice.");
				strcpy_s(question5_grade5.answer_text, sizeof question5_grade5.answer_text, "because");
				strcpy_s(question5_grade5.grade_level, sizeof question5_grade5.grade_level, "5th Grade");
				strcpy_s(question5_grade5.subject, sizeof question5_grade5.subject, "Grammar");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question5_grade5.grade_level, question5_grade5.subject);
				printf("%s", question5_grade5.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question5_grade5.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					fifthGradeAnswered_question2 = true; //Sets fifthGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else {
					printf("\nIncorrect answer!"); //If the answer is incorrect
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 6) { //If random question number is "6"
				system("cls"); //Clears the console

				//Defines question 6 of grade 5
				strcpy_s(question6_grade5.question_text, sizeof question6_grade5.question_text, "What is the study of the classification of living\nthings?\n\nType your answer WITHOUT capitalization.");
				strcpy_s(question6_grade5.answer_text, sizeof question6_grade5.answer_text, "taxonomy");
				strcpy_s(question6_grade5.grade_level, sizeof question6_grade5.grade_level, "5th Grade");
				strcpy_s(question6_grade5.subject, sizeof question6_grade5.subject, "Life Science");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question6_grade5.grade_level, question6_grade5.subject);
				printf("%s", question6_grade5.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question6_grade5.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					fifthGradeAnswered_question2 = true; //Sets fifthGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else { //If random int is not in correct range
				game(); //Reboots the game
			}
		}
		else { //If bool fifthGradeAnswered_question2 is true
			printf("\nNot a valid option. Please try again.");
			Sleep(1500); //Sleeps for 1500 ms
			game(); //Calls the game function again
		}
	}
	else if (strcmp(grade_level, "11") == 0) { //Compares string grade_level to string "11"
		if (!sixthGradeAnswered_question1) { //Checks if bool sixthGradeAnswered_question1 is false
			int question_number = random_int(1,3); //Selects a random integer between range [1,3]
			if (question_number == 1) { //If random question number is "1"
				system("cls"); //Clears the console

				//Defines question 1 of grade 6
				strcpy_s(question1_grade6.question_text, sizeof question1_grade6.question_text, "Fill in the blank:\nThe U.S. Supreme Court case _____ v. Board of Education\noutlawed racial segregation in public schools.");
				strcpy_s(question1_grade6.answer_text, sizeof question1_grade6.answer_text, "Brown");
				strcpy_s(question1_grade6.grade_level, sizeof question1_grade6.grade_level, "6th Grade");
				strcpy_s(question1_grade6.subject, sizeof question1_grade6.subject, "U.S. History");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question1_grade6.grade_level, question1_grade6.subject);
				printf("%s", question1_grade6.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question1_grade6.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					sixthGradeAnswered_question1 = true; //Sets sixthGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 2) { //If random question number is "2"
				system("cls"); //Clears the console

				//Defines question 2 of grade 6
				strcpy_s(question2_grade6.question_text, sizeof question2_grade6.question_text, "Which vitamin is responsible for maintaining the immune\nsystem?\n\nType just the capitalized letter of the vitamin.");
				strcpy_s(question2_grade6.answer_text, sizeof question2_grade6.answer_text, "A");
				strcpy_s(question2_grade6.grade_level, sizeof question2_grade6.grade_level, "6th Grade");
				strcpy_s(question2_grade6.subject, sizeof question2_grade6.subject, "Health Science");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question2_grade6.grade_level, question2_grade6.subject);
				printf("%s", question2_grade6.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question2_grade6.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					sixthGradeAnswered_question1 = true; //Sets sixthGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else {
					printf("\nIncorrect answer!"); //If the answer is incorrect
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 3) { //If random question number is "3"
				system("cls"); //Clears the console

				//Defines question 3 of grade 6
				strcpy_s(question3_grade6.question_text, sizeof question3_grade6.question_text, "In literature, what term refers to the event of a\ncharacter speaking to oneself out loud in a monologue?\n\nType your answer WITHOUT capitalization.");
				strcpy_s(question3_grade6.answer_text, sizeof question3_grade6.answer_text, "soliloquy");
				strcpy_s(question3_grade6.grade_level, sizeof question3_grade6.grade_level, "6th Grade");
				strcpy_s(question3_grade6.subject, sizeof question3_grade6.subject, "Literature");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question3_grade6.grade_level, question3_grade6.subject);
				printf("%s", question3_grade6.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question3_grade6.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					sixthGradeAnswered_question1 = true; //Sets sixthGradeAnswered_question1 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else { //If random int is not in correct range
				game(); //Reboots the game
			}
		}
		else { //If bool firstGradeAnswered is true
			printf("\nNot a valid option. Please try again.");
			Sleep(1500); //Sleeps for 1500 ms
			game(); //Calls the game function again
		}
	}
	else if (strcmp(grade_level, "12") == 0) { //Compares string grade_level to string "12"
		if (!sixthGradeAnswered_question2) { //Checks if bool sixthGradeAnswered_question2 is false
			int question_number = random_int(4,6); //Selects a random integer between range [4,6]
			if (question_number == 4) { //If random question number is "4"
				system("cls"); //Clears the console

				//Defines question 4 of grade 6
				strcpy_s(question4_grade6.question_text, sizeof question4_grade6.question_text, "What is the capital of Hungary?");
				strcpy_s(question4_grade6.answer_text, sizeof question4_grade6.answer_text, "Budapest");
				strcpy_s(question4_grade6.grade_level, sizeof question4_grade6.grade_level, "6th Grade");
				strcpy_s(question4_grade6.subject, sizeof question4_grade6.subject, "Geography");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question4_grade6.grade_level, question4_grade6.subject);
				printf("%s", question4_grade6.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question4_grade6.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					sixthGradeAnswered_question2 = true; //Sets sixthGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 5) { //If random question number is "5"
				system("cls"); //Clears the console

				//Defines question 5 of grade 6
				strcpy_s(question5_grade6.question_text, sizeof question5_grade6.question_text, "The expression i^4 simplifies into which value?\n\nType ONLY digit(s) WITHOUT punctuation.");
				strcpy_s(question5_grade6.answer_text, sizeof question5_grade6.answer_text, "1");
				strcpy_s(question5_grade6.grade_level, sizeof question5_grade6.grade_level, "6th Grade");
				strcpy_s(question5_grade6.subject, sizeof question5_grade6.subject, "Mathematics");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question5_grade6.grade_level, question5_grade6.subject);
				printf("%s", question5_grade6.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question5_grade6.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					sixthGradeAnswered_question2 = true; //Sets sixthGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else {
					printf("\nIncorrect answer!"); //If the answer is incorrect
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else if (question_number == 6) { //If random question number is "6"
				system("cls"); //Clears the console

				//Defines question 6 of grade 6
				strcpy_s(question6_grade6.question_text, sizeof question6_grade6.question_text, "Which term refers to a form of government in which\npower is vested with a small number of people?\n\nType your answer WITHOUT capitalization.");
				strcpy_s(question6_grade6.answer_text, sizeof question6_grade6.answer_text, "oligarchy");
				strcpy_s(question6_grade6.grade_level, sizeof question6_grade6.grade_level, "6th Grade");
				strcpy_s(question6_grade6.subject, sizeof question6_grade6.subject, "Civics");

				printf("-------------------------------------------------------\n\n");
				printf("%s %s\n\n", question6_grade6.grade_level, question6_grade6.subject);
				printf("%s", question6_grade6.question_text);
				printf("\n\n-------------------------------------------------------\n\n");
				printf("Enter an answer: ");

				scanf_s("%s", answer, 1024); //Asks the player for an answer

				if (strcmp(answer, question6_grade6.answer_text) == 0) { //If the answer is correct
					printf("\nCorrect answer!");
					sixthGradeAnswered_question2 = true; //Sets sixthGradeAnswered_question2 to true
					Sleep(1500); //Sleeps for 1500 ms
					game(); //Calls the game function again
				}
				else { //If the answer is incorrect
					printf("\nIncorrect answer!");
					Sleep(1500); //Sleeps for 1500 ms
					game_over(); //Calls the game_over function
				}
			}
			else { //If random int is not in correct range
				game(); //Reboots the game
			}
		}
		else { //If bool fourthGradeAnswered_question2 is true
			printf("\nNot a valid option. Please try again.");
			Sleep(1500); //Sleeps for 1500 ms
			game(); //Calls the game function again
		}
	}
	else { //If string grade_level is not valid
		printf("\nNot a valid option. Please try again.");
		Sleep(1500); //Sleeps for 1500 ms
		game(); //Calls the menu function again
	}
}

//Definition of random_number function to generate a random integer between a range
int random_int(int min, int max) {
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}