#ifndef ROBOTS_H
#define ROBOTS_H
#include<unordered_map>
#include<string>
namespace my
{
    using uns = unsigned short;

    class robots
    {
    public:
        robots();
        ~robots() = default;
        uns blood

    private:
        // unsigned short  Blood_Ceiling;
        //unsigned short  Heat_Ceiling;
        uns Blood_Count;
        uns Heat_Count;
        uns team;
        uns Team_Id;

    };

    class Construction_Robots : public robots
    {
    public:
        Construction_Robots();
        ~Construction_Robots() = default;
        bool level_up();
    private:
        static uns Blood_Ceiling ;
        static uns Heat_Ceiling ;

    };

    class Infantry_Robots_1 : public robots
    {
        public:
        Infantry_Robots_1();
        ~Infantry_Robots_1() = default;
        static uns Blood_Ceiling ;
        static uns Heat_Ceiling ;
        void level_up();
    };

    class Infantry_Robots_2 : public robots
    {
        public:
        Infantry_Robots_2();
        ~Infantry_Robots_2() = default;
        static uns Blood_Ceiling ;
        static uns Heat_Ceiling ;
        void level_up();
    };

    class Infantry_Robots_3 : public robots
    {
        public:
        Infantry_Robots_3();
        ~Infantry_Robots_3() = default;
        static uns Blood_Ceiling ;
        static uns Heat_Ceiling ;
    };
} // my

#endif //ROBOTS_H
