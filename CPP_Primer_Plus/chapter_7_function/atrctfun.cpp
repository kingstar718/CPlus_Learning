//
// Created by wujinxing on 2019/10/29.
// 点的两种表示
//
#include <iostream>
#include <cmath>

// structure declarations
struct polar {
    double distance;
    double angle;
};

struct rect {
    double x;
    double y;
};

//prototype
polar rect_to_polar(rect xypos);
void show_polar2(const polar * pda);
void show_polar(polar dapos);

int main() {

    using namespace std;
    rect rplace;
    polar pplace;

    cout << "Enter the x and y value: ";
    while (cin >> rplace.x >> rplace.y) {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        show_polar(pplace); //传地址
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Done.\n";
    return 0;
}

//convert rectangular to polar coordinates
polar rect_to_polar(rect xypos) {
    using namespace std;
    polar answer;

    answer.distance =
            sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    answer.angle = atan2(xypos.y, xypos.x);
    return answer;
}

void show_polar(polar dapos) {
    using namespace std;
    const double Rad_to_deg = 57.29577951;

    cout << "distance = " << dapos.distance;
    cout << ", angle = " << dapos.angle * Rad_to_deg;
    cout << " degrees\n";
}

//传递结构的地址
void show_polar2(const polar * pda) {
    using namespace std;
    const double Rad_to_deg = 57.29577951;

    cout << "distance = " << pda->distance;
    cout << ", angle = " << pda->angle * Rad_to_deg;
    cout << " degrees\n";
}