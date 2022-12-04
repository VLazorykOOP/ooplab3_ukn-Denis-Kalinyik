#include <iostream>
#include <math.h>
 
using namespace std;
 
class triangle {
    int a, b, c;
public:
    triangle(int a1, int b1, int c1) {
        a = a1;
        b = b1;
        c = c1;
    }
    bool exist();
    int perimetr();
    double square();
    void print();
    triangle operator++();
    triangle operator--();
};
 
bool triangle::exist() {
    return a < b + c && b < a + c && c < b + a;
}
 
int triangle::perimetr() {
    return a + b + c;
}
 
double triangle::square() {
    double p = perimetr()/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
void triangle::print() {
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "Perimetr = " << perimetr() << endl;
    cout << "Ploshad = " << square() << endl;
}
 
triangle triangle::operator++() {
    ++a;
    ++b;
    ++c;
    return *this;
}
 
triangle triangle::operator--() {
    --a;
    --b;
    --c;
    return *this;
}


 
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    cin >> a;
    cin >> b;
    cin >> c;
 
    triangle trianglep(a,b,c);
    ++trianglep;
    trianglep.print();
    system("pause");
}
