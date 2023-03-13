#include <iostream>
#include <iomanip>
#include <string>

/*
1. dynamic array +1 DONE
2. add student info DONE
 -name,std#, course& year, 3 subjects math, science ,programming DONE
3. view student info
 - search using std# DONE
 - display all DONE
display if failed or pass DONE
 gpa converted to feu grading system DONE
 97-100 = 4.0
 93-96 = 3.5
 89-93 = 3.0
 85 - 88 = 2.5
 80 - 84 = 2.0
 75-79 = 1.5
 70-75 = 1.0
 < 70 = 0.5 Failed
 */

using namespace std;


struct student
{
    string name;
    int studentNum = {};
    string course;
    string year;

    double gradeMath = {};
    double gradeScience = {};
    double gradeProg = {};

    string ratingMath;
    string ratingScience;
    string ratingProg;
};

void getData(student* stud, int);
void rating(student* stud, int);
int main();

student getData(student);
int main()
{
    int in,stdNum,nums,dispChoice;

    cout << "=========================" << endl;
    cout << setw(20) << "GRADE CALCULATOR" << endl;
    cout << "=========================" << endl;

    student* stud = nullptr;


    cout << "1. Add Student Info" << endl << "2. Display Student Info" << endl <<"3. Exit" <<endl<< "Choice: ";
    cin >> in; 
    cin.ignore();

    switch (in)
    {
    case 1:
        
        cout << "How many students? ";
        cin >> stdNum;
        cin.ignore(); 
        nums = stdNum + 1;
        stud = new student[nums];
        
        getData(stud, nums);
        rating(stud, nums);

        break;
    case 2:

        cout << "1. Search by Student Number" << endl << "2. Display All" << endl << "Choice: ";
        cin >> dispChoice; 
        cin.ignore();

        cout << stud[0].gradeMath << " " << stud[0].ratingMath;

        break;
    default:
        break;
    }
    
}


void getData(student* stud, int nums) {
    for (int i = 0; i < nums; i++)
    {
        cout << "Enter name " << i + 1 << ": ";
        getline(cin, stud[i].name);
        
        cout << "Enter student number: ";
        cin >> stud[i].studentNum;
        cin.ignore();

        cout << "Enter your course: ";
        getline(cin, stud[i].course);

        cout << "Enter Your Year level: ";
        getline(cin, stud[i].year);

        cout << "Enter your grade in math: ";
        cin >> stud[i].gradeMath;
        cin.ignore();

        cout << "Enter your grade in Science: ";
        cin >> stud[i].gradeScience;
        cin.ignore();

        cout << "Enter your grade in Programming: ";
        cin >> stud[i].gradeProg;
        cin.ignore();
    }
}

void rating(student* stud, int nums)
{
    for (int i = 0; i < nums; i++)
    {
        if (stud[i].gradeMath >= 70)
        {
            stud[i].ratingMath = "PASS";
        }
        else { stud[i].ratingMath = "FAIL"; }

        if (stud[i].gradeScience >= 70)
        {
            stud[i].ratingScience = "PASS";
        }
        else { stud[i].ratingScience = "FAIL"; }

        if (stud[i].gradeProg >= 70)
        {
            stud[i].ratingProg = "PASS";
        }
        else { stud[i].ratingProg = "FAIL"; }
    }
}
