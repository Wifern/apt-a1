#include "player.h"

Position::Position()
{
    // INITIALISE POSITION
    this->x = 0;
    this->y = 0;
}

Position::Position(int x, int y)
{
    // UPDATE POSITION WITH NEW X AND Y
    this->x = x;
    this->y = y;
}

Player::Player()
{
    // INITIALISE PLAYER
    this->position = Position();
    this->direction = Direction::NORTH;
    this->moves = 0;
}

void Player::initialisePlayer(Position *position, Direction direction)
{
    // UPDATE PLAYER WITH NEW POSITION AND DIRECTION
    this->position = *position;
    this->direction = direction;
    this->moves = 0;
}

void Player::turnDirection(TurnDirection turnDirection)
{
    // TURN RIGHT
    if (this->direction == Direction::NORTH && turnDirection == TurnDirection::TURN_RIGHT)
    {
        this->direction = Direction::EAST;
    }
    else if (this->direction == Direction::EAST && turnDirection == TurnDirection::TURN_RIGHT)
    {
        this->direction = Direction::SOUTH;
    }
    else if (this->direction == Direction::SOUTH && turnDirection == TurnDirection::TURN_RIGHT)
    {
        this->direction = Direction::WEST;
    }
    else if (this->direction == Direction::WEST && turnDirection == TurnDirection::TURN_RIGHT)
    {
        this->direction = Direction::NORTH;
    }

    // TURN LEFT
    else if (this->direction == Direction::NORTH && turnDirection == TurnDirection::TURN_LEFT)
    {
        this->direction = Direction::WEST;
    }
    else if (this->direction == Direction::EAST && turnDirection == TurnDirection::TURN_LEFT)
    {
        this->direction = Direction::NORTH;
    }
    else if (this->direction == Direction::SOUTH && turnDirection == TurnDirection::TURN_LEFT)
    {
        this->direction = Direction::EAST;
    }
    else if (this->direction == Direction::WEST && turnDirection == TurnDirection::TURN_LEFT)
    {
        this->direction = Direction::SOUTH;
    }
}

Position Player::getNextForwardPosition()
{
    // GET THE POSITION OF THE NEXT TILE IN THE DIRECTION THE PLAYER IS FACING
    Position forwardpos = this->position;
    if (this->direction == Direction::NORTH)
    {
        forwardpos.y--;
    }
    else if (this->direction == Direction::EAST)
    {
        forwardpos.x++;
    }
    else if (this->direction == Direction::SOUTH)
    {
        forwardpos.y++;
    }
    else if (this->direction == Direction::WEST)
    {
        forwardpos.x--;
    }

    return forwardpos;
}

void Player::updatePosition(Position position)
{
    // UPDATE THE PLAYER'S POSITION
    this->position = position;
    this->moves++;
}

void Player::displayDirection()
{
    if (this->direction == Direction::NORTH)
    {
        std::cout << DIRECTION_ARROW_OUTPUT_NORTH;
    }
    else if (this->direction == Direction::EAST)
    {
        std::cout << DIRECTION_ARROW_OUTPUT_EAST;
    }
    else if (this->direction == Direction::SOUTH)
    {
        std::cout << DIRECTION_ARROW_OUTPUT_SOUTH;
    }
    else if (this->direction == Direction::WEST)
    {
        std::cout << DIRECTION_ARROW_OUTPUT_WEST;
    }
}
