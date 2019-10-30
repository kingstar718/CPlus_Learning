//
// Created by wujinxing on 2019/10/29.
//

#ifndef CPLUS_LEARNING_COORDIN_H
#define CPLUS_LEARNING_COORDIN_H

struct polar{
    double distance;
    double angle;
};

struct rect{
    double x;
    double y;
};

//prototype
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif //CPLUS_LEARNING_COORDIN_H
