#include "shapes.h"
// #include <iostream>

// using namespace std;

int main() {
    // cout << shape::get_count() << endl;

    // niit 6 durs baigaa
    int n = 6;
    shape2d **sh = new shape2d*[n];

    sh[0] = new square("sq1", 3, 0, 0);
    sh[1] = new square("sq2", 2.5, 0, 0);
    sh[2] = new eqTriangle("tr1", 4, 0, 0);
    sh[3] = new eqTriangle("tr2", 3, 0, 0);
    sh[4] = new circle("circ1", 1.5, 0, 0);
    sh[5] = new circle("circ2", 2.5, 0, 0);
    
    // // talbaigaar erembelew
    // for(int i =0; i < n-1; i++) {
    //     for(int j = 0; j<n-i-1; j++) {
    //         if(sh[j]->area() < sh[j+1]->area()) {
    //             shape2d *temp;
    //             temp = sh[j];
    //             sh[j] = sh[j+1];
    //             sh[j+1] = temp;
    //         }
    //     }
    // }
    // // erembelsnee delgetslew
    // cout << "\ttalbaigaar erembelsen: " << endl;
    // for(int i = 0; i < n; i++) {
    //     sh[i]->show_data();
    // }

    // perimetreer erembelew
    for(int i =0; i < n-1; i++) {
        for(int j = 0; j<n-i-1; j++) {
            if(sh[j]->perimeter() < sh[j+1]->perimeter()) {
                shape2d *temp;
                temp = sh[j];
                sh[j] = sh[j+1];
                sh[j+1] = temp;
            }
        }
    }
    // erembelsnee delgetslew
    cout << "\tperimetreer erembelsen: " << endl;
    for(int i = 0; i < n; i++) {
        sh[i]->show_data();
    }
       
    for(int i = n-1; i >=0 ; i--) {
        delete sh[i];
    }
   delete []sh;

    return 0;
}