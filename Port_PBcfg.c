/*
 * Module : PORT
 *
 * File name: Port_PBcfg.h
 *
 * Description: Post Build configuration file for TM4C123GH6PM Micro-controller - Port Driver
 *
 * Author: Mario Kaldas
 */


/* Module Version 4.0.3 */
#define PORT_PBCFG_SW_MAJOR_VERSION           (1U)
#define PORT_PBCFG_SW_MINOR_VERSION           (0U)
#define PORT_PBCFG_SW_PATCH_VERSION           (0U)

/* AUTOSAR Version 4.0.3 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION   (3U)


#include"Port.h"

/* Check if Port_PBcfg and Port SW versions are compatible */
#if((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION) ||\
        (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION) ||\
        (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION)   \
)
#error "The SW version of Port doesn'y match the expected version "
#endif

/* Check if Port_PBcfg and Port AUTOSAR versions are compatible */
#if((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) ||\
        (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION) ||\
        (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION)   \
)
#error "The AUTOSAR version of Port doesn'y match the expected version "
#endif


const Port_ConfigType Port_configurations = {

                                             {

                                              {PORTA_PIN0_DIRECTION, PORTA_PIN0_DIRECTION_CHANGEABLE, PORTA_PIN0_INITIAL_MODE, PORTA_PIN0_MODE_CHANGEABLE, PORTA_PIN0_MODE, PORTA_PIN0_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTA_PIN1_DIRECTION, PORTA_PIN1_DIRECTION_CHANGEABLE, PORTA_PIN1_INITIAL_MODE, PORTA_PIN1_MODE_CHANGEABLE, PORTA_PIN1_MODE, PORTA_PIN1_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTA_PIN2_DIRECTION, PORTA_PIN2_DIRECTION_CHANGEABLE, PORTA_PIN2_INITIAL_MODE, PORTA_PIN2_MODE_CHANGEABLE, PORTA_PIN2_MODE, PORTA_PIN2_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTA_PIN3_DIRECTION, PORTA_PIN3_DIRECTION_CHANGEABLE, PORTA_PIN3_INITIAL_MODE, PORTA_PIN3_MODE_CHANGEABLE, PORTA_PIN3_MODE, PORTA_PIN3_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTA_PIN4_DIRECTION, PORTA_PIN4_DIRECTION_CHANGEABLE, PORTA_PIN4_INITIAL_MODE, PORTA_PIN4_MODE_CHANGEABLE, PORTA_PIN4_MODE, PORTA_PIN4_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTA_PIN5_DIRECTION, PORTA_PIN5_DIRECTION_CHANGEABLE, PORTA_PIN5_INITIAL_MODE, PORTA_PIN5_MODE_CHANGEABLE, PORTA_PIN5_MODE, PORTA_PIN5_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTA_PIN6_DIRECTION, PORTA_PIN6_DIRECTION_CHANGEABLE, PORTA_PIN6_INITIAL_MODE, PORTA_PIN6_MODE_CHANGEABLE, PORTA_PIN6_MODE, PORTA_PIN6_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTA_PIN7_DIRECTION, PORTA_PIN7_DIRECTION_CHANGEABLE, PORTA_PIN7_INITIAL_MODE, PORTA_PIN7_MODE_CHANGEABLE, PORTA_PIN7_MODE, PORTA_PIN7_LEVEL_VALUE, NO_RESISTOR },

                                              {PORTB_PIN0_DIRECTION, PORTB_PIN0_DIRECTION_CHANGEABLE, PORTB_PIN0_INITIAL_MODE, PORTB_PIN0_MODE_CHANGEABLE, PORTB_PIN0_MODE, PORTB_PIN0_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTB_PIN1_DIRECTION, PORTB_PIN1_DIRECTION_CHANGEABLE, PORTB_PIN1_INITIAL_MODE, PORTB_PIN1_MODE_CHANGEABLE, PORTB_PIN1_MODE, PORTB_PIN1_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTB_PIN2_DIRECTION, PORTB_PIN2_DIRECTION_CHANGEABLE, PORTB_PIN2_INITIAL_MODE, PORTB_PIN2_MODE_CHANGEABLE, PORTB_PIN2_MODE, PORTB_PIN2_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTB_PIN3_DIRECTION, PORTB_PIN3_DIRECTION_CHANGEABLE, PORTB_PIN3_INITIAL_MODE, PORTB_PIN3_MODE_CHANGEABLE, PORTB_PIN3_MODE, PORTB_PIN3_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTB_PIN4_DIRECTION, PORTB_PIN4_DIRECTION_CHANGEABLE, PORTB_PIN4_INITIAL_MODE, PORTB_PIN4_MODE_CHANGEABLE, PORTB_PIN4_MODE, PORTB_PIN4_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTB_PIN5_DIRECTION, PORTB_PIN5_DIRECTION_CHANGEABLE, PORTB_PIN5_INITIAL_MODE, PORTB_PIN5_MODE_CHANGEABLE, PORTB_PIN5_MODE, PORTB_PIN5_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTB_PIN6_DIRECTION, PORTB_PIN6_DIRECTION_CHANGEABLE, PORTB_PIN6_INITIAL_MODE, PORTB_PIN6_MODE_CHANGEABLE, PORTB_PIN6_MODE, PORTB_PIN6_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTB_PIN7_DIRECTION, PORTB_PIN7_DIRECTION_CHANGEABLE, PORTB_PIN7_INITIAL_MODE, PORTB_PIN7_MODE_CHANGEABLE, PORTB_PIN7_MODE, PORTB_PIN7_LEVEL_VALUE, NO_RESISTOR },

                                              {PORTC_PIN0_DIRECTION, PORTC_PIN0_DIRECTION_CHANGEABLE, PORTC_PIN0_INITIAL_MODE, PORTC_PIN0_MODE_CHANGEABLE, PORTC_PIN0_MODE, PORTC_PIN0_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTC_PIN1_DIRECTION, PORTC_PIN1_DIRECTION_CHANGEABLE, PORTC_PIN1_INITIAL_MODE, PORTC_PIN1_MODE_CHANGEABLE, PORTC_PIN1_MODE, PORTC_PIN1_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTC_PIN2_DIRECTION, PORTC_PIN2_DIRECTION_CHANGEABLE, PORTC_PIN2_INITIAL_MODE, PORTC_PIN2_MODE_CHANGEABLE, PORTC_PIN2_MODE, PORTC_PIN2_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTC_PIN3_DIRECTION, PORTC_PIN3_DIRECTION_CHANGEABLE, PORTC_PIN3_INITIAL_MODE, PORTC_PIN3_MODE_CHANGEABLE, PORTC_PIN3_MODE, PORTC_PIN3_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTC_PIN4_DIRECTION, PORTC_PIN4_DIRECTION_CHANGEABLE, PORTC_PIN4_INITIAL_MODE, PORTC_PIN4_MODE_CHANGEABLE, PORTC_PIN4_MODE, PORTC_PIN4_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTC_PIN5_DIRECTION, PORTC_PIN5_DIRECTION_CHANGEABLE, PORTC_PIN5_INITIAL_MODE, PORTC_PIN5_MODE_CHANGEABLE, PORTC_PIN5_MODE, PORTC_PIN5_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTC_PIN6_DIRECTION, PORTC_PIN6_DIRECTION_CHANGEABLE, PORTC_PIN6_INITIAL_MODE, PORTC_PIN6_MODE_CHANGEABLE, PORTC_PIN6_MODE, PORTC_PIN6_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTC_PIN7_DIRECTION, PORTC_PIN7_DIRECTION_CHANGEABLE, PORTC_PIN7_INITIAL_MODE, PORTC_PIN7_MODE_CHANGEABLE, PORTC_PIN7_MODE, PORTC_PIN7_LEVEL_VALUE, NO_RESISTOR },

                                              {PORTD_PIN0_DIRECTION, PORTD_PIN0_DIRECTION_CHANGEABLE, PORTD_PIN0_INITIAL_MODE, PORTD_PIN0_MODE_CHANGEABLE, PORTD_PIN0_MODE, PORTD_PIN0_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTD_PIN1_DIRECTION, PORTD_PIN1_DIRECTION_CHANGEABLE, PORTD_PIN1_INITIAL_MODE, PORTD_PIN1_MODE_CHANGEABLE, PORTD_PIN1_MODE, PORTD_PIN1_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTD_PIN2_DIRECTION, PORTD_PIN2_DIRECTION_CHANGEABLE, PORTD_PIN2_INITIAL_MODE, PORTD_PIN2_MODE_CHANGEABLE, PORTD_PIN2_MODE, PORTD_PIN2_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTD_PIN3_DIRECTION, PORTD_PIN3_DIRECTION_CHANGEABLE, PORTD_PIN3_INITIAL_MODE, PORTD_PIN3_MODE_CHANGEABLE, PORTD_PIN3_MODE, PORTD_PIN3_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTD_PIN4_DIRECTION, PORTD_PIN4_DIRECTION_CHANGEABLE, PORTD_PIN4_INITIAL_MODE, PORTD_PIN4_MODE_CHANGEABLE, PORTD_PIN4_MODE, PORTD_PIN4_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTD_PIN5_DIRECTION, PORTD_PIN5_DIRECTION_CHANGEABLE, PORTD_PIN5_INITIAL_MODE, PORTD_PIN5_MODE_CHANGEABLE, PORTD_PIN5_MODE, PORTD_PIN5_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTD_PIN6_DIRECTION, PORTD_PIN6_DIRECTION_CHANGEABLE, PORTD_PIN6_INITIAL_MODE, PORTD_PIN6_MODE_CHANGEABLE, PORTD_PIN6_MODE, PORTD_PIN6_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTD_PIN7_DIRECTION, PORTD_PIN7_DIRECTION_CHANGEABLE, PORTD_PIN7_INITIAL_MODE, PORTD_PIN7_MODE_CHANGEABLE, PORTD_PIN7_MODE, PORTD_PIN7_LEVEL_VALUE, NO_RESISTOR },

                                              {PORTE_PIN0_DIRECTION, PORTE_PIN0_DIRECTION_CHANGEABLE, PORTE_PIN0_INITIAL_MODE, PORTE_PIN0_MODE_CHANGEABLE, PORTE_PIN0_MODE, PORTE_PIN0_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTE_PIN1_DIRECTION, PORTE_PIN1_DIRECTION_CHANGEABLE, PORTE_PIN1_INITIAL_MODE, PORTE_PIN1_MODE_CHANGEABLE, PORTE_PIN1_MODE, PORTE_PIN1_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTE_PIN2_DIRECTION, PORTE_PIN2_DIRECTION_CHANGEABLE, PORTE_PIN2_INITIAL_MODE, PORTE_PIN2_MODE_CHANGEABLE, PORTE_PIN2_MODE, PORTE_PIN2_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTE_PIN3_DIRECTION, PORTE_PIN3_DIRECTION_CHANGEABLE, PORTE_PIN3_INITIAL_MODE, PORTE_PIN3_MODE_CHANGEABLE, PORTE_PIN3_MODE, PORTE_PIN3_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTE_PIN4_DIRECTION, PORTE_PIN4_DIRECTION_CHANGEABLE, PORTE_PIN4_INITIAL_MODE, PORTE_PIN4_MODE_CHANGEABLE, PORTE_PIN4_MODE, PORTE_PIN4_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTE_PIN5_DIRECTION, PORTE_PIN5_DIRECTION_CHANGEABLE, PORTE_PIN5_INITIAL_MODE, PORTE_PIN5_MODE_CHANGEABLE, PORTE_PIN5_MODE, PORTE_PIN5_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTE_PIN6_DIRECTION, PORTE_PIN6_DIRECTION_CHANGEABLE, PORTE_PIN6_INITIAL_MODE, PORTE_PIN6_MODE_CHANGEABLE, PORTE_PIN6_MODE, PORTE_PIN6_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTE_PIN7_DIRECTION, PORTE_PIN7_DIRECTION_CHANGEABLE, PORTE_PIN7_INITIAL_MODE, PORTE_PIN7_MODE_CHANGEABLE, PORTE_PIN7_MODE, PORTE_PIN7_LEVEL_VALUE, NO_RESISTOR },

                                              {PORTF_PIN0_DIRECTION, PORTF_PIN0_DIRECTION_CHANGEABLE, PORTF_PIN0_INITIAL_MODE, PORTF_PIN0_MODE_CHANGEABLE, PORTF_PIN0_MODE, PORTF_PIN0_LEVEL_VALUE, PULLUP_RESISTOR },
                                              {PORTF_PIN1_DIRECTION, PORTF_PIN1_DIRECTION_CHANGEABLE, PORTF_PIN1_INITIAL_MODE, PORTF_PIN1_MODE_CHANGEABLE, PORTF_PIN1_MODE, PORTF_PIN1_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTF_PIN2_DIRECTION, PORTF_PIN2_DIRECTION_CHANGEABLE, PORTF_PIN2_INITIAL_MODE, PORTF_PIN2_MODE_CHANGEABLE, PORTF_PIN2_MODE, PORTF_PIN2_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTF_PIN3_DIRECTION, PORTF_PIN3_DIRECTION_CHANGEABLE, PORTF_PIN3_INITIAL_MODE, PORTF_PIN3_MODE_CHANGEABLE, PORTF_PIN3_MODE, PORTF_PIN3_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTF_PIN4_DIRECTION, PORTF_PIN4_DIRECTION_CHANGEABLE, PORTF_PIN4_INITIAL_MODE, PORTF_PIN4_MODE_CHANGEABLE, PORTF_PIN4_MODE, PORTF_PIN4_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTF_PIN5_DIRECTION, PORTF_PIN5_DIRECTION_CHANGEABLE, PORTF_PIN5_INITIAL_MODE, PORTF_PIN5_MODE_CHANGEABLE, PORTF_PIN5_MODE, PORTF_PIN5_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTF_PIN6_DIRECTION, PORTF_PIN6_DIRECTION_CHANGEABLE, PORTF_PIN6_INITIAL_MODE, PORTF_PIN6_MODE_CHANGEABLE, PORTF_PIN6_MODE, PORTF_PIN6_LEVEL_VALUE, NO_RESISTOR },
                                              {PORTF_PIN7_DIRECTION, PORTF_PIN7_DIRECTION_CHANGEABLE, PORTF_PIN7_INITIAL_MODE, PORTF_PIN7_MODE_CHANGEABLE, PORTF_PIN7_MODE, PORTF_PIN7_LEVEL_VALUE, NO_RESISTOR },
                                             }

};

