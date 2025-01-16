//
// Created by Lenovo on 25-1-5.
//

#ifndef MANAGE_H
#define MANAGE_H
#include <memory>
#include <vector>
#include"robots.h"
#include"teams.h"
namespace my {
class robots;

class manage {
public:

     std::pmr::vector<std::shared_ptr<robots>> Robots_List_ALL;//存所有的机器人的指针的数组
};
inline manage mymanage;
} // my

#endif //MANAGE_H
