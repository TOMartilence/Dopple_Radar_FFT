void sample_adc() {
  for (int i = 0; i < FFT_SIZE; i++) {
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    adc_input[i] = (float32_t)HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    // Windowing or DC offset removal
    fft_input[2*i]   = adc_input[i] - 2048.0f;  // Assuming 12-bit ADC with Vref=3.3V
    fft_input[2*i+1] = 0.0f;
  }
}
