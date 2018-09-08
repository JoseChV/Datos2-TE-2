cmake_minimum_required(VERSION 3.12)
project(AbstractFactory)

set(CMAKE_CXX_STANDARD 14)

add_executable(AbstractFactory main.cpp Widget.cpp Widget.h LinuxButton.cpp LinuxButton.h LinuxTaskBar.cpp LinuxTaskBar.h WindowsButton.cpp WindowsButton.h WindowsTaskBar.cpp WindowsTaskBar.h AppleButton.cpp AppleButton.h AppleTaskBar.cpp AppleTaskBar.h User.cpp User.h Factory.cpp Factory.h LinuxFactory.cpp LinuxFactory.h WindowsFactory.cpp WindowsFactory.h AppleFactory.cpp AppleFactory.h)