//
// Created by Lenovo on 25-1-16.
//

#ifndef COMMAND_H
#define COMMAND_H
#include "robots.h"

namespace my {

class command {
  public:
  command();//构造函数就是流程主函数
  ~command()=default;
  uns time=0;//时间吗（实时）
  uns cmd_step=0;//实时指令索引
  void Add_Robots(uns,uns,uns  );//指令A创造机器人
  void Print(std::shared_ptr<robots>);//打印相关信息
  void Attack(uns,uns,uns);//攻击机器人
  void Heat(uns,uns,uns);//热量上升
  void Upgrade(uns,uns,uns);//机器人升级
  bool Time_Comparing();//判断时间码有没有指令触发
  std::shared_ptr<uns[]> timecode;//存指令参数
  std::shared_ptr<char[]> cmdcodes;//存指令参数
  std::shared_ptr<uns[]> parameter1;//存指令参数
  std::shared_ptr<uns[]> parameter2;//存指令参数
  std::shared_ptr<uns[]> parameter3;//存指令参数
  private:
};

} // my

#endif //COMMAND_H
