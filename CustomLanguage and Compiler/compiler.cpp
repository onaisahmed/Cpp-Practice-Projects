#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <limits>

using namespace std;

class MiniCompiler {
private:
    unordered_map<string, int> variables;

    void handleLetCommand(const string& line) {
        istringstream iss(line);
        string keyword, var, equals;
        iss >> keyword >> var >> equals;

        if (equals == "=") {
            string expression;
            getline(iss, expression);
            int value = evaluateExpression(expression);
            variables[var] = value;
        } else {
            cerr << "Error: Invalid syntax in let command.\n";
        }
    }

    void handlePrintCommand(const string& line) {
        istringstream iss(line);
        string keyword, var;
        iss >> keyword >> var;

        if (variables.find(var) != variables.end()) {
            cout << var << " = " << variables[var] << endl;
        } else {
            cerr << "Error: Variable \"" << var << "\" is not defined.\n";
        }
    }

    void handleInputCommand(const string& line) {
        istringstream iss(line);
        string keyword, var;
        iss >> keyword >> var;

        if (!var.empty()) {
            cout << "Enter value for " << var << ": ";
            int value;
            cin >> value;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            variables[var] = value;
        } else {
            cerr << "Error: Invalid syntax in input command.\n";
        }
    }

    int evaluateExpression(const string& expression) {
        istringstream iss(expression);
        string token;
        int result = 0;
        char operation = '+';

        while (iss >> token) {
            if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
                int value = stoi(token);
                result = calculate(result, value, operation);
            } else if (variables.find(token) != variables.end()) {
                int value = variables[token];
                result = calculate(result, value, operation);
            } else if (token == "+" || token == "-" || token == "*" || token == "/") {
                operation = token[0];
            } else {
                cerr << "Error: Invalid token in expression \"" << token << "\".\n";
                return 0;
            }
        }

        return result;
    }

    int calculate(int left, int right, char operation) {
        switch (operation) {
            case '+': return left + right;
            case '-': return left - right;
            case '*': return left * right;
            case '/': return right != 0 ? left / right : 0;
            default: return left;
        }
    }

public:
    void execute(const string& line) {
        if (line.rfind("let", 0) == 0) {
            handleLetCommand(line);
        } else if (line.rfind("print", 0) == 0) {
            handlePrintCommand(line);
        } else if (line.rfind("input", 0) == 0) {
            handleInputCommand(line);
        } else {
            cerr << "Error: Unknown command.\n";
        }
    }

    // Method to read a custom file with .mypl extension and execute commands
    void executeFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            // Ignore empty lines and comments (assuming comments start with #)
            if (line.empty() || line[0] == '#') continue;
            execute(line);
        }

        file.close();
    }
};

int main() {
    MiniCompiler compiler;
    string command;

    cout << "Mini Compiler (type 'exit' to quit)\n";
    cout << "You can also load and run a custom script with .mypl extension (e.g., 'run myscript.mypl').\n";
    while (true) {
        cout << "> ";
        getline(cin, command);

        if (command == "exit") break;

        if (command.rfind("run ", 0) == 0) {
            string filename = command.substr(4); // Extract the filename
            compiler.executeFile(filename);
        } else {
            compiler.execute(command);
        }
    }

    return 0;
}
