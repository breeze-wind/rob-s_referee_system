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
namespace my {
    command::command()
    {    time=0;
        uns cmd_nums=0;
        std::cin>>cmd_nums;
         timecode=std::make_shared<uns>(cmd_nums);
        parameter1=std::make_shared<uns>(cmd_nums);
        parameter2=std::make_shared<uns>(cmd_nums);
        parameter3=std::make_shared<uns>(cmd_nums);
        cmdcodes=std::make_shared<char>(cmd_nums);
       // int ch;
        for (int i=0;i<cmd_nums;i++)
        {

            cin>>timecode[i];
            cin.get();

            cin.get(cmdcodes[i]);
            cin.get();
            cin>>parameter1[i]>>parameter2[i]>>parameter3[i];
            cin.get();
        }
        //指令该村起来的存起来

        while (true)
        {


            if (Time_Comparing())//检查时间码，有没有需要执行的指令
            {
                switch (cmdcodes[cmd_step])
                {
                    case 'A':Add_Robots(parameter1,parameter2,parameter3);
                    break;
                case 'F':Attack(parameter1,parameter2,parameter3);
                    break;
                case 'H':Heat(parameter1,parameter2,parameter3);
                    break;
                case 'U':Upgrade(parameter1,parameter2,parameter3);
                    break;
                    cmd_step++;
                }
            }

        }
        // for (int i=0;i<cmd_nums;i++)
        // {
        //     //cout<<cmdcodes[i]<<endl;
        //     cout<<timecodes[i]<<" "<<cmdcodes[i]<<" "<<parameter1[i]<<" "<<parameter2[i]<<" "<<parameter3[i]<<endl;
        // }

    }

bool command::Time_Comparing()
{
  return time==timecode[cmd_step];
}

} // my