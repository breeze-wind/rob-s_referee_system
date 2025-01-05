//
// Created by Lenovo on 25-1-1.
//

#include "robots.h"
#include "teams.h"
namespace my
{
    Infantry_Robots_1::Infantry_Robots_1(uns team,uns tid):robots(team,tid)
    {
        Infantry_Robots_1::Blood_Ceiling = 100;
        Infantry_Robots_1::Heat_Ceiling = 100;
        blood(this->Blood_Ceiling);
    }

    Construction_Robots::Construction_Robots(uns team,uns tid):robots(team,tid)
    {
        Construction_Robots::Blood_Ceiling = 300;
        Construction_Robots::Heat_Ceiling = 0;
        blood(Blood_Ceiling);
    }

    Infantry_Robots_2::Infantry_Robots_2(uns team,uns tid):robots(team,tid)
    {
        Infantry_Robots_2::Blood_Ceiling = 150;
        Infantry_Robots_2::Heat_Ceiling = 200;
        blood(this->Blood_Ceiling);
    }

    Infantry_Robots_3::Infantry_Robots_3(uns team,uns tid):robots(team,tid)
    {
        Infantry_Robots_3::Blood_Ceiling = 250;
        Infantry_Robots_3::Heat_Ceiling = 300;
        blood(this->Blood_Ceiling);
    }

    uns robots::blood()
    {
        return Blood_Count;
    }

    uns robots::heat()
    {
        return Heat_Count;
    }
    void robots::blood(uns blood)
    {
        Blood_Count = blood;
    }
    void robots::heat(uns heat)
    {
        Heat_Count = heat;
    }
    robots::robots(uns Team,uns tid)
    {
        Heat_Count=0;//热量初始为0
        team = Team;//队伍名
        team_id = tid;//机器人标识符
        auto p=TeamList.find(Team);
        if(p==TeamList.end()||TeamList.empty())//检查有无该队名，若没有则创建新队伍
        {
            std::shared_ptr<teams> p=std::make_shared<teams>();//加入teamlist映射
            auto q=std::make_pair(Team,p);
            TeamList.insert(q);

        }
        std::shared_ptr<robots> r=tothis;
       mymanage.Robots_List_ALL.push_back(r);//机器人列表里加上这个机器人
       // TeamList[Team]->Team_Robots_List_Survive.push_back(r);//存活列表里加机器人
        auto q=std::make_pair(tid,r);
        TeamList[Team]->robmap.insert(q);//加入tid的映射
        TeamList[Team]->robmap_survive.insert(q);
        TeamList[Team]->robmap_damaged.insert(q);
    }
    robots::~robots()
    {
      // mymanage.Robots_List_ALL.;

    }

    // robots::robots(uns heat,uns Team,uns tid)//已废弃
    // {
    //     Heat_Count=heat;
    //     team = Team;
    //
    //     Blood_Count=this->Blood_Count;
    // }




} // my
