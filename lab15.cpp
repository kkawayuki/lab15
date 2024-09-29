#include <iostream>
using namespace std;

class Movie
{
private:
    int year;
    string title;

public:
    int getYear()const{return year;}
    string getTitle()const{return title;}

    void setYear(int num){year = num;}
    void setTitle(string name){title = name;}

    void printAll()
    {
        cout << "year published: " << year;
        cout << "title of Movie: " << title;
    }
};

int main()
{

}