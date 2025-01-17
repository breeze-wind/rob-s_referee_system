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

     std::pmr::vector<std::shared_ptr<robots>> Robots_List_Survive;//存所有的存活机器人的指针的数组
     //std::pmr::vector<std::shared_ptr<robots>> Robots_List_Damaged;//阵亡机器人指针
};
inline manage mymanage;

} // my

#endif //MANAGE_H
