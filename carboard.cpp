#include "game.h"
#include "helper.h"

#define PLAY_GAME "1"
#define STUDENT_INFO "2"
#define QUIT_GAME "3"

using std::cin;
using std::cout;
using std::endl;
using std::string;

// FUNCTION: SHOW STUDENT'S INFORMATION
void showStudentInformation(string name, string id, string email)
{

    cout << "\n--------------------------------------------\n";
    cout << "Student Name: " << name << endl;
    cout << "Student ID: " << id << endl;
    cout << "Student Email: " << email << endl;
    cout << "--------------------------------------------\n\n";
}
// FUNCTION: PROMPT USER FOR CHOICE
void prompt()
{
    cout << "Please enter your choice: ";
}

// FUNCTION: MAIN MENU
void mainMenu()
{
    cout << "Welcome to the Car Board\n";
    cout << "------------------------\n";
    cout << "1. Play game\n";
    cout << "2. Show student's information\n";
    cout << "3. Quit\n\n";
}

// FUNCTION: MENU FOR PLAYING THE GAME
// void playGame()
// {
//     cout << "\nYou can use the following commands to play the game:\n";
//     cout << "load <g>\n";
//     cout << "\tg: number of the game board to load\n";
//     cout << "init <x>,<y>,<direction>\n";
//     cout << "\tx: horizontal position of the car on the board (betwwen 0 & 9)\n";
//     cout << "\ty: vertical position of the car on the board (between 0 & 9)\n";
//     cout << "\tdirection: direction of the car's movement (north, east, south, west)\n";
//     cout << "forward (or f)\n";
//     cout << "turn_left (or l)\n";
//     cout << "turn_right (or r)\n";
//     cout << "quit\n\n";
// }

int main()
{
    /**
     * TODO: here's the main function. You can write the "main menu" loop/code
     * here or you can make separate functions - up to you.
     */

    string choice = "";
    string choice2 = "";
    string choice3 = "";

    // SHOW MAIN MENU AND PROMPT USER FOR CHOICE
    mainMenu();
    // prompt();

    Game *game = new Game();

    while (choice != PLAY_GAME && choice != QUIT_GAME && !cin.eof())
    {
        choice = Helper::readInput();

        if (choice == PLAY_GAME)
        game->start();
        
        else if (choice == STUDENT_INFO)
        {
            string name = "Fernaldy Winata";
            string id = "S3912660";
            string email = "s3912660@student.rmit.edu.au";

            showStudentInformation(name, id, email);
            prompt();
        }
        else if (choice != QUIT_GAME)
        {
            prompt();
        }
    }
    if (choice == QUIT_GAME)
    {
        cout << "Good bye!\n\n";
        return EXIT_SUCCESS;
    }
}