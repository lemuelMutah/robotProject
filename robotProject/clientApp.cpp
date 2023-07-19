#include <iostream>
#include "robot.h"
#include <cstring>

using namespace std;

void displayMenu();
void getInitData(int &, int &, int &, int&);
void chooseFunction(Robot &, char);
void powerButton(Robot &);
void forwardButton(Robot &);
void backwardButton(Robot &);
void leftButton(Robot &);
void rightButton(Robot &);
void checkPower(Robot);
void checkDirection(Robot);
void checkCordinates(Robot);
void displayState(Robot);

int main()
{
    int row;
    int column;
    int init_x;
    int init_y;
    char choice;

    cout << "Enter the number of rows: ";
    cin >> row;

    cout << endl << "Enter the number of columns: ";
    cin >> column;

    cout << endl << "Enter the x cordinate you want to start on: ";
    cin >> init_x;

    cout << endl << "Enter the y cordinate you want to start on: ";
    cin >> init_y;

    Robot robo(row, column, init_x, init_y);

    cout << "Rows " << row << endl
         << "Columns " << column << endl
         << "x " << init_x << endl
         << "y " << init_y << endl << endl;

    while(cin)
    {
        displayMenu();
        cin >> choice;
        chooseFunction(robo, choice);
        // end program if 0 is pressed
        if (choice == '0') return 0;
    }

    return 0;
}

void displayMenu()
{
    cout << "1. Press the power button" << endl
         << "2. Press the forward button" << endl
         << "3. Press the backward button" << endl
         << "4. Press the left button" << endl
         << "5. Press the right button" << endl
         << "6. Press the check power button" << endl
         << "7. Display the robot's direction" << endl
         << "8. Display the robot's cordinates" << endl
         << "9. Display the robot state" << endl
         << "0. Exit" << endl
         << endl;
}

// gets a choice from the user and call robot function based on the choice
void chooseFunction(Robot &robo, char choice)
{
    if (tolower(choice) == '1')
    {
        cout << "'1' was pressed!";
        powerButton(robo);
    }
    else if (tolower(choice) == '2')
    {
        cout << "'2' was pressed!";
        forwardButton(robo);
    }
    else if (tolower(choice) == '3')
    {
        cout << "'3' was pressed!";
        backwardButton(robo);
    }
    else if (tolower(choice) == '4')
    {
        cout << "'4' was pressed!";
        leftButton(robo);
    }
    else if (tolower(choice) == '5')
    {
        cout << "'5' was pressed!";
        rightButton(robo);
    }
    else if (tolower(choice) == '6')
    {
        cout << "'6' was pressed!";
        checkPower(robo);
    }
    else if (tolower(choice) == '7')
    {
        cout << "'7' was pressed!";
        checkDirection(robo);
    }
    else if (tolower(choice) == '8')
    {
        cout << "'8' was pressed!";
        checkCordinates(robo);
    }
    else if (tolower(choice) == '9')
    {
        cout << "'9' was pressed!" << endl;
        displayState(robo);
    }
    else if (tolower(choice) == '0')
    {
        cout << "'0' was pressed!" << endl;
        return;
    }
}

void powerButton(Robot &robo)
{
    robo.powerOnOff();
}

void forwardButton(Robot &robo)
{
    robo.moveForward();
}

void backwardButton(Robot &robo)
{
    robo.moveBackward();
}

void leftButton(Robot &robo)
{
    robo.turnLeft();
}

void rightButton(Robot &robo)
{
    robo.turnRight();
}

void checkPower(Robot robo)
{
    cout << endl << "The power state of the Robot is "<< robo.isOn() << endl << endl;
}

void checkDirection(Robot robo)
{
    if (robo.getDirection() == 0)
        cout << endl << "The robot is facing East." << endl << endl;
    else if (robo.getDirection() == 1)
        cout << endl << "The robot is facing West. " << endl << endl;
    else if (robo.getDirection() == 2)
        cout << endl << "The robot is facing South. " << endl << endl;   
    else if (robo.getDirection() == 3)
        cout << endl << "The robot is facing North. " << endl << endl;
}

void checkCordinates(Robot robo)
{
    cout << endl << "The robot's x coordinate is " << robo.getX() << endl << endl;
    cout << endl << "The robot's y coordinate is " << robo.getY() << endl << endl;
}

void displayState(Robot robo)
{
    robo.display();
}