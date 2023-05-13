#include <iostream>
using namespace std;

class Point{
    public: 
        float x, y;
        Point(float a, float b) {
            x = a;
            y = b;
        }
        void getData() {
            cin >> x;
            cin >> y;
        }
        Point() {
            x = 0;
            y = 0;
        }
};
