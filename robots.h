#ifndef ROBOTS_H
#define ROBOTS_H
#include <memory>
#include <thread>
#include"manage.h"
#include<unordered_map>
#include<string>

enum type
{
    Construction = 0,
    Infantry = 1
};

namespace my
{
    using uns = unsigned short;

    class robots : public std::enable_shared_from_this<robots>
    {
    public:
        robots(uns, uns); //初始化热量0血量满，并加入或创造相应队伍，加入队伍机器人名单，加入teamid映射
        //  robots::robots(uns heat,uns,uns);//同上，但带初始热量（已废弃）
        ~robots();
        uns blood(void); //返回血量
        uns heat(void); //返回热量
        void blood(uns); //设定血量
        void heat(uns); //设定热量
        enum type robottype;
        uns teamname; //队伍名称
        uns team_id; //tid
        bool is_survive = true;
        std::shared_ptr<robots> tothis = shared_from_this(); //指向自身的智能指针
        bool level_up(void) = delete; //升级（删除自身，创造一个高等级的，各种映射处理利索）
        void damage(void); //阵亡
        const uns Blood_Ceiling = 0;
        const uns Heat_Ceiling = 0;
        void print(void); //打印相关信息
        void Revive(void); //复活
        void level_reset(uns);
        uns level = 0;

    private:
        // unsigned short  Blood_Ceiling;
        //unsigned short  Heat_Ceiling;
        uns Blood_Count; //目前血量
        uns Heat_Count; //目前热量
    };

    class Construction_Robots : public robots
    {
    public:
        enum type robottype = Construction;
        Construction_Robots(uns, uns); //初始化
        ~Construction_Robots() = default ;
        void level_reset(void) = delete;

    private:
        const uns Blood_Ceiling = 300;
        const uns Heat_Ceiling = 0;
    };

    class Infantry_Robots_1 : public robots
    {
    public:
        enum type robottype = Infantry;
        Infantry_Robots_1(uns, uns);
        ~Infantry_Robots_1() = default;
        const uns Blood_Ceiling = 100;
        const uns Heat_Ceiling = 100;
        uns level = 1;
    };

    class Infantry_Robots_2 : public robots
    {
    public:
        enum type robottype = Infantry;
        Infantry_Robots_2(uns, uns);
        ~Infantry_Robots_2() = default;
        const uns Blood_Ceiling = 150;
        const uns Heat_Ceiling = 200;
        uns level = 2;
    };

    class Infantry_Robots_3 : public robots
    {
    public:
        enum type robottype = Infantry;
        Infantry_Robots_3(uns, uns);
        ~Infantry_Robots_3() = default;
        const uns Blood_Ceiling = 250;
        const uns Heat_Ceiling = 300;
        uns level = 3;
    };
} // my

#endif //ROBOTS_H
