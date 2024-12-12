#include <iostream>
#include <vector>

using namespace std;

void displaySquare(const vector<vector<int>>& square) {
    cout << "-------------" << endl;
    for (size_t i = 0; i < square.size(); ++i) {
        cout << "| ";
        for (size_t j = 0; j < square[i].size(); ++j) {
            cout << square[i][j] << " | ";
        }
        cout << endl;
        if (i != square.size() - 1) {
            cout << "-------------" << endl;
        }
    }
    cout << "-------------" << endl;
}

bool isMagicSquare(const vector<vector<int>>& square) {
    int magicSum = square[0][0] + square[0][1] + square[0][2]; // Calculate the sum of the first row

    // Check rows and columns sums
    for (size_t i = 0; i < 3; ++i) {
        int rowSum = 0, colSum = 0;
        for (size_t j = 0; j < 3; ++j) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if (rowSum != magicSum || colSum != magicSum) {
            return false;
        }
    }

    // Check diagonal sums
    if (square[0][0] + square[1][1] + square[2][2] != magicSum || square[0][2] + square[1][1] + square[2][0] != magicSum) {
        return false;
    }

    return true;
}

int main() {
    bool continuePlaying = true;

    while (continuePlaying) {
        vector<vector<int>> magicSquare(3, vector<int>(3, 0));
        vector<int> numChecker(10, 0); // To check duplicates

        cout << "Creating Lo Shu Square ... " << endl;
        cout << endl;

        cout << "Enter Nine Numbers (1-9)" << endl;
        for (size_t i = 0; i < 3; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                int num;
                cout << "\tNumber " << j + 1 << ": ";
                cin >> num;

                // Validate input
                if (num < 1 || num > 9) {
                    cout << "Invalid input. Please enter a number from 1 to 9." << endl;
                    j--;
                    continue;
                }

                // Check for duplicates
                if (numChecker[num] == 1) {
                    cout << "\tError ... " << num << " is already in the Lo Shu Square. Try again " << endl;
                    cout << endl;
                    j--;
                    continue;
                }

                numChecker[num] = 1;
                magicSquare[i][j] = num;
            }
        }

        displaySquare(magicSquare);

        if (isMagicSquare(magicSquare)) {
            cout << "\nThis is a Lo Shu Magic Square!!!" << endl;
        }
        else {
            cout << "\nThis is not a Lo Shu Magic Square." << endl;
        }

        cout << endl;

        char choice;
        cout << "Would you like to try again? (y/n)? ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            continuePlaying = false;
        }
    }

    return 0;
}
