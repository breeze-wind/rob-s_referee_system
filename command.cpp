//
// Created by Lenovo on 25-1-16.
//

#include "command.h"

#include <iostream>

#include "teams.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace my
{
    command::command() //创建该类代表流程开始
    {
        time = 0;
        uns cmd_nums = 0;
        std::cin >> cmd_nums;
        timecode = std::make_shared<uns[]>(cmd_nums);
        parameter1 = std::make_shared<uns[]>(cmd_nums);
        parameter2 = std::make_shared<uns[]>(cmd_nums);
        parameter3 = std::make_shared<uns[]>(cmd_nums);
        cmdcodes = std::make_shared<char[]>(cmd_nums); //给指令存储库分配空间
        // int ch;
        for (int i = 0; i < cmd_nums; i++)
        {
            cin >> timecode[i];
            cin.get();

            cin.get(cmdcodes[i]);
            cin.get();
            cin >> parameter1[i] >> parameter2[i] >> parameter3[i];
            cin.get();
        }
        //指令该村起来的存起来

        while (true)
        {
            Time_Routine();

            while (Time_Comparing()) //检查时间码，有没有需要执行的指令
            {
                switch (cmdcodes[cmd_step])
                {
                case 'A': Add_Robots(parameter1[cmd_step], parameter2[cmd_step], parameter3[cmd_step]);
                    break;
                case 'F': Attack(parameter1[cmd_step], parameter2[cmd_step], parameter3[cmd_step]);
                    break;
                case 'H': Heat(parameter1[cmd_step], parameter2[cmd_step], parameter3[cmd_step]);
                    break;
                case 'U': Upgrade(parameter1[cmd_step], parameter2[cmd_step], parameter3[cmd_step]);
                    break;
                    cmd_step++;
                default: cout << "Wrong command!" << endl;
                }
            }
            time++;
        }
        // for (int i=0;i<cmd_nums;i++)
        // {
        //     //cout<<cmdcodes[i]<<endl;
        //     cout<<timecodes[i]<<" "<<cmdcodes[i]<<" "<<parameter1[i]<<" "<<parameter2[i]<<" "<<parameter3[i]<<endl;
        // }
    }

    bool command::Time_Comparing()
    {
        return time == timecode[cmd_step];
    }

    void Time_Routine() //回合日常工作
    {
        for (auto i : mymanage.Robots_List_Survive)
        {
            is_overheated(i); //判断热量并扣除血量热量
            is_damaged(i);
        }
    }

    void is_overheated( std::shared_ptr<robots>& the_robot) //判断热量并扣除血量热量
    {
        if (the_robot->heat() >= the_robot->Heat_Ceiling)
        {
            the_robot->blood(the_robot->blood() - 1);
        }
        if (the_robot->heat() > 0)
            the_robot->heat(the_robot->heat() - 1);
    }

    void is_damaged(std::shared_ptr<robots>& the_robot) //判断坏没坏
    {
        if (the_robot->blood() <= 0)
        {
            the_robot->damage();
        }
    }

    void command::Add_Robots(uns teamname, uns team_id, uns type) //指令A
    {
        auto p = TeamList.find(teamname);
        if (p == TeamList.end() || TeamList.empty()) //检查有无该队名，若没有则创建新队伍，创建新机器人
        {
            switch (type)
            {
            case 0: Construction_Robots(teamname, team_id);
                break;
            case 1: Infantry_Robots_1(teamname, team_id);
                break;
            default: cout << "Wrong command!" << endl;
            }
        }
        else
        {
            //队伍存在，判断在不在阵亡池
            auto theteam = TeamList[teamname];
            auto q = theteam->Team_Robots_Damaged.find(team_id);
            if (q != theteam->Team_Robots_Damaged.end()) //在阵亡池,给他复活
            {
                auto tmp = std::make_pair(team_id, theteam->Team_Robots_Damaged.at(team_id));
                theteam->Team_Robots_Damaged.erase(q);
                theteam->Team_Robots_Survive.insert(tmp);
                theteam->Team_Robots_Damaged.at(team_id)->Revive();
            }
            else
            {
                auto q1 = theteam->Team_Robots_Survive.find(team_id);
                if (q1 == theteam->Team_Robots_Survive.end()) //不在正常池
                {
                    switch (type)
                    {
                    case 0: Construction_Robots(teamname, team_id);
                        break;
                    case 1: Infantry_Robots_1(teamname, team_id);
                        break;
                    default: cout << "Wrong command!" << endl;
                    }
                }
            }
        }
    }
    void command::Attack(uns teamname , uns team_id, uns damage_account)
    {
        try
        {
            auto p=TeamList[teamname]->Team_Robots_Survive.at(team_id);
            p->blood(p->blood()-damage_account);
            is_damaged(p);
        }
        catch (...){};


    }
    void command::Heat(uns teamname, uns teamid, uns heat_account)
    {
        try
        {
            auto p=TeamList.at(teamname)->Team_Robots_Survive.at(teamid);
            p->heat(p->heat()+heat_account);
        }catch(...){};
    }
    void command::Upgrade(uns teamname, uns teamid, uns level)
    {
        try
        {
            auto p=TeamList.at(teamname)->Team_Robots_Survive.at(teamid);
            if (p->level>=level)
            {
                return;
            }
            for ()
        }catch (...){};
    }


} // my
