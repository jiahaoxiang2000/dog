At our software, we use PlatformIO to build and upload firmware for STM32F103C8T6. We use the hardware configuration from the reference [open project](https://oshwhub.com/misgon/dian-zi-chong-wu-shen-ti-3).

## Building and Uploading

To build and upload the firmware:
```
platformio run --target upload
```

## experience

- OLED IIC display, not inverse connect the power, easy to burn the display.

## Reference

- [Open Project](https://oshwhub.com/misgon/dian-zi-chong-wu-shen-ti-3)