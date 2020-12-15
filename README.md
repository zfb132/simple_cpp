## 简单的C++项目文件结构
如下：  
```txt
simple_cpp
├── include
│   ├── model
│   │   └── model.h
│   └── test.h
├── main.cpp
├── Makefile
├── README.md
└── src
    ├── model.cpp
    └── test.cpp
```
## 编写C++项目的通用Makefile文件
内容见[Makefile](https://github.com/zfb132/simple_cpp/tree/master/Makefile)  
原始版本为[mbcrawfo/GenericMakefile](https://github.com/mbcrawfo/GenericMakefile)  
使用说明：  
* 编译（默认编译为`Release`版本）：`make`或者`make release`
* 编译为调试版本：`make debug`
* 多线程编译：`make -j12 debug`
* 清除文件：`make clean`

**注意**  
* 添加头文件路径
`INCLUDES = -I $(SRC_PATH) -I include/`

## 使用VSCode调试代码[可选]
参考[使用VSCode调试ITensor项目](https://blog.whuzfb.cn/blog/2020/07/04/itensor_vscode/#34-%E6%AD%A3%E5%BC%8F%E7%BC%96%E5%86%99%E4%BB%A3%E7%A0%81)  
1. 创建文件夹`.vscode`，不要忘记前面的`.`
2. 在`.vscode`文件夹下为`C/C++`扩展添加配置文件`c_cpp_properties.json`，内容如下
```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
            ],
            "defines": [],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "clang-x64"
        }
    ],
    "version": 4
}
```
3. 在`.vscode`文件夹下添加配置文件`tasks.json`，内容如下
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "cpp-build",
            "command": "make",
            "args": [],
            "type": "shell"
          },
          {
            "label": "cpp-build-debug",
            "command": "make",
            "args": [
              "debug"
            ],
            "type": "shell"
          },
          {
            "label": "cpp-clean",
            "command": "make",
            "args": [
              "clean"
            ],
            "type": "shell"
          }
    ]
}
```
4. 在`.vscode`文件夹下添加配置文件`launch.json`，内容如下
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}-g",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": false,
                }
            ],
            "preLaunchTask": "cpp-build-debug" 
            // 调试会话开始前执行的任务，与tasks.json的label相对应
        }
    ]
}
```
以上四步执行完毕后的目录如下  
```txt
simple_cpp
├── include
│   ├── model
│   │   └── model.h
│   └── test.h
├── main.cpp
├── Makefile
├── README.md
├── src
│   ├── model.cpp
│   └── test.cpp
└── .vscode
    ├── c_cpp_properties.json
    ├── launch.json
    └── tasks.json
```
参考[使用VSCode调试ITensor项目](https://blog.whuzfb.cn/blog/2020/07/04/itensor_vscode/#35-%E7%BC%96%E8%AF%91%E5%92%8C%E8%BF%90%E8%A1%8C)调试代码

## 混乱的文件结构
如下：  
```txt
simple_cpp
├── main.cpp
├── model.cpp
├── model.h
├── Makefile
├── README.md
├── test.cpp
└── test.h
```
此[Makefile](https://github.com/zfb132/simple_cpp/tree/master/Makefile)文件依然可用，只是为了效率，需要修改头文件目录（删除原先的`include/`）  
`INCLUDES = -I $(SRC_PATH)`