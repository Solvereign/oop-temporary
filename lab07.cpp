#include "shapes.h"
// #include <iostream>

// using namespace std;

int main() {
    // durs bur hed orohig iltgene
    int count = 2;
    // n - niit heden durs baigaa we
    int n = count * 3;
    shape2d **sh = new shape2d*[n];
    
    // current - heden durs oruulsnig hadgalna
    int current = 0;
    // ehnii 2 dursiig durwuljin bolgoj baina
    for(int i = 0; i < count; i++) {
        sh[i+current] = new square;
    }
    current += count;
    //daraagiin 2 durs gurwaljin
    for(int i = 0; i < count; i++) {
        sh[i+current] = new eqTriangle;
    }
    current += count;
    // suuliin 2 durs toirog
    for(int i = 0; i < count; i++) {
        sh[i+current] = new circle;
    }
    // bugdiinh ni utgig awch baina 
    for(int i = 0; i < n; i++)
        // get_data turdee oroinuudin medeellig awahgui baigaa
        sh[i]->get_data();
    
    // talbaigaar erembelew
    for(int i =0; i < n-1; i++) {
        for(int j = 0; j<n-i-1; j++) {
            if(sh[j]->area() < sh[j+1]->area()) {
                shape2d *temp;
                temp = sh[j];
                sh[j] = sh[j+1];
                sh[j+1] = temp;
            }
        }
    }
    // erembelsnee delgetslew
    for(int i = 0; i < n; i++) {
        // show_data turdee oroinuud, perimetriig haruulahgui baigaa
        sh[i]->show_data();
    }
       
    for(int i = n-1; i >=0 ; i--) {
        delete sh[i];
    }
   delete []sh;

    return 0;
}