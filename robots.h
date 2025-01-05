#ifndef ROBOTS_H
#define ROBOTS_H
#include <memory>
#include <thread>
#include"manage.h"
#include<unordered_map>
#include<string>

namespace my
{
    using uns = unsigned short;

    class robots: public std::enable_shared_from_this<robots>
    {




    public:
        robots(uns,uns);//初始化热量0血量满，并加入或创造相应队伍，加入队伍机器人名单，加入teamid映射
      //  robots::robots(uns heat,uns,uns);//同上，但带初始热量（已废弃）
        ~robots() ;
        uns blood ();//返回血量
        uns heat ();//返回热量
        void blood(uns);//设定血量
        void heat(uns);//设定热量
        uns team;//队伍名称
        uns team_id;//tid
        std::shared_ptr<robots> tothis=shared_from_this();//指向自身的智能指针
    private:
        // unsigned short  Blood_Ceiling;
        //unsigned short  Heat_Ceiling;
        uns Blood_Count;//目前血量
        uns Heat_Count;//目前热量

    };

    class Construction_Robots : public robots
    {
    public:
        Construction_Robots(uns,uns);//初始化
        ~Construction_Robots()=default ;
        bool level_up();
    private:
        static uns Blood_Ceiling ;
        static uns Heat_Ceiling ;

    };

    class Infantry_Robots_1 : public robots
    {
        public:
        Infantry_Robots_1(uns,uns);
        ~Infantry_Robots_1() = default;
        static uns Blood_Ceiling ;
        static uns Heat_Ceiling ;
        void level_up();
    };

    class Infantry_Robots_2 : public robots
    {
        public:
        Infantry_Robots_2(uns,uns);
        ~Infantry_Robots_2() = default;
        static uns Blood_Ceiling ;
        static uns Heat_Ceiling ;
        void level_up();
    };

    class Infantry_Robots_3 : public robots
    {
        public:
        Infantry_Robots_3(uns,uns);
        ~Infantry_Robots_3() = default;
        static uns Blood_Ceiling ;
        static uns Heat_Ceiling ;
    };
} // my

#endif //ROBOTS_H
