#include <iostream>
#include <iomanip> // For controlling output format

using namespace std;

// Function prototypes
void applyCurve(double* gradePtr, double curvePercentage);
void displayFinalGrade(double grade);

int main() {
	char repeat; // Variable to store the user's choice for repeating the program

	do {
		// Welcome message
		cout << "Welcome to the Grade Curving Program!" << endl;
		cout << "This program will curve a student's grade by a certain percentage." << endl << endl;

		// Declare variables
		double grade; // Variable to store the student's grade
		double curvePercentage; // Variable to store curve percentage

		// Input student's grade and curve percetage from user
		cout << "Please enter the student's grade (0 - 100): ";
		cin >> grade;

		// Error handling for invalid grade input
		while (grade < 0 || grade > 100) {
			cout << "Invalid input. Please enter a grae between 0 and 100: ";
			cin >> grade;
		}
		cout << "Please enter the curve percentage (e.g., 10 for 10%): ";
		cin >> curvePercentage;

		// Declare pointer pointing to the grade variable
		double* gradePtr = &grade; // Pointer to the grade variable

		// Call function to apply the curve using a pointer
		applyCurve(gradePtr, curvePercentage); // Pass the grade pointer and curve the percentage to the function

		// Display the final curved grade
		displayFinalGrade(grade); // Call function to display the final grade

		// Ask the user if they want to enter another grade
		do {
			cout << "\nWould you like to enter another student's grade? (Y/N: ";
			cin >> repeat;
			repeat = toupper(repeat); // Convert input to uppercase to handle 'y' and 'n'

			if (repeat != 'Y' && repeat != 'N') {
				cout << "Invalid input. Please enter 'Y' or 'N'." << endl;
			}
		} while (repeat != 'Y' && repeat != 'N'); // Repeat until valid input is entered

		cout << endl; // Add a new line for better formatting

	} while (repeat == 'Y'); // Repeat the program if the user enters 'Y'

	cout << "Thank you for using the Grade Curving Program! Goodbye!" << endl;

	return 0; // Exit the program
}

//Function to apply a curve to the student's grade
void applyCurve(double* gradePtr, double curvePercentage) {
	// Apply the curve by increasing the grade by the percentage specified
	*gradePtr += (*gradePtr * curvePercentage / 100.0);

	// Ensure the grade does not exceed 100
	if (*gradePtr > 100.0) {
		*gradePtr = 100.0;
	}

	// Inform the user that the curve has been applied
	cout << "\nApplying a curve of " << curvePercentage << "% to the grade..." << endl;
}

// Function to display the final curved grade
void displayFinalGrade(double grade) {
	// Display the final curved grade with two decimal places
	cout << fixed << setprecision(2);
	cout << "\nThe student's final curved grade is: " << grade << endl;
}