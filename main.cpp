
//  TallyHoProbabilityGenerator
//
//  Created by Ezazul Hoque on 22/8/20.
//  Copyright © 2020 Ezazul Hoque. All rights reserved.
//
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

//Program functions
void runMenu();
void displayText();
void createLists();
void generateTable();
void saveData();
void loadData();

int main() {
    // seed randoms
    srand(unsigned(time(NULL)));
    // run the program
    runMenu();
    // wait and exit
    system("pause");
    return 0;
}


//Intialising Functions

//This function creates and displays the menu.
void runMenu() {

    //Local Variables
    int userInput;
    //Displaying the header
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\tThe Tally Ho Probability Generator\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    //Displaying the Menu
    cout << "[0] End Testing the Program" << endl;
    cout << "[1] Display About Information" << endl;
    cout << "[2] Read and store data from files" << endl;
    cout << "[3] Generate a dice table" << endl;
    cout << "[4] Save Tally statistics to a file" << endl;
    cout << "[5] Load Tally statistics to a file" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    //Asking for the option
    cout << "Which option would you like? (0-5): ";
    cin >> userInput;
    //Checks if user inputs 0 and then the program will end
    if (userInput == 0) {
        cout << "Thank you for testing this application" << endl;
        system("PAUSE");
    }
    //Checks if the user inputs 1 and then calls the displayText function
    else if (userInput == 1) {
        system("CLS");
        displayText();
    }
    //Checks if the user inputs 2 and then calls the saveData function
    else if (userInput == 2) {
        createLists();

    }
    //Checks if the user inputs 3 and then calls the generateTable function
    else if (userInput == 3) {
        generateTable();
    }
    //Checks if the user inputs 4 and then calls the  function
    else if (userInput == 4) {
        saveData();
    }

    else if (userInput == 5) {
        loadData();
    }
    else {
        cout << "Please enter valid option numbers";
        system("CLS");
        runMenu();

    }

}

//This function will display the about information from the TallyAbout text file
void displayText() {
    /* This function reads the data from TallyAbout.txt file. Also the code was obtained from Lab 3 and some edits were made
    */

    // open file for reading
    ifstream fileToRead("TallyAbout.txt");
    if (fileToRead.is_open()) {
        string line = "";
        while (!fileToRead.eof()) {
            getline(fileToRead, line);
            cout << line << "\n";
        }
    } //If the file is not available this message will pop up
    else {
        cout << "\n File not found!\n";
    }
    // remember to close the file
    fileToRead.close();
    //The system pauses and when pressed enter it goes back to the main menu
    system("PAUSE");
    runMenu();
}


//This function will generate and display the dice table
void generateTable() {
    /*
    */

    //local variables
    int numOfDice = 0;
    int sizeOfDice = 6;
    int numOfRolls = 0;
    int result = 0;
    int rollsTotal = 0;
    string answer1 = "";
    string answer2 = "";
    string userInput = "";

    //Asking the user to input the number of dice to roll
    cout << endl;
    cout << "How many dice to roll (1-2): ";
    cin >> numOfDice;

    //Asking the user to input the rolls required
    cout << "How many rolls required (1-10): ";
    cin >> numOfRolls;
    cout << endl;
    rollsTotal = numOfRolls * 10;
    cout << "You rolled " << numOfDice << " dice " << rollsTotal << " times.\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

    /* In this part I have created a different way to generate table.
      If the user inputs one dice to roll, the die will start from one and until the numOfRolls.
      If the user inputs two dice to roll, the die will start from two and until numOfRolls.
      To make the process of the dice table some codes were obtained from https://www.youtube.com/watch?v=8eU4TDicf38, https://www.youtube.com/watch?v=87RHCdbEmgk and https://www.wikihow.com/Write-to-a-Text-File-in-C%2B%2B
      Then I combined them together and came up with a new process of dice table
      */
    if (numOfDice == 1) {

        ofstream saveFile;
        saveFile.open("savedTallyData.txt", ios::binary | ios::trunc);

        //To store the number of dice and the total dice rolls.
        saveFile << "You rolled " << numOfDice << " dice " << rollsTotal << " times.\n";
        saveFile << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        //Process of generating the table
        for (int i = 0; i < numOfRolls; i++) {
            //Generates a number between 1 and 6
            result = rand() % sizeOfDice + 1;
            //Displays and concatenates the all total generated numbers and also stores the data and saves it in savedTallyData text file
            answer1 = to_string(i + 1);
            answer2 = to_string(result);
            saveFile << answer1 << ": " << answer2 << endl;
            cout << answer1 << ": " << answer2 << endl;
        }
        saveFile.close();
        system("PAUSE");
        runMenu();

    }

    else if (numOfDice == 2) {

        ofstream saveFile;
        saveFile.open("savedTallyData.txt", ios::binary | ios::trunc);

        //To store the number of dice and the total dice rolls.
        saveFile << "You rolled " << numOfDice << " dice " << rollsTotal << " times.\n";
        saveFile << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        //Process of generating the table
        for (int i = 2; i < numOfRolls + 3; i++) {
            //Generates a number between 1 and 12
            result = (rand() % sizeOfDice + 1) * 2;
            //Displays the all total generated numbers
            answer1 = to_string(i);
            answer2 = to_string(result);
            cout << answer1 << ": " << answer2 << endl;
            saveFile << answer1 << ": " << answer2 << endl;
        }
        saveFile.close();
        system("PAUSE");
        runMenu();
    }
    else {
        system("CLS");
        cout << "Invalid statement" << endl;
        system("PAUSE");
        runMenu();
    }
}

