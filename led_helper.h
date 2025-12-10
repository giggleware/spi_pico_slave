#ifndef LED_HELPER_H
#define LED_HELPER_H

const uint LED_R = 0;
const uint LED_Y = 1;
const uint LED_G = 2;

int initLEDs()
{
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_init(LED_Y);
    gpio_set_dir(LED_Y, GPIO_OUT);
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
}

int zeroLEDs()
{
    gpio_put(LED_R, 0);
    gpio_put(LED_Y, 0);
    gpio_put(LED_G, 0);
}

static bool get_led_state(uint led_target)
{
    bool state = gpio_get(led_target);
    return state;
}

static void led_on(uint led_target)
{
    gpio_put(led_target, 1);
}

static void led_off(uint led_target)
{
    gpio_put(led_target, 0);
}

void toggleLED(uint8_t led_id)
{
    bool state = get_led_state(led_id);
    char ledLabel[10];
    switch (led_id)
    {
    case 0:
        strcpy(ledLabel, "RED");
        break;
    case 1:
        strcpy(ledLabel, "YELLOW");
        break;
    case 2:
        strcpy(ledLabel, "GREEN");
        break;
    default: // do nothing
    }

    if (state == 1)
    {
        led_off(led_id);
        printf("LED TOGGLED OFF: %s\n", ledLabel);
    }
    else
    {
        led_on(led_id);
        printf("LED TOGGLED ON: %s\n", ledLabel);
    }
}
#endif