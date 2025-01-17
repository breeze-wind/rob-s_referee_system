//
// Created by Lenovo on 25-1-16.
//

#ifndef COMMAND_H
#define COMMAND_H
#include "robots.h"

namespace my {

class command {
  public:
  command();
  ~command()=default;
  uns time=0;
  uns cmd_step=0;
  void Add_Robots(uns,uns,uns  );//指令A
  void Print(std::shared_ptr<robots>);//打印相关信息
  void Attack(uns,uns,uns);//攻击机器人
  void Heat(uns,uns,uns);//热量上升
  void Upgrade(uns,uns,uns);//机器人升级
  bool Time_Comparing();//判断时间码有没有指令触发
  std::shared_ptr<uns> timecode;
  std::shared_ptr<char> cmdcodes;
  std::shared_ptr<uns> parameter1;
  std::shared_ptr<uns> parameter2;
  std::shared_ptr<uns> parameter3;
  private:
};

} // my

#endif //COMMAND_H
