#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
    int x, y;
};

// Function to calculate the Euclidean distance between two points
double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    int N;
    cin >> N;
    vector<Point> points(N);
    
    // Read points of interest
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    Point user;
    cin >> user.x >> user.y;

    Point closestPoint;
    double minDistance = numeric_limits<double>::max();

    // Find the closest point to the user's location
    for (const auto& point : points) {
        double dist = distance(point, user);
        if (dist < minDistance ||
            (dist == minDistance && point.x < closestPoint.x) ||
            (dist == minDistance && point.x == closestPoint.x && point.y < closestPoint.y)) {
            minDistance = dist;
            closestPoint = point;
        }
    }

    cout << closestPoint.x << " " << closestPoint.y << endl;

    return 0;
}
