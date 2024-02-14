#include <iostream>;
#include <string>;
#include <vector>;
struct Student
{
std::string name;
std::vector<double>grades;
};
// Function to calculate CGPA for a student
double calculateCGPA(const Student& student) {
double totalPoints = 0.0;
int totalCourses = 0;
for (const double& grade : student.grades) {
if (grade != -1) { // Exclude missing courses
totalPoints += grade;
totalCourses++;
}
}
return (totalCourses > 0) ? (totalPoints / totalCourses) : 0.0;
}
int main() {
// Define the courses and credit hours
const int numCourses = 5;
const double creditHours = 3.0;
// Create student records
std::vector<Student> students = {
{"Ali", {3.66, 3.33, 4.0, 3.0, 2.66}},
{"Hiba", {3.33, 3.0, 3.66, 3.0, -1}},
{"Asma", {4.0, 3.66, 2.66, -1, -1}},
{"Zain", {2.66, 2.33, 4.0, -1, -1}},
{"Faisal", {3.33, 3.66, 4.0, 3.0, 3.33}}

};
// Calculate and display CGPA for each student
for (const Student & student : students) {
double cgpa = calculateCGPA(student);
std::cout << student.name << "s CGPA:" << (cgpa * creditHours) << std::endl;
}
return 0;
}
