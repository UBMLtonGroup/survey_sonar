#include <stdbool.h>
#include <stdint.h>


// ---- This source is automatically generated by Atom ----
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

bool g_sensor_ready;
uint16_t g_sensor_value;
void sensor_on(void);
void sensor_off(void);
void sensor_trigger(void);


static uint64_t __global_clock = 0;






struct {  /* state_example */
  struct {  /* atom_example */
    uint64_t clock_sec;
    struct {  /* check_sensor */
      uint64_t warmup;
      bool triggered;
      bool sensor_on;
    } check_sensor;
  } atom_example;
} state_example =
{  /* state_example */
  {  /* atom_example */
    /* clock_sec */  0ULL,
    {  /* check_sensor */
      /* warmup */  0ULL,
      /* triggered */  false,
      /* sensor_on */  false
    }
  }
};

/* atom_example.second */
static void __r0() {
  bool __0 = true;
  uint64_t __1 = state_example.atom_example.clock_sec;
  uint64_t __2 = 1ULL;
  uint64_t __3 = __1 + __2;
  if (__0) {
  }
  state_example.atom_example.clock_sec = __3;
}

/* atom_example.check_sensor.powerOn */
static void __r1() {
  bool __0 = true;
  bool __1 = false;
  uint64_t __2 = __global_clock;
  uint64_t __3 = 10ULL;
  uint64_t __4 = __2 + __3;
  if (__0) {
    sensor_on();
  }
  state_example.atom_example.check_sensor.triggered = __1;
  g_sensor_ready = __1;
  state_example.atom_example.check_sensor.sensor_on = __0;
  state_example.atom_example.check_sensor.warmup = __4;
}

/* atom_example.check_sensor.powerOff */
static void __r5() {
  bool __0 = state_example.atom_example.check_sensor.sensor_on;
  bool __1 = ! __0;
  bool __2 = g_sensor_ready;
  bool __3 = __1 && __2;
  if (__0) {
    printf("Sensor timeout.\n");
    sensor_off();
  }
  g_sensor_ready = __3;
}

/* atom_example.check_sensor.trigger */
static void __r2() {
  bool __0 = state_example.atom_example.check_sensor.sensor_on;
  bool __1 = state_example.atom_example.check_sensor.triggered;
  bool __2 = ! __1;
  uint64_t __3 = __global_clock;
  uint64_t __4 = state_example.atom_example.check_sensor.warmup;
  bool __5 = __3 < __4;
  bool __6 = ! __5;
  bool __7 = __0 && __2 && __6;
  bool __8 = __6 && __2 && __0;
  bool __9 = ! __8;
  bool __10 = __9 && __1;
  bool __11 = ! __10;
  bool __12 = __9 && __11;
  bool __13 = ! __12;
  if (__7) {
    sensor_trigger();
  }
  state_example.atom_example.check_sensor.triggered = __13;
}

/* atom_example.check_sensor.checkSensorValue.checkThreshold */
static void __r3() {
  uint16_t __0 = 40000;
  uint16_t __1 = g_sensor_value;
  bool __2 = __0 < __1;
  bool __3 = g_sensor_ready;
  bool __4 = __2 && __3;
  if (__4) {
    printf("Sensor value over threshold!\n");
  }
}

/* atom_example.check_sensor.checkSensorValue */
static void __r4() {
  bool __0 = g_sensor_ready;
  bool __1 = false;
  bool __2 = ! __0;
  bool __3 = state_example.atom_example.check_sensor.sensor_on;
  bool __4 = __2 && __3;
  if (__0) {
    sensor_off();
  }
  g_sensor_ready = __1;
  state_example.atom_example.check_sensor.sensor_on = __4;
}


static void __assertion_checks() {
}


void atom_tick()
{

  {
    static uint16_t __scheduling_clock = 0;
    if (__scheduling_clock == 0) {
      __assertion_checks(); __r0();  /* atom_example.second */
      __scheduling_clock = 999;
    }
    else {
      __scheduling_clock = __scheduling_clock - 1;
    }
  }
  {
    static uint16_t __scheduling_clock = 500;
    if (__scheduling_clock == 0) {
      __assertion_checks(); __r1();  /* atom_example.check_sensor.powerOn */
      __scheduling_clock = 1999;
    }
    else {
      __scheduling_clock = __scheduling_clock - 1;
    }
  }
  {
    static uint16_t __scheduling_clock = 550;
    if (__scheduling_clock == 0) {
      __assertion_checks(); __r5();  /* atom_example.check_sensor.powerOff */
      __scheduling_clock = 1999;
    }
    else {
      __scheduling_clock = __scheduling_clock - 1;
    }
  }
  {
    static uint8_t __scheduling_clock = 0;
    if (__scheduling_clock == 0) {
      __assertion_checks(); __r2();  /* atom_example.check_sensor.trigger */
      __assertion_checks(); __r3();  /* atom_example.check_sensor.checkSensorValue.checkThreshold */
      __assertion_checks(); __r4();  /* atom_example.check_sensor.checkSensorValue */
      __scheduling_clock = 0;
    }
    else {
      __scheduling_clock = __scheduling_clock - 1;
    }
  }

  __global_clock = __global_clock + 1;

}

int main(void) {
    while (true) {
        atom_tick();
        usleep(1000);
    }
    return 0;
}
void sensor_on(void) {
    printf("%lu: sensor_on()\n", __global_clock);
}

void sensor_off(void) {
    printf("%lu: sensor_off()\n", __global_clock);
}

void sensor_trigger(void) {
    if (rand() % 4) {
        g_sensor_value = rand();
        g_sensor_ready = true;
        printf("%lu: Triggered sensor, value=%u\n",
               __global_clock, g_sensor_value);
    }
}

// ---- End automatically-generated source ----
