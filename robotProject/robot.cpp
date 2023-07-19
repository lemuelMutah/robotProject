#include <iostream>
#include "robot.h"

using namespace std;

// robot constructor with default values for its parameters if none is put
// in the object instantiation
Robot::Robot(int new_rows = 10, int new_columns = 10, int initial_x = 5,
             int initial_y = 5)
{
    rows = new_rows;
    columns =  new_columns;
    current_x = initial_x;
    current_y = initial_y;
    facing = EAST;
}

// checks power state and turns either on or off
void Robot::powerOnOff()
{
    if (power_state)
    {
        power_state = false;
        cout << endl << "The robot is now off!!" << endl << endl;
    }
    else
    {
        power_state = true;
        cout << endl << "The robot is now on!!" << endl << endl;
    }
}

// move the robot forward in the direction it is facing
void Robot::moveForward()
{
    if (power_state)
    {
        if ((facing == 0) && current_x < rows)
        {
            current_x += 1;
            cout << endl << "The robot moved forward facing East!!" << endl << endl;
        }
        else if ((facing == 1) && current_x > 0)
        {
            current_x -= 1;
            cout << endl << "The robot moved forward facing West!!" << endl << endl;
        }
        else if ((facing == 2) && current_y > 0)
        {
            current_y -= 1;
            cout << endl << "The robot moved forward facing South!!" << endl << endl;
        }
        else if ((facing == 3) && current_y < columns)
        {
            current_y += 1;
            cout << endl << "The robot moved forward facing North!!" << endl << endl;
        }
        else
        {
            cout << endl << "Unable to move forwards passed the border"  << endl << endl;
        }
    }
    else
    {
        cout << endl << "Unable to move forward. The robot is off!" << endl << endl;
    }
}

// move the robot opposite to the direction it is facing.
void Robot::moveBackward()
{
    if (power_state)
    {
        if ((facing == 0) && current_x > 0)
        {
            current_x -= 1;
            cout << endl << "The robot moved backward facing East!!" << endl << endl;

        }
        else if ((facing == 1) && current_x < rows)
        {
            current_x += 1;
            cout << endl << "The robot moved backward facing West!!" << endl << endl;
        }
        else if ((facing == 2) && current_y < columns)
        {
            current_y += 1;
            cout << endl << "The robot moved backward facing South!!" << endl << endl;
        }
        else if ((facing == 3) && current_x > 0)
        {
            current_y -= 1;
            cout << endl << "The robot moved backward facing North!!" << endl << endl;
        }
        else
        {
            cout << endl << "Unable to move backwards passed the border" << endl << endl;
        }
    }
    else
    {
        cout << endl << "Unable to move backward. The robot is off!" << endl << endl;
    }
}

// rotate the robot leftwards/ counterclockwise
void Robot::turnLeft()
{
    if (power_state)
    {
        if (facing == EAST)
        {
            facing = NORTH;
            cout << endl << "The robot turned left and is now facing North!!" << endl << endl;

        }
        else if (facing == WEST)
        {
            facing = SOUTH;
            cout << endl << "The robot turned left and is now facing South!!" << endl << endl;
        }
        else if (facing == SOUTH)
        {
            facing = EAST;
            cout << endl << "The robot turned left and is now facing East!!" << endl << endl;
        }
        else if (facing == NORTH)
        {
            facing = WEST;
            cout << endl << "The robot turned left and is now facing West!!" << endl << endl;
        }
    }
    else
    {
        cout << endl << "Unable to turn left. The robot is off!" << endl << endl;
    }
}

// rotate the robot rightwards/ clockwise
void Robot::turnRight()
{
    if (power_state)
    {
        if (facing == EAST)
        {
            facing = SOUTH;
            cout << endl << "The robot turned right and is now facing South!!" << endl << endl;

        }
        else if (facing == WEST)
        {
            facing = NORTH;
            cout << endl << "The robot turned right and is now facing North!!" << endl << endl;
        }
        else if (facing == SOUTH)
        {
            facing = WEST;
            cout << endl << "The robot turned right and is now facing West!!" << endl << endl;
        }
        else if (facing == NORTH)
        {
            facing = EAST;
            cout << endl << "The robot turned right and is now facing East!!" << endl << endl;
        }
    }
    else
    {
        cout << endl << "Unable to turn right. The robot is off!" << endl << endl;
    }
}

// return the robot power state
bool Robot::isOn()
{
    if (power_state)
        return true;
    else
        return false;
}

// returnt the direction in which the robot is facing
Direction Robot::getDirection()
{
    return facing;
}

// return the robots x cordinate
int Robot::getX()
{
    return current_x;
}

// return the robots right cordinate
int Robot::getY()
{
    return current_y;
}

// display the complete status of the robot.
void Robot::display()
{
    if(power_state)
        cout << endl << "The robot is on!" << endl;
    else
        cout << "The robot is off!" << endl;

    cout << "The map is a " << rows << " by " << columns << " map." << endl;
    cout << "The robot's current position is (" << current_x  << ", " << current_y << ")" << endl;
    if (facing == 0)
        cout << "The robot is facing East." << endl << endl;
    else if (facing == 1)
        cout << "The robot is facing West. " << endl << endl;
    else if (facing == 2)
        cout << "The robot is facing South. " << endl << endl;   
    else if (facing == 3)
        cout << "The robot is facing North. " << endl << endl;
}