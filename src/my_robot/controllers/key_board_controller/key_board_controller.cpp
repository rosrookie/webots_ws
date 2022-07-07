// File:          4_wheel_car_keyboard_controller.cpp
// Date:          2022.7.6
// Description:   keyboard_controll for 4_wheel_car
// Author:        Loren
// Modifications:

// webots头文件
#include <iostream>
#include <webots/Keyboard.hpp>  // 键盘控制
#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

//所有 webots 类都定义在“webots”命名空间中
using namespace webots;
using namespace std;

int main(int argc, char **argv) {
  // 定义常量
  const int c_time_step = 64;
  const double c_max_speed = 6.28;
  //创建机器人对象
  Robot *robot = new Robot();

  //创建键盘控制对象并启动
  Keyboard keyboard_controll;
  keyboard_controll.enable(c_time_step);

  //创建底盘电机对象并初始化
  Motor *wheels[4];
  // wheels[0] = robot->getMotor("wheel1");
  // wheels[1] = robot->getMotor("wheel2");
  // wheels[2] = robot->getMotor("wheel3");
  // wheels[3] = robot->getMotor("wheel4");

  // wheels[0]->setPosition(INFINITY);
  // wheels[1]->setPosition(INFINITY);
  // wheels[2]->setPosition(INFINITY);
  // wheels[3]->setPosition(INFINITY);

  // wheels[0]->setVelocity(0.0);
  // wheels[1]->setVelocity(0.0);
  // wheels[2]->setVelocity(0.0);
  // wheels[3]->setVelocity(0.0);

  char wheels_names[4][8] = {"wheel1", "wheel2", "wheel3", "wheel4"};
  for (int i = 0; i < 4; i++) {
    wheels[i] = robot->getMotor(wheels_names[i]);
    wheels[i]->setPosition(INFINITY);
    wheels[i]->setVelocity(0.0);
  }

  //初始化速度
  double leftSpeed = 0.0;
  double rightSpeed = 0.0;

  // 开始循环执行
  while (robot->step(c_time_step) != -1) {
    //读取键盘输入
    auto kb = keyboard_controll.getKey();
    if (kb == keyboard_controll.DOWN) {  // DOWN
      leftSpeed = -0.8 * c_max_speed;
      rightSpeed = -0.8 * c_max_speed;
      wheels[0]->setVelocity(leftSpeed);
      wheels[1]->setVelocity(rightSpeed);
      wheels[2]->setVelocity(leftSpeed);
      wheels[3]->setVelocity(rightSpeed);
    } else if (kb == keyboard_controll.RIGHT) {  // RIGHT
      leftSpeed = 0.8 * c_max_speed;
      rightSpeed = -0.8 * c_max_speed;
      wheels[0]->setVelocity(leftSpeed);
      wheels[1]->setVelocity(rightSpeed);
      wheels[2]->setVelocity(leftSpeed);
      wheels[3]->setVelocity(rightSpeed);
    } else if (kb == keyboard_controll.LEFT) {  // LEFT
      leftSpeed = -0.8 * c_max_speed;
      rightSpeed = 0.8 * c_max_speed;
      wheels[0]->setVelocity(leftSpeed);
      wheels[1]->setVelocity(rightSpeed);
      wheels[2]->setVelocity(leftSpeed);
      wheels[3]->setVelocity(rightSpeed);
    } else if (kb == keyboard_controll.UP) {  // UP
      leftSpeed = 0.8 * c_max_speed;
      rightSpeed = 0.8 * c_max_speed;
      wheels[0]->setVelocity(leftSpeed);
      wheels[1]->setVelocity(rightSpeed);
      wheels[2]->setVelocity(leftSpeed);
      wheels[3]->setVelocity(rightSpeed);
    } else if (kb == keyboard_controll.END) {  // END
      leftSpeed = 0.0 * c_max_speed;
      rightSpeed = 0.0 * c_max_speed;
      wheels[0]->setVelocity(leftSpeed);
      wheels[1]->setVelocity(rightSpeed);
      wheels[2]->setVelocity(leftSpeed);
      wheels[3]->setVelocity(rightSpeed);
    } else {
    }
  }
  delete robot;  //程序结束，释放内存
  return 0;
}
