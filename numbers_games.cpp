#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<cmath>
using namespace std;
enum enRigtOrWrong { right = 1, wrong = 2 };
enum enOperationType { add = 1, sub = 2, mult = 3, divi = 4, mixx = 5 };
enum enQuestionsLevel { easy = 1, medium = 2, hard = 3, mix = 4 };
struct stQuestionInfo {
	short questionNumber = 0;
	enRigtOrWrong rightOrWrong;
	string answerRightOrWrong;
};
struct stGameResult {
	short numberOfQuestions = 0;
	short numberOfWriteAnswers = 0;
	short numberOfWrongAnswers = 0;
	enOperationType gameOperationType;
	enQuestionsLevel gameLevel;
};
stGameResult fillGameResult(short numberOfWriteAnswers,
	short numberOfWrongAnswers,
	enOperationType gameOperationType, enQuestionsLevel gameLevel) {
	stGameResult gameResult;

	gameResult.gameLevel = gameLevel;
	gameResult.gameOperationType = gameOperationType;
	gameResult.numberOfWriteAnswers = numberOfWriteAnswers;
	gameResult.numberOfWrongAnswers = numberOfWrongAnswers;

	return gameResult;

}

int generateRandomnumber(int from, int to) {
	int randnum = rand() % (to - from + 1) + from;
	return randnum;
}
short howManyQuestionsYouWant() {
	short howManyQuestions = 0;
	do {
		cout << "How many questions you want ? ";
		cin >> howManyQuestions;
	} while (howManyQuestions < 1);
	return howManyQuestions;
}
enOperationType readOperationType() {
	short numberOfOperationType = 0;
	cout << endl;
	do {
		cout << "Choose operation type [1]:Add , [2]:Sub , [3]:Mult , [4]:Div , [5]:Mix ? ";
		cin >> numberOfOperationType;
	} while (numberOfOperationType < 1 || numberOfOperationType>5);
	return(enOperationType)numberOfOperationType;
}
string nameOfOperationType(enOperationType numberOfOperationType) {
	string arrNameOfOperationType[5] = { "Add","Sub","Mult","Div","Mix" };
	return arrNameOfOperationType[numberOfOperationType - 1];
}
enQuestionsLevel questionLevel() {
	short questionsLevel = 0;
	cout << endl;
	do {
		cout << "Choose questions level [1]:Easy , [2]:Medium , [3]:Hard , [4]:Mix ? ";
		cin >> questionsLevel;
	} while (questionsLevel < 1 || questionsLevel>4);
	return (enQuestionsLevel)questionsLevel;
}
string nameOfQuestionsLevel(enQuestionsLevel numberOfQuestionLevel) {
	string arrQuestionLevel[4] = { "easy","medium","hard","mix" };
	return arrQuestionLevel[numberOfQuestionLevel - 1];
}
void setRightAnswerScreen() {
	system("color 2f");
}
void questionSite(short questionNumber, short howManyQuestions) {
	cout << "Queestion [" << questionNumber << "/" << howManyQuestions << "]" << endl << endl;

}
char shapeOfMark(enOperationType operationType) {
	char arrshape[4] = { '+','-','*','/' };
	return arrshape[operationType - 1];
}
void OperationsProcedure(enOperationType OperationType,
	enQuestionsLevel gameLevel, short& numberOfRightAnswers, short& numberOfWrongAnswers) {
	int number1 = 0;
	int number2 = 0;
	char shape = shapeOfMark(enOperationType(generateRandomnumber(1, 4)));

	int result = 0;
	switch (gameLevel) {
	case enQuestionsLevel::easy:
		number1 = generateRandomnumber(1, 10);
		number2 = generateRandomnumber(1, 10);
		break;
	case enQuestionsLevel::medium:
		number1 = generateRandomnumber(10, 50);
		number2 = generateRandomnumber(10, 50);
		break;
	case enQuestionsLevel::hard:
		number1 = generateRandomnumber(50, 100);
		number2 = generateRandomnumber(50, 100);
		break;
	case enQuestionsLevel::mix:
		number1 = generateRandomnumber(1, 100);
		number2 = generateRandomnumber(1, 100);
		break;

	}

	switch (OperationType) {
	case enOperationType::add:
		cout << number1 << "+" << endl;
		cout << number2 << endl;
		cout << "_____" << endl;
		cin >> result;
		if (result != (number1 + number2)) {
			cout << "Wrong answer :-( " << endl; ;
			cout << "The right answer is : " << number1 + number2 << endl;
			system("color 4f");
			cout << "\a";
			numberOfWrongAnswers++;
		}
		else {
			cout << "Right answer :-)" << endl;
			system("color 2f");
			numberOfRightAnswers++;
		}
		break;
	case enOperationType::sub:
		cout << number1 << "-" << endl;
		cout << number2 << endl;
		cout << "_____" << endl;
		cin >> result;
		if (result != (number1 - number2)) {
			cout << "Wrong answer :-( " << endl; ;
			cout << "The right answer is : " << number1 - number2 << endl;
			system("color 4f");
			cout << "\a";
			numberOfWrongAnswers++;
		}
		else {
			cout << "Right answer :-)" << endl;
			system("color 2f");
			numberOfRightAnswers++;
		}
		break;
	case enOperationType::mult:
		cout << number1 << "*" << endl;
		cout << number2 << endl;
		cout << "_____" << endl;
		cin >> result;
		if (result != (number1 * number2)) {
			cout << "Wrong answer :-( " << endl; ;
			cout << "The right answer is : " << number1 * number2 << endl;
			system("color 4f");
			cout << "\a";
			numberOfWrongAnswers++;
		}
		else {
			cout << "Right answer :-)" << endl;
			system("color 2f");
			numberOfRightAnswers++;
		}
		break;
	case enOperationType::divi:
		cout << number1 << "/" << endl;
		cout << number2 << endl;
		cout << "_____" << endl;
		cin >> result;
		if (result != (number1 / number2)) {
			cout << "Wrong answer :-( " << endl; ;
			cout << "The right answer is : " << number1 / number2 << endl;
			system("color 4f");
			cout << "\a";
			numberOfWrongAnswers++;
		}
		else {
			cout << "Right answer :-)" << endl;
			system("color 2f");
			numberOfRightAnswers++;
		}
		break;
	case enOperationType::mixx:


		switch (shape) {
		case '+':
			cout << number1 << "+" << endl;
			cout << number2 << endl;
			cout << "_____" << endl;
			cin >> result;
			if (result != (number1 + number2)) {
				cout << "Wrong answer :-( " << endl; ;
				cout << "The right answer is : " << number1 + number2 << endl;
				system("color 4f");
				cout << "\a";
				numberOfWrongAnswers++;
			}
			else {
				cout << "Right answer :-)" << endl;
				system("color 2f");
				numberOfRightAnswers++;
			}
			break;
		case '-':
			cout << number1 << "-" << endl;
			cout << number2 << endl;
			cout << "_____" << endl;
			cin >> result;
			if (result != (number1 - number2)) {
				cout << "Wrong answer :-( " << endl; ;
				cout << "The right answer is : " << number1 - number2 << endl;
				system("color 4f");
				cout << "\a";
				numberOfWrongAnswers++;
			}
			else {
				cout << "Right answer :-)" << endl;
				system("color 2f");
				numberOfRightAnswers++;
			}
			break;
		case '*':
			cout << number1 << "*" << endl;
			cout << number2 << endl;
			cout << "_____" << endl;
			cin >> result;
			if (result != (number1 * number2)) {
				cout << "Wrong answer :-( " << endl; ;
				cout << "The right answer is : " << number1 * number2 << endl;
				system("color 4f");
				cout << "\a";
				numberOfWrongAnswers++;
			}
			else {
				cout << "Right answer :-)" << endl;
				system("color 2f");
				numberOfRightAnswers++;
			}
			break;
		case '/':
			cout << number1 << "/" << endl;
			cout << number2 << endl;
			cout << "_____" << endl;
			cin >> result;
			if (result != (number1 / number2)) {
				cout << "Wrong answer :-( " << endl; ;
				cout << "The right answer is : " << number1 / number2 << endl;
				system("color 4f");
				cout << "\a";
				numberOfWrongAnswers++;
			}
			else {
				cout << "Right answer :-)" << endl;
				system("color 2f");
				numberOfRightAnswers++;
			}
			break;


		}


	}
	fillGameResult(numberOfRightAnswers, numberOfWrongAnswers, OperationType, gameLevel);




}
void showGameResult(stGameResult gameresult) {

	cout << "Questions level         : " << nameOfQuestionsLevel(gameresult.gameLevel) << endl;
	cout << "Operation type          : " << nameOfOperationType(gameresult.gameOperationType) << endl;
	cout << "Number of right answers : " << gameresult.numberOfWriteAnswers << endl;
	cout << "Number of wrong answers : " << gameresult.numberOfWrongAnswers << endl;
	cout << "_________________________________" << endl;
}
void resetSystem() {
	system("cls");
	system("color 0f");
}

