#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <iomanip>
using namespace std;

void PrintWelcome();
void GetNumberOfStudents(int &numOfStudents);
void PrintMenu();
char GetUserSelection();
void PrintSummary(const vector<string> &students, vector<string> &studentsFirst, vector<string> &studentsLast, const vector<double> &grades);
void AddStudent(vector<string> &students,vector<string> &studentsFirst, vector<string> &studentsLast, vector<double> &grades);
void RemoveStudent(vector<string> &students, vector<double> &grades);
void SortByFirstName(vector<string> &studentsFirst, vector<double> &grades);
void SortByLastName(vector<string> &studentsLast, vector<double> &grades);
void SortByGrade(vector<string> &students, vector<double> &grades);

int main() {
    const char QUIT = 'q';
    const char ADD = 'a';
    const char REMOVE = 'r';
    const char PRINT = 'p';
    const char MENU = 'm';

    string thankYou = "Thank you for entering your students information!\n";
    string notValid = "Not a valid selection.\n";
    char selection;

    int numOfStudents;

    vector<string> students;
    vector<string> studentsFirst;
    vector<string> studentsLast;
    vector<double> grades;

    //Print the Welcome Message
    PrintWelcome();
    //Get Number of Students
    GetNumberOfStudents(numOfStudents);
    //Add the total number of students to the student and grades vectors
    for(int i = 0; i <numOfStudents; i++){
        AddStudent(students, studentsFirst, studentsLast, grades);
    }
    cout << studentsLast[1];
    //Print thank you message
    cout << thankYou;
    //Print the Roster Menu
    PrintMenu();
    //Get the users selection
    selection = GetUserSelection();

    while(selection != QUIT){
        if(selection == ADD){
            AddStudent(students, studentsFirst, studentsLast, grades);
        }
        else if(selection == REMOVE){
            RemoveStudent(students, grades);
        }
        else if(selection == PRINT){
            PrintSummary(students, studentsFirst, studentsLast, grades);
        }
        else if(selection == MENU){
            PrintMenu();
        }
        else if(selection == 'f') {
            SortByFirstName(studentsFirst, grades);
         }
        else if(selection == 'l') {
            SortByLastName(studentsLast, grades);
         }
        else if(selection == 'g') {
            SortByGrade(students, grades);
         }
        else{
            cout << notValid;
        }
        selection = GetUserSelection();
    }



}

void PrintWelcome(){
    string welcome = "Welcome to the student roster!\n";
    cout << welcome;
}

void GetNumberOfStudents(int &numOfStudents){
    string numOfStudentsQuestion = "How many students are in your class?:\n";
    cout << numOfStudentsQuestion;
    cin >> numOfStudents;
}

