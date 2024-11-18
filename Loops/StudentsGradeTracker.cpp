#include <iostream>
using namespace std;

int main()
{
    int numOfStudents, numOfSubjects;
    double classTotalGrade, classAverage;

    cout << "-----------------------\n";
    cout << "Students Grades Tracker\n";
    cout << "-----------------------\n";
    cout << "Enter the number of Students: ";
    cin >> numOfStudents;
    cout << "Enter the number of Subjects: ";
    cin >> numOfSubjects;

    for (int currStudent = 1; currStudent <= numOfStudents; currStudent++)
    {
        // Loop for iterating over each student
        double currStudentAverage = 0;
        double currStudentTotal = 0;

        cout << "\nEntering Student " << currStudent << " grades:\n";
        for (int currSubject = 1; currSubject <= numOfSubjects; currSubject++)
        {
            // Loop for iterating over current student's subjects
            double currSubjectGrade;
            cout << "Enter the grade for Subject " << currSubject << ": ";
            cin >> currSubjectGrade;
            currStudentTotal += currSubjectGrade;
        }

        currStudentAverage = currStudentTotal / numOfSubjects;
        classTotalGrade += currStudentAverage;
        cout << "Average Grade for Student " << currStudent << " is: " << currStudentAverage << endl;
    }

    classAverage = classTotalGrade / numOfStudents;
    cout << "\nOverall class average is: " << classAverage << endl;

    return 0;
}
