cmake_minimum_required(VERSION 3.10)
project(MyProject)
include_directories(app/src/main/headers)
add_executable(MyProject \
  app/src/main/cpp/app.cpp \
  app/src/main/cpp/tokenstream.cpp \
  app/src/main/cpp/polyn.cpp \
)
