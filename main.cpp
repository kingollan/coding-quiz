//
//  main.cpp
//  Coding Quiz
//
//  Created by Oliver Berglund on 2023-12-09.
//

#include <iostream>
#include <string>
#include <fstream>

int guess{};
int total{};
std::string highScore{};
int looper{1};

bool startCheck;

class Question{
private:
    std::string Question_Text;
    std::string Answer_1;
    std::string Answer_2;
    std::string Answer_3;
    std::string Answer_4;
    int Correct_Answer;
    int Question_Score;
    
public:
// Function for setting value
    void setValues(std::string, std::string,
                       std::string, std::string,
                       std::string, int, int);
    
// Function to ask questions
    void askQuestion();
};

void Question::setValues(
    std::string q, std::string a1,
    std::string a2, std::string a3,
    std::string a4, int ca, int pa)
{
    Question_Text = q;
    Answer_1 = a1;
    Answer_2 = a2;
    Answer_3 = a3;
    Answer_4 = a4;
    Correct_Answer = ca;
    Question_Score = pa;
}

void Question::askQuestion()
{
    std::cout << std::endl;
 
    // Print the questions
    std::cout << Question_Text << std::endl;
    std::cout << "1. " << Answer_1 << std::endl;
    std::cout << "2. " << Answer_2 << std::endl;
    std::cout << "3. " << Answer_3 << std::endl;
    std::cout << "4. " << Answer_4 << std::endl;
    std::cout << std::endl;
 
    // Display the answer
    std::cout << "What is your answer?(in number)"
         << std::endl;
    std::cin >> guess;
 
    // If the answer is correct
    if (guess == Correct_Answer) {
        std::cout << std::endl;
        std::cout << "Correct !" << std::endl;
 
        // Update the correct score
        total += Question_Score;
        std::cout << "Score + " << Question_Score
             << "!" << std::endl;
        std::cout << std::endl;
    }
 
    // Otherwise
    else {
        std::cout << std::endl;
        std::cout << "Wrong!" << std::endl;
        std::cout << "Correct answer = "
             << Correct_Answer
             << "." << std::endl;
        std::cout << std::endl;
    }
}

void startGame(){
    Question q1;
    Question q2;
    Question q3;

    
    // Set the values of the object
    /*
     q1.setValues("Question : ", 
                "Answer 1",
                "Answer 2", 
                "Answer 3",
                "Answer 4",
                Correct Answer,
                Points for correct answer
                );
     */
    
    q1.setValues(
                 "Vad är en integer?\n",
                 "1. Bokstav\n",
                 "2. Heltal\n",
                 "3. Decimal\n",
                 "4. Programmeringsspråk\n",
                 2, 1);
    
    q2.setValues(
                 "Vad gör ++ operatören?\n",
                 "1. Ökar men 1\n",
                 "2. Miskar med 1\n",
                 "3. Delar på 2\n",
                 "4. Multiplicerar på 2\n",
                 1, 1);
    
    q3.setValues(
                 "Vilken av följande är inte en grundläggande data typ\n",
                 "1. int\n",
                 "2. float\n",
                 "3. char\n",
                 "4. string\n",
                 4, 1);
    
    // Asks the questions
    q1.askQuestion();
    q2.askQuestion();
    q3.askQuestion();
}

std::string quoteOfTheDay(){
    // Lista med strings, glöm inte öka minnet på listan om ord ska läggas till
    // Ska uppdateras senare för automatisering
    const char* quotes[6]{
        "Let's beat the highscore\n",
        "HEY HOW YOU DOING?\n",
        "Hello there...\n",
        "Work in silence.\n",
        "8008135\n",
        "Another day, another dollar..\n"};
    return quotes[rand() % 6 + 1];
}

void mainMenu(){
    std::cout << "Welcome Player 1. | Highscore: " << highScore << "\n";
    std::cout << quoteOfTheDay();
    std::cout << "1. Start Game \n";
    std::cout << "0. Exit    \n";
    int selection{};
    std::cin >> selection;
    // Initialize a oblect of the Question class
    if(selection == 1){
        startCheck = true;
    }
    else if(selection == 0){
        looper = 0;
        startCheck = false;
        return;
    }
    else{
        startCheck = false;
    }
}

void showScore(){
    char tryAgain{};
    std::cout << "Great job, let's see how you did.\n";
    std::cout << "Your score is: " << total << std::endl;
    std::cout << std::endl;
    int hsInt = stoi(highScore);
    if(hsInt < total){
        highScore = std::to_string(total);
    }
    
    std::cout << "Would you like to try again? Y/N: ";
    std::cin >> tryAgain;
    std::cout << std::endl;
    
    total = 0;
    
    if(tryAgain == 'Y' || tryAgain == 'y'){
        return;
    }
    else if (tryAgain == 'N' || tryAgain == 'n'){
        looper = 0;
    }
    else{
        return;
    }
    
    
}
    
void saveHighScore(){
    std::ofstream writeFile("./highscore.txt");
    writeFile << highScore << std::endl;
    writeFile.close();
}

std::string loadHighScore(){
    std::ifstream readFile("./highscore.txt");
    std::string hS{};
    while (getline (readFile, hS)) {
        break;
    }
    readFile.close();
    return hS;
}
    
int main(){
    highScore = loadHighScore();
    while (looper == 1){
        mainMenu();
        if (startCheck == true){
            startGame();
            showScore();
            saveHighScore();
        }
    }
    return 0;
}
