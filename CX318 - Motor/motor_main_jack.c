//#include <msp430.h>
//
//#include "msp430g2553.h" // make sure you change the header to suit your particular device.
//
//// Connect the motor SIGNAL wire to P1.2 through a 1K resistor.
//
//#define MCU_CLOCK           1000000
//#define PWM_FREQUENCY       1000      // In Hertz, ideally 50Hz.
//
//#define motor_STEPS         100     // Maximum amount of steps in degrees (180 is common)
//#define motor_MIN           0     // The minimum duty cycle for this motor
//#define motor_MAX           1000    // The maximum duty cycle
//
//unsigned int PWM_Period     = (MCU_CLOCK / PWM_FREQUENCY);  // PWM Period
//unsigned int PWM_Duty       = 0;                            // %
//
//void main (void){
//
//    unsigned int motor_stepval, motor_stepnow;
//    unsigned int motor_lut[ motor_STEPS+1 ];
//    unsigned int i;
//
//    // Calculate the step value and define the current step, defaults to minimum.
//    motor_stepval   = ( (motor_MAX - motor_MIN) / motor_STEPS );
//    motor_stepnow   = motor_MIN;
//
//    // Fill up the LUT
//    for (i = 0; i < motor_STEPS; i++) {
//        motor_stepnow += motor_stepval;
//        motor_lut[i] = motor_stepnow;
//    }
//
//    // Setup the PWM, etc.
//    WDTCTL  = WDTPW + WDTHOLD;     // Kill watchdog timer RIP
//    TACCTL1 = OUTMOD_7;            // TACCR1 reset/set
//    TACTL   = TASSEL_2 + MC_1;     // SMCLK, upmode
//    TACCR0  = PWM_Period-1;        // PWM Period
//    TACCR1  = PWM_Duty;            // TACCR1 PWM Duty Cycle
//    P1DIR   |= BIT2;               // P1.2 = output
//    P1SEL   |= BIT2;               // P1.2 = TA1 output
//                           // P2.2 Selection
//    P2DIR &=~BIT0;
//    // Main loop
//    while (1){
////        if((P2IN & 0x04) && (P2IN & 0x02)){
////            TACCR1 = motor_lut[90];
////        }
////        else if(P2IN & 0x04){
////            TACCR1 = motor_lut[0];
////        }
////        else if(P2IN & 0x02){
////            TACCR1 = motor_lut[179];
////        }
////        else{
////            TACCR1 = motor_lut[90];
////        }
//        TACCR1 = motor_lut[50];
//
//        __delay_cycles(1000);
//
//
//        // Go to 0°
////        TACCR1 = motor_lut[0];
////        __delay_cycles(1000000);
////
////        // Go to 45°
////        TACCR1 = motor_lut[45];
////        __delay_cycles(1000000);
////
////         Go to 90°
////        TACCR1 = motor_lut[90];
////        __delay_cycles(1000000);
////
////        // Go to 180°
////        TACCR1 = motor_lut[179];
////        __delay_cycles(1000000);
//
//        // Move forward toward the maximum step value
////                for (i = 0; i < motor_STEPS; i++) {
////                    TACCR1 = motor_lut[i];
////                    __delay_cycles(2000);      }
////        // Move backward toward the minimum step value
////                for (i = motor_STEPS; i > 0; i--) {
////                    TACCR1 = motor_lut[i];
////                    __delay_cycles(2000);
////                }
//        }
//
//}
//
