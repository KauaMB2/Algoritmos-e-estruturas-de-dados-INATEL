#include <iostream>
#include <vector>

using namespace std;

struct Point {//Struct to represent a point
    int x, y;
};

int orientation(const Point& p, const Point& q, const Point& r) {// It uses the cross product of the vectors pq and qr to determine if the points are collinear (returns 0), clockwise (returns 1), or counterclockwise (returns 2).
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);//Calculate the cross product of the vectors pq and qr
    if (val == 0){ //If they are collinear
        return 0; //Return 0;
    }
    return (val > 0) ? 1 : 2;// clockwise or counterclockwise
}

vector<Point> JarvisMarchAlgorithm(vector<Point>& points) {// Function to compute the convex hull using Jarvis March algorithm
    int n = points.size();//Get the number of points in the vector
    if (n < 3){//If there is less than 3 points
        return {}; // Convex hull not defined for less than 3 points
    }
    // Find the leftmost point
    int leftmost = 0;
    for (int i = 1; i < n; i++) {//Pass throught every point
        if (points[i].x < points[leftmost].x){//Try see if the "i" point in more to the left than the current "leftmost". If it is...
            leftmost = i;//Define a new "leftmost" point
        }
    }

    vector<Point> convexHullPoints;//Variable to storage the Convex Hull Points
    int p = leftmost;//Define a "p" value
    int q;//Define a variable to pass throught the vector
    do {
        convexHullPoints.push_back(points[p]);//Add the current point p in the hull
        q = (p + 1) % n;//"q" is set to the next point in the list (cyclically, using % n).
        // If p = 0, then q = (0 + 1) % n = 1
        // If p = 1, then q = (1 + 1) % n = 2
        // If p = 2, then q = (2 + 1) % n = 3
        // If p = 3, then q = (3 + 1) % n = 4
        for (int i = 0; i < n; i++) {//checks if every point "i" is more counterclockwise than point "q" relative to the point "p"...
            if (orientation(points[p], points[i], points[q]) == 2){//If so, "q" is updated to "i"...
                q = i;//Update "q" to "i"
            }
        }
        p = q;//Define a new "p" value as beeing the current "q" value
        // If q = 1, then p = 1
        // If q = 2, then p = 2
        // If q = 3, then p = 3
        // If q = 4, then p = 4
    } while (p != leftmost);// While the current point "p" isn't the "leftmost" point...

    return convexHullPoints;//Return the convexHullPoints
}

int main() {
    // Example usage
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};//Define the points
    vector<Point> convexHullPoints = JarvisMarchAlgorithm(points);//Call the algorithm

    // Print the convex hull points
    cout << "Convex Hull Points:" << endl;
    for (const auto& point : convexHullPoints) {
        cout << "(" << point.x << ", " << point.y << ")" << endl;
    }

    return 0;
}
