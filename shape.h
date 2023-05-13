#include <cstring>
#include <iostream>
using namespace std;

class shape {
    protected: 
        static int count;
        char *name;

    public: 
        shape() {
            this->name = new char[4];
            strcpy(this->name, "durs");
            count++;
            cout << "there are " << count << " objects" << endl;
        }
        ~shape() {
            delete name;
            count--;
            // cout << count << " objects left" << endl;
        }
        shape(const char *n) {
            this->name = new char[strlen(n)+1];
            strcpy(this->name, n);
            count++;
            // cout << "there are " << count << " objects" << endl;
        }

        virtual void show_data() {
            cout.width(10); cout<< this -> name;
            // cout << "ner: " << this->name << endl;
        }
        // heden object baigaag butsaana
        static int get_count() {
            return count;
        }
        // count static huwisagchiin utgig uurchluh hereg?
        // static void set_count(int a) {
        //     count = a;
        // }

};

int shape::count = 0;