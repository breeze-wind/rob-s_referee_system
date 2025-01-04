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
{
    class teams
    {
        public:
        std::pmr::unordered_map<int, uns> robmap;
        std::pmr::vector<std::shared_ptr<robots>> Team_Robots_List_ALL;
        std::pmr::vector<std::shared_ptr<robots>> Team_Robots_List_Survive;
        std::pmr::vector<std::shared_ptr<robots>> Team_Robots_List_Damaged;
        //std::vector<bool> Team_Robots_Issurvive;
        teams();
        ~teams()=default;
       std::shared_ptr<robots>();
       std::shared_ptr<robots>rvive();
       std::shared_ptr<robots>maged();
    };
}

#endif //TEAMS_H
