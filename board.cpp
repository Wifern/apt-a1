#include "board.h"

using std::vector;
using std::cout;

const vector<vector<Cell>> Board::BOARD_1 =
    {
        {BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED}};

const vector<vector<Cell>> Board::BOARD_2 =
    {
        {BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}};

Board::Board()
{
    // initialize the board to a 10*10 board with all EMPTY cells
    // vector<Cell> column (DEFAULT_BOARD_DIMENSION, EMPTY);
    board = new vector<vector<Cell>>(DEFAULT_BOARD_DIMENSION, vector<Cell>(DEFAULT_BOARD_DIMENSION, EMPTY));
}

Board::~Board()
{
    // initialize to null pointer
    delete board;
}

void Board::load(int boardId)
{
    // TODO
    // load the board to either BOARD_1 or BOARD_2 according to user input.
    if (boardId == 1)
    {
        *board = BOARD_1;
    }
    else if (boardId == 2)
    {
        *board = BOARD_2;
    }
}

bool Board::placePlayer(Position position)
{
    // TODO
    // Try to place the PLAYER cell at the provided position.
    // Note that if the position is outside the bounds of the board or if the cell
    // at the provided position is BLOCKED then you should return FALSE.
    // Return TRUE when the cell at the position is successfully set to PLAYER.
    if (position.x < 0 || position.x >= DEFAULT_BOARD_DIMENSION ||
        position.y < 0 || position.y >= DEFAULT_BOARD_DIMENSION)
    {
        cout << "The car is at the edge of the board and cannot be placed there\n";
        return false;
    }
    else if (board->at(position.x).at(position.y) == BLOCKED)
    {
        cout << "The car is blocked and cannot be placed there\n";
        return false;
    }
    else if (board->at(position.x).at(position.y) == EMPTY && board->at(position.x).at(position.y) != BLOCKED)
    {
        board->at(position.x).at(position.y) = PLAYER;
        return true;
    }
    return false;
}

PlayerMove Board::movePlayerForward(Player* player)
{
    Position currentPosition = player->position;
    Position nextPosition = player->getNextForwardPosition();
    if (nextPosition.x < 0 || nextPosition.x >= DEFAULT_BOARD_DIMENSION ||
        nextPosition.y < 0 || nextPosition.y >= DEFAULT_BOARD_DIMENSION)
    {   
        std::cout << "The car is at the edge of the board and cannot move further in that direction\n";
        return OUTSIDE_BOUNDS;
    }
    else if (board->at(nextPosition.x).at(nextPosition.y) == BLOCKED)
    {   
        std::cout << "The car is blocked and cannot move further in that direction\n";
        return CELL_BLOCKED;
    }
    else if (board->at(nextPosition.x).at(nextPosition.y) == EMPTY && board->at(nextPosition.x).at(nextPosition.y) != BLOCKED)
    {
        board->at(currentPosition.x).at(currentPosition.y) = EMPTY;
        board->at(nextPosition.x).at(nextPosition.y) = PLAYER;
        player->updatePosition(nextPosition);
        return PLAYER_MOVED;
    }
    return PLAYER_MOVED;
}


void Board::display(Player* player) {
    std::cout << "| |0|1|2|3|4|5|6|7|8|9|" << std::endl;
    for (int i = 0; i < DEFAULT_BOARD_DIMENSION; i++) {
        std::cout << LINE_OUTPUT << i << LINE_OUTPUT;
        for (int j = 0; j < DEFAULT_BOARD_DIMENSION; j++) {
            if (board->at(i).at(j) == BLOCKED) {

                std::cout << BLOCKED_OUTPUT;
            } else if (player != nullptr && i == player->position.y && j == player->position.x) {
                player->displayDirection();
            } else {
                std::cout << EMPTY_OUTPUT;
            }
            std::cout << LINE_OUTPUT;
        }
        std::cout << std::endl;
    }
}

