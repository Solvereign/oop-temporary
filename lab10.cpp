#include "list.h"
#include "shapes.h"
#include <ctime>
#include <cstdlib>

void heading(){

    int f;
    for(f=0; f<75; f++)
        cout<<"-";
    cout<<endl;
    cout.width(10); cout<< "name";
    // cout.width(10); cout<< "Point X";
    // cout.width(10); cout<< "Point Y";
    cout.width(15); cout<< "Side/Rad";
    cout.width(15); cout<< "Area";
    cout.width(15); cout<< "Perimeter";
    cout<<endl;
    for(f=0; f<75; f++)
        cout<<"-";
    cout << endl;
}
float randomFloat() {
    return (float)(rand()) / (float)(RAND_MAX);
}

int randomInt(int a, int b) {
    if(a > b)
        return randomInt(b, a);
    else if(a == b)
        return a;
    return a + (rand()%(b - a));
}

float randomFloat(int a, int b) {
    if (a > b)
        return randomFloat(b, a);
    if (a == b)
        return a;
    return (float)randomInt(a, b) + randomFloat();
}

int main() {
    srand(time(0));
    // sanamsarguigeer 7->10 utgig butsaana
    int n = rand() % 4 + 7;
    char names[10];
    strcpy(names, "square0");
    // durwuljin dursuud nemj baina
    shape2d* t = new square(names, randomFloat(1, 4));
    list<shape2d*> dursuud(t);
    for(int i = 1; i < n; i++) {
        names[6] = i + 48;
        t = new square(names, randomFloat(1, 4));
        dursuud.add(t);
    }
    // dugui dursuud nemj baina
    n = rand() % 4 + 7;
    strcpy(names, "circle-");
    for(int i = 0; i < n; i++) {
        names[6] = i + 48;
        t = new circle(names, randomFloat(1, 4));
        dursuud.add(t);
    }
    // gurwaljin dursuud nemj baina
    n = rand() % 4 + 7;
    strcpy(names, "triangle-");
    for(int i = 0; i < n; i++) {
        names[8] = i + 48;
        t = new circle(names, randomFloat(1, 4));
        dursuud.add(t);
    }
    // niit dursiin toog n-d hadgalj baina
    n = dursuud.length();
    cout << "niit " << n << " durs baina" << endl;
    // hewlehed goy haragdana
    heading();

    while(n-->1){
        t = dursuud.get(0);
        int index = 0;
        float maxArea = t->area();

        for(int i = 1; i <= n; i++){
            shape2d* temp = dursuud.get(i);
            if(temp->area() > maxArea) {
                maxArea = temp->area();
                index = i;
                t = temp;
            }
        }

        t->show_data();
        delete t;
        dursuud.del(index);
    }
    t = dursuud.get(0);
    t->show_data();
    delete t;    
   
    return 0;
}