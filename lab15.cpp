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
        cout << "Movie: " << writer << '\n';
        cout << "\tYear released: " << year << '\n';
        cout << "\tScreenwriter: " << title << "\n\n";
    }
};

// global variable
const int SIZE = 4; // max capacity, edit based on input.txt

// prototype
void readInMovies(array<Movie, SIZE> &movies);

/**************************************
 * Fucntion: Main
 **************************************/
int main()
{
    array<Movie, SIZE> movies;

    readInMovies(movies);

    // output array elements
    for (int i = 0; i < SIZE; i++)
    {
        movies[i].printAll();
    }
}

void readInMovies(array<Movie, SIZE> &movies)
{
    Movie temp;
    string buf;
    int ibuf;

    ifstream in;
    in.open("input.txt");

    if (!in.good()) // validation
    {
        cout << "Error opening text file\n";
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            getline(in, buf);
            temp.setTitle(buf);

            in >> ibuf;
            temp.setYear(ibuf);

            in.ignore();
            getline(in, buf);
            temp.setWriter(buf);

            movies[i] = temp;
        }
    }
    in.close();
}
