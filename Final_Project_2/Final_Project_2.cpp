#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

struct student
{
    int studentNum = {};

    string name;
    string course;
    string year;
    string ratingMath;
    string ratingScience;
    string ratingProg;

    double gradeMath = {}; 
    double gradeScience = {};
    double gradeProg = {};
    double average = {};
    double gpa = {};

};

void getData(student* stud, int); //get the data of the students
void rating(student* stud, int); // determines if the student passses or fails
void assignGPA(student* stud, int); // assigns the GPA according to FEU Tech Grading System

void displayAll(student* stud, int); // displays all students and their records

int nums;

int main()
{
    string conts;
    int in,stdNum,dispChoice;
    //used pointer to be able to create a dynamic number of students
    student* stud = nullptr;
    start:
    do {
        system("cls");
        cout << "=========================" << endl;
        cout << setw(20) << "GRADE CALCULATOR" << endl;
        cout << "=========================" << endl;

        cout << "1. Add Student Info" << endl << "2. Display Student Info" << endl << "3. Exit" << endl << "Choice: ";
        cin >> in;
        cin.ignore();

        switch (in)
        {
        case 1:
            cout << "=========================" << endl;
            cout << "How many students? ";
            cin >> stdNum;
            cin.ignore();
            cout << "=========================" << endl;
            nums = stdNum + 1;
            //dynamic number of student
            stud = new student[nums];
            getData(stud, nums);
            /*
            rating(stud, nums);
            assignGPA(stud, nums);*/
            break;
        case 2:
            if (stud == nullptr)
            {
                cout << "No Records yet!" << endl;
                break;
            }
            else
            {
                int searchNum;
                cout << "1. Search by Student Number" << endl << "2. Display All" << endl << "Choice: ";
                cin >> dispChoice;
                cin.ignore();
                //lets the user choose if they want to search using student number or just display all   
                if (dispChoice == 1) {
                    cout << "Enter student number: ";
                    cin >> searchNum;
                    cin.ignore();
                    //search for the corresponding student number
                   
                    rating(stud, nums);
                    assignGPA(stud, nums);
                    for (int i = 0; i < nums; i++)
                    {
                        if (searchNum == stud[i].studentNum)
                        {
                            cout << "=================================================" << endl;
                            cout << fixed << setprecision(2) << "Name: " << stud[i].name << endl << "Student Number: " << stud[i].studentNum << endl
                                << "=================================================" << endl
                                << "Course and Year: " << stud[i].course << " " << stud[i].year << endl
                                << "=================================================" << endl
                                << "Math Grade: " << setw(14) << stud[i].gradeMath << " " << setw(13) << "Remarks: " << stud[i].ratingMath << endl
                                << "Science Grade: " << setw(11) << stud[i].gradeScience << " " << setw(13) << "Remarks: " << stud[i].ratingScience << endl
                                << "Programming Grade: " << setw(7) << stud[i].gradeProg << " " << setw(13) << "Remarks: " << stud[i].ratingProg << endl
                                << "=================================================" << endl
                                << "GPA: " << stud[i].gpa << endl << endl;
                        }
                    }
                }
                else if (dispChoice == 2) {
                    
                    rating(stud, nums);
                    assignGPA(stud, nums);
                    displayAll(stud, nums); //function call to display all
                }
                else 
                { 
                    cout << " INAVALID";
                }
            }
            break;
        case 3: 
            //exit program
            exit(1);
            break;
        default:
            //invalid input 
            cout << "INVALID!" << endl;
            system("cls");
            goto start;
            break;
        }
        //asks if you want to continue the program
        cout << "Do you want to continue? ";
        getline(cin, conts);
        //convert input conts to uppercase
        transform(conts.begin(), conts.end(), conts.begin(), ::toupper);

    } while (conts == "YES" || conts == "Y");
}


