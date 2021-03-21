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
		cout << "�̸��� �Է��ϼ��� : ";
		cin >> name;
		cout << "\n�ȳ��ϼ���, " << name << "��!" << endl;
		cout << "���� ���� ���Ű� ȯ���մϴ�!" << endl;
		ShowChoice();
	}
	void result() {
		ofstream out(name + ".txt");
		
		cout << "\n�ͼ��� ������� " << ::ncount << "��, \n";
		out << "�ͼ��� ������� " << ::ncount << "��," << endl;

		cout << "\n��� ������� " << ::ccount << "��, \n";
		out << "\n��� ������� " << ::ccount << "��, " << endl;

		cout << "\nOX ������� " << ::oxcount << "����, \n";
		out << "\nOX ������� " << ::oxcount << "����,\n" << endl;

		::count = ::ncount + ::ccount + ::oxcount;

		cout << name << "�� ���� ���ݱ��� ���߽� �� ������ ������ " << ::count << "���̸�,\n\n";
		out << name << "�� ���� ���ݱ��� ���߽� �� ������ ������ " << ::count << "���̸�,\n\n" << endl;


		cout << "\n�ͼ��� ������� " << ::nwrong << "��, \n\n";
		out << "�ͼ��� ������� " << ::nwrong << "��," << endl;

		cout << "\n��� ������� " << ::cwrong << "��, \n\n";
		out << "\n��� ������� " << ::cwrong << "��, " << endl;

		cout << "\nOX ������� " << ::oxwrong << "����, \n\n";
		out << "\nOX ������� " << ::oxwrong << "����, \n" << endl;

		::wrong = ::nwrong + ::cwrong + ::oxwrong;

		cout << name << "�� ���� ���ݱ��� Ʋ���� �� ������ ������ " << ::wrong << "�� �Դϴ�.\n";
		out << name << "�� ���� ���ݱ��� Ʋ���� �� ������ ������ " << ::wrong << "�� �Դϴ�." << endl;

		out.close();
	}
	void ShowChoice()
	{
		cout << "		 �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
		cout << "		|		|		 |		 |" << endl;
		cout << "		|	��	|	��	 |	 ��	 |" << endl;
		cout << "		|		|		 |		 |" << endl;
		cout << "		|     �ͼ���	|      ��� 	 |     O or X	 |" << endl;
		for (int i = 1; i <= 3; i++) {
			cout << "		|		|		 |		 |" << endl;
		}
		cout << "		 �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n\n" << endl;

		cout << "���Ͻô� ���� ��ȣ�� �������ּ��� : " << endl;
		cout << "���α׷� ���Ḧ ���ϽŴٸ� ���� '0'�� �Է����ּ���." << endl;
		cin >> choice;
		Choice(choice);
	}
	void Choice(int choice)
	{
		this->choice = choice;
		if (this->choice == 1) {
			cout << "\n�ͼ����� �����ϼ̽��ϴ�!" << endl;
			cout << "���̾� ��� ���� �˴ϴ�!" << endl;
			Sleep(1000);

			for (int i = 3; i >= 1; i--) {
				cout << i << endl;
				Sleep(1000);
			}

			system("cls");
			cout << "�ͼ��� ��� ���Ű� ȯ���մϴ�!" << endl;
			Quiz_choice();
		}
		else if (this->choice == 2) {
			cout << "\n����� �����ϼ̽��ϴ�!" << endl;
			cout << "���̾� ��� ���� �˴ϴ�!" << endl;
			Sleep(1000);

			for (int i = 3; i >= 1; i--) {
				cout << i << endl;
				Sleep(1000);
			}

			system("cls");
			cout << "��� ��� ���Ű� ȯ���մϴ�!" << endl;
			Quiz_choice();
		}
		else if (this->choice == 3) {
			cout << "\nOX�� �����ϼ̽��ϴ�!" << endl;
			cout << "���̾� ��� ���� �˴ϴ�!" << endl;
			Sleep(1000);

			for (int i = 3; i >= 1; i--) {
				cout << i << endl;
				Sleep(1000);
			}

			system("cls");
			cout << "OX ��� ���Ű� ȯ���մϴ�!" << endl;
			Quiz_choice();
		}
		else if (this->choice == 0) {
			system("cls");
			cout << "\n��� ���� �մϴ�.\n" << endl;

			for (int i = 3; i >= 1; i--) {
				cout << i << endl;
				Sleep(1000);
			}

			HWND hWndConsole = GetConsoleWindow();
			ShowWindow(hWndConsole, SW_HIDE);
		}
	}
	void Quiz_choice() {
		cout << "��� �����ϰ� �����ôٸ� ����'0'��, \n������ �н��ϰ� �����ôٸ� '�н�' �Ǵ� 'pass'�� �Է��� �ּ���. \n" << endl;
		cout << "�ٸ� ������ ��� Ǯ�� �����ôٸ� '100'�� �Է��� �ּ���.\n\n" << endl;
		cout << "���� ��ȣ�� ������ �ּ���!(�ִ� 30)" << endl;
		if (Quiznum[num] <= 30) {
			for (int i = 1; i <= 29; i++) {
				if (choice == 1) {
					cin >> Quiznum[num];

					if (Quiznum[num] == 0) {
						system("cls");
						result();
						cout << "\n��� ���� �մϴ�.\n" << endl;
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
						cout << "\n��� ���� �մϴ�.\n" << endl;
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
						cout << "\n��� ���� �մϴ�.\n" << endl;
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
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���";
			Quiz_choice();
		}
	}
	void N_Quiz() {
		switch (Quiznum[num])
		{
		case 1:
			cout << "\nQ1. ���󿡼� ���� ���� ���ڴ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�ʱ���" || answer == "190,000" || answer == "190000") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;

				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�ʱ���(190,000)'�̾����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 2:
			cout << "\nQ2. ����ġ�� ����� �ϸ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "���佺Ƽ��" || answer == "rockfestival") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;

				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);

				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '���佺Ƽ��'�̾����ϴ�!";
				Sleep(1000);
				nwrong++;
				system("cls");
				Quiz_choice();
			}
			break;
		case 3:
			cout << "\nQ3. ������ ����� ǰ�� �ٴϴ� ����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '����'�̾����ϴ�!";
				Sleep(1000);
				nwrong++;
				system("cls");
				Quiz_choice();
			}
			break;
		case 4:
			cout << "\nQ4. �л����� �Ⱦ��ϴ� ���ڴ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "å����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ 'å����'�����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 5:
			cout << "\nQ5. ���� �ٴϴ� ����� �̸���? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '����'�̾����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 6:
			cout << "\nQ6. ���յ� ��� ���� ���� ����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�����'�̾����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 7:
			cout << "\nQ7. ������ ���� ����̴� ����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '����'�̾����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 8:
			cout << "\nQ8. ���� ��, ������ ���̸� �� ���� �ϱ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "4����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '4����'�����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 9:
			cout << "\nQ9. �ұ������ ���� �ݱ�� �����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�̰ſ� ���" || answer == "�̰ſ���") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�̰ſ� ���'�̿����ϴ�!";
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
			cout << "\nQ10. ������� ���� ������ ����� ���ڴ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�ټ�" || answer == "5") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�ټ�(5)'�̾����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 11:
			cout << "\nQ11. �� �߿� ���� ���� ����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�̺�") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�̺�'�̾����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 12:
			cout << "\nQ12. ��¥ ���� �̸��� �����ϱ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '����'�����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 13:
			cout << "\nQ13. ����� �����԰� ���� ���� ���� ����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "ö�� ��" || answer == "ö�鶧") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ 'ö�� ��'�̾����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 14:
			cout << "\nQ14. ���󿡼� ���� �߰ſ� �ٴٴ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "���ٴ�") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '���ٴ�(���޾�)'�����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 15:
			cout << "\nQ15. ���󿡼� ���� �߿� �ٴٴ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�䷷��") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�䷷��'�����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 16:
			cout << "\nQ16. '���� ����� ����ģ��'�� 4���ڷ� ���δٸ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "��������") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '��������'�����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 17:
			cout << "\nQ17. �������� �ݴ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "��") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '��'�̾����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 18:
			cout << "\nQ18. ���߿��� ���� ������� �����ϴ� ����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				cout << "��� ���� �մϴ�" << endl;
				Sleep(1000);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '����'�̾����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 19:
			cout << "\nQ19. �������� �Ͼ�� ������? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "����" || answer == "TheWar" || answer == "The war") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '����(The war)'�����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 20:
			cout << "\nQ20. �Ƹ����� ��� �ִ� ��� �̸���? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�Ƹ�,��?" || answer == "�Ƹ�,��" || answer == "��") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '��(�Ƹ�,��)'�̾����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 21:
			cout << "\nQ21. ������ �Ѿ����鼭 �ϴ� ����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�ƾ�") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�ƾ�'�����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 22:
			cout << "\nQ22. ����� �� ��ġ�� ����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '����'�̾����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 23:
			cout << "\nQ23. ������� Ż �� �ִ� ����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�λ���") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�λ���'�����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 24:
			cout << "\nQ24. ���Ƹ��� �����ϴ� ����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�߾�") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�߾�'�̾����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 25:
			cout << "\nQ25. ȥ�ڸ� �� �� �ִ� �����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�޳���") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�޳���'�����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 26:
			cout << "\nQ26. ���� ȭ������? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�Ź߲�" || answer == "�� �߲�") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�Ź߲�'�̾����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 27:
			cout << "\nQ27. ���� ������ ������ �ɱ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "��") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '��'�̾����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 28:
			cout << "\nQ28. �մ��� ���ϸ� �� ���� �����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "���ǻ�" || answer == "�� �ǻ�") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '���ǻ�'�����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 29:
			cout << "\nQ29. ���� ��ư� ���� �� �̸���? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�쿭����" || answer == "�쿭��" || answer == "�쿭�� ��") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�쿭����'�̾����ϴ�!";
				nwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 30:
			cout << "\nQ30. ����Ʈ���� ������ Ż �� ������? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "����" || answer == "9" || answer == "��ȩ��" || answer == "9��") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '��(9)��'�̾����ϴ�!";
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
			cout << "Q.�������� ������ ���� ��� ���ϱ��?, \n�λ��� �ÿ���ȭ��ȣ + \n2001�� �λ� ���� ��ȭ���� ���� ȸ�� + \n���� ���Ǵ� �츮���� ������ ����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "63") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '63'�̾����ϴ�! �λ��� �ÿ���ȭ��ȣ= 051, �λ��� ���� ��ȭ�� ȸ�� = 6ȸ, ���� ���Ǵ� ������ ���� = 6��";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 2:
			cout << "Q. ���� �Ӵ㿡 �������� ���� '�̰�'�� �����ϱ��?";
			cout << "\n'�̰�'�� �ڱ� �� �ϴ� ���� �� �� ���ָ� �Ѵ´�.";
			cout << "\n'�̰�' �� ���ؿ��� �������� ���� �Ź� �� ���� �־� ��������.";
			cout << "\n'�̰�'�� ������ ���ְ� �ִ�.\n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "������") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);

				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '������'�����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 3:
			cout << "Q. �̰��� ������ ��Ӵϰ� ������ ������ ���� �� �� �̻� �� �Ϳ��� ������ ��缺���Դϴ�.";
			cout << "��Ȱȯ���� ������ ��ġ�� ������ �ſ� ũ��, �߿��� ������ �Ѵٴ� ���� �̸��� ���Դϴ�. ";
			cout << "�� ������ ���ڼ���� �����ϱ��?\n\n" << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "��õ����" || answer == "�͸��õ����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�͸��õ����(��õ����)'�����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 4:
			cout << "Q. �������� �����ϴ� ������� ��ⱸ, ��׸�, ���ڱ� ���� ����� ����� ���´� ���̾�����";
			cout << "���翡�� ���� �鿩 ������ �����, �������� ������ ��￩ â���Ѵٴ� �濡�� â�ۿ������� ���´� ���� �Ǿ����ϴ�.";
			cout << "�̷� ������� �����̶�� �ұ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '����'�̾����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 5:
			cout << "\nQ5. ��ǻ���� ǥ��Ű���忡�� F1���� F12������ Ű�� �ֽ��ϴ�. ���⼭ F�� ������ �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "Function" || answer == "function") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ 'Function'�̾����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 6:
			cout << "\nQ6. ��ȭ�� ����, �߸��Ҽ� ��� ����ذ��� �Ǹ����� Ǯ���� �ʰ� ���ڸ� ���������ϰ� �ϴ� ���尨�� ȿ���� ���մϴ�.\n";
			cout << "�����̳� ��ȭ������ ������ �ҾȰ��� ���� ���� ������ �ḻ���� �������� �ʰ�, ������ ��̸� ���ϱ� ���� �������� ���˴ϴ�.\n";
			cout << "�̰��� �����̶�� �ұ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�����潺") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�����潺'�̾����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 7:
			cout << "\nQ7. �����Ƿ��� �ۿ��� �Թ� �� ���� �� ����� ������ ������,";
			cout << "\n������ ������ �����ϴ� ��ġ���������� �̰��� �����ϱ�� ? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "��� �и�" || answer == "��Ǻи�") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '��� �и�'�̾����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 8:
			cout << "\nQ8. �̱� Ķ�����Ͼ��� ������ �ֳ����ӿ� ��ġ�� �ִ� �������� ����������, ��Ը��� �����ü��� �̰��� ����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "����Ϸ���" || answer == "����� ����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '����Ϸ���'�����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 9:
			cout << "\nQ9. Ÿ���� ��볪 �������� ���Ͽ� �ɷ��� �����ų� ����� �������� ������ �� ȿ���� �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�Ǳ� ������ ȿ��" || answer == "�Ǳ� ������") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�Ǳ� ������ ȿ��'�����ϴ�!";
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
			cout << "\nQ10. ������ ���� �������� ���� ���Ż簡 �Ƹ��ٿ� ������������ ¦����ϴ� ������ ��� �� �������� �̸��� �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "������� ����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '������� ����'�̾����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 11:
			cout << "\nQ11. ����� �꼺, ���⼺�� �Ǵ��ϴµ� ���̴� '������ �̸�'���� �꼺�� ������, ���⼺�� Ǫ������ ���� �� ������ �̸���? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "��Ʈ�ӽ�" || answer == "��Ʈ�ӽ� ����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '��Ʈ�ӽ� ����'�����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 12:
			cout << "\nQ12. ��𰭿� ���ϴ� ȯ�������� ��Ī���� ö���� �Ƹ������ڷ����� �̰��� '������ â��'��� �߽��ϴ� �̰��� �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "������") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '������'�����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 13:
			cout << "\nQ13. ������ ������ �ŷɽ����� ���̸� ������ ��Ȱ�� �ݺ��Ͽ� �һ������ �Ҹ��� �̰��� �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�Ǵн�" || answer == "����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�Ǵн�(����)'�̾����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 14:
			cout << "\nQ14. ������ ������� ���� �� �� ����� ó�� ����� ���� �ʰ� �Ǵ� ������ ���ϴ� �� �ɸ��� ���� �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "����� ȿ��" || answer == "�����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '����� ȿ��'�����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 15:
			cout << "\nQ15. ���������� �ٺ�ġ�� �׸� '������ ����'���� ������ �����Ͽ� ������ �ι��� �� ����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "13��" || answer == "13") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '13�� (12�� + ���� 1��)'�̾����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 16:
			cout << "\nQ16. �տ����� ȭ���� ���ŵ��� ���� �� �������� �ξ��� �䱫��, ȥö���̶�� ���⸦ ����ϴ� �� �ι��� �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�츶��" || answer == "��õ�뼺" || answer == "��¸���") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�츶�� (��õ�뼺 Ȥ�� ��¸���)'�̾����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 17:
			cout << "\nQ17. �ܱ���ȭ���� '����'�� �����ϴ� �ּ���(��)�� �˷��� �� �ι��� �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "���") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '���'�̾����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 18:
			cout << "\nQ18. ���� ��ȭ�� ��ǳ��� ���� Ŀ�ٶ� ��ȭ�� ���߽�Ű�� ������ ���ϴ� �� ���� �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "����ȿ��") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				cout << "��� ���� �մϴ�" << endl;
				Sleep(1000);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '����ȿ��'�̾����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 19:
			cout << "\nQ19. �׸����θ���ȭ �� ���̴޷ν��� �Ƶ��̸�, ������� ������ ��¡�ϴ� �ι���, ";
			cout << "�ٴٿ� �߶��Ͽ� ����� �� �ι��� �����ϱ�� ? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "��ī�罺") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '��ī�罺'�����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 20:
			cout << "\nQ20. ����ö���� �� �¼� ��(��� ���� ����)���� ���� �� �ִ� �ִ� ������ ����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "7��" || answer == "7") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '7��'�̾����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 21:
			cout << "\nQ21. ���ÿ� �ڿ� ȯ��ӿ� �����ϴ� �پ��� ��ֹ����� Ȱ���Ͽ� �̵��ϴ� ���� �Ʒ��� �̰��� �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '����'�����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 22:
			cout << "\nQ22. �ҷ������ �޲ٱ� ���� �߱� ����Ȳ�� ������� ���Ѽ� ã���ߴ�, �ڿ������� ���ϴ� �� ������ �̸��� �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�ҷ���") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�ҷ���'�̾����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 23:
			cout << "\nQ23. ����Ʈ���� ��� �հ������� ������ '�̰�'�� �޴����� ���޵Ǿ� ��ġ�� �����ϴ� ���Դϴ� �̰��� �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '����'�����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 24:
			cout << "\nQ24. 1884�� ������� ����� ������ȭ�İ� ��ȭ����� �������� ������ ���ֵ����� �ٴ�ȭ�� ��ǥ�� ����Ų �� ������ �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "��������") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '��������'�̾����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 25:
			cout << "\nQ25. ���� 14���⿡ �������� �佺Ʈ���� ������ ���� �޼����� �Ͼ�� ������ ������ �̸��� �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "��纴") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '��纴'�����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 26:
			cout << "\nQ26. ������ü�� �ֻ����� ������ ���� ���� 2�� �޸鿡 ���� ���ڴ� �����ϱ��?   \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "5" || answer == "��") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '5'�����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 27:
			cout << "\nQ27. ���� ����� 25�� �̻��� ������ ���� ���ϴ� ����� �̰��� �����ϱ��?  \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�����") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�����'�̾����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 28:
			cout << "\nQ28. �׾�� ������ ���� �ʰ� ���� �ٴ� ������, ������ ���� �־��ٴ� ��翡�� ������ �� ���ڼ���� �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "���ʺ���") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '���ʺ���'�����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 29:
			cout << "\nQ29. ������ ����Ⱑ ���� ū �������� �������̶�� �ϸ�, ū �������� �߻���ŵ�ϴ�. �� ���� �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�Ҵ� ��") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '�Ҵ� ��'�̾����ϴ�!";
				cwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 30:
			cout << "\nQ30. �߱� �ﱹ�ô� ������ ��ġ�� �� ������. ���� ���� '����ʷ�'�� ���� �ʺ��Ǿ��� �� �ι��� �����ϱ��? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "������" || answer == "��������") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ '������'�̾����ϴ�!";
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
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ1. �������� �� ���� ���� ���� ����ϴ� ���� ������? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, ���� ���� ���� ����ϴ� ���������� Ź�� �Դϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 2:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ2. �������� �̰� �ְ� �β���� �̰� ����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);

				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ O, �������� �̰� ������ �β���� �̰� �����ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 3:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ3.  ���� ������ �츮���̴�?  \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, ���� �����������Դϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 4:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ4. �ϸ��� ���� �����̴�?  \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, �ϸ��� ������ �����Դϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 5:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ5. ���� ���� 5���� ������ �� �ӿ��� ���� �ܴ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, ���� ���ķ� ȣ���ϴ� ô�ߵ����̱� ������ ���鿡�� ���� ��ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 6:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ6. ������� ���ڽ��� �������̴�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, ������� ���ڽ��� ���������Դϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 7:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ7. 63�������� ����Ÿ���� �� ����? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, 63������ �� �����ϴ�";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 8:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ8. ���غ��� �ϱ��� �� ���? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, ������ �ϱغ��� �� ����ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 9:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ9. ���̴� ä�Ұ� �ƴ϶� �����̴�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ O, ���̴� ������ �ƴ϶� ä�� �Դϴ�.";
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
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ10. ������ ������ �ִ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ O, ������ ������ ������ �ֽ��ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 11:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ11.  ��Ÿ�� Ȥ �ӿ��� ���� ����ִ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "�̺�") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, ��Ÿ�� Ȥ �ӿ��� ������ ����ֽ��ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 12:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ12. �ϱذ��� �ܿ����� �ܴ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, �ϱذ��� �ܿ����� �����ʽ��ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 13:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ13. ��¡��� ���� �ٸ��� 10���̰�, ����� ������ 8���̴�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ O, ��¡��� ���� �ٸ��� 10���̰�, ����� ������ �ٸ��� 8�� �Դϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 14:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ14. ���� �����̴�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, ���� ������ �����Դϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 15:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ15. ���� �� �� ���� �ܴ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ O, ���� �� �� ���� ��ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 16:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ16. �츮���� ���� ��鰪�� 10���̾���? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ O, �츮������ ���� ��鰪�� 10���Դϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 17:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ17. �Ϻ����� ȸ������ �ִ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, �Ϻ����� ȸ������ �����ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 18:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ18.  ����� ��̰��� ���Ѵ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				cout << "��� ���� �մϴ�" << endl;
				Sleep(1000);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ O, ����� ��̰� ����ӿ� ���մϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 19:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ19. ���� �ٵϵ� ��ǰ�� �򵹰� �������� ũ�Ⱑ �ٸ���? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ O, ���� �ٵϵ� ��ǰ�� �򵹰� �������� ũ�Ⱑ �ٸ��ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 20:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ20. �츮���� ����� ��� ������ �����Ǿ���? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, �츮������ ����� �� 9�� ���� �Ǿ����ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 21:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ21. ���� �ܰ� �ܹ��� ���� �Ȱ���? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, �ܹ��� �ܿ��� ���� �ܿ� ���а� �ٸ� ������ ������ �ֽ��ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 22:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ22. �������� ���ʷ� ������ ����� ������ Ȳ�� ���������̴�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ O, �������� ���ʷ� ������ ����� ���������� �½��ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 23:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ23. �����̵� �̻��� �ִ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ O, �����̴� ���̸� ���� �Ա� ������ �̻��� �ֽ��ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 24:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ24. �����ΰ��� ����̴�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ O, ���� ����� ������ ������ �����ΰ��� �����Ѵٸ� ���� �� �� �� �����ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 25:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ25. ���������� ������ ���µ� ������ �̿��Ѵ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ O, ��� ������ �丮�� ���̴� Ư���� ������ ���� ���� ������ �̿��մϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 26:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ26. �ϴ��� �������� ���� �ۿ����� �׻� Ǫ���� ���δ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, ���� �ۿ����� ���Ⱑ ���� ������ �ϴ��� �˰� ���Դϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 27:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ27. �ٴ幰 �ӿ��� ���� ����ִ�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ O, �ٴ幰 100�� ���, 0.5g ���� ����ֽ��ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 28:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ28. ����� �� �¿찡 ��Ȯ�� �Ȱ��� ��Ī�̴�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, ����� ���� �¿�� ���ݾ� ���̰� �ֽ��ϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 29:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ29. ������ ���� �ƴϰ� �Ǻΰ� ���� ���̴�? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "O") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ O, ������ ���� �ƴϰ� �Ǻΰ� ���� �� �Դϴ�.";
				oxwrong++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			break;
		case 30:
			cout << "O(�빮�� O) �� X(�빮�� X)�� ����� �ּ���.\n" << endl;
			cout << "\nQ30. ������ �¾��� �� ���� ���µ� ��Ȯ�ϰ� 365���� �ɸ���? \n\n " << endl;
			cout << "A. ";
			cin >> answer;
			if (answer == "X") {
				cout << "�����Դϴ�!" << endl;
				::ncount++;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "�н�" || answer == "pass") {
				cout << "���� ������ �Ѿ�ϴ�.(���͸� �ѹ� ���ּ���)" << endl;
				Sleep(1000);
				system("cls");
				Quiz_choice();
			}
			else if (answer == "0") {
				result();
				cout << "��� ���� �մϴ�" << endl;
				Sleep(4500);
				HWND hWndConsole = GetConsoleWindow();
				ShowWindow(hWndConsole, SW_HIDE);
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! ������ X, 365�� + 6�ð��� �ɸ��ϴ�.";
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