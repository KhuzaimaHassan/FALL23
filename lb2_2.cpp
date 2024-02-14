#include <iostream>
#include <vector>

using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    int birthYear;
    int birthMonth;
    int birthDate;

public:
    Person(string firstName, string lastName, int birthYear, int birthMonth, int birthDate) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->birthYear = birthYear;
        this->birthMonth = birthMonth;
        this->birthDate = birthDate;
    }

    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    int getBirthYear() const {
        return birthYear;
    }

    int getBirthMonth() const {
        return birthMonth;
    }

    int getBirthDate() const {
        return birthDate;
    }

    void print() const {
        cout << "\nFirst Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Birth Year: " << birthYear << endl;
        cout << "Birth Month: " << birthMonth << endl;
        cout << "Birth Date: " << birthDate << endl;
    }
};

void selectionSort(vector<Person>& persons) {
    int n = persons.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (persons[j].getBirthYear() < persons[minIndex].getBirthYear()) {
                minIndex = j;
            } else if (persons[j].getBirthYear() == persons[minIndex].getBirthYear()) {
                if (persons[j].getBirthMonth() < persons[minIndex].getBirthMonth()) {
                    minIndex = j;
                } else if (persons[j].getBirthMonth() == persons[minIndex].getBirthMonth()) {
                    if (persons[j].getBirthDate() < persons[minIndex].getBirthDate()) {
                        minIndex = j;
                    }
                }
            }
        }

        swap(persons[i], persons[minIndex]);
    }
}

int main() {
    int n; // Number of persons
     cout<<"Enter the number of Persons: ";
    cin >> n;
    vector<Person> persons;
    for (int i = 0; i < n; i++) {
        string firstName, lastName;
        int birthYear, birthMonth, birthDate;
        cout<<" \nPERSON NUMBER "<<i+1<<"\n";
        cout<<"Enter first name: ";
        cin >> firstName;
         cout<<"Enter last name: ";
        cin>> lastName;
        cout<<"Enter Birth year: ";
         cin>> birthYear;
         cout<<"Enter Birth month: ";
         cin>> birthMonth;
         cout<<"Enter Birth date: ";
         cin>> birthDate;
      Person person(firstName, lastName, birthYear, birthMonth, birthDate);
        persons.push_back(person);
    }

    selectionSort(persons);

    for (Person person : persons) {
        person.print();
        cout << endl;
    }

    return 0;
}
