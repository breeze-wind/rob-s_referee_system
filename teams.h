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
        std::pmr::unordered_map<uns,std::shared_ptr<robots>> robmap;//机器人tid映射
        std::pmr::unordered_map<uns,std::shared_ptr<robots>> robmap_survive;//存活机器人tid映射
        std::pmr::unordered_map<uns,std::shared_ptr<robots>> robmap_damaged;//阵亡机器人tid映射
        //std::pmr::vector<std::shared_ptr<robots>> Team_Robots_List_Survive;
        //std::pmr::vector<std::shared_ptr<robots>> Team_Robots_List_Damaged;
        //std::vector<bool> Team_Robots_Issurvive;
        teams();
        ~teams()=default;
       //std::shared_ptr<robots>();
       std::shared_ptr<robots>find_in_survive();
       std::shared_ptr<robots>find_in_damaged();
    };

    inline std::unordered_map<my::uns,std::shared_ptr<my::teams>> TeamList;//TeamList映射

}

#endif //TEAMS_H