void PrintMenu(){
    string menu = "Please choose one of the following options:\n"
                  "a: add a student\n"
                  "r: remove a student\n"
                  "p: print the class summary\n"
                  "m: print menu\n"
                  "f: sort - first name\n"
                  "l: sort - last name\n"
                  "g: sort - grade\n"
                  "q: quit program\n";

    cout << menu;
}
char GetUserSelection(){
    string selectionString = "selection:\n";
    char selection;
    cout << selectionString;
    cin >> selection;
    return selection;
}
void PrintSummary(const vector<string> &students, vector<string> &studentsFirst, vector<string> &studentsLast, const vector<double> &grades){
    string summaryHeading = "Class Summary\n"
                            "------------------------\n";
    string nameGradeHeading = "Name                Grade\n"
                              "---------           --------\n";
    string numOfStudentsString = "Number of Students:\n"
                                 "-------------------\n";
    string averageGradeString = "Average Grade:\n"
                                "--------------\n";
    double sum = 0.0;
    double average = 0.0;
    int numOfStudents = students.size();
    cout << endl;
    cout << summaryHeading << nameGradeHeading;
    for(int i = 0; i < students.size(); i++){
        sum += grades.at(i);
        cout << left << setw(20) << studentsFirst.at(i) + " " + studentsLast.at(i) << setprecision(2) << fixed << grades.at(i) << endl;
    }
    cout << numOfStudentsString << numOfStudents << endl;
    cout << averageGradeString << setprecision(2) << fixed << sum/numOfStudents << endl;
    cout << endl;
}
void AddStudent(vector<string> &students, vector<string> &studentsFirst, vector<string> &studentsLast, vector<double> &grades){
    string studentInfo = "Please enter student (First Last Grade) info:\n";
    string firstName, lastName;
    double grade;

    cout << studentInfo;
    cin >> firstName >> lastName >> grade;
    studentsFirst.push_back(firstName);
    studentsLast.push_back(lastName);
    students.push_back(firstName + " " + lastName);
    grades.push_back(grade);
}
void RemoveStudent(vector<string> &students, vector<double> &grades){
    string removeStudent = "Please enter students first and last name";
    string firstName, lastName;

    cout << removeStudent;
    cin >> firstName >> lastName;
    string fullName = firstName + " " + lastName;
    for(int i = 0; i < students.size(); i++){
        if(students.at(i) == fullName) {
            students.erase(students.begin() + i);
            grades.erase(grades.begin() + i);
            cout << "Removing: " << fullName;
        }
    }
}
void SortByFirstName(vector<string> &studentsFirst, vector<double> &grades){
   cout << "Sorting by first name" << endl;
   int i;
   int j;
   int indexSmallest;
   string temp;
   double temp2;
   string temp3; // Temporary variable for swap
   
   for (i = 0; i < studentsFirst.size() - 1; ++i) {
      
      // Find index of smallest remaining element
      indexSmallest = i;
      for (j = i + 1; j < studentsFirst.size(); ++j) {
         
         if ( studentsFirst[j] < studentsFirst[indexSmallest] ) {
            indexSmallest = j;
         }
      }
      
      // Swap numbers[i] and numbers[indexSmallest]
      temp = studentsFirst[i];
      temp2 = grades[i];
      //temp3 = studentsLast[i];
      studentsFirst[i] = studentsFirst[indexSmallest];
      grades[i] = grades[indexSmallest];
      //studentsLast[i] = studentsLast[indexSmallest];
      studentsFirst[indexSmallest] = temp;
      grades[indexSmallest] = temp2;
      //studentsLast[indexSmallest] = temp3;
   }
}

void SortByLastName(vector<string> &studentsLast, vector<double> &grades){
   cout << "Sorting by last name" << endl;
   /*int i;
   int j;
   int indexSmallest;
   string temp;  
   double temp2;
   string temp3; // Temporary variable for swap
   
   for (i = 0; i < studentsLast.size() - 1; ++i) {
      
      // Find index of smallest remaining element
      indexSmallest = i;
      for (j = i + 1; j < studentsLast.size(); ++j) {
         
         if ( studentsLast[j] < studentsLast[indexSmallest] ) {
            indexSmallest = j;
         }
      }
      
      // Swap numbers[i] and numbers[indexSmallest]
      temp = studentsLast[i];
      temp2 = grades[i];
      //temp3 = studentsFirst[i];
      studentsLast[i] = studentsLast[indexSmallest];
      grades[i] = grades[indexSmallest];
      //studentsFirst[i] = studentsFirst[indexSmallest];
      studentsLast[indexSmallest] = temp;
      grades[indexSmallest] = temp2;
      //studentsFirst[indexSmallest] = temp3;
   }
   */
}

void SortByGrade(vector<string> &students, vector<double> &grades){
   cout << "Sorting by grade" << endl;
   int i;
   int j;
   int indexSmallest;
   string temp;
   double temp2; // Temporary variable for swap
   
   for (i = 0; i < students.size() - 1; ++i) {
      
      // Find index of smallest remaining element
      indexSmallest = i;
      for (j = i + 1; j < students.size(); ++j) {
         
         if ( grades[j] < grades[indexSmallest] ) {
            indexSmallest = j;
         }
      }
      
      // Swap numbers[i] and numbers[indexSmallest]
      temp = students[i];
      temp2 = grades[i];
      students[i] = students[indexSmallest];
      grades[i] = grades[indexSmallest];
      students[indexSmallest] = temp;
      grades[indexSmallest] = temp2;
   }
}
