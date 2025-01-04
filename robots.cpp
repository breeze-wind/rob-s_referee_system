//
// Created by Lenovo on 25-1-1.
//

#include "robots.h"

namespace my
{
    Infantry_Robots_1::Infantry_Robots_1()
    {
        Infantry_Robots_1::Blood_Ceiling = 100;
        Infantry_Robots_1::Heat_Ceiling = 100;
    }

    Construction_Robots::Construction_Robots()
    {
        Construction_Robots::Blood_Ceiling = 300;
        Construction_Robots::Heat_Ceiling = 0;
    }

    Infantry_Robots_2::Infantry_Robots_2()
    {
        Infantry_Robots_2::Blood_Ceiling = 150;
        Infantry_Robots_2::Heat_Ceiling = 200;
    }

    Infantry_Robots_3::Infantry_Robots_3()
    {
        Infantry_Robots_3::Blood_Ceiling = 250;
        Infantry_Robots_3::Heat_Ceiling = 300;
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
    robots::robots()
    {
        Heat_Count=0;
        Blood_Count=this->Blood_Count;
    }
    robots::robots(uns heat)
    {
        Heat_Count=heat;
        Blood_Count=this->Blood_Count;
    }




} // my
