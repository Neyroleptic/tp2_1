#include "Student.h"

Student::Student() : secondName("�� ������"), iniciales("�� ������"), numberGroup(0)
{
	cout << "������ �����������" << endl;
}

Student::Student(string secondName, string iniciales, int numberGroup, Marray<int> marks) :
	secondName(secondName), iniciales(iniciales), numberGroup(numberGroup), marks(marks)
{
	cout << "������ �����������" << endl;
}

Student::Student(const Student& student) : secondName(student.secondName), iniciales(student.iniciales), 
numberGroup(student.numberGroup), marks(student.marks)
{
	cout << "������ ����������� �����������" << endl;
}

Student::~Student()
{
	cout << "������ ����������" << endl;
}

//void Student::inputFromConsole()
//{
//	cout << "������� �������: ";
//	getline(cin, secondName);
//	cout << "������� ��������: ";
//	iniciales = inputIniciales();
//	cout << "������� ����� ������: ";
//	numberGroup = safeInput(1, INT32_MAX);
//	cout << "������� ���������� ������: ";
//	int countMarks = safeInput(1, INT32_MAX);
//	for (int i = 0; i < countMarks; i++) {
//		cout << "������� " << i + 1 << " ������: ";
//		marks +=safeInput(2, 5);
//	}
//}
//
//void Student::printToConsole()
//{
//	cout << "���: " << secondName << " " << iniciales << endl;
//	cout << "����� ������: " << numberGroup << endl;
//	cout << "������: ";
//	for (int i = 0; i < marks.getSize(); i++)
//		cout << marks[i] << " ";
//	cout << endl;
//}

void Student::change()
{
	marks.clear();
	cout << "������� ����� �������: ";
	getline(cin, secondName);
	cout << "������� ����� ��������: ";
	getline(cin, iniciales);
	cout << "������� ����� ����� ������: ";
	numberGroup = safeInput(1, INT32_MAX);
	cout << "������� ����� ���������� ������: ";
	int countMarks = safeInput(1, INT32_MAX);
	for (int i = 0; i < countMarks; i++) {
		cout << "������� " << i + 1 << " ������: ";
		marks += safeInput(2, 5);
	}
	marks.sort();
}

double Student::getAverageMark() {
	int sum = 0;
	for (int i = 0; i < marks.getSize(); i++)
		sum += marks[i];
	return double(sum) / double(marks.getSize());
}

Student& Student::operator=(const Student& student) {
	if (this == &student)
		return *this;
	secondName = student.secondName;
	iniciales = student.iniciales;
	numberGroup = student.numberGroup;
	marks = student.marks;
	return *this;
}

bool Student::operator>(Student& student) {
	return getAverageMark() > student.getAverageMark();
}

ostream& operator<<(ostream& out, Student& obj)
{
	out << "���: " << obj.secondName << " " << obj.iniciales << endl;
	out << "����� ������: " << obj.numberGroup << endl;
	out << "������: ";
	for (int i = 0; i < obj.marks.getSize(); i++)
		cout << obj.marks[i] << " ";
	out << endl;
	return out;
}

istream& operator>>(istream& in, Student& obj)
{
	cout << "������� �������: ";
	getline(in, obj.secondName);
	cout << "������� ��������: ";
	obj.iniciales = inputIniciales();
	cout << "������� ����� ������: ";
	obj.numberGroup = safeInput(1, INT32_MAX);
	cout << "������� ���������� ������: ";
	int countMarks = safeInput(1, INT32_MAX);
	for (int i = 0; i < countMarks; i++) {
		cout << "������� " << i + 1 << " ������: ";
		obj.marks += safeInput(2, 5);
	}
	obj.marks.sort();
	return in;
}

