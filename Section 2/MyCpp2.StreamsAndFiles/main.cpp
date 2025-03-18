#include <iostream>
#include <limits>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Movie {
    int id;
    string title;
    int year;
};

void readingFromStreams();

void writingToTextFiles();

void readingFromTextFiles();

int main() {
    // readingFromStreams();

    cout << endl;

    // writingToTextFiles();

    cout << endl;

    readingFromTextFiles();
    return 0;
}

void userInput(const string &msg, int &value) {
    while (true) {
        cout << msg;
        cin >> value;
        if (cin.fail()) {
            cout << "Enter a valid number!" << endl;
            // set the stream in a clear state
            cin.clear();
            // remove everything from the buffer
            cin.ignore(numeric_limits<int>::max(), '\n');
        } else break;
    }
}

void readingFromStreams() {
    // Reading from streams

    // Buffer: temporary storage
    // input: [10 20]
    cout << endl << " == Reading from streams == " << endl;

    int first;
    int second;

    userInput("First: ", first);

    cin.ignore(numeric_limits<int>::max(), '\n');

    userInput("Second: ", second);

    cout << "You entered " << first << " and " << second << endl;
}

void writingToTextFiles() {
    cout << endl << " == Writing to text files == " << endl;

    // ofstream: output file stream
    ofstream file;
    // if the file does not exist, it will be created
    // if the file exists, it will be overwritten
    file.open("data.csv");

    if (file.is_open()) {
        // file implements same stream interface
        // as cout, so it can be used in the same way
        // with streams
        // file << setw(20) << "Hello" << setw(20) << "World!" << endl;

        // CSV:
        file << "id,title,year\n"
                << "1,Terminator 1, 1984\n"
                << "1,Terminator 2, 1991\n";

        // release file
        file.close();

        cout << "File written successfully!" << endl;
    }
}

void readingFromTextFiles() {
    // Reading from text files
    cout << endl << " == Reading from text files == " << endl;
    // ifstream: input file stream
    ifstream file;
    file.open("data.csv");

    if (file.is_open()) {
        string str;

        // same problem as with cin
        // stream stops at delimiter like ' ', '\n'
        // file >> str;
        // use getline() instead

        // eof = end of line
        getline(file, str);

        while (!file.eof()) {
            // default delimiter is '\n'

            getline(file, str, ',');
            if (str.empty()) continue;
            Movie movie;
            movie.id = stoi(str);

            getline(file, str, ',');
            movie.title = str;

            getline(file, str);
            movie.year = stoi(str);

            cout << movie.title << endl;
        }

        file.close();
    }
}
