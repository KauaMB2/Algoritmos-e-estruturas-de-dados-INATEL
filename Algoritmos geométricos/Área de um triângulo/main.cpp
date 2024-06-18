#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double triangleArea(const Point& p1, const Point& p2, const Point& p3) {// Function to calculate the area of a triangle using the Shoelace formula
    return 0.5 * abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
}

int main() {
    Point p1, p2, p3;
    
    // Read coordinates of the three points
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;

    // Calculate and print the area of the triangle
    double area = triangleArea(p1, p2, p3);
    cout << fixed << area << endl;

    return 0;
}
