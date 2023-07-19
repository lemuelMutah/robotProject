#ifndef CLASS_ROBOT_
#define CLASS_ROBOT_

//enumerate for direction
enum Direction{EAST, WEST, SOUTH, NORTH};

// robot class declaration
class Robot
{
    private:
        bool power_state;
        int rows;
        int columns;
        Direction facing;
        int current_x;
        int current_y;

    public:
        // robot constructor
        Robot(int new_rows, int new_columns,
              int initial_x, int initial_y);
        void powerOnOff();
        void moveForward();
        void moveBackward();
        void turnLeft();
        void turnRight();
        bool isOn();
        Direction getDirection();
        int  getX();
        int  getY();
        void display();
}; // class Robot
#endif