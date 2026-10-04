# 耿力 FSJ_666

2026-10-04 调试版。正常开机发送8次主界面背景PIC31，最后一包后重新计时，等待200ms再绘制文字。恢复标题、四行距离和mm单位；左/中/右臂选择读取本地扫描状态，避免无线安全处理清零发送变量导致界面误显示中臂。

## 工程与改动

- Keil工程：HDH_YKQ_SPJ.uvprojx；FLASH目标；LPC1764；ARM Compiler 5.06。
- 机型：USER_TYPE=KXCAN_GLGJT312E_L3X。
- C/H维持GBK编码、CRLF换行。
- 修改仅涉及Src/main.c、Src/App_lcd.c、User/KXCAN_GLGJT312E.c；输入扫描、无线安全处理、CAN控制和参数没有修改。
- [完整框架与问题复核](FRAMEWORK_REVIEW_20261004.md)列明入口、初始化、定时器、任务顺序、共享状态、界面/通信/安全退出及其他原有隐患。

## 最新 BIN

- [FSJ_666_LCD_8x_200ms_arm_fix_debug.bin](out/FSJ_666_LCD_8x_200ms_arm_fix_debug.bin)，39,044字节。
- [编译及最终核对记录](out/FSJ_666_LCD_8x_200ms_arm_fix_debug.verification.json)。
- [文件校验清单](manifest.json)。

SHA-256：

~~~text
dc3cc55ed943d3af5f4f3e9cf4c819b2f08186aebdade4391f7af1c830bd77a7
~~~

BIN沿用从0地址补齐的导出方式，应用向量在0x2000。烧录沿用本工程既有流程。

## 验证范围

真实GPIO扫描表、DI_Scan、Activar、TIMER0_IRQHandler、主循环无线先于LCD的分支、WL_Recv、YKQ_Data_WL、主界面与文字绘制均参与针对性主机检查。覆盖3臂×使能/未使能/急停、各组持续切换6次、距离文字/数值/mm、8包背景与最后200个1ms节拍、背光开启延时、安全包字段。修复前同一检查能复现左臂被显示成中臂；修复后通过。

ARMCC增量编译及FLASH链接成功。最终BIN与AXF加载段逐字节一致，向量/入口/GBK文字核对，并确认显示代码读取原始扫描变量。

GPIO/计时器寄存器、绘制及物理串口回调为模拟，未运行整机所有菜单/电源路径。实机开机重叠、切换、急停/唤醒和实际串口时序尚未验证。

## 下载和协作

本仓库已公开，可直接下载。编辑提交需要写权限或Pull Request。

旧加密包FSJ_666_20261003_8bg_200ms.7z及此前debug/text_fix BIN均未包含本次臂切换修正，没有重新打包；请取最新BIN或当前源码。
