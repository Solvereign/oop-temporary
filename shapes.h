// #include <iostream>
#include "shape2d.h"
#include <cmath>
// #include <cstring>
// using namespace std;

class square: public shape2d {
    protected: 
        Point vertex[4];
        
        //ehnii oroi, l medegdsen uyd busad oroig olno
        void calcVertex() {
            this->vertex[1].x = this->vertex[0].x + l/2;
            this->vertex[1].y = this->vertex[0].y;
            this->vertex[2].x = this->vertex[0].x;
            this->vertex[2].y = this->vertex[0].y - l/2;
            this->vertex[3].x = this->vertex[0].x + l/2;
            this->vertex[3].y = this->vertex[0].y - l/2;
        }

    public:
        //default constructor
        square() : shape2d("mySquare", 5) {
            // strcpy(name, "mySquare");
            this->vertex[0].x = 0;
            this->vertex[0].y = 0;
            this->calcVertex();
        }
        //parametered constructor
        square(const char n[], float f, float x, float y) : shape2d(n, f) {
            this->vertex[0].x = x;
            this->vertex[0].y = y;
            this->calcVertex();
        }
        square(const char n[], float f) : shape2d(n, f) {
            this->vertex[0].x = 0;
            this->vertex[0].y = 0;
            this->calcVertex();
        }
        //perimeter butsaana
        float perimeter() {
            return this->l*4;
        }
        // talbaig butsaana
        float area() {
            return this->l*this->l;
        }
        //medeelliig delgetslene
        void show_data() {
            // cout << "ner: " << this->name <<  endl; hereggui 
            // cout << "turul: durwuljin" << endl;
            shape2d::show_data();
            // cout << "oroi1: (" << this->vertex[0].x << ", " << this->vertex[0].y << ")" << endl;
            // cout << "oroi2: (" << this->vertex[1].x << ", " << this->vertex[1].y << ")" << endl;
            // cout << "oroi3: (" << this->vertex[2].x << ", " << this->vertex[2].y << ")" << endl;
            // cout << "oroi4: (" << this->vertex[3].x << ", " << this->vertex[3].y << ")" << endl;
            // cout << "talbai: " << this->area() << endl;
            // cout << "perimeter: " << this->perimeter() << endl;
        } 
        //zuun deed oroin bairshlig awdag
        void getFirst() {
            cout << "zuun deed oroin coord: " ;
            this->vertex[0].getData() ;
            this->calcVertex();
        }

        //dursiin medeelliig awdag
        void get_data() {
            cout << "durwuljin durs" << endl;
            shape2d::get_data();
            // getFirst();
        }

};

class eqTriangle: public shape2d {
    protected: 
        Point vertex[3];
        
        //deed oroi medegdsen bol busad oroi olno
        void calcVertex() {
            this->vertex[1].x = this->vertex[0].x - l/2;
            this->vertex[2].x = this->vertex[0].x + l/2;
            float h = l*sqrt(3)/2;
            this->vertex[1].y = this->vertex[0].y - h;
            this->vertex[2].y = this->vertex[0].y - h; 
        }

    public:
        //default constructor
        eqTriangle() : shape2d("gurwalj", 5){
            this->vertex[0].x = 0;
            this->vertex[0].y = 0;
            this->calcVertex();
        }
        // parameterd constructor
        eqTriangle(const char n[], float l, float x, float y) : shape2d(n, l){
            this->vertex[0].x = x;
            this->vertex[0].y = y;
            this->calcVertex();
        }
        eqTriangle(const char n[], float l) : shape2d(n, l){
            this->vertex[0].x = 0;
            this->vertex[0].y = 0;
            this->calcVertex();
        }
        float area() {
            return this->l*this->l*sqrt(3)/4;
        }
        float perimeter() {
            return this->l*3;
        }

        void show_data() {
            // cout << "turul: gurwaljin" << endl;
            shape2d::show_data();
            // cout << "oroi1: (" << this->vertex[0].x << ", " << this->vertex[0].y << ")" << endl;
            // cout << "oroi2: (" << this->vertex[1].x << ", " << this->vertex[1].y << ")" << endl;
            // cout << "oroi3: (" << this->vertex[2].x << ", " << this->vertex[2].y << ")" << endl;
            // doorh 2 shape2d::show_data()-d baigaa
            // cout << "talbai: " << area() << endl; end anhaar
            // cout << "perimeter: " << perimeter() << endl;
        } 
        void get_data() {
            cout << "gurwaljin durs" << endl;
            shape2d::get_data();
            // getFirst();
        }
        void getFirst() {
            cout << "gurwaljni deed oroin coord: ";
            this->vertex[0].getData() ;
            calcVertex();
        }

};

class circle: public shape2d {
    protected:
        Point center;
        
    public:
         // default constructor:
        circle() : shape2d("tugsuu", 5) {
            this->center.x = 0;
            this->center.y = 0;
        }
        // parametered constructor:
        circle(const char n[], float l, float x, float y) : shape2d(n, l) {
            this->center.x = x;
            this->center.y = y;
        }
        circle(const char n[], float l) : shape2d(n, l) {
            this->center.x = 0;
            this->center.y = 0;
        }
        float perimeter() {
            return 2*this->l*3.14;
        }
        float area() {
            return 3.14*this->l*this->l;
        }
        void show_data() {
            // cout << "turul: dugui" << endl;
            // cout << "ner: " << this->name << endl; hereggui
            shape2d::show_data();
            // cout << "tuw: (" << this->center.x << ", " << this->center.y << ")" << endl;
            // cout << "talbai: " << this->area() << endl;
            // cout << "perimeter: " << this->perimeter() << endl;
        }

        void get_data() {
            cout << "dugui durs" << endl;
            shape2d::get_data();
            // cout << "duguin tuwiin coord: " ;
            // center.getData();
        }
};