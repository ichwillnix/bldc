/*
	Copyright 2012-2014 Benjamin Vedder	benjamin@vedder.se

	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */

#include "ch.h"
#include "hal.h"
#include <stm32f4xx.h>
#include "stm32f4xx_conf.h"
#include "main.h"
#include "mcpwm.h"
#include "servo.h"

CH_IRQ_HANDLER(TIM7_IRQHandler) {
	CH_IRQ_PROLOGUE();
	TIM_ClearITPendingBit(TIM7, TIM_IT_Update);
	servo_irq();
	CH_IRQ_EPILOGUE();
}

CH_IRQ_HANDLER(ADC1_2_3_IRQHandler) {
	CH_IRQ_PROLOGUE();
	ADC_ClearITPendingBit(ADC1, ADC_IT_JEOC);
	mcpwm_adc_inj_int_handler();
	CH_IRQ_EPILOGUE();
}
