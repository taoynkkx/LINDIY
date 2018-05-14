本目录存放Altium Designer的硬件工程。
本工程采用Altium Designer 9 Winter版本制作。

V1.01版本修改：
1，在MCU端无供电时，LIN端有供电会使NSLP为低电平状态。
2，显示D1, D2, D4 型号。
3，使用BOOT管脚
BOOT0和BOOT1只用BOOT功能。
板子预留BOOT0和3.3V焊盘，用于官方FlashLoader下载使用。
BOOT1电阻下拉到地。
4，预留下载口
预留串口用于官方FlashLoader下载程序（PA9/10或PA14/15）
方案1：PA9/10接USB串口，PA2/3接LIN。
方案2：PA9/10接LIN保持不变，PA2/3接USB串口不变，PA15引出到PA14附近接下载串口。
5，不使用调试口
使用其它管脚替换PB3/JTDO和PB4/JNTRST。

V1.02版本修改:
1,将原来0R电阻做boot0跳线修改成使用,2.54mm排针跳线方式.
2,将原来用0R电阻做SWD和串口loader下载方式切换,修改成将SWD和串口同时接到P2排针上.
     将原来5PIN的排针修改成6PIN的排针,增加了PA15(RXD)引脚.