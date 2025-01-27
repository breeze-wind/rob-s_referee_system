//
// Created by Lenovo on 25-1-5.
//

#ifndef TEAMS_H
#define TEAMS_H

#include <memory>
#include<unordered_map>
#include <vector>

#include"robots.h"

namespace my
{using uns=unsigned short;
    class robots;
    class teams
    {
        public:
        std::pmr::unordered_map<uns,std::shared_ptr<robots>> Team_Robots_All;//机器人tid映射
        std::pmr::unordered_map<uns,std::shared_ptr<robots>> Team_Robots_Survive;//存活机器人tid映射
        std::pmr::unordered_map<uns,std::shared_ptr<robots>> Team_Robots_Damaged;//阵亡机器人tid映射
        //std::pmr::vector<std::shared_ptr<robots>> Team_Robots_List_Survive;
        //std::pmr::vector<std::shared_ptr<robots>> Team_Robots_List_Damaged;
        //std::vector<bool> Team_Robots_Issurvive;
        teams()=default;
        ~teams()=default;
       //std::shared_ptr<robots>();
      // std::shared_ptr<robots>find_in_survive();//在幸存机器人中查找
       //std::shared_ptr<robots>find_in_damaged();//在阵亡机器人里找
    };

    inline std::unordered_map<my::uns,std::shared_ptr<my::teams>> TeamList;//TeamList映射

}

#endif //TEAMS_H
