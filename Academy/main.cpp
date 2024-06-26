//Academy
#include <iostream>
#include <string>
using namespace std;

#define delimeter "\n------------------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS  const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age




class Human
{
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

};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << "y/o " << endl;
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student :public Human
{
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
};

std::ostream& operator<<(std::ostream& os,  const Student & obj)
{
	return os <<(Human&)obj<<" " << obj.get_speciality() << " " << obj.get_group() << " " << obj.get_rating() << " " << obj.get_attendance();
}

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, unsigned int experience
#define TEACHER_GIVE_PARAMETERS speciality,experience


class Teacher : public Human
{
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
};

std::ostream& operator<<(std::ostream& os, const Teacher& obj)
{
	return os <<(Human)obj<<" " << obj.get_speciality() << " " << obj.get_experience() << " y/o ";
}

#define GRADUATE_TAKE_PARAMETERS const std::string& dip_subj, const std::string& practice_place, const double& dip_complete
#define GRADUATE_GIVE_PARAMETERS dip_subj, practice_place, dip_complete

class Graduate :public Student
{
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
};

std::ostream& operator<<(std::ostream& os, const Graduate& obj)
	{
		return os <<(Student&)obj<<" " << obj.get_dip_subj() << " " << obj.get_practice_place() << " " << obj.get_dip_complete() << " " << endl;
	}

//std::ostream& operator<<(std::ostream& os, const Human& obj)
//{
//	obj.info();
//	return os;
//}


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
		new Graduate("John","Snow",24,"Biology","WR_220",65,77,"Cooking","CookFactory",78)

	};
	cout << delimeter << endl;
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		cout << typeid(*group[i]).name() << ":\t";
		//Specialization (Downcast):
		if (typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Teacher))cout << *dynamic_cast<Teacher*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Graduate))cout << *dynamic_cast<Graduate*>(group[i]) << endl;
		//cout<<i<<" "<<sizeof(group[i])<<"\n";
		//group[i]->info();
		//cout << *group[i] << endl;
		cout << delimeter << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
		cout << delimeter;
	}
     
}