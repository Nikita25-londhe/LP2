#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Employee
{
    public:
    string department,name,position;
    vector<int>ratings;
    Employee(string n,string dept,string pos,vector<int>ratings)
    {
        department=dept;
        name=n;
        position=pos;
        this->ratings=ratings;
    }

};
class EvaluationSystem
{
    vector<Employee>employees;
    public:
    vector<string> getQuestions(string pos)
    {
        vector<string>questions;
        if(pos=="Developer")
        {
            questions={"Coding skill","Code Quality","Tech knowledge","Collaboration","Problem Solving"};
        }
        else if(pos=="Manager")
        {
            questions={"Team Leader","Motivation","Decision Making","Knowledge","Strategy"};
        }
        else if(pos=="Customer Support")
        {
            questions={"Product Knowledge","Satisfaction","Patience","Communication","Resolution"};
        }
        return questions;
    }
    void addEmployee()
    {
        string name,dept,pos;
        cout<<"\nEnter name of Employee:";
        getline(cin,name);
        cout<<"\nEnter EMployee's department(IT/Finance/Marketing):";
        getline(cin,dept);
        cout<<"\nEnter Employee's position(Manger/Developer/Customer Support):";
        getline(cin,pos);
        vector<string>questions=getQuestions(pos);
        if(questions.empty())
        {
            cout<<"\nPlease Enter correct role:";
            return;
        }
        vector<int>ratings=getRatings(questions);
        Employee emp(name,dept,pos,ratings);
        employees.push_back(emp);
    }
    vector<int>getRatings(vector<string>questions)
    {
        cout<<"\nGive Ratings for given quality (0-10):\n";
        int rate;
        vector<int>ratings;
        for(int i=0;i<5;i++)
        {
            cout<<"\n"<<questions[i]<<"\n";
            cin>>rate;
            ratings.push_back(rate);
        }
        return ratings;
    }
    void giveAdvice(string quality,int rating)
    {
        cout<<"\nAdvice for "<<quality<<" is : ";
        if(rating>=8)
        {
            cout<<"Excellent!Keep it up";
        }
        else if(rating>=6)
        {
            cout<<"Good !!Aim Higher";
        }
        else if(rating>=4)
        {
            cout<<"Needs Improvement!";
        }
        else
        {
            cout<<"Unsatisfactory!Urgent Action needed!";
        }
    }
    void performanceIndividual()
    {
        string name;
        cout<<"\nEnter name of employee:";
        cin>>name;
        int flag=1;
        for(Employee e:employees)
        {
            if(e.name==name)
            {
                cout<<"\nDepartment:"<<e.department<<"\nPosition:"<<e.position;
                vector<string>questions=getQuestions(e.position);
                for(int i=0;i<5;i++)
                {
                    cout<<"\n"<<questions[i]<<" : "<<e.ratings[i]<<" /10 ";
                    giveAdvice(questions[i],e.ratings[i]);
                }
                flag=0;
            }
        }
        if(flag)
        {
            cout<<"\nNo such employee in knowledgeBase";
            return;
        }
    }
    void performanceAll()
    {
        for(Employee e:employees)
        {
            cout<<"\nDepartment:"<<e.department<<"\nPosition:"<<e.position;
            vector<string>questions=getQuestions(e.position);
            for(int i=0;i<5;i++)
            {
                cout<<"\n"<<questions[i]<<" : "<<e.ratings[i]<<" /10 ";
                giveAdvice(questions[i],e.ratings[i]);
            }
        }
    }
};
int main()
{
    EvaluationSystem system;
    while(true)
    {
        cout<<"\n1=Add Employee\n2=Specific Employee Performance Evaluation\n3=Overall Performance Evaluation\n4=Exit";
        int choice;
        cout<<"\nEnter choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cin.ignore(1);
            system.addEmployee();
            break;
            case 2:
            system.performanceIndividual();
            break;
            case 3:
            system.performanceAll();
            break;
            case 4:
            exit(0);
        }
    }
    return 0;
}
