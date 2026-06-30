#include <unistd.h>
#include "stdio.h"
#include "ohos_init.h"
#include "cmsis_os2.h"
#include "iot_gpio.h"
#include "hi_io.h"

#define LED_TEST_GPIO 9
#define KEY_GPIO 5

IotGpioValue key_val;

void *LedTask(const char *arg)
{
    IoTGpioInit(LED_TEST_GPIO);

    IoTGpioSetDir(LED_TEST_GPIO,IOT_GPIO_DIR_OUT);

    (void)arg;

    while(1)
    {


    }

    return NULL;
}

void *KeyTask(const char *arg)
{

    IoTGpioInit(LED_TEST_GPIO);

    IoTGpioSetDir(LED_TEST_GPIO,IOT_GPIO_DIR_OUT);

    IoTGpioInit(KEY_GPIO);

    IoTGpioSetDir(KEY_GPIO,IOT_GPIO_DIR_IN);

    hi_io_set_pull(KEY_GPIO,HI_IO_PULL_UP);

    (void)arg;

    while(1)
    {
        IoTGpioGetInputVal(KEY_GPIO,&key_val);
        if(key_val==IOT_GPIO_VALUE1)
        {
            IoTGpioSetDir(LED_TEST_GPIO,0);
        }
        else
        {
            IoTGpioSetDir(LED_TEST_GPIO,1);
        }

        
        if(key_val==IOT_GPIO_VALUE1)
        {
            printf("HI_GPIO_VALUE_0\n");
        }
        else
        {
            printf("LOW_GPIO_VALUE_1\n");
        }
        usleep(10000);
    }
    
}


void led_demo(void)
{
     osThreadAttr_t key_attr;

    key_attr.name = "KeyTask";
    key_attr.attr_bits = 0U;
    key_attr.cb_mem = NULL;
    key_attr.cb_size = 0U;
    key_attr.stack_mem = NULL;
    key_attr.stack_size = 512;
    key_attr.priority = 26;

    if(osThreadNew((osThreadFunc_t)KeyTask,NULL, &key_attr)==NULL)
    {
        printf("falied to create keytask\n");
    }


   

}

SYS_RUN(led_demo);