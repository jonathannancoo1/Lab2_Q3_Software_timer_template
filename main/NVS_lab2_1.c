// 8166030798 Non-Volatile Storage

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

#include "NVS_lab2_1.h"  // Include custom header file for non-volatile storage (NVS) functions

struct tm Time = {
        .tm_year = 116, //since 1900 (2016 - 1900)
        .tm_mon  = 9,  // 0-based
        .tm_mday = 9,
        .tm_hour = 13,
        .tm_min  = 50,
        .tm_sec  = 10
    };



i2c_config_t pinconfig={


//Installing driver
//i2c_driver_install(I2C_NUM_0,I2C_MODE_MASTER);
 //master mode
.mode=I2C_MODE_MASTER,

//disabling pullups
.sda_pullup_en=GPIO_PULLUP_DISABLE,
.scl_pullup_en=GPIO_PULLUP_DISABLE,


//Setting SCL as IO 0
.scl_io_num=GPIO_NUM_0,

//Setting SDA as IO2
.sda_io_num=GPIO_NUM_2,

//wait for 1000 tics
.clk_stretch_tick = 1000,
};

static const char *TAG = "example";
void hello_world_func(){



    printf("hello world 1 \n");




    i2c_dev_t dev;
    memset(&dev, 0, sizeof(i2c_dev_t));
    dev.addr=DS3231_ADDR;
    dev.cfg=pinconfig;
    dev.port=I2C_NUM_0;

  if(ds3231_init_desc(&dev,0,GPIO_NUM_2,GPIO_NUM_0)==ESP_OK){


        printf("work");
    }

    else
    {printf("not working");}


    if(ds3231_init_desc(&dev,0,GPIO_NUM_2,GPIO_NUM_0)==ESP_OK){


        printf("work");
    }

    else
    {printf("not working");}


    
         if (ds3231_set_time(&dev, &Time) == ESP_OK)
        {
            printf("Timeset\n");}

            else
            {printf("Error");}

    printf("hello world 2 \n");
}


void write_to_RTC(){


    
    i2c_dev_t dev2;
    memset(&dev2, 0, sizeof(i2c_dev_t));
    dev2.addr=DS3231_ADDR;
    dev2.cfg=pinconfig;
    dev2.port=I2C_NUM_0;

    if(ds3231_init_desc(&dev2,0,GPIO_NUM_2,GPIO_NUM_0)==ESP_OK){


        printf("work\n");
    }

    else
    {printf("not working\n");}

    printf("Here\n");


    
         if (ds3231_set_time(&dev2, &Time) == ESP_OK)
        {
            printf("Timeset\n");}

            else
            {printf("Error\n");}

            
        printf("Here 2\n");

}