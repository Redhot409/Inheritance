//Academy
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define delimeter "\n------------------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS  const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age




class Human
{
	static const int HUMAN_TYPE_WIDTH = 10;
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRST_NAME_WIDTH = 15;
	static const int AGE_WIDTH = 5;
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	const unsigned int  get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//                             Constructors:

	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor\t" << this << endl;
	}

	virtual ~Human()
	{
		cout << "HDestructor\t" << this << endl;
	}

	//                          Methods:

	virtual void info()const
	{
		cout << last_name << "  " <<first_name << "   " << age << " y/o" << endl;
	}
	virtual std::ostream& info(std::ostream& os)const
	{
		return os << last_name << "  " << first_name << "   " << age << " y/o";
	}
	virtual std::ofstream& info(std::ofstream& ofs)const
	{
		//ofs << strchr(typeid(*this).name(),' ') + 1 << " :\t" << last_name << "  " << first_name << "   " << age;
		ofs.width(HUMAN_TYPE_WIDTH);ofs << left<<std::string(strchr(typeid(*this).name(), ' ') + 1) + ":";
		ofs.width(LAST_NAME_WIDTH);ofs <<left<< last_name;
		ofs.width(FIRST_NAME_WIDTH); ofs <<left<< first_name;
		ofs.width(AGE_WIDTH); ofs <<left<< age;
		return ofs;
	}

};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.info(os);
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	return obj.info(ofs);
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student :public Human
{
	static const int SPECIALITY_WIDTH = 25;
	static const int GROUP_WIDTH = 8;
	static const int RATING_WIDTH = 8;
	static const int ATTENDANCE_WIDTH = 8;
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}

	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//         Constructors:

	Student(HUMAN_TAKE_PARAMETERS,STUDENT_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//          Methods:

	 void info()const override
	{
		Human::info();
		cout << speciality << " " << group << " " << rating << " " << attendance << " " << endl;
	}
	 std::ostream& info(std::ostream& os)const override
	 {
		 return Human::info(os)<<" "
		  << speciality << " " << group << " " << rating << " " << attendance<<" ";
	 }
	  std::ofstream& info(std::ofstream& ofs)const override
	 {
		  Human::info(ofs);
		  ofs.width(SPECIALITY_WIDTH);  ofs<< speciality;
		  ofs.width(GROUP_WIDTH);		ofs << group;
		  ofs.width(RATING_WIDTH);		ofs << rating;
		  ofs.width(ATTENDANCE_WIDTH);	ofs << attendance;
		  return ofs;
	 }

};



#define TEACHER_TAKE_PARAMETERS const std::string& speciality, unsigned int experience
#define TEACHER_GIVE_PARAMETERS speciality,experience


class Teacher : public Human
{
	static const int SPECIALITY_WIDTH = 25;
	static const int EXPERIENCE_WIDTH = 5;
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	//             Constructors

	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	//             Methods:


	void info()const override
	{
		Human::info();
		cout << speciality << " " << experience << " " << "years" << endl;
	}
	std::ostream& info(std::ostream& os)const
	{
		return Human::info(os)<<" "<< speciality << " " << experience << " " << "years";
	}
	std::ofstream& info(std::ofstream& ofs)const override
	{
		Human::info(ofs);
		ofs.width(SPECIALITY_WIDTH);ofs << speciality;
		ofs.width(EXPERIENCE_WIDTH);ofs << experience;
		return ofs;
	}
};

std::ostream& operator<<(std::ostream& os, const Teacher& obj)
{
	return os <<(Human)obj<<" " << obj.get_speciality() << " " << obj.get_experience() << " y/o ";
}

#define GRADUATE_TAKE_PARAMETERS const std::string& dip_subj, const std::string& practice_place, const double& dip_complete
#define GRADUATE_GIVE_PARAMETERS dip_subj, practice_place, dip_complete

class Graduate :public Student
{
	static const int DIP_SUBJ_WIDTH = 32;
	std::string dip_subj;
	std::string practice_place;
	double dip_complete;
public:
	const std::string& get_dip_subj()const
	{
		return dip_subj;
	}
	const std::string& get_practice_place()const
	{
		return practice_place;
	}
	const double get_dip_complete()const
	{
		return dip_complete;
	}

	void set_dip_subj(const std::string& dip_subj)
	{
		this->dip_subj=dip_subj;
	}
	void set_practice_place(const std::string& practice_place)
	{
		this->practice_place = practice_place;
	}
	void set_dip_complete(const double& dip_complete)
	{
		this->dip_complete = dip_complete;
	}

	//         Constructors:

	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS,GRADUATE_TAKE_PARAMETERS) :Student(HUMAN_GIVE_PARAMETERS,STUDENT_GIVE_PARAMETERS)
	{
		set_dip_subj(dip_subj);
		set_practice_place(practice_place);
		set_dip_complete(dip_complete);
		cout << "GrConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GrDestructor:\t" << this << endl;
	}

	//           Methods:

	 void info()const override
	{
		Student::info();
		cout << dip_subj << " " << practice_place << " " << dip_complete << " " << endl;
	}
	 std:: ostream& info(std::ostream& os)const override
	 {
		 return Student::info(os) << " "
			 << dip_subj << " " << practice_place << " " << dip_complete << " ";
	 }
	 std::ofstream& info(std::ofstream& ofs)const override
	 {
		 Student::info(ofs) ;
		 ofs.width(DIP_SUBJ_WIDTH); ofs << dip_subj;
		 return ofs;
	 }
};

std::ostream& operator<<(std::ostream& os, const Graduate& obj)
	{
		return os <<(Student&)obj<<" " << obj.get_dip_subj() << " " << obj.get_practice_place() << " " << obj.get_dip_complete() << " " << endl;
	}

//std::ostream& operator<<(std::ostream& os, const Human& obj)
//{
//	
//	return os<<obj._get_last_name()<<" "<<obj.get_first_name()<<" "<<obj.get_age(); 
//}

void Print( Human* group[], const int n)
{
	cout << delimeter << endl;
	for (int i = 0; i < n; i++)
	{
		//group[i]->info();
		cout << *group[i] << endl;
		cout << delimeter << endl;
	}
}

void Clear(Human* group[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		delete group[i];
		cout << delimeter;
	}
}

void Save(Human* group[], const int n, const std::string& filename)
{
	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	std::string cmd = "notepad " + filename;
	system(cmd.c_str());// c-str- возвращает содержимое объекта  std::string в виде обычной C-string(Null terminated line)
}

#define INHERITANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE_CHECK
	Human human("Vercetty", "Tommy", 30);
	human.info();

	Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 70, 97);
	student.info();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.info();

	Graduate Stud_1("John", "Snow",24, "Biology", "WR_220", 65, 77,"Cooking", "CookFactory", 78);
	Stud_1.info();
#endif // INHERITANCE_CHECK

	// Generalization (Upcast):
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 70, 97),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Student("Vercetty", "Tommy", 30,"Theft","Vice",97,98),
		new Graduate("John","Snow",24,"Biology","WR_220",65,77,"Cooking","CookFactory",78),
		new Teacher ("Diaz", "Ricardo", 50, "Weapons distribution",20)
	};
	Print(group, sizeof(group) / sizeof(group[0]));
	Save(group, sizeof(group) / sizeof(group[0]), "group.txt");
	Clear(group, sizeof(group) / sizeof(group[0]));
	
}