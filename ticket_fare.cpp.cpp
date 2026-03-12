/**
 * PF Assignment 2 - Question 1
 * Ticket Fare Calculator
 * 
 * This program calculates railway ticket fare based on distance and class code.
 * Class codes: E (Economy), B (Business), F (First Class)
 */

#include <iostream>
using namespace std;

// Function prototype
void ticket_fare(int distance, char class_code);

int main() {
    int dist;
    char code;
    
    // Input from user
    cout << "Enter distance in km: ";
    cin >> dist;
    cout << "Enter class code (E, B, F): ";
    cin >> code;
    
    // Call function
    ticket_fare(dist, code);
    
    return 0;
}

/**
 * Calculates and displays ticket fare based on distance and class
 * 
 * Fare Structure:
 * - Economy (E): Basic fare Rs. 500, then Rs. 8 per km beyond 50km
 * - Business (B): Basic fare Rs. 1000, then Rs. 15 per km beyond 50km
 * - First Class (F): Basic fare Rs. 2000, then Rs. 25 per km beyond 50km
 * 
 * @param distance Travel distance in kilometers
 * @param class_code Class code (E, B, or F)
 */
void ticket_fare(int distance, char class_code) {
    int basicFare = 0, addFare = 0, totalFare = 0;
    
    // Invalid input check
    if (distance <= 0 || (class_code != 'E' && class_code != 'B' && class_code != 'F')) {
        cout << "ticket error" << endl;
        return;
    }
    
    // Fare rates based on class
    if (class_code == 'E') {
        basicFare = 500;
        addFare = 8;
    }
    else if (class_code == 'B') {
        basicFare = 1000;
        addFare = 15;
    }
    else if (class_code == 'F') {
        basicFare = 2000;
        addFare = 25;
    }
    
    // Fare calculation
    if (distance <= 50)
        totalFare = basicFare;
    else
        totalFare = basicFare + (distance - 50) * addFare;
    
    // Output result
    cout << "Total fare: " << totalFare << endl;
}