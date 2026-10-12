
#include <iostream>
#include <string>
using namespace std;

class Movie {
public:
    string name, genre;
    float rating;

    Movie(string n, string g, float r) {
        name = n;
        genre = g;
        rating = r;
    }

    void display() {
        cout << name << " | "
             << genre << " | Rating: "
             << rating << "/10" << endl;
    }
};
