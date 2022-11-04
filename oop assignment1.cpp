#include <iostream>
#include <string>
using namespace std;
class student
{
	string name,clas,dob,blood_grp,addr,lic;
	int *rollno,div,mob;
	public:
		friend class teacher;
	student()
	{
		//printer_)variable = new data_type
		rollno=new int;
		name,clas,dob,blood_grp,addr,lic="";
		*rollno,div,mob=0;
	}
	student (student &obj)
	{
		this->name=obj.name;
		this->addr=obj.addr;
		this->div=obj.div;
		this->rollno=obj.rollno;
		this->mob=obj.mob;
		this->blood_grp=obj.blood_grp;
		this->dob=obj.dob;
	}
	~student()
	{
		delete rollno;
	}
	
	inline static void display_header()
	{
		cout<<"\n------student information system---";
		cout<<"\n name \t rollno \t division \t class \t dateofbirth \t mobile \t blood_grp";
	}
	void getdata()
	{
		
		cout<<"\n Enter the rollno :";
		cin>>*rollno;
		cout<<"\n Enter the name :";
		cin>>name;
		cout<<"\n Enter the division :";
		cin>>div;
		cout<<"\n Enter the mobile no :";
		cin>>mob;
		cout<<"\n enter the class, date of birth,blood grp, licence no,address:";
		cin>>clas>>dob>>blood_grp>>addr>>lic;
	}
	void display()
	{
		cout<<"\n"<<name<<"\t"<<*rollno<<"\t"<<div<<"\t"<<clas<<"\t"<<dob<<"\t"<<blood_grp;
	}
};

class teacher
{
	int id;
	public:
		teacher()
		{
			id = 0;
		}
		
		void display_t(student &obj1,int t_d)
		{
		try
		
		{
			if(obj1.div==t_d)
			obj1.display();
			else
			throw(obj1.div);
		}
			catch(int x)
			{
				cout<<"student & techer division can not matched";
			}
		}

};

	int main()
	{
		student s[10];
		teacher t;
		int ch,count=0;
	do
	{
	cout<<"\n------------stuent information system---------";
	cout<<"\n----------menu---------";
	cout<<"\n 1.add student record";
	cout<<"\n 2.Display student record";
	cout<<"\n 3.copy constructor";
	cout<<"\n 4.division wise information";
	cout<<"\n 5.`exit";
	cout<<"\n enter choice";
	cin>>ch;
	switch(ch)
	{
		case 1:
			s[count].getdata();
			count++;
			break;
		case 2:
			student::display_header();
			for(int i=0;i<count;i++)
			{
			s[i].display();
			}
			break;
		case 3:
			{
			cout<<"\n copy constructor";
			student s1;
			s1.getdata();
			student s2(s1);
			s2.display();
			}
		break;
		case 4:
			
			int t_div;
			cout<<"\n enter the division";
			cin>>t_div;
			for(int i=0;i<count;i++)
			{
				t.display_t(s[i],t_div);
			}
			break;
		case 5:
			exit (0);
	}
}while(ch!=5);
return 0;
}
	
	
	
		
			
	
			
