//This program will grade final exams that have 20 multiple choice questions each with 4 possible answers
//will grade and output their answer, and the expected answer, along with a final score and if they passed or not.
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;




//defining prototypes

void getAnswers(const string answersFileName,vector<char> &rightArray);


int gradeExam(const vector<char>& rightArray, const vector<char>& studentArray, vector<int>& incorrectQuestions, vector<vector<char>>& incorrectAnswers);

void writeReport(const vector<int>& incorrectQuestions, const vector<vector<char>>& incorrectAnswers, int totalQuestions);


int main()
{
    const int totalQuestions = 20;
    std::vector<char> rightArray;
    std::vector<char> studentArray;
    std::vector<int> wrongQuestions;
    std::vector<vector<char>> incorrectAnswers;

    std::string answerKeyName;
    std::string studentAnswersName;

    std::cout << "Enter the full file name of the answer key: ";
    getline(cin, answerKeyName);
    getAnswers(answerKeyName, rightArray);

    std::cout << "\nEnter the full name of the student answers file: ";
    getline(cin, studentAnswersName);
    getAnswers(studentAnswersName, studentArray);






 
    return 0;
}

