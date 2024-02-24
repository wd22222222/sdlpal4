# sdlpal_edit
#建立此项目的是以开源项目sdlpal为基础，编制一款全新的综合游戏数据编辑软件，通过对数据修改，可生成全新的游戏，实现全新的游戏体验，
#
#功能描述：

1.本项目基于微软MFC开发，开发工具为vs2022。暂不支持其他开发工具

2.表格工具采用由Chris Maunder先生开发的GridCtrl开源版本

3.游戏数据编码、解码部分使用Yihua Lou 先生开发的开源版本。

4.原SdlPal部分由C改为用C++重构。

5.SDL改用OPENGL的GLSL进行渲染。

6.表格编辑部分除可对游戏数据进行修改外，还开发了对游戏地图等图像编辑功能

7.实现了游戏脚本编辑功能。

8.同时适应对SDLPAL两大基本原生版本的支持。

9.实现了游戏调试和运行功能

运行示例
1.主页面
![image](https://github.com/wd22222222/sdlpal_edit/assets/63216297/40be8df2-272e-4505-80c4-5b4abec0131a)

2.编辑页面
![image](https://github.com/wd22222222/sdlpal_edit/assets/63216297/bdb2c6a3-5b2b-4305-bf03-a500c581761d)

3.地图编辑
![image](https://github.com/wd22222222/sdlpal_edit/assets/63216297/3d23d35c-b7bf-4695-b100-b9fa178dfbd3)

4.运行
![image](https://github.com/wd22222222/sdlpal_edit/assets/63216297/afc8a2c7-99fb-4ef4-9cfa-833f0fb173f3)

#系统构建：

1、 C++版本设置为17以上

2、字符集设定为使用 Unicode 字符集

3、编译选项为在共享 DLL 中使用 MFC

4、使用vcpkg工具引入SDL2库和GLAD库，具体指令为在命令行提示符下，转到c:\或d:\目录或任意目录 
输入命令 ：

git clone https://github.com/microsoft/vcpkg.git

cd vcpkg

bootstrap-vcpkg.bat 
#生成VCPKG.EXE

D:\vcpkg>vcpkg  integrate install

D:\vcpkg>vcpkg install sdl2
#建立64位SDL2库

D:\vcpkg>vcpkg install sdl2:x86-windows 
#建立32位SDL2库

D:\vcpkg>vcpkg install glew:x64-windows-static 
#建立64位GLAD库

D:\vcpkg>vcpkg install glad:x86-windows 
#建立32位SDL2库

D:\vcpkg>vcpkg integrate install

至此所有附加库均已经引入完毕，具体解释可以参照网上相关资料

5、使用VS中的生成命令构建，构建成功OK。

#注意使用VCPKG生成的调试库会有内存泄露提示，具体原因未知。

#使用SDL2静态库

使用静态库后，在发布调用SDL2游戏时不用同时拷贝SDL.DLL，可以避免因SDL2.DLL版本问题，只需要单独拷贝 EXE文件。

使用静态库的方法

1.使用vcpkg 建立静态库

在已经安装并使用vcpkg 管理附加库的前提下键入命令

d:\vcpkg\vcpkg install sdl2:x64-windows-static //64位库

d:\vcpkg\vcpkg install sdl2:x86-windows-static //32位库

引用 在VS中 项目-》属性-》链接器-》输入-》编辑中 

将原来的 SDL.LIB项 改为 sdl-static.lib

增加一项  Version.lib

或 直接将 以下 条目 拷贝到编辑栏中

winmm.lib;imm32.lib;setupapi.lib;glu32.lib;opengl32.lib;sdl2-static.lib;Version.lib;%(AdditionalDependencies)

如果编译时提示找不到静态库时，可在项目属性 VC++ 目录中 将内容用下面条目拷贝上

D:\drv\vcpkg\buildtrees\sdl2\x64-windows-static-rel;$(LibraryPath)

其中：d:\drv 是我自己的vcpkg 目录，在操作中将此改成自己的vcpkg目录即可

OK






