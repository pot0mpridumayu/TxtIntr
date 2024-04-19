#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int calculate(string operation, vector<int> operands) {
    int result = 0;
    if (operation == "summa") {
        for (int operand : operands) {
            result += operand;
        }
    } else if (operation == "subtract") {
        if (operands.size() > 0) {
            result = operands[0];
            for (int i = 1; i < operands.size(); i++) {
                result -= operands[i];
            }
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc < 4 || argc > 8) {
        cout << "Usage: " << argv[0] << " -o <operation> <operand1> <operand2> <operand3> [operand4] [operand5]" << endl;
        cout << "Supported operations: summa, subtract" << endl;
        return 1;
    }

    string operation = "";
    vector<int> operands;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-o" && i + 1 < argc) {
            operation = argv[i + 1];
            i++; // Skip the next argument which is the operation
        } else {
            stringstream ss(arg);
            int tempOperand;
            if (ss >> tempOperand) {
                operands.push_back(tempOperand);
            }
        }
    }

    if (operands.size() < 3 || operands.size() > 5) {
        cout << "Invalid number of operands. Number of operands should be between 3 and 5." << endl;
        return 1;
    }

    int result = calculate(operation, operands);
    cout << "Result: " << result << endl;

    return 0;
}
