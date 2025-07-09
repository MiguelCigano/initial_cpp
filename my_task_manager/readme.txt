Organizacion del proyecto

my_task_server/
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   ├── server/
│   │   ├── HttpServer.cpp
│   │   └── HttpServer.hpp
│   ├── task/
│   │   ├── Task.cpp
│   │   └── Task.hpp
│   └── utils/
│       ├── Logger.cpp
│       └── Logger.hpp
├── include/  (si quieres separar headers públicos)
├── tests/
│   └── test_task.cpp
├── data/
│   └── tasks.json
└── config/
    └── config.json



Como compilar y ejecutar:

Desde el directorio raíz (my_task_manager/):

mkdir build
cd build
cmake ..
make
./task_server