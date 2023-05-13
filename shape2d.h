#include "shape.h"
#include "point.h"
// #include <iostream>
class shape2d: public shape {
    // protected:
    public: 
        float l;

    // public: 
        virtual float area() = 0;
        //  {
        //     return l*l;
        // }

        virtual float perimeter() = 0;
        //  {
        //     return l;
        // }
        
        virtual void get_data() {
            cout << "insert name: ";
            char temp[20];
            cin >> temp;
            delete name;
            this->name = new char(strlen(temp) + 1);
            strcpy(this->name, temp);
            cout << "insert l: ";
            cin >> l;
        }
        virtual void show_data() {
            shape::show_data();
            // cout << "ner: " << this->name << endl;
            cout.width(15); cout<< this->l;
            cout.width(15); cout<< this->area();
            cout.width(15); cout<< this->perimeter();
            cout << endl;
            // cout << "l: " << this->l << endl;
            // cout << "talbai: " << this->area() << endl;
            // cout << "perimeter: " << this->perimeter() << endl;
        }
        shape2d() : shape("2dshape") {
            // strcpy(name, "2dshape");
            l = 0;
        }
        shape2d(const char n[], float k) : shape(n){
            this->l = k;
        }
};
