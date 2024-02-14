#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Prompt the user to input the number of students
    int num_students;
    cout << "Enter the number of students: ";
    cin >> num_students;

    // Create a jagged array to store names
    vector<vector<string>> students(1);

    // Populate the jagged array with user-defined names
    for (int i = 0; i < num_students; ++i) {
        string name;
        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> name;
        students[0].push_back(name);
    }

    // Prompt the user for the name to search
    string search_name;
    cout << "Enter the name to search: ";
    cin >> search_name;

    // Perform the search
    bool found = false;
    for (const auto &name : students[0]) {
        if (name == search_name) {
            found = true;
            break;
        }
    }

    // Display the result of the search
    if (found) {
        cout << search_name << " has submitted the contribution." << endl;
    } else {
        cout << search_name << " has not submitted the contribution." << endl;
    }

    return 0;
}

