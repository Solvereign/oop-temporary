#include <iostream>
#include <vector>
#include "shapes.h"
using namespace std;

int main()
{
	vector<shape> dursuud;
	circle c1, c2;
	eqTriangle t1, t2;
	square s1, s2;
	dursuud.push_back(c1); 
	cout << dursuud.size();
	dursuud.push_back(c2); 
	cout << dursuud.size();
	dursuud.push_back(t1); 
	cout << dursuud.size();
	dursuud.push_back(t2); 
	cout << dursuud.size();
	dursuud.push_back(s1); 
	cout << dursuud.size();
	dursuud.push_back(s2);
	cout << dursuud.size();
	return 0;
}