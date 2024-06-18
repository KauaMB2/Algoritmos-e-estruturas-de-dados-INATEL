#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

bool onSegment(Point p, Point q, Point r) {// Function to check if a point lies on a segment
    //Verify if the X value of the Q point is inside the X variation of the segment PR and verify if the Y value of the Q point is inside the Y variation of the segment PR
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)){
        return true;//Return true if the Q point lies the segment PR
    }
    return false;//Return false if the Q point don't lies the segment PR
}

// Function to find the orientation of the ordered triplet (p, q, r)
// Returns:
// 0 if points are collinear
// 1 if they form a counterclockwise turn
// 2 if they form a clockwise turn
int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);//Apply the cross product between P, Q and R points
    if (val == 0) return 0;    // collinear
    return (val > 0) ? 1 : 2;  // clockwise(1) or counterclockwise(2)
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {// Function to check if two segments intersect
    // Find the four orientations needed for general and special cases
    int orientation1 = orientation(p1, q1, p2);
    int orientation2 = orientation(p1, q1, q2);
    int orientation3 = orientation(p2, q2, p1);
    int orientation4 = orientation(p2, q2, q1);

    // General case
    if ((orientation1 != orientation2) && (orientation3 != orientation4)){//Check if there are segments that intersect between themself
        return true;//Intersect
    }
    
    // Special Cases
    //Intersecção de Caso Especial: Quando p2 está no segmento p1q1, indica que p2 é um ponto de sobreposição entre os segmentos p1q1 e p2q2. Como p2 é um ponto comum em ambos os segmentos, isso implica que eles se cruzam em p2.
    if (orientation1 == 0 && onSegment(p1, p2, q1)){// p1, q1 and p2 are collinear and p2 lies on segment p1q1
        return true;
    }
    if (orientation2 == 0 && onSegment(p1, q2, q1)){// p1, q1 and q2 are collinear and q2 lies on segment p1q1
        return true;
    }
    if (orientation3 == 0 && onSegment(p2, p1, q2)){// p2, q2 and p1 are collinear and p1 lies on segment p2q2
        return true;
    }
    if (orientation4 == 0 && onSegment(p2, q1, q2)){// p2, q2 and q1 are collinear and q1 lies on segment p2q2
        return true;
    }
    return false; // Doesn't fall in any of the above cases
}

bool isInsidePolygon(vector<Point>& polygon, Point p){// Function to check if a point is inside a polygon
    int n = polygon.size();//Get the number of points of the polygon
    if (n < 3){// A polygon must have at least 3 vertices
        return false;
    }

    // Create a point for the ray
    Point extreme = {1001, p.y}; // A point far outside the polygon

    // Count intersections of the above ray with the sides of the polygon
    int count = 0, i = 0;
    do {
        int next = (i + 1) % n;
        if (doIntersect(polygon[i], polygon[next], p, extreme)) {// Check if the ray intersects with the polygon edge
            if (orientation(polygon[i], p, polygon[next]) == 0){// Check if the point is collinear with the polygon edge
                return onSegment(polygon[i], p, polygon[next]);
            }
            count++;
        }
        i = next;
    } while (i != 0);

    // Return true if count is odd, false otherwise
    return count % 2 == 1;
}

int main() {
    int n;
    cin >> n;
    vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }
    Point p;
    cin >> p.x >> p.y;

    if (isInsidePolygon(polygon, p))
        cout << "DENTRO" << endl;
    else
        cout << "!(DENTRO)" << endl;

    return 0;
}
