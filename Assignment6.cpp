#include<iostream>
#include<string>
using namespace std;
int main()
{
    int score=0;
    string punctuality,teamwork,initiative,taskCompletion;
    cout<<"\nWelcome to Expert SYstem Evaluating Employee Performance!";
    cout<<"\nIs Punctual?";
    getline(cin,punctuality);
    cout<<"\nIs taking part in teamwork activity?";
    getline(cin,teamwork);
    cout<<"\nIs Taking initiative?";
    getline(cin,initiative);
    cout<<"\nCompletes the task in time?";
    getline(cin,taskCompletion);
    if(punctuality=="yes")
    {
        score++;
    }
    if(teamwork=="yes")
    {
        score++;
    }
    if(initiative=="yes")
    {
        score++;
    }
    if(taskCompletion=="yes")
    {
        score++;
    }
    switch (score)
    {
    case 4:
        cout<<"\nExcellent Performance!";
        break;
    case 3:
        cout<<"\nGood ";
        break;
    case 2:
        cout<<"\nAverage";
        break;
    case 1:
        cout<<"\nNeeds Improvement";
        break;
    case 0:
        cout<<"\nNeeds Training";
        break;
    default:
        break;
    }

}
