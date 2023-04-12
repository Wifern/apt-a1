#include "game.h"

using std::cin;
using std::cout;
using std::string;

Game::Game()
{
    // TODO
    // initialize the member variables
    board = new Board();
    player = new Player();
}

Game::~Game()
{
    // TODO
    // delete the member variables
    delete board;
    delete player;
}
void menu()
{
    cout << "You can use the following commands to play the game:\n";
    cout << "load <g>\n";
    cout << "\tg: number of the game board to load\n";
    cout << "init <x>,<y>,<direction>\n";
    cout << "\tx: horizontal position of the car on the board (betwwen 0 & 9)\n";
    cout << "\ty: vertical position of the car on the board (between 0 & 9)\n";
    cout << "\tdirection: direction of the car's movement (north, east, south, west)\n";
}

void Game::start()
{
    // print the menu
    menu();
    board->display(player);
    // prompt the user for input
    string menu_choice = "";

    cin >> menu_choice;
    while (menu_choice != COMMAND_LOAD && menu_choice != COMMAND_INIT && menu_choice != COMMAND_QUIT)
    {
        Helper::printInvalidInput();
        menu();
        cin >> menu_choice;
    }
    if (menu_choice == COMMAND_LOAD)
    {
        Game::loadBoard();
    }
    else if (menu_choice == "init")
    {
        Game::initializePlayer();
        menu();
        cout << "forward\n";
        cout << "turn_left\n";
        cout << "turn_right\n";
        cout << "quit\n";
        play();
    }
    else if (menu_choice == COMMAND_QUIT)
    {
        cout << "Goodbye!\n";
    }
}
bool Game::loadBoard()
{
    int boardId = 0;
    cin >> boardId;
    if (boardId == 1 || boardId == 2)
    {
        board->load(boardId);
        board->display(player);
        Game::start();
    }
    else
    {
        Helper::printInvalidInput();
    }
    return false;
}

bool Game::initializePlayer()
{
    int x = 0;
    int y = 0;
    std::string direction = "";

    cin >> x;
    cin.ignore();
    cin >> y;
    cin.ignore();
    cin >> direction;
    cin.ignore(); // ignore the newline character after reading the direction

    if (x < 0 || x > 9 || y < 0 || y > 9 ||
        (direction != DIRECTION_NORTH && direction != DIRECTION_SOUTH && direction != DIRECTION_EAST && direction != DIRECTION_WEST))
    {
        Helper::printInvalidInput();
        return false;
    }
    else
    {
        player->position = Position(x, y);
        board->placePlayer(player->position);
        if (direction == DIRECTION_NORTH)
            player->direction = NORTH;
        else if (direction == DIRECTION_EAST)
            player->direction = EAST;
        else if (direction == DIRECTION_SOUTH)
            player->direction = SOUTH;
        else if (direction == DIRECTION_WEST)
            player->direction = WEST;
        board->display(player);
        return true;
    }
}

void Game::play()
{
    board->display(player);

    while (true)
    {
        std::string command;
        std::cin >> command;

        if (command == COMMAND_FORWARD || command == COMMAND_FORWARD_SHORTCUT)
        {
            board->movePlayerForward(player);
            board->display(player);
        }
        else if (command == COMMAND_TURN_RIGHT || command == COMMAND_TURN_RIGHT_SHORTCUT)
        {
            player->turnDirection(TurnDirection::TURN_RIGHT);
            board->display(player);
        }
        else if (command == COMMAND_TURN_LEFT || command == COMMAND_TURN_LEFT_SHORTCUT)
        {
            player->turnDirection(TurnDirection::TURN_LEFT);
            board->display(player);
        }
        else if (command == COMMAND_QUIT)
        {
            cout << "Number of successful moves: " << player->moves << "\n";
            Game::start();
        }
        else
        {
            Helper::printInvalidInput();
        }
    }
}
