#include <stdio.h>

// Define the line segment endpoints
struct Point {
    int x, y;
};

// Define the clipping window corners
struct Window {
    struct Point topLeft;
    struct Point bottomRight;
};

// Function to determine which region a point lies in
int getRegion(struct Point p, struct Window w) {
    int region = 0;
    if (p.x < w.topLeft.x) {
        region |= 1;  // Bitwise OR operator to set the first bit to 1
    }
    if (p.x > w.bottomRight.x) {
        region |= 2;  // Bitwise OR operator to set the second bit to 1
    }
    if (p.y < w.topLeft.y) {
        region |= 4;  // Bitwise OR operator to set the third bit to 1
    }
    if (p.y > w.bottomRight.y) {
        region |= 8;  // Bitwise OR operator to set the fourth bit to 1
    }
    return region;
}

// Function to clip the line segment to the clipping window
void clipLine(struct Point p1, struct Point p2, struct Window w) {
    int region1 = getRegion(p1, w);
    int region2 = getRegion(p2, w);
    int accept = 0;
    while (1) {
        if (!(region1 | region2)) {
            // Both endpoints are inside the clipping window
            accept = 1;
            break;
        } else if (region1 & region2) {
            // Both endpoints are outside the clipping window
            break;
        } else {
            // One endpoint is inside and the other is outside
            struct Point p;
            int region = region1 ? region1 : region2;
            if (region & 1) {
                // Intersection with the left edge
                p.y = p1.y + (p2.y - p1.y) * (w.topLeft.x - p1.x) / (p2.x - p1.x);
                p.x = w.topLeft.x;
            } else if (region & 2) {
                // Intersection with the right edge
                p.y = p1.y + (p2.y - p1.y) * (w.bottomRight.x - p1.x) / (p2.x - p1.x);
                p.x = w.bottomRight.x;
            } else if (region & 4) {
                // Intersection with the top edge
                p.x = p1.x + (p2.x - p1.x) * (w.topLeft.y - p1.y) / (p2.y - p1.y);
                p.y = w.topLeft.y;
            } else if (region & 8) {
                // Intersection with the bottom edge
                p.x = p1.x + (p2.x - p1.x) * (w.bottomRight.y - p1.y) / (p2.y - p1.y);
                p.y = w.bottomRight.y;
            }
            if (region == region1) {
                p1 = p;
                region1 = getRegion(p1, w);
            } else {
                p2 = p;
                region2 = getRegion(p2, w);
            }
        }
    }
    if (accept) {
        printf("Line segment (%d,%d)-(%d,%d) clipped to window (%d,%d)-(%d,%d)\n",
               p1.x, p1.y,p2.x,p2.y);
    }}
