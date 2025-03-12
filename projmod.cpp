#include <iostream>
#include <string>

class RoboticArm {
public:
    // Initialize the robotic arm with default angles and torque values for each segment
    RoboticArm() : baseAngle(0), upArmAngle(0), loArmAngle(0), baseTorque(0), upArmTorque(0), loArmTorque(0) {}

    // Function to move the arm by setting angles
    void moveArm(double base, double upperArm, double lowerArm, double baseT, double upperT, double lowerT) {
        baseAngle = base;
        upArmAngle = upperArm;
        loArmAngle = lowerArm;
        baseTorque = baseT;
        upArmTorque = upperT;
        loArmTorque = lowerT;
        printState();
    }

    // Function to print the current state of the robotic arm
    void printState() {
        std::cout << "Current Arm Angles and Torque:\n";
        std::cout << "  Base Angle: " << baseAngle << " degrees, Torque: " << baseTorque << " Nm\n";
        std::cout << "  Upper Arm Angle: " << upArmAngle << " degrees, Torque: " << upArmTorque << " Nm\n";
        std::cout << "  Lower Arm Angle: " << loArmAngle << " degrees, Torque: " << loArmTorque << " Nm\n";
    }

    // Function to reset the arm back to initial position (0 degrees for all segments and torque)
    void resetArm() {
        baseAngle = 0;
        upArmAngle = 0;
        loArmAngle = 0;
        baseTorque = 0;
        upArmTorque = 0;
        loArmTorque = 0;
        printState();
    }

    // Function to adjust the torque for each arm segment
    void adjustTorque(double baseT, double upperT, double lowerT) {
        baseTorque = baseT;
        upArmTorque = upperT;
        loArmTorque = lowerT;
        printState();
    }

private:
    double baseAngle;    // Base angle of the arm
    double upArmAngle;   // Upper arm angle
    double loArmAngle;   // Lower arm angle
    double baseTorque;   // Torque for the base segment
    double upArmTorque;  // Torque for the upper arm segment
    double loArmTorque;  // Torque for the lower arm segment
};

int main() {
    RoboticArm arm;
    std::string command;

    std::cout << "Welcome to the Robotic Arm Control System!\n";
    std::cout << "Commands:\n";
    std::cout << "  'move <base angle> <upper arm angle> <lower arm angle> <base torque> <upper torque> <lower torque>'\n";
    std::cout << "  'adjust_torque <base torque> <upper torque> <lower torque>'\n";
    std::cout << "  'reset' to reset the arm to its initial position\n";
    std::cout << "  'exit' to quit the program\n\n";

    // Infinite loop to keep receiving commands
    while (true) {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;  // Exit the program
        }
        else if (command == "reset") {
            arm.resetArm();  // Reset the arm
        }
        else if (command.substr(0, 4) == "move") {
            double base, upperArm, lowerArm, baseT, upperT, lowerT;
            if (sscanf(command.c_str(), "move %lf %lf %lf %lf %lf %lf", &base, &upperArm, &lowerArm, &baseT, &upperT, &lowerT) == 6) {
                arm.moveArm(base, upperArm, lowerArm, baseT, upperT, lowerT);  // Move arm to new angles with torque
            } else {
                std::cout << "Invalid command format. Please use 'move <base> <upper> <lower> <base_torque> <upper_torque> <lower_torque>'.\n";
            }
        }
        else if (command.substr(0, 14) == "adjust_torque") {
            double baseT, upperT, lowerT;
            if (sscanf(command.c_str(), "adjust_torque %lf %lf %lf", &baseT, &upperT, &lowerT) == 3) {
                arm.adjustTorque(baseT, upperT, lowerT);  // Adjust the torque of the arm segments
            } else {
                std::cout << "Invalid command format. Please use 'adjust_torque <base_torque> <upper_torque> <lower_torque>'.\n";
            }
        }
        else {
            std::cout << "Unknown command. Please try again.\n";
        }
    }

    return 0;
}