void play(int howManyQuestions) {

	short numberOfwriteAnswers = 0;
	short numberOfWrongAnswers = 0;
	enQuestionsLevel GameLevel = questionLevel();
	enOperationType operationType = readOperationType();

	for (int questionNumber = 1; questionNumber <= howManyQuestions; questionNumber++) {
		questionSite(questionNumber, howManyQuestions);
		OperationsProcedure(operationType, GameLevel, numberOfwriteAnswers, numberOfWrongAnswers);
	}
	cout << "________________________________" << endl;
	if (numberOfwriteAnswers >= numberOfWrongAnswers) {

		cout << "\nFinal result is PASS :-)" << endl;
		system("color 2f");
	}
	else {
		cout << "\nFinal result is FAIL :-(" << endl;
		system("color 4f");
		cout << "\a";
	}
	cout << "________________________________" << endl;
	cout << "\nNumber of questions     : " << howManyQuestions << endl;;
	showGameResult(fillGameResult(numberOfwriteAnswers, numberOfWrongAnswers, operationType, GameLevel));

}
void startGame() {
	char playAgain = 'Y';
	do {
		resetSystem();
		play(howManyQuestionsYouWant());
		cout << "\n\nDo you want to play again ? Y/N? ";
		cin >> playAgain;
	} while (playAgain == 'Y' || playAgain == 'y');
}



int main() {
	srand((unsigned)time(NULL));


	startGame();

}
