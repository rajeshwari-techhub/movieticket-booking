
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string selectedMovie = "";
int selectedPrice = 0;

struct Movie {
    string name;
    string industry;
    int price;
};

void recommend(string genre) {
    transform(genre.begin(), genre.end(), genre.begin(), ::tolower);

    vector<Movie> movies;

    // COMEDY - 10 MOVIES
    if (genre == "comedy") {
        movies = {
            {"Panchatanthiram", "South Indian", 180},
            {"Bangalore Days", "South Indian", 190},
            {"F2: Fun and Frustration", "South Indian", 200},
            {"3 Idiots", "Hindi", 180},
            {"Hera Pheri", "Hindi", 160},
            {"Munna Bhai M.B.B.S.", "Hindi", 170},
            {"Home Alone", "Hollywood", 150},
            {"Jumanji", "Hollywood", 200},
            {"The Mask", "Hollywood", 190},
            {"Mr. Bean's Holiday", "Hollywood", 170}
        };
    }

    // ACTION - 10 MOVIES
    else if (genre == "action") {
        movies = {
            {"RRR", "South Indian", 250},
            {"KGF: Chapter 2", "South Indian", 260},
            {"Vikram", "South Indian", 240},
            {"Pushpa: The Rise", "South Indian", 230},
            {"War", "Hindi", 250},
            {"Pathaan", "Hindi", 240},
            {"Dhoom 2", "Hindi", 200},
            {"John Wick", "Hollywood", 250},
            {"The Dark Knight", "Hollywood", 270},
            {"Mission: Impossible - Fallout", "Hollywood", 280}
        };
    }

    // LOVE STORY - 10 MOVIES
    else if (genre == "love story" || genre == "love") {
        movies = {
            {"Sita Ramam", "South Indian", 200},
            {"Geetha Govindam", "South Indian", 180},
            {"96", "South Indian", 190},
            {"Jab We Met", "Hindi", 180},
            {"Veer-Zaara", "Hindi", 190},
            {"Aashiqui 2", "Hindi", 200},
            {"Yeh Jawaani Hai Deewani", "Hindi", 220},
            {"The Notebook", "Hollywood", 200},
            {"Titanic", "Hollywood", 250},
            {"La La Land", "Hollywood", 210}
        };
    }

    // SCI-FI - 10 MOVIES
    else if (genre == "sci-fi" || genre == "sci fi") {
        movies = {
            {"Kalki 2898 AD", "South Indian", 300},
            {"2.0", "South Indian", 250},
            {"24", "South Indian", 220},
            {"Koi Mil Gaya", "Hindi", 180},
            {"Krrish", "Hindi", 200},
            {"Ra.One", "Hindi", 210},
            {"Interstellar", "Hollywood", 280},
            {"Inception", "Hollywood", 250},
            {"The Matrix", "Hollywood", 240},
            {"Avatar", "Hollywood", 300}
        };
    }

    // HORROR - 10 MOVIES
    else if (genre == "horror") {
        movies = {
            {"Arundhati", "South Indian", 220},
            {"Bhoothakaalam", "South Indian", 200},
            {"Maya", "South Indian", 190},
            {"Stree", "Hindi", 200},
            {"Bhool Bhulaiyaa", "Hindi", 190},
            {"Tumbbad", "Hindi", 220},
            {"The Conjuring", "Hollywood", 230},
            {"IT", "Hollywood", 220},
            {"The Exorcist", "Hollywood", 200},
            {"A Quiet Place", "Hollywood", 240}
        };
    }

    // FANTASY - 10 MOVIES
    else if (genre == "fantasy") {
        movies = {
            {"Baahubali: The Beginning", "South Indian", 250},
            {"Baahubali 2: The Conclusion", "South Indian", 280},
            {"Magadheera", "South Indian", 220},
            {"Brahmastra", "Hindi", 250},
            {"Paheli", "Hindi", 180},
            {"Bajirao Mastani", "Hindi", 230},
            {"Harry Potter and the Philosopher's Stone", "Hollywood", 250},
            {"The Lord of the Rings", "Hollywood", 280},
            {"The Chronicles of Narnia", "Hollywood", 240},
            {"Fantastic Beasts", "Hollywood", 250}
        };
    }

    // HISTORICAL - 10 MOVIES
    else if (genre == "historical") {
        movies = {
            {"Ponniyin Selvan: I", "South Indian", 250},
            {"Ponniyin Selvan: II", "South Indian", 260},
            {"Sye Raa Narasimha Reddy", "South Indian", 240},
            {"Jodhaa Akbar", "Hindi", 220},
            {"Kesari", "Hindi", 210},
            {"Samrat Prithviraj", "Hindi", 200},
            {"The Legend of Bhagat Singh", "Hindi", 190},
            {"Gladiator", "Hollywood", 260},
            {"Braveheart", "Hollywood", 240},
            {"Kingdom of Heaven", "Hollywood", 250}
        };
    }

    // THRILLER - 10 MOVIES
    else if (genre == "thriller") {
        movies = {
            {"Drishyam", "South Indian", 200},
            {"Ratsasan", "South Indian", 210},
            {"Evaru", "South Indian", 190},
            {"Andhadhun", "Hindi", 200},
            {"Kahaani", "Hindi", 180},
            {"Talaash", "Hindi", 190},
            {"Badla", "Hindi", 200},
            {"Shutter Island", "Hollywood", 230},
            {"Gone Girl", "Hollywood", 220},
            {"Se7en", "Hollywood", 210}
        };
    }

    else {
        cout << "\nGenre not found! Please try again.\n";
        return;
    }

    // SELECT FILM INDUSTRY
    string industry;
    cout << "\nSelect Film Industry:\n";
    cout << "1. South Indian\n";
    cout << "2. Hindi\n";
    cout << "3. Hollywood\n";
    cout << "Enter your choice: ";
    int industryChoice;
    cin >> industryChoice;

    if (industryChoice == 1)
        industry = "South Indian";
    else if (industryChoice == 2)
        industry = "Hindi";
    else if (industryChoice == 3)
        industry = "Hollywood";
    else {
        cout << "Invalid industry choice!\n";
        return;
    }

    // DISPLAY MATCHING MOVIES
    cout << "\nRecommended " << genre << " Movies:\n";

    int number = 1;
    for (const Movie &m : movies) {
        if (m.industry == industry) {
            cout << number << ". " << m.name
                 << " - Rs. " << m.price << endl;
            number++;
        }
    }

    // SELECT MOVIE
    int choice;
    cout << "\nSelect a movie (1-" << number - 1 << "): ";
    cin >> choice;

    if (choice < 1 || choice >= number) {
        cout << "Invalid movie choice!\n";
        return;
    }

    number = 1;
    for (const Movie &m : movies) {
        if (m.industry == industry) {
            if (number == choice) {
                selectedMovie = m.name;
                selectedPrice = m.price;
                break;
            }
            number++;
        }
    }

    cout << "\nYou selected: " << selectedMovie << endl;
    cout << "Ticket Price: Rs. " << selectedPrice << endl;
}
