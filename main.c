#include "main.h"
#include "ssd1306.h"
#include "arm_math.h"
#include <math.h>
#include <stdio.h>

#define FFT_SIZE       256
#define SAMPLE_RATE    4000  // 4kHz sampling
#define WAVELENGTH     0.0124f

ADC_HandleTypeDef hadc1;
I2C_HandleTypeDef hi2c1;

float32_t adc_input[FFT_SIZE];
float32_t fft_input[2 * FFT_SIZE]; // interleaved real + imag
float32_t fft_output[FFT_SIZE];

char display_buffer[32];

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_I2C1_Init(void);

void sample_adc();
float calculate_speed();

int main(void) {
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_I2C1_Init();
  SSD1306_Init();

  SSD1306_Clear();
  SSD1306_GotoXY(10, 10);
  SSD1306_Puts("HB100 Speed Meter", &Font_7x10, 1);
  SSD1306_UpdateScreen();
  HAL_Delay(1000);

  while (1) {
    sample_adc();
    float speed_kmh = calculate_speed();

    // Display speed
    SSD1306_Clear();
    sprintf(display_buffer, "Speed: %.2f km/h", speed_kmh);
    SSD1306_GotoXY(0, 0);
    SSD1306_Puts(display_buffer, &Font_11x18, 1);
    SSD1306_UpdateScreen();

    HAL_Delay(300);
  }
}
