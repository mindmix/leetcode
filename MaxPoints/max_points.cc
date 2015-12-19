#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
private:
    static bool sortPoints(Point &lhs, Point &rhs) {
        if (lhs.x < rhs.x)
            return true;
        else if (lhs.x > rhs.x)
            return false;

        if (lhs.y < rhs.y)
            return true;

        return false;
    }
    static bool samePoint(Point &lhs, Point &rhs) {
        if (lhs.x == rhs.x && lhs.y == rhs.y)
            return true;

        return false;
    }
    static bool oneLine(Point &p1, Point &p2, Point &p3) {
        if (p1.x == p2.x && p2.x == p3.x)
            return true;

        if (samePoint(p1, p2) || samePoint(p2, p3) || samePoint(p1, p3))
            return true;

        if (p1.x == p2.x || p1.x == p3.x || p2.x == p3.x)
            return false;

        if ((((float)p1.y - p2.y) / (p1.x - p2.x)) == (((float)p1.y - p3.y) / (p1.x - p3.x)))
            return true;

        return false;
    }
public:
    int maxPoints(vector<Point>& points) {
        vector<Point>::iterator iter;
        int **workspace = NULL;
        int num = points.size();
        int i, j, k;
        Point *p = NULL;
        int max = 1;

        if (0 == points.size())
            return 0;

        p = (Point *)malloc(num * sizeof(Point));

        sort(points.begin(), points.end(), sortPoints);

        for (iter = points.begin(), i = 0; iter != points.end(); ++iter, ++i) {
            p[i].x = iter->x;
            p[i].y = iter->y;
            //cout << iter->x << " " << iter->y << endl;
        }

        workspace = (int **)malloc(num * sizeof(int*));

        for (i = 0; i < num; ++i) {
            workspace[i] = (int *)malloc(num * sizeof(int));
        }

        for (i = 0; i < num; ++i) {
            for (j = i; j < num; ++j) {
                // we are calculating workspace[i][j]
                if (i == j) {
                    workspace[i][j] = 1;
                    continue;
                }
                
                // just i and j
                workspace[i][j] = 2;

                for (k = j - 1; k > i; --k) {
                    if (true == oneLine(p[i], p[k], p[j])) {
                        if (workspace[i][k] + 1 > workspace[i][j])
                            workspace[i][j] = workspace[i][k] + 1;
                    }
                }

                if (workspace[i][j] > max)
                    max = workspace[i][j];
            }
        }

        for (i = 0; i < num; ++i) {
            free(workspace[i]);
        }
        free(workspace);

        return max;
    }
};

int main()
{
    Solution s;
    //Point p[] = {Point(0, 0), Point(0, 3), Point(2, 1), Point(1, 2), Point(3, 5), Point(4, 3), Point(2, 5)};
    Point p[] = {Point(0, 0), Point(0, 0), Point(1, 1), Point(1, 1), Point(0, 0)};
    vector<Point> points(p, p + sizeof(p)/sizeof(p[0]));

    cout << s.maxPoints(points) << endl;

    return 0;
}

