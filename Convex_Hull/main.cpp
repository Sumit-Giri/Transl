#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_3 Point_3;

// Utility function to find the next point in the convex hull
int next_point(const std::vector<Point_3>& points, int curr, int n) {
    int next = (curr + 1) % n;
    for (int i = 0; i < n; i++) {
        if (CGAL::orientation(points[curr], points[next], points[i]) == CGAL::LEFT_TURN)
            next = i;
    }
    return next;
}

// Gift Wrapping algorithm for 3D convex hull
std::vector<Point_3> gift_wrapping(const std::vector<Point_3>& points) {
    int n = points.size();
    if (n < 4) {
        std::cerr << "Convex hull not possible with less than 4 points." << std::endl;
        return std::vector<Point_3>();
    }

    // Find the leftmost point (lowest x-coordinate)
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x() < points[leftmost].x())
            leftmost = i;
    }

    int p = leftmost;
    std::vector<Point_3> convex_hull;
    std::stack<int> stack;

    do {
        convex_hull.push_back(points[p]);
        int q = next_point(points, p, n);
        p = q;
    } while (p != leftmost);

    return convex_hull;
}

int main() {
    std::vector<Point_3> points;
    // Add your 3D points here
    points.push_back(Point_3(0, 0, 0));
    points.push_back(Point_3(1, 0, 0));
    points.push_back(Point_3(0, 1, 0));
    points.push_back(Point_3(0, 0, 1));

    std::vector<Point_3> convex_hull = gift_wrapping(points);

    std::cout << "Convex Hull vertices:" << std::endl;
    for (const auto& point : convex_hull) {
        std::cout << point << std::endl;
    }

    return 0;
}