void getData(student* stud, int nums) { //asks the user to input the data required
    for (int i = 0; i < nums; i++)
    {
        
        cout << "Enter name " << i + 1 << ": ";
        getline(cin, stud[i].name);
        
        cout << "Enter student number: ";
        cin >> stud[i].studentNum;
        cin.ignore();
        cout << "-------------------------" << endl;
        cout << "Enter your course: ";
        getline(cin, stud[i].course);

        cout << "Enter Your Year level: ";
        getline(cin, stud[i].year);
        cout << "-------------------------" << endl;
        entergrade:
        cout << "Enter your grade in math: ";
        cin >> stud[i].gradeMath;
        cin.ignore();

        if(stud[i].gradeMath > 100 || stud[i].gradeMath <0) //check if inputed grade is greater than 100 or less than 0
        {
            goto entergrade;
        }
        entergradeScie:
        cout << "Enter your grade in Science: ";
        cin >> stud[i].gradeScience;
        cin.ignore();

        if (stud[i].gradeScience > 100 || stud[i].gradeScience < 0) //check if inputed grade is greater than 100 or less than 0
        {
            goto entergradeScie;
        }
        entergradeProg:
        cout << "Enter your grade in Programming: ";
        cin >> stud[i].gradeProg;
        cin.ignore();

        if (stud[i].gradeProg > 100 || stud[i].gradeProg < 0) //check if inputed grade is greater than 100 or less than 0
        {
            goto entergradeProg;
        }
        cout << "=========================" << endl;
        
    }
}

void displayAll(student* stud, int nums) //displays all records
{
    for(int i =0; i < nums; i++)
    {
        cout << "=================================================" << endl;
        cout << fixed << setprecision(2) << "Name: " << stud[i].name << endl << "Student Number: " << stud[i].studentNum << endl
            << "=================================================" << endl
            << "Course and Year: " << stud[i].course << " " << stud[i].year << endl
            << "=================================================" << endl
            << "Math Grade: " << setw(14) << stud[i].gradeMath << " " << setw(13) << "Remarks: " << stud[i].ratingMath << endl
            << "Science Grade: " << setw(11) << stud[i].gradeScience << " " << setw(13) << "Remarks: " << stud[i].ratingScience << endl
            << "Programming Grade: " << setw(7) << stud[i].gradeProg << " " << setw(13) << "Remarks: " << stud[i].ratingProg << endl
            << "=================================================" << endl
            << "GPA: " << stud[i].gpa << endl << endl;
    }
    
}

void rating(student* stud, int nums) //assign if grade is passed or failed
{
    for (int i = 0; i < nums; i++)
    {
        if (stud[i].gradeMath >= 70 && stud[i].gradeMath <=100)
        {
            stud[i].ratingMath = "PASS";
        }
        else { stud[i].ratingMath = "FAIL"; }

        if (stud[i].gradeScience >= 70 && stud[i].gradeScience <= 100)
        {
            stud[i].ratingScience = "PASS";
        }
        else { stud[i].ratingScience = "FAIL"; }

        if (stud[i].gradeProg >= 70 && stud[i].gradeProg <= 100)
        {
            stud[i].ratingProg = "PASS";
        }
        else { stud[i].ratingProg = "FAIL"; }
    }
}

void assignGPA(student* stud,int nums) //GPA of student
{
    double gpa=0;
    for (int i = 0; i < nums; i++) {
       
        stud[i].average = (stud[i].gradeMath + stud[i].gradeScience + stud[i].gradeProg) / 3;
        
        if (stud[i].average >= 97 && stud[i].average <=100)
        {
            stud[i].gpa = 4.0;
        }
        else if (stud[i].average >= 93 && stud[i].average <= 96)
        {
            stud[i].gpa = 3.5;
        }
        else if (stud[i].average >= 89 && stud[i].average <= 92)
        {
            stud[i].gpa = 3.0;
        }
        else if (stud[i].average >= 85 && stud[i].average <= 88)
        {
            stud[i].gpa = 2.5;
        }
        else if (stud[i].average >= 80 && stud[i].average <= 84)
        {
            stud[i].gpa = 2.0;
        }
        else if (stud[i].average >= 75 && stud[i].average <= 79)
        {
            stud[i].gpa = 1.5;
        }
        else if(stud[i].average >= 70 && stud[i].average <= 74)
        {
            stud[i].gpa = 1.0;
        }
        else if (stud[i].average >= 0 && stud[i].average <=69 )
        {
            stud[i].gpa = 0.5;
        }
    }
 
}


