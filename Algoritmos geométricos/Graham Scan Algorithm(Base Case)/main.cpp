#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

// Utility function to find the orientation of triplet (p, q, r)
// Returns:
// 0 if points are collinear
// 1 if they form a counterclockwise turn
// 2 if they form a clockwise turn
int orientation(const Point& p, const Point& q, const Point& r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;    // collinear
    return (val > 0) ? 1 : 2;  // counterclockwise or clockwise
}

// Utility function to compare points based on polar angle
bool compare(const Point& p1, const Point& p2) {
    // Calculate orientation of triplet (p, p1, p2)
    // Points are sorted based on their polar angle with respect to the lowest point
    // If they have the same polar angle, the one closer to the lowest point comes first
    int o = orientation({0, 0}, p1, p2);
    if (o == 0) {
        // If collinear, sort based on distance from the lowest point
        return (p1.x * p1.x + p1.y * p1.y) < (p2.x * p2.x + p2.y * p2.y);
    }
    return o == 1; // counterclockwise
}

// Function to compute the convex hull using Graham Scan algorithm
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {}; // Convex hull not defined for less than 3 points

    // Find the lowest point (lexicographically smallest, or leftmost bottommost point)
    Point lowest = points[0];
    for (int i = 1; i < n; i++) {
        if (points[i].y < lowest.y || (points[i].y == lowest.y && points[i].x < lowest.x)) {
            lowest = points[i];
        }
    }

    // Sort points based on polar angle with respect to the lowest point
    sort(points.begin(), points.end(), compare);

    // Initialize stack for storing convex hull
    vector<Point> convexHull;
    convexHull.push_back(points[0]);
    convexHull.push_back(points[1]);

    // APPLY THE GRAHAM ALGORITHM
    for (int i = 2; i < n; i++) {
        //(orientation(hull[hull.size() - 2], hull.back(), points[i]) != 1): Checks if the orientation of the triplet (fecho[fecho.size() - 2], fecho.back(), pontos[i]) is not counterclockwise. If it's not counterclockwise, it means the last point can be deleted of the vector, because the current point and the penultimate point can be connected.
        while (orientation(convexHull[convexHull.size() - 2], convexHull.back(), points[i]) != 1) {// Keep removing points from the stack while the orientation is not counterclockwise
            convexHull.pop_back();//Remove the last element(Point that have a clockwise connection to the current point)
        }
        convexHull.push_back(points[i]); // Add the current point to the convex hull
    }

    return convexHull;
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
