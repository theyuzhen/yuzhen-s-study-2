<student.cpp>

#include<iostream>
#include<string.h>
using namespace std;


class college
{
public:
	college(int a=30,char*pname1="softwareCollege")
	{
		NumberOfTeacher = a;
		strcpy_s(NameOfCollege, pname1);//不用加sizeof（NameOfCollege)
		NameOfCollege[sizeof(NameOfCollege)-1] = '\n';
	}

protected:
	int NumberOfTeacher;
	char NameOfCollege[20];

};
class grade//继承自college父类，子类可直接访问其私有成员
{
public:
	grade(int c=2018,char*pname3="刘旭")
	{
		yearGrade = c;
		strcpy_s(NameOfInstructor, pname3);
		NameOfInstructor[sizeof(NameOfInstructor)-1] = '\0';

	}
protected:
	int yearGrade;//年级
	
	char NameOfInstructor[20];//辅导员
};
class student:protected grade,protected college
{
public:
	//参数列表七个，六个用“：”赋值，一个直接赋值。
	student(int a, char*pname1, int c, char*pname3, int d, int e, char*pname2) :college(a, pname1), grade(c, pname3),  studentid(d), age(e)
	{
		strcpy_s(NameOfStudent, pname2);
		NameOfStudent[sizeof(NameOfStudent)-1] = '\0';
		//studentid = d;
		//age = e;
	}
	void print()
	{
		cout << "这是" << NameOfCollege << "  " << "共有" << NumberOfTeacher << "位老师" << endl;
		cout << "这是" << yearGrade << "届" << "    " << "辅导员是::" << NameOfInstructor << endl;
		cout << "名字：" << NameOfStudent << "    " << "年龄:" << age << "   " << "学号：" << studentid << endl;

	}
protected:
	 char NameOfStudent[20];
	int studentid;
	int age;
};

int main()
{
	student a( 30 ,"softwarecollege", 2018,"刘旭", 201823333, 19, "yuzhen");
	a.print();
}
