#include<iostream>
using namespace std;
class Chatbot
{
    public:
    void start()
    {
        cout<<"\nWelcome to my Restaurant chatbot!!!";
        cout<<"\nHow can I help you today?";
        cout<<"\nnIf you don't want any service enter exit";
        string input;
        while(true)
        {
            cout<<"\nUser:";
            getline(cin,input);
            if(input=="exit")
            {
                cout<<" Thanks for visiting us!!Have a nice day!";
                break;
            }
            getResponse(input);
        }
    }
    void getResponse(string input)
    {
        cout<<"\nChatbot:";
        if(input.find("menu")!=string::npos)
        {
            cout<<" What would you like to order?";
        }
        else if(input.find("order")!=string::npos)
        {
            cout<<" what would like to order?";
        }
        else if(input.find("reservation")!=string::npos)
        {
            cout<<"How many people are there with you?";
        }
        else if(input.find("thank you")!=string::npos)
        {
            cout<<" Ok!Let's meet again!";
        }
        else if(input.find("special")!=string::npos)
        {
            cout<<" Our special menu is kadhi vada.You must try it";
        }
        else
        {
            cout<<"None";
        }
    }
};
int main()
{
    Chatbot bot;
    bot.start();
    return 0;
}
