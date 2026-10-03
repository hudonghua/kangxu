# 耿力 FSJ_666

2026-10-03 调试版本。

## 本次修改

欢迎界面结束后，主界面背景图发送 8 次，发送间隔约 200ms；最后一包背景发送后重新开始显示计时，等待 200ms，再绘制文字和图标。等待通过现有显示节拍完成，主循环继续运行。

改动位置：`Src/main.c` 的启动刷新计数，以及 `Src/App_lcd.c` 的主界面背景结束阶段。

## 工程与文件

- Keil 工程：`HDH_YKQ_SPJ.uvprojx`，目标 `FLASH`，MCU `LPC1764`。
- 当前机型：`User/_Device_config.h` 中的 `KXCAN_GLGJT312E_L3X`。
- 原有 C/H 文件保持 GBK 编码和 CRLF 换行。
- 调试固件：`out/FSJ_666_LCD_8x_200ms_debug.bin`，38,388 字节。
- 构建核对记录：`out/FSJ_666_LCD_8x_200ms_debug.verification.json`。
- 文件校验清单：`manifest.json`。

BIN SHA-256：

```text
c79f07232a9971e27d31e766791a377e185178f54eda0800b092cf13f1d5fe39
```

BIN 沿用本工程原有的从 0 地址补齐导出方式，应用向量表位于 `0x2000`。下载或烧录时沿用本工程已有流程。

## 验证情况

已完成受影响文件的 ARM Compiler 5.06 编译、现有对象文件依赖检查、FLASH 目标链接、BIN 与 AXF 加载段逐字节核对，以及最终 BIN 的启动次数和等待逻辑核对。

本版本尚未在目标设备上验证屏幕重叠是否消除。

## 给同事下载

同级目录的 `FSJ_666_20261003_8bg_200ms.7z` 含本工程源码和同一份调试 BIN，可用 7-Zip 解压。密码由负责人单独提供。
