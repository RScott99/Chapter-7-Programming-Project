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

void getAnswers(const string& fileName,vector<char>& array);


int gradeExam(const vector<char>& rightArray, const vector<char>& studentArray, vector<int>& wrongQuestions, vector<vector<char>>& incorrectAnswers);

void writeReport(const vector<int>& wrongQuestions, const vector<vector<char>>& incorrectAnswers, int totalQuestions);


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

    int numMissed = gradeExam(rightArray, studentArray, wrongQuestions, incorrectAnswers);

    writeReport(wrongQuestions, incorrectAnswers, totalQuestions);

    return 0;
}

void getAnswers(const string& fileName, vector<char>& array) {
    std::ifstream file(fileName);

    if (!file) {
        //cause an error and quit
        std::cerr << "Error: couldn't open file " << fileName << "\n";
        exit(1);
    }

    char temp;
    while (file >> temp) {
        array.push_back(temp);
    }

    file.close();
}

int gradeExam(const vector<char>& rightArray, const vector<char>& studentArray, vector<int>& wrongQuestions, vector<vector<char>>& incorrectAnswers) {
    int count = 0;

    for (int i = 0; i < rightArray.size(); ++i) {
        if (rightArray[i] != studentArray[i]) {
            wrongQuestions.push_back(i + 1);
            incorrectAnswers.push_back({ rightArray[i], studentArray[i] });
            ++count;
        }
    }
    return count;
}

void writeReport(const vector<int>& wrongQuestions, const vector<vector<char>>& incorrectAnswers, int totalQuestions) {
    int numMissed = wrongQuestions.size();
    int numCorrect = totalQuestions - numMissed;
    double percentRight = (static_cast<double>(numCorrect) / totalQuestions) * 100.0;

    std::cout << "\nExam Results:\n\n";

    if (numMissed > 0) {
        std::cout << std::left << std::setw(12) << "Question" << std::setw(18) << "Correct Answer" << std::setw(18) << "Student Answer" << '\n';

        std::cout << std::string(48, '-') << '\n';

        for (int i = 0; i < wrongQuestions.size(); ++i) {
            std::cout << std::left << std::setw(12) << wrongQuestions[i] << std::setw(18) << incorrectAnswers[i][0] << std::setw(18) << incorrectAnswers[i][1] << '\n';
        }
    } else {
        std::cout << "All answers were correct!\n";
    }
    std::cout << "\nTotal Missed: " << numMissed << '\n';
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Score: " << percentRight << "%\n";

    if (percentRight >= 70.0) {
        std::cout << "You passed the exam.\n";
    } else {
        std::cout << "You failed the exam.\n";
    }
}