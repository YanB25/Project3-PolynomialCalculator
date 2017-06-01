# Project3-PolynomialCalculator
项目3 多项式计算器 

1. 这是什么及如何使用
	- windos:
	直接运行`/bin/PolynomialCalculator.exe` 即可打开系统，并根据提示进行操作
	- Linux:
	在`/src`并目录下输入`make`指令后输入`./PolynomialCalculator.out`即可打开系统
	(或输入`make run`运行系统)
运行后输入`help`可查看帮助

2. 各个文件的包含关系：
	详情请见 `src/Makefile` 文件及文档

3. 各个文件的用途简介：
	- PolynomialCalculator.cpp
		定义了`main`函数以及用户交互界面。调用Polynomial类。
	- IOHelper.*
		定义了一系列辅助`main`函数输入输出的函数。与`main`耦合性较强。
	- Polynomial.*
		定义了多项式类。实现了对输入的parsing以及输入是否有效的检测。
4. 注意事项：

5. github: [YanB25](https://github.com/YanB25)

6. 更新日志：

	1. v1.0：项目完成