//This function Reads and Stores data
void createLists() {
    // I did this code in a different way without using array or vectors.
    /*I did not create any array for this code, I did it in a different way. Some code was obtained from https://www.daniweb.com/programming/software-development/threads/250669/check-if-file-is-empty

    */
    string userInput = "";

    cout << "Data loading from savedTallyData.txt" << endl;

    // open file for reading
    ifstream fileToRead("savedTallyData.txt", ios::app);
    if (fileToRead.is_open()) {
        fileToRead.seekg(0, ios::end);
        size_t size = fileToRead.tellg();
        if (size == 0)
        {
            cout << "File not found\n";
        }
        else {
            string line = "";
            while (!fileToRead.eof()) {
                getline(fileToRead, line);
                cout << line << "\n";
            }

        }
    } //If the file is not available this message will pop up

    // remember to close the file
    fileToRead.close();
    //The system pauses and when pressed enter it goes back to the main menu
    system("PAUSE");
    runMenu();

}



//This function saves data from previous statistics
void saveData() {
    // Some of the codes here is obtained from Lab 3 and then they were modified.
    string userInput = "";
    cout << endl;
    // open file for reading
    ifstream fileToRead("savedTallyData.txt", ios::app);
    if (fileToRead.is_open()) {
        string line = "";
        while (!fileToRead.eof()) {
            getline(fileToRead, line);
            cout << line << "\n";
        }
    } //If the file is not available this message will pop up
    else {
        cout << "\n File not found!\n";
    }
    // remember to close the file
    fileToRead.close();
    //The system pauses and when pressed enter it goes back to the main menu
    //Asks the user if they want to save the file
    cout << "Do you want to save this data? (y/n) " << endl;
    cin >> userInput;
    //checks the user input
    if (userInput == "y" || userInput == "Y") {



        //Display to tell the user that the code is saved
        cout << "These statistics are now being saved" << endl;
        system("PAUSE");
        runMenu();
    }



    else {
        system("PAUSE");
        runMenu();
    }
    // remember to close the file
    fileToRead.close();
    //The system pauses and when pressed enter it goes back to the main menu
    system("PAUSE");
    runMenu();
}


//This function loads the data from savedTallyData
void loadData() {
    /*Some of the codes was obtained from Lab 3 and then modified.
    */
    cout << endl;
    // open file for reading
    ifstream fileToRead("savedTallyData.txt", ios::app);
    if (fileToRead.is_open()) {
        string line = "";
        while (!fileToRead.eof()) {
            getline(fileToRead, line);
            cout << line << "\n";
        }
    } //If the file is not available this message will pop up
    else {
        cout << "\n File not found!\n";
    }
    // remember to close the file
    fileToRead.close();
    //The system pauses and when pressed enter it goes back to the main menu
    system("PAUSE");
    runMenu();
}
