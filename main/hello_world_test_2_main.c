//816030798

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_sleep.h"
#include "driver/gpio.h"
#include "driver/hw_timer.h"
#include "driver/uart.h"
#include "driver/i2c.h"
#include "freertos/semphr.h"
#include "freertos/FreeRTOSConfig.h"
#include "ds3231.h"
#include <i2cdev.h>
#include <string.h>

#include "esp_timer.h"


#include "NVS_lab2_1.h"

struct tm Time1 = {
        .tm_year = 116, //since 1900 (2016 - 1900)
        .tm_mon  = 9,  // 0-based
        .tm_mday = 9,
        .tm_hour = 13,
        .tm_min  = 50,
        .tm_sec  = 10
    };

void my_timer_callback(void* arg) {
    printf("Timer expired!\n");
    // Perform actions here (keep them short for minimal delay)
}

void init_microsecond_timer() {
    // Define the timer configuration
    const esp_timer_create_args_t timer_args = {
        .callback = &my_timer_callback,
        .arg = NULL,                 // Argument to pass to the callback
        .dispatch_method = ESP_TIMER_TASK, // Run in the timer task
        .name = "microsecond_timer"
    };

    // Create the timer
    esp_timer_handle_t timer_handle;
    esp_err_t err = esp_timer_create(&timer_args, &timer_handle);
    if (err != ESP_OK) {
        printf("Failed to create timer: %s\n", esp_err_to_name(err));
        return;
    }

    // Start the timer for 100,000 microseconds (100 ms)
    err = esp_timer_start_periodic(timer_handle, 100000);  // Set in microseconds
    if (err != ESP_OK) {
        printf("Failed to start timer: %s\n", esp_err_to_name(err));
        return;
    }

    printf("Microsecond timer started\n");
}





void app_main(){

    
    i2cdev_init();

  while(1){  

      int32_t start_time = esp_timer_get_time(); // Start time in microseconds

hello_world_func();
printf("Could not get time\n");

//printf("set up properly");
write_to_RTC();
printf("loop");
  
  int32_t end_time = esp_timer_get_time();   // End time in microseconds


      int32_t duration = end_time - start_time;  // Calculate elapsed time

      printf("Execution time: %d microseconds\n", duration);


  }
}