
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger {
public:
    virtual void write(string msg) = 0;
    virtual ~Logger() {}
};

class ConsoleLogger : public Logger {
public:
    void write(string msg) override {
        cout << "Console: " << msg << endl;
    }
};

class FileLogger : public Logger {
public:
    void write(string msg) override {
        ofstream file("log.txt", ios::app);

        if (file.is_open()) {
            file << msg << endl;
            file.close();
            cout << "Message written to file\n";
        }
    }
};

int main() {
    Logger *log;
    int choice;

    cout << "1. Console Logger\n";
    cout << "2. File Logger\n";
    cout << "Enter choice: ";
    cin >> choice;

    cin.ignore();

    string msg;
    cout << "Enter message: ";
    getline(cin, msg);

    if (choice == 1) {
        log = new ConsoleLogger();
    }
    else if (choice == 2) {
        log = new FileLogger();
    }
    else {
        cout << "Invalid choice\n";
        return 0;
    }

    log->write(msg);

    delete log;

    return 0;
}
