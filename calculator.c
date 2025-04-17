#include <stdio.h> //preprocessor directive

// Enumeration for exercise types. defines constants for exercise types and assigns a number for each type
typedef enum {
    RUNNING = 1,
    SWIMMING = 2,
    CYCLING = 3
} ExerciseType;

// Function to calculate calories burned
float calculateCalories(int exerciseType, float duration) { //calculates calories burned based on exercise type and duration
    float caloriesPerMinute; //stores the number of calories burned per minute per exercise 

   if(exerciseType == 1) {
    caloriesPerMinute = 10;
   } else if(exerciseType == 2) {
    caloriesPerMinute = 8;
   } else if(exerciseType == 3) {
    caloriesPerMinute = 6;
   } else {
    printf("Invalid exercise type selected.\n");
    return -1;
   }
    return caloriesPerMinute * duration;
}

// Function to display results
void displayResults(int exerciseType, float duration, float caloriesBurned) { // displays formatted summary of the exercise
    printf("\n--- Exercise Summary ---\n");
    printf("Exercise Type: ");
    if(exerciseType == 1) {
        printf("RUNNING\n");
       } else if(exerciseType == 2) {
        printf("SWIMMING\n");
       } else if(exerciseType == 3) {
        printf("CYCLING\n");
       } else {
        printf("Unknown\n");
    }
    printf("Duration: %.2f minutes\n", duration);
    printf("Calories Burned: %.2f calories\n", caloriesBurned);
}

int main() { // handles user input, calls the necessary functions, and manages the program flow
    int exerciseType; // stores selected exercise type as an integer
    float duration; // stores duration of exercise in minutes
    float caloriesBurned; // stores calculated calories
    char continueTracking; // determines if the user wants to continue tracking exercises

    printf("CALORIE FITNESS TRACKER CALCULATOR\n");// prints out the title of the program

    do { // ensures that the program runs atleast once and contributes until the user decides to quit
        // Display exercise options
        printf("\nSelect an exercise type : \n"); //displays a menu of exercise types
        printf("1. Running\n");
        printf("2. Swimming\n");
        printf("3. Cycling\n");
        printf("Enter exercise type (1-3): "); //user is prompted to enter a number
        scanf("%d", &exerciseType); // input is stored in the exercise type variable

        // Input duration
        printf("Enter duration in minutes: ");
        scanf("%f", &duration);

        // Calculate calories burned
        caloriesBurned = calculateCalories(exerciseType, duration);

        if (caloriesBurned != -1) { //If the caloriesBurned value is valid (not -1), the displayResults function is called to display the exercise summary.

            // Display results
            displayResults(exerciseType, duration, caloriesBurned);
        }

        // Ask if the user wants to continue
        printf("\nDo you want to track another exercise? (y/n): ");//The program asks the user if they want to track another exercise. The input (y or n) is stored in the continueTracking variable.

        scanf(" %c", &continueTracking);

    } while (continueTracking == 'y' || continueTracking == 'Y');

    printf("\nThank you for using the Calorie Fitness Tracker Calculator. Stay healthy!\n");

    return 0;
}