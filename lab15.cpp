// COMSC-210 | lab 15 | Kent Kawashima
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
    // inline functions to get each private value, const to avoid loophole changes
    string getWriter() const { return writer; }
    int getYear() const { return year; }
    string getTitle() const { return title; }

    // setter inline functions for each seperate variable
    void setWriter(string name) { writer = name; }
    void setYear(int num) { year = num; }
    void setTitle(string name) { title = name; }

    // method to print out all values of specified class, formatted neatly.
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
 * Function: Main
 **************************************/
int main()
{
    array<Movie, SIZE> movies;

    // read in data from txt file, fill array
    readInMovies(movies);

    // output array elements
    for (int i = 0; i < SIZE; i++)
    {
        movies[i].printAll();
    }
}

/************************************************
 * Function: Takes in the original array holding
 * Movie information from origin of call, fills
 * each of SIZE elements with data from a formatted
 * txt file input, ensuring that the file exists
 * and is open. Afterwards, closes the txt file.
 *
 * Parameters: &movies, the array of movies, passed
 * by reference so its elements can be modified
 * Return: NONE
 ************************************************/
void readInMovies(array<Movie, SIZE> &movies)
{
    Movie temp;
    string buf;
    int ibuf;

    ifstream in;
    in.open("input.txt");

    if (!in.good()) // file validation
    {
        cout << "Error opening text file\n";
    }
    else
    {
        for (int i = 0; i < SIZE; i++) // for i=0 -> i=4
        {
            // read in/set title, year, and writer respectively using public setter functions
            getline(in, buf);
            temp.setTitle(buf);

            in >> ibuf;
            temp.setYear(ibuf);

            in.ignore();
            getline(in, buf);
            temp.setWriter(buf);

            movies[i] = temp; // set specific element to temporary Movie
        }
    }
    in.close();
}
