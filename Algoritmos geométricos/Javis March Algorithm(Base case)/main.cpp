#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

// Utility function to find the orientation of triplet (p, q, r)
int orientation(const Point& p, const Point& q, const Point& r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;    // collinear
    return (val > 0) ? 1 : 2;  // clockwise or counterclockwise
}

// Function to compute the convex hull using Jarvis March algorithm
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {}; // Convex hull not defined for less than 3 points

    // Find the leftmost point
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x)
            leftmost = i;
    }

    vector<Point> hull;
    int p = leftmost, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;
    } while (p != leftmost);

    return hull;
}

int main() {
    // Example usage
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    vector<Point> convexHullPoints = convexHull(points);

    // Print the convex hull points
    cout << "Convex Hull Points:" << endl;
    for (const auto& point : convexHullPoints) {
        cout << "(" << point.x << ", " << point.y << ")" << endl;
    }

    return 0;
}
