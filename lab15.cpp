#include <iostream>
#include <array>
#include <fstream>
#include <string>
using namespace std;

// class declaration
class Movie
{
private:
    string writer;
    int year;
    string title;

public:
    string getWriter() const { return writer; }
    int getYear() const { return year; }
    string getTitle() const { return title; }

    void setWriter(string name) { writer = name; }
    void setYear(int num) { year = num; }
    void setTitle(string name) { title = name; }

    void printAll() const
    {
        cout << "---------------------\n";
        cout << "Writer of Movie: " << writer << '\n';
        cout << "Year published: " << year << '\n';
        cout << "Title of Movie: " << title << '\n';
    }
};

// prototype
Movie readInMovies();

// global
const int SIZE = 4; // max capacity

/**************************************
 * Fucntion: Main
 **************************************/
int main()
{
    array<Movie, SIZE> movies;

    for (int i = 0; i < SIZE; i++)
        movies[i] = readInMovies(); // pass pointer to

    // output array elements
    for (int i = 0; i < SIZE; i++)
    {
        movies[i].printAll();
    }
}

Movie readInMovies()
{
    Movie temp;
    string buf;
    int ibuf;

    ifstream in;
    in.open("data.txt");

    if (!in.good()) // validation
    {
        cout << "Error opening text file\n";
    }
    else
    {
        getline(in, buf);
        temp.setWriter(buf);

        in >> ibuf;
        temp.setYear(ibuf);

        in.ignore();
        getline(in, buf);
        temp.setTitle(buf);
    }
    return (temp);
}
