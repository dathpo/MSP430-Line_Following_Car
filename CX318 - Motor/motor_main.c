#include <msp430.h> 

#include "msp430g2553.h" // make sure you change the header to suit your particular device.

// Connect the servo SIGNAL wire to P1.2 through a 1K resistor.

#define MCU_CLOCK           1000000
#define PWM_FREQUENCY       50    // In Hertz, ideally 50Hz.

#define MOTOR_STEPS         180     // Maximum amount of steps in degrees (180 is common)
#define MOTOR_MIN           0     // The minimum duty cycle for this servo
#define MOTOR_MAX           2700*8    // The maximum duty cycle

unsigned int PWM_Period     = (MCU_CLOCK / PWM_FREQUENCY);  // PWM Period
unsigned int PWM_Duty       = 0;                            // %

void main (void){

    unsigned int motor_stepval, motor_stepnow;
    unsigned int motor_lut[ MOTOR_STEPS+1 ];
    unsigned int i;

    // Calculate the step value and define the current step, defaults to minimum.
    motor_stepval   = ( (MOTOR_MAX - MOTOR_MIN) / MOTOR_STEPS );
    motor_stepnow   = MOTOR_MIN;

    // Fill up the LUT
    for (i = 0; i < MOTOR_STEPS; i++) {
        motor_stepnow += motor_stepval;
        motor_lut[i] = motor_stepnow;
    }

    // Setup the PWM, etc.
    WDTCTL  = WDTPW + WDTHOLD;     // Kill watchdog timer
    TACCTL1 = OUTMOD_7;            // TACCR1 reset/set
    TACTL   = TASSEL_2 + MC_1;     // SMCLK, upmode
    TACCR0  = PWM_Period-1;        // PWM Period
    TACCR1  = PWM_Duty;            // TACCR1 PWM Duty Cycle
    P1DIR   |= BIT2;               // P1.2 = output
    P1SEL   |= BIT2;               // P1.2 = TA1 output
                           // P2.2 Selection
    // Main loop
    while (1){
//         Move forward toward the maximum step value
                for (i = 0; i < MOTOR_STEPS; i++) {
                    TACCR1 = motor_lut[i];
                    __delay_cycles(100000);
                }
        // Move backward toward the minimum step value
                for (i = MOTOR_STEPS; i > 0; i--) {
                    TACCR1 = motor_lut[i];
                    __delay_cycles(100000);
                }
        }
}
