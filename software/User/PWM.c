#include "PWM.h" // Device

void PWM_Init(void)
{
}

/**
 * 函    数：PWM设置CCR
 * 参    数：Compare 要写入的CCR的值，范围：0~100
 * 返 回 值：无
 * 注意事项：CCR和ARR共同决定占空比，此函数仅设置CCR的值，并不直接是占空比
 *           占空比Duty = CCR / (ARR + 1)
 */
void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM3, Compare); // 设置CCR2的值
}
void PWM_SetCompare2(uint16_t Compare)
{
	TIM_SetCompare2(TIM3, Compare); // 设置CCR2的值
}
void PWM_SetCompare3(uint16_t Compare)
{
	TIM_SetCompare3(TIM3, Compare); // 设置CCR2的值
}
void PWM_SetCompare4(uint16_t Compare)
{
	TIM_SetCompare4(TIM3, Compare); // 设置CCR2的值
}
