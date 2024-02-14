#include <iostream>
using namespace std;

class Student
{

protected:
  string Studentname;
  int Roll_no;
  int CGPA;

public:
  string getStudentname()
  {
    return Studentname;
  }
  int getRoll_no()
  {
    return Roll_no;
  }
  float getCGPA()
  {
    return CGPA;
  }
  void SetStudentname(string Studentname)
  {
    this->Studentname = Studentname;
  }
  void SetRoll_no(int Roll_no)
  {
    this->Roll_no = Roll_no;
  }
  void SetCGPA(float CGPA)
  {
    this->CGPA = CGPA;
  }
};
// SINGLE INHERITANCE
class Data : public Student
{
public:
  int marks;
};
// MULTILEVEL INHERITANCE
class Teacher : public Student
{
public:
  string name;
  string qualifications;

public:
  void setname(string name)
  {
    this->name = name;
  }
  void setqualification(string qualifications)
  {
    this->qualifications = qualifications;
  }
  string getname()
  {
    return name;
  }
  string getqualifications()
  {
    return qualifications;
  }
};
// MULTIPLE INHERITANCE
class Hybrid : public Data, public Student
{
};

int main()
{
  Teacher One;
  // Student One;
  One.SetStudentname("KHUZAIMA");
  // One.Studentname="Hassan";

  One.SetRoll_no(302);
  One.SetCGPA(3.825);
  cout << "Student Name: " << One.getStudentname() << endl;
  cout << "Roll NO : " << One.getRoll_no() << endl;
  cout << "CGPA : " << One.getCGPA() << endl;
  cout << sizeof(Student);

  // MULTILEVEL INHERITANCE
  /*Hybrid two ;

  two.setqualification
  cout<<two.
  */
  return 0;
}