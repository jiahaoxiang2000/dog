At our software, we use STM32CubeMX to create CMake projects. We use the hardware configuration from the reference [open project](https://oshwhub.com/misgon/dian-zi-chong-wu-shen-ti-3). Since we have the same hardware, we can use the same hardware configuration.

## Download

After the cmake build process, we can download the firmware to the hardware. We use openocd to download the firmware.

```
openocd -f openocd.cfg -c "program build/Release/dog.elf verify reset exit"
```

## Reference

- [Open Project](https://oshwhub.com/misgon/dian-zi-chong-wu-shen-ti-3)