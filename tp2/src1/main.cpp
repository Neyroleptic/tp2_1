#include "Student.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void printMenu();
void addObject(Marray<Student>& students);
void changeObject(Marray<Student>& students);
void deleteObject(Marray<Student>& students);
void print(Marray<Student>& students);
void searchFellows(Marray<Student>& students);
void searchDeducting(Marray<Student>& students);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Marray<Student> students;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = safeInput(0, 6);
		switch (method)
		{
		case 1:
			addObject(students);
			system("pause");
			system("cls");
			break;
		case 2:
			changeObject(students);
			system("pause");
			system("cls");
			break;
		case 3:
			deleteObject(students);
			system("pause");
			system("cls");
			break;
		case 4:
			//cout << students;
			print(students);
			system("pause");
			system("cls");
			break;
		case 5:
			searchFellows(students);
			system("pause");
			system("cls");
			break;
		case 6:
			searchDeducting(students);
			system("pause");
			system("cls");
			break;
		case 0:

			isExit = true;
			break;
		}
	}
	
}

void printMenu() {
	cout << "1. Добавить объект" << endl;
	cout << "2. Изменить объект" << endl;
	cout << "3. Удалить объект" << endl;
	cout << "4. Вывести данные" << endl;
	cout << "5. Вывести фамилии студентов и номера групп, имеющих 4 и 5" << endl;
	cout << "6. Вывести фамилии студентов и номера групп, под угрозой отчисления" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберете пункт меню: ";
}

void addObject(Marray<Student>& students) {
	Student student;
	cin >> student;
	students += student;
	students.sortbymarks();
}

void changeObject(Marray<Student>& students) {
	if (students.getSize() > 0) {
		print(students);
		cout << "Введите номер студента для изменения: ";
		students[safeInput(1, students.getSize()) - 1].change();
		students.sortbymarks();
	}
	else
		cout << "Список студентов пуст.\n";
}

void deleteObject(Marray<Student>& students) {
	if (students.getSize() > 0) {
		print(students);
		cout << "Введите номер студента для удаления: ";
		students -= safeInput(1, students.getSize()) - 1;
		students.sortbymarks();
	}
	else
		cout << "Список студентов пуст.\n";
}

void print(Marray<Student>& students) {
	if (students.getSize() == 0)
		cout << "Список студентов пуст.\n";
	else {
		cout << "Список студентов\n";
		for (int i = 0; i < students.getSize(); i++) {
			cout << i + 1 << ". Студент\n";
			cout << students[i];
		}
	}
}

void searchFellows(Marray<Student>& students) {
	if (students.getSize() == 0)
		cout << "Список студентов пуст\n";
	else {
		bool isPrint = false;
		for (int i = 0; i < students.getSize(); i++) {
			Marray<int> marks = students[i].getMarks();
			bool is5 = false, is4 = false;
			for (int j = 0; j < marks.getSize(); j++) {
				if (marks[j] == 4) is4 = true;
				if (marks[j] == 5) is5 = true;
			}	
			if (is5 && is4) {
				cout << students[i].getNumberGroup() << " " << students[i].getSecondName() << endl;
				isPrint = true;
			}
		}
			
		if (!isPrint)
			cout << "Студентов хотя бы с 4 и 5 нет\n";
	}
}

void searchDeducting(Marray<Student>& students) {
	if (students.getSize() == 0)
		cout << "Список студентов пуст\n";
	else {
		bool isPrint = false;
		for (int i = 0; i < students.getSize(); i++) {
			Marray<int> marks = students[i].getMarks();
			int count2 = 0;
			for (int j = 0; j < marks.getSize(); j++) {
				if (marks[j] == 2) count2++;
			}
			if (count2 >= 2) {
				cout << students[i].getNumberGroup() << " " << students[i].getSecondName() << endl;
				isPrint = true;
			}
		}

		if (!isPrint)
			cout << "Студентов, готовящихся к отчислению нет\n";
	}
}