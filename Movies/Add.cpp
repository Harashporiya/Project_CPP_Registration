#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class Movie {
    string nameMovie;
public:
    Movie(string movie) {
        nameMovie = movie;
    }

    string getNameMovie() {
        return nameMovie;
    }
};

class movieManager {
    vector<Movie> namemovie;
    vector<string> DataMovies;

    void saveDataToFile() {
        ofstream file("moviedata.txt");
        if (file.is_open()) {
            for (auto &name : DataMovies) {
                file << name << endl;
            }
            file.close();
        }
    }

    void loadDataFromFile() {
        ifstream file("moviedata.txt");
        if (file.is_open()) {
            string name;
            while (getline(file, name)) {
                DataMovies.push_back(name);
                namemovie.push_back(Movie(name));
            }
            file.close();
        }
    }

public:
    movieManager() {
        loadDataFromFile();
    }

    void putNameMovies() {
        string name;
        cout << "\t\t Enter Movie Name: ";
        cin.ignore();
        getline(cin, name);
       

        Movie newname(name);
        namemovie.push_back(newname);
        DataMovies.push_back(name);
          saveDataToFile();
        cout << "\t\t Movie Added Successfully!" << endl;
    }

    void moviesList() {
        cout << "\t\t --Movies List---" << endl;
        for (int i = 0; i < namemovie.size(); i++) {
            cout << "\t\t " << namemovie[i].getNameMovie() << endl;
        }
    }

    void searchMovie(string name) {
        for (int i = 0; i < namemovie.size(); i++) {
            if (namemovie[i].getNameMovie() == name) {
                cout << "\t\t Movie Found" << endl;
                return;
            }
        }
        cout << "\t\t Movie Not Found" << endl;
    }

    void deleteMoviesName(string name) {
        for (int i = 0; i < namemovie.size(); i++) {
            if (namemovie[i].getNameMovie() == name) {
                namemovie.erase(namemovie.begin() + i);
                DataMovies.erase(DataMovies.begin() + i);
                 saveDataToFile();
                cout << "\t\t Movie Deleted Successfully" << endl;
                return;
            }
        }
        cout << "\t\t Movie Not Found" << endl;
    }
};

int main() {
    movieManager managerMovie;
    int option;
    char choice;

    do {
        cout << "\t\t1. Add Movie Name. " << endl;
        cout << "\t\t2. All Movies List. " << endl;
        cout << "\t\t3. Search Movies Name." << endl;
        cout << "\t\t4. Movies Name Delete. " << endl;
        cout << "\t\t5. Exit" << endl;
        cout << "\t\t Enter your Choice: ";
        cin >> option;

        switch (option) {
            case 1: {
                managerMovie.putNameMovies();
                break;
            }
            case 2: {
                managerMovie.moviesList();
                break;
            }
            case 3: {
                string name;
                cout << "\t\t Search Movie name: ";
                cin >> name;
                managerMovie.searchMovie(name);
                break;
            }
            case 4: {
                string name;
                cout << "\t\t Enter Movie Name to Delete: ";
                cin >> name;
                managerMovie.deleteMoviesName(name);
                break;
            }
            case 5: {
                cout << "\t\t Exiting Program." << endl;
                break;
            }
            default: {
                cout << "\t\t Invalid Option! Try Again." << endl;
            }
        }

        if (option != 5) {
            cout << "Do You Want to Continue [Yes/No] ? :";
            cin >> choice;
        } else {
            choice = 'n';
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
