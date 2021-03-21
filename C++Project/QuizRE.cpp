#include <iostream>
#include<fstream>
#include <string>
#include <Windows.h>
using namespace std;

int count = 0, wrong = 0;
int ncount = 0, ccount = 0, oxcount = 0;
int nwrong = 0, cwrong = 0, oxwrong = 0;

class MainScreen
{
private:
	string name, answer = "";
	int choice = 0, num = 0;
	int	Quiznum[30];
public:
	void start() {
		cout << "이름을 입력하세요 : ";
		cin >> name;
		cout << "\n안녕하세요, " << name << "님!" << endl;
		cout << "퀴즈 나라에 오신걸 환영합니다!" << endl;
		ShowChoice();
	}
	void result() {
		ofstream out(name + ".txt");
		
		cout << "\n넌센스 퀴즈에서는 " << ::ncount << "개, \n";
		out << "넌센스 퀴즈에서는 " << ::ncount << "개," << endl;

		cout << "\n상식 퀴즈에서는 " << ::ccount << "개, \n";
		out << "\n상식 퀴즈에서는 " << ::ccount << "개, " << endl;

		cout << "\nOX 퀴즈에서는 " << ::oxcount << "개로, \n";
		out << "\nOX 퀴즈에서는 " << ::oxcount << "개로,\n" << endl;

		::count = ::ncount + ::ccount + ::oxcount;

		cout << name << "님 께서 지금까지 맞추신 총 퀴즈의 개수는 " << ::count << "개이며,\n\n";
		out << name << "님 께서 지금까지 맞추신 총 퀴즈의 개수는 " << ::count << "개이며,\n\n" << endl;


		cout << "\n넌센스 퀴즈에서는 " << ::nwrong << "개, \n\n";
		out << "넌센스 퀴즈에서는 " << ::nwrong << "개," << endl;

		cout << "\n상식 퀴즈에서는 " << ::cwrong << "개, \n\n";
		out << "\n상식 퀴즈에서는 " << ::cwrong << "개, " << endl;

		cout << "\nOX 퀴즈에서는 " << ::oxwrong << "개로, \n\n";
		out << "\nOX 퀴즈에서는 " << ::oxwrong << "개로, \n" << endl;

		::wrong = ::nwrong + ::cwrong + ::oxwrong;

		cout << name << "님 께서 지금까지 틀리신 총 퀴즈의 개수는 " << ::wrong << "개 입니다.\n";
		out << name << "님 께서 지금까지 틀리신 총 퀴즈의 개수는 " << ::wrong << "개 입니다." << endl;

		out.close();
	}
	void ShowChoice()
	{
		cout << "		 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		cout << "		|		|		 |		 |" << endl;
		cout << "		|	①	|	②	 |	 ③	 |" << endl;
		cout << "		|		|		 |		 |" << endl;
		cout << "		|     넌센스	|      상식 	 |     O or X	 |" << endl;
		for (int i = 1; i <= 3; i++) {
			cout << "		|		|		 |		 |" << endl;
		}
		cout << "		 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n" << endl;

		cout << "원하시는 퀴즈 번호를 선택해주세요 : " << endl;
		cout << "프로그램 종료를 원하신다면 숫자 '0'을 입력해주세요." << endl;
		cin >> choice;
		Choice(choice);
	}
	void Choice(int choice)
	{
		this->choice = choice;
		if (this->choice == 1) {
			cout << "\n넌센스를 선택하셨습니다!" << endl;
			cout << "곧이어 퀴즈가 시작 됩니다!" << endl;
			Sleep(1000);

			for (int i = 3; i >= 1; i--) {
				cout << i << endl;
				Sleep(1000);
			}

			system("cls");
			cout << "넌센스 퀴즈에 오신걸 환영합니다!" << endl;
			Quiz_choice();
		}
		else if (this->choice == 2) {
			cout << "\n상식을 선택하셨습니다!" << endl;
			cout << "곧이어 퀴즈가 시작 됩니다!" << endl;
			Sleep(1000);

			for (int i = 3; i >= 1; i--) {
				cout << i << endl;
				Sleep(1000);
			}

			system("cls");
			cout << "상식 퀴즈에 오신걸 환영합니다!" << endl;
			Quiz_choice();
		}
		else if (this->choice == 3) {
			cout << "\nOX를 선택하셨습니다!" << endl;
			cout << "곧이어 퀴즈가 시작 됩니다!" << endl;
			Sleep(1000);

			for (int i = 3; i >= 1; i--) {
				cout << i << endl;
				Sleep(1000);
			}

			system("cls");
			cout << "OX 퀴즈에 오신걸 환영합니다!" << endl;
			Quiz_choice();
		}
		else if (this->choice == 0) {
			system("cls");
			cout << "\n퀴즈를 종료 합니다.\n" << endl;

			for (int i = 3; i >= 1; i--) {
				cout << i << endl;
				Sleep(1000);
			}

			HWND hWndConsole = GetConsoleWindow();
			ShowWindow(hWndConsole, SW_HIDE);
		}
	}
	void Quiz_choice() {
		cout << "퀴즈를 종료하고 싶으시다면 숫자'0'을, \n문제를 패스하고 싶으시다면 '패스' 또는 'pass'를 입력해 주세요. \n" << endl;
		cout << "다른 종류의 퀴즈를 풀고 싶으시다면 '100'을 입력해 주세요.\n\n" << endl;
		cout << "퀴즈 번호를 선택해 주세요!(최대 30)" << endl;
		if (Quiznum[num] <= 30) {
			for (int i = 1; i <= 29; i++) {
				if (choice == 1) {
					cin >> Quiznum[num];

					if (Quiznum[num] == 0) {
						system("cls");
						result();
						cout << "\n퀴즈를 종료 합니다.\n" << endl;
						Sleep(4500);
						HWND hWndConsole = GetConsoleWindow();
						ShowWindow(hWndConsole, SW_HIDE);
					}
					N_Quiz();
				}
				if (choice == 2) {
					cin >> Quiznum[num];

					if (Quiznum[num] == 0) {
						system("cls");
						result();
						cout << "\n퀴즈를 종료 합니다.\n" << endl;
						Sleep(4500);
						HWND hWndConsole = GetConsoleWindow();
						ShowWindow(hWndConsole, SW_HIDE);
					}
					C_Quiz();
				}
				if (choice == 3) {
					cin >> Quiznum[num];

					if (Quiznum[num] == 0) {
						system("cls");
						result();
						cout << "\n퀴즈를 종료 합니다.\n" << endl;
						Sleep(4500);
						HWND hWndConsole = GetConsoleWindow();
						ShowWindow(hWndConsole, SW_HIDE);
					}
					OX_Quiz();
				}
				num = i;
				if (num == 29) {
					ShowChoice();
				}
			}
		}
		else {
			cout << "잘못 입력하셨습니다. 다시 입력해 주세요";
			Quiz_choice();
		}
	}
	void N_Quiz() {
		switch (Quiznum[num])
		{
		case 1:
			cout << "\nQ1. 세상에서 가장 쉬운 숫자는? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "십구만" || answer == "190,000" || answer == "190000") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;

				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '십구만(190,000)'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 2:
			cout << "\nQ2. 돌잔치를 영어로 하면? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "락페스티벌" || answer == "rockfestival") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;

				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);

				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '락페스티벌'이었습니다!";
				Sleep(1000);
				nwrong++;
				system("cls");
				Quiz_choice();
			}
			break;
		case 3:
			cout << "\nQ3. 날마다 흑심을 품고 다니는 것은? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "연필") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '연필'이었습니다!";
				Sleep(1000);
				nwrong++;
				system("cls");
				Quiz_choice();
			}
			break;
		case 4:
			cout << "\nQ4. 학생들이 싫어하는 피자는? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "책피자") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '책피자'였습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 5:
			cout << "\nQ5. 곰이 다니는 목욕탕 이름은? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "곰탕") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '곰탕'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 6:
			cout << "\nQ6. 병균들 가운데 가장 높은 균은? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "대장균") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '대장균'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 7:
			cout << "\nQ7. 오래될 수록 젊어보이는 것은? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "사진") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '사진'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 8:
			cout << "\nQ8. 형이 셋, 동생이 셋이면 몇 형제 일까? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "4형제") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '4형제'였습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 9:
			cout << "\nQ9. 소금장수가 가장 반기는 사람은? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "싱거운 사람" || answer == "싱거운사람") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '싱거운 사람'이였습니다!";
				nwrong++;
				Sleep(1000);
				for (int i = 3; i >= 1; i--) {
					cout << i << endl;
					Sleep(1000);
				}
				system("cls");
			}
			break;
		case 10:
			cout << "\nQ10. 사람들을 벌떡 일으켜 세우는 숫자는? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "다섯" || answer == "5") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '다섯(5)'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 11:
			cout << "\nQ11. 별 중에 가장 슬픈 별은? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "이별") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '이별'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 12:
			cout << "\nQ12. 진짜 새의 이름을 무엇일까? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "참새") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '참새'였습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 13:
			cout << "\nQ13. 사람의 몸무게가 가장 많이 나갈 때는? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "철들 때" || answer == "철들때") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '철들 때'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 14:
			cout << "\nQ14. 세상에서 가장 뜨거운 바다는? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "열바다") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '열바다(열받아)'였습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 15:
			cout << "\nQ15. 세상에서 가장 추운 바다는? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "썰렁해") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '썰렁해'였습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 16:
			cout << "\nQ16. '개가 사람을 가르친다'를 4글자로 줄인다면? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "개인지도") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '개인지도'였습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 17:
			cout << "\nQ17. 딩동댕의 반대는? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "땡") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '땡'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 18:
			cout << "\nQ18. 물중에서 가장 사람들이 좋아하는 물은? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "선물") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(1000);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '선물'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 19:
			cout << "\nQ19. 여름마다 일어나는 전쟁은? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "더워" || answer == "TheWar" || answer == "The war") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '더워(The war)'였습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 20:
			cout << "\nQ20. 아마존에 살고 있는 사람 이름은? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "아마,존?" || answer == "아마,존" || answer == "존") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '존(아마,존)'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 21:
			cout << "\nQ21. 우유가 넘어지면서 하는 말은? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "아야") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '아야'였습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 22:
			cout << "\nQ22. 목수도 못 고치는 집은? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "고집") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '고집'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 23:
			cout << "\nQ23. 세사람만 탈 수 있는 차는? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "인삼차") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '인삼차'였습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 24:
			cout << "\nQ24. 병아리가 좋아하는 약은? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "삐약") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '삐약'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 25:
			cout << "\nQ25. 혼자만 갈 수 있는 나라는? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "꿈나라") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '꿈나라'였습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 26:
			cout << "\nQ26. 신이 화가나면? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "신발끈" || answer == "신 발끈") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '신발끈'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 27:
			cout << "\nQ27. 눈이 녹으면 무엇이 될까? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "봄") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '봄'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 28:
			cout << "\nQ28. 손님이 뜸하면 돈 버는 사람은? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "한의사" || answer == "한 의사") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '한의사'였습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 29:
			cout << "\nQ29. 정말 어렵게 지은 절 이름은? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "우열곡절" || answer == "우열곡" || answer == "우열곡 절") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '우열곡절'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 30:
			cout << "\nQ30. 구명보트에는 몇명까지 탈 수 있을까? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "구명" || answer == "9" || answer == "아홉명" || answer == "9명") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '구(9)명'이었습니다!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		}
	}
	void C_Quiz() {
		switch (Quiznum[num])
		{
		case 1:
			cout << "Q.다음에서 숫자의 합은 모두 얼마일까요?, \n부산의 시외전화번호 + \n2001년 부산 국제 영화제의 개최 회수 + \n현재 통용되는 우리나라 동전의 종류? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "63") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '63'이었습니다! 부산의 시외전화번호= 051, 부산의 국제 영화제 회수 = 6회, 현재 통용되는 동전의 개수 = 6개";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 2:
			cout << "Q. 다음 속담에 공통으로 들어가는 '이것'은 무엇일까요?";
			cout << "\n'이것'도 자기 일 하는 날은 열 번 재주를 넘는다.";
			cout << "\n'이것' 이 지붕에서 떨어지는 것은 매미 될 셈이 있어 떨어진다.";
			cout << "\n'이것'도 구르는 재주가 있다.\n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "굼벵이") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);

				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '굼벵이'였습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 3:
			cout << "Q. 이것은 맹자의 어머니가 맹자의 교육을 위해 세 번 이사 한 것에서 유래한 고사성어입니다.";
			cout << "생활환경이 교육에 미치는 영향이 매우 크며, 중요한 구실을 한다는 것을 이르는 말입니다. ";
			cout << "이 넉자의 한자성어는 무엇일까요?\n\n" << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "삼천지교" || answer == "맹모삼천지교") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '맹모삼천지교(삼천지교)'였습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 4:
			cout << "Q. 수공업에 종사하던 사람으로 농기구, 놋그릇, 도자기 등을 만드는 사람을 일컫는 말이었으나";
			cout << "현재에는 공을 들여 물건을 만들고, 예술가가 심혈을 기울여 창작한다는 뜻에서 창작예술가를 일컫는 말이 되었습니다.";
			cout << "이런 사람들을 무엇이라고 할까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "장인") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '장인'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 5:
			cout << "\nQ5. 컴퓨터의 표준키보드에는 F1부터 F12까지의 키가 있습니다. 여기서 F는 무엇의 약자일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "Function" || answer == "function") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 'Function'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 6:
			cout << "\nQ6. 영화나 연극, 추리소설 등에서 사건해결의 실마리가 풀리지 않고 독자를 조마조마하게 하는 긴장감의 효과를 말합니다.\n";
			cout << "연극이나 영화에서는 관객의 불안감을 고조 시켜 반전의 결말까지 지루하지 않고, 극적인 재미를 더하기 위한 수법으로 사용됩니다.\n";
			cout << "이것을 무엇이라고 할까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "서스펜스") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '서스펜스'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 7:
			cout << "\nQ7. 국가권력의 작용을 입법 · 행정 · 사법의 셋으로 나누어,";
			cout << "\n국가의 남용을 방지하는 통치조직원리인 이것은 무엇일까요 ? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "삼권 분립" || answer == "삼권분립") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '삼권 분립'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 8:
			cout << "\nQ8. 미국 캘리포니아주 남서부 애너하임에 위치해 있는 세계적인 유원지이자, 대규모의 오락시설인 이곳은 어디일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "디즈니랜드" || answer == "디즈니 랜드") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '디즈니랜드'였습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 9:
			cout << "\nQ9. 타인의 기대나 관심으로 인하여 능률이 오르거나 결과가 좋아지는 현상인 이 효과는 무엇일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "피그 말리온 효과" || answer == "피그 말리온") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '피그 말리온 효과'였습니다!";
				cwrong++;
				Sleep(1000);
				for (int i = 3; i >= 1; i--) {
					cout << i << endl;
					Sleep(1000);
				}
				system("cls");
			}
			break;
		case 10:
			cout << "\nQ10. 흉측한 얼굴을 가면으로 가린 괴신사가 아름다운 프리마돈나를 짝사랑하는 내용이 담긴 이 뮤지컬의 이름은 무엇일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "오페라의 유령") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '오페라의 유령'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 11:
			cout << "\nQ11. 용액의 산성, 염기성을 판단하는데 쓰이는 '종이의 이름'으로 산성은 붉은색, 염기성은 푸른색을 띠운다 이 종이의 이름은? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "리트머스" || answer == "리트머스 종이") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '리트머스 종이'였습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 12:
			cout << "\nQ12. 빈모강에 속하는 환형동물의 총칭으로 철학자 아리스토텔레스는 이것을 '지구의 창자'라고 했습니다 이것은 무엇일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "지렁이") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '지렁이'였습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 13:
			cout << "\nQ13. 전설에 나오는 신령스러운 새이며 죽음과 부활을 반복하여 불사조라고도 불리는 이것은 무엇일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "피닉스" || answer == "주작") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '피닉스(주작)'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 14:
			cout << "\nQ14. 주위에 사람들이 많을 수 록 어려움에 처한 사람을 돕지 않게 되는 현상을 뜻하는 이 심리학 용어는 무엇일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "방관자 효과" || answer == "방관자") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '방관자 효과'였습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 15:
			cout << "\nQ15. 레오나르도 다빈치가 그린 '최후의 만찬'에서 예수를 포함하여 나오는 인물은 총 몇명일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "13명" || answer == "13") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '13명 (12명 + 예수 1명)'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 16:
			cout << "\nQ16. 손오공이 화과산 수렴동에 있을 때 의형제를 맺었던 요괴로, 혼철곤이라는 무기를 사용하는 이 인물은 누구일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "우마왕" || answer == "평천대성" || answer == "대력마왕") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '우마왕 (평천대성 혹은 대력마왕)'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 17:
			cout << "\nQ17. 단군신화에서 '구름'을 관장하는 주술사(신)로 알려진 이 인물은 누구일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "운사") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '운사'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 18:
			cout << "\nQ18. 작은 변화가 폭풍우와 같은 커다란 변화로 유발시키는 현상을 말하는 이 용어는 무엇일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "나비효과") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(1000);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '나비효과'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 19:
			cout << "\nQ19. 그리스로마신화 중 다이달로스의 아들이며, 어리석음과 과욕을 상징하는 인물로, ";
			cout << "바다에 추락하여 사망한 이 인물은 누구일까요 ? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "이카루스") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '이카루스'였습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 20:
			cout << "\nQ20. 지하철에서 한 좌석 열(길게 뻗은 의자)에서 앉을 수 있는 최대 정원은 몇명일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "7명" || answer == "7") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '7명'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 21:
			cout << "\nQ21. 도시와 자연 환경속에 존재하는 다양한 장애물들을 활용하여 이동하는 개인 훈련인 이것은 무엇일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "파쿠르") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '파쿠르'였습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 22:
			cout << "\nQ22. 불로장생을 꿈꾸기 위해 중국 진시황이 사람들을 시켜서 찾게했던, 자연버섯을 뜻하는 이 약초의 이름은 무엇일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "불로초") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '불로초'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 23:
			cout << "\nQ23. 스마트폰은 사람 손가락에서 나오는 '이것'이 휴대폰에 전달되어 터치가 반응하는 것입니다 이것은 무엇일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "전기") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '전기'였습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 24:
			cout << "\nQ24. 1884년 김옥균을 비롯한 급진개화파가 개화사상을 바탕으로 조선의 자주독립과 근대화를 목표로 일으킨 이 정변은 무엇일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "갑신정변") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '갑신정변'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 25:
			cout << "\nQ25. 유럽 14세기에 대유행한 페스트균의 감염에 의해 급성으로 일어나는 공포의 전염병 이름은 무엇일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "흑사병") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '흑사병'였습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 26:
			cout << "\nQ26. 정육면체의 주사위를 굴려서 나온 숫자 2의 뒷면에 나올 숫자는 무엇일까요?   \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "5" || answer == "오") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '5'였습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 27:
			cout << "\nQ27. 최저 기온이 25℃ 이상인 무더운 밤을 뜻하는 용어인 이것은 무엇일까요?  \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "열대야") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '열대야'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 28:
			cout << "\nQ28. 죽어서도 은혜를 잊지 않고 갚는 다는 것으로, 은인을 구해 주었다는 고사에서 유래한 이 사자성어는 무엇일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "결초보은") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '결초보은'였습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 29:
			cout << "\nQ29. 초음속 비행기가 내는 큰 소음이자 폭발음이라고도 하며, 큰 에너지를 발생시킵니다. 이 용어는 무엇일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "소닉 붐") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '소닉 붐'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 30:
			cout << "\nQ30. 중국 삼국시대 촉한의 정치가 겸 전략가. 유비에 의해 '삼고초려'의 예로 초빙되었던 이 인물은 누구일까요? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "제갈량" || answer == "제갈공명") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 '제갈량'이었습니다!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		}
	}
	void OX_Quiz() {
		switch (Quiznum[num])
		{
		case 1:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ1. 구기종목 중 가장 작은 공을 사용하는 경기는 골프다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 제일 작은 공을 사용하는 구기종목은 탁구 입니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 2:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ2. 개구리는 이가 있고 두꺼비는 이가 없다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);

				break;
			}
			else {
				cout << "틀렸습니다! 정답은 O, 개구리는 이가 있지만 두꺼비는 이가 없습니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 3:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ3.  빵은 순수한 우리말이다?  \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 빵은 포르투갈어입니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 4:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ4. 하마는 말의 일종이다?  \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 하마는 돼지의 일종입니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 5:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ5. 고래는 수심 5미터 이하의 물 속에서 잠을 잔다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 고래는 허파로 호흡하는 척추동물이기 때문에 수면에서 잠을 잡니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 6:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ6. 비행기의 블랙박스는 검은색이다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 비행기의 블랙박스는 오렌지색입니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 7:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ7. 63빌딩보다 남산타워가 더 높다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 63빌딩이 더 높습니다";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 8:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ8. 남극보다 북극이 더 춥다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 남극이 북극보다 더 춥습니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 9:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ9. 오이는 채소가 아니라 과일이다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 O, 오이는 과일이 아니라 채소 입니다.";
				oxwrong++;
				Sleep(1000);
				for (int i = 3; i >= 1; i--) {
					cout << i << endl;
					Sleep(1000);
				}
				system("cls");
			}
			break;
		case 10:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ10. 벼룩은 날개가 있다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 O, 벼룩은 날개를 가지고 있습니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 11:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ11.  낙타의 혹 속에는 물이 들어있다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "이별") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 낙타의 혹 속에는 지방이 들어있습니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 12:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ12. 북극곰은 겨울잠을 잔다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 북극곰은 겨울잠을 자지않습니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 13:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ13. 오징어와 게의 다리는 10개이고, 문어와 낙지는 8개이다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 O, 오징어와 게의 다리는 10개이고, 문어와 낙지의 다리는 8개 입니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 14:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ14. 고래도 생선이다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 고래는 포유류 동물입니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 15:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ15. 말은 잘 때 서서 잔다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 O, 말은 잘 때 서서 잡니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 16:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ16. 우리나라 최초 라면값은 10원이었다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 O, 우리나라의 최초 라면값은 10원입니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 17:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ17. 일본에도 회덮밥이 있다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 일본에는 회덮밥이 없습니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 18:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ18.  딸기는 장미과에 속한다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(1000);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 O, 딸기는 장미과 딸기속에 속합니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 19:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ19. 정상 바둑돌 제품은 흰돌과 검은돌의 크기가 다르다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 O, 정상 바둑돌 제품은 흰돌과 검은돌의 크기가 다릅니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 20:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ20. 우리나라 헌법은 모두 여덟번 개정되었다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 우리나라의 헌법은 총 9번 개정 되었습니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 21:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ21. 꽃의 꿀과 꿀벌의 꿀은 똑같다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 꿀벌의 꿀에는 꽃의 꿀에 성분과 다른 성분이 합쳐져 있습니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 22:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ22. 통조림을 최초로 생각한 사람은 프랑스 황제 나폴레옹이다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 O, 통조림을 최초로 생각한 사람은 나폴레옹이 맞습니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 23:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ23. 달팽이도 이빨이 있다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 O, 달팽이는 먹이를 갉아 먹기 때문에 이빨이 있습니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 24:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ24. 투명인간은 장님이다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 O, 빛이 통과해 버리기 때문에 투명인간이 존재한다면 눈을 볼 수 가 없습니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 25:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ25. 프랑스에서 버섯을 따는데 돼지를 이용한다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 O, 고급 프랑스 요리에 쓰이는 특수한 버섯을 따기 위해 돼지를 이용합니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 26:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ26. 하늘은 땅에서도 지구 밖에서도 항상 푸르게 보인다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 지구 밖에서는 공기가 없기 때문에 하늘이 검게 보입니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 27:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ27. 바닷물 속에도 금이 들어있다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 O, 바닷물 100만 톤당, 0.5g 금이 들어있습니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 28:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ28. 사람의 몸 좌우가 정확이 똑같은 대칭이다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 사람의 몸의 좌우는 조금씩 차이가 있습니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 29:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ29. 손톱은 뼈가 아니고 피부가 변한 것이다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 O, 손톱은 뼈가 아니고 피부가 변한 것 입니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 30:
			cout << "O(대문자 O) 와 X(대문자 X)를 사용해 주세요.\n" << endl;
			cout << "\nQ30. 지구가 태양을 한 바퀴 도는데 정확하게 365일이 걸린다? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "정답입니다!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "패스" || answer == "pass") {
				cout << "다음 문제로 넘어갑니다.(엔터를 한번 쳐주세요)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "퀴즈를 종료 합니다" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "틀렸습니다! 정답은 X, 365일 + 6시간이 걸립니다.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		}
	}
};

int main()
{
	MainScreen ms;
	ms.start();

	return 0;
}