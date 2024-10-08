/*
 * Module : PORT
 *
 * File name: Port_Cfg.h
 *
 * Description: pre-compiled configuration file for TM4C123GH6PM Micro-controller - Port Driver
 *
 * Author: Mario Kaldas
 */

#ifndef PORT_CFG_H_
#define PORT_CFG_H_


/* Module Version 4.0.3 */
#define PORT_CFG_SW_MAJOR_VERSION           (1U)
#define PORT_CFG_SW_MINOR_VERSION           (0U)
#define PORT_CFG_SW_PATCH_VERSION           (0U)

/* AUTOSAR Version 4.0.3 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION   (3U)




/* Switches the Development Error Detection and Notification on or off. */
#define PORT_DEV_ERROR_DETECT   (STD_ON)

/* Pre-processor switch to enable / disable the use of the functionPort_SetPinDirection(). */
#define PORT_SET_PIN_DIRECTION_API  (STD_ON)

/* Pre-processor switch to enable / disable the use of the function Port_SetPinMode() */
#define PORT_SET_PIN_MODE_API   (STD_ON)

/* Pre-processor switch to enable / disable the API to read out the modules version information. */
#define PORT_VERSION_INFO_API (STD_ON)


/* Total number of pins in tm4c123gh6pm (8 pins * 6 ports) */
#define TOTAL_NUMBER_OF_PINS        (48U)

/* number of pins per every port */
#define NUMBER_OF_PINS_PER_PORT     (8)


/*******************************************************************************************
 *                                           PORTA
 ******************************************************************************************/

/* The number of specified PortPins in this PortA. */
#define PortContainer_PORT_A_NUM_OF_PINS (8U)


#define PORTA_PIN0_ID                       (0U)
#define PORTA_PIN0_DIRECTION                (PORT_PIN_IN)
#define PORTA_PIN0_DIRECTION_CHANGEABLE     (TRUE)
#define PORTA_PIN0_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTA_PIN0_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTA_PIN0_MODE                     (PORT_PIN_MODE_DIO)
#define PORTA_PIN0_MODE_CHANGEABLE          (TRUE)

#define PORTA_PIN1_ID                       (1U)
#define PORTA_PIN1_DIRECTION                (PORT_PIN_IN)
#define PORTA_PIN1_DIRECTION_CHANGEABLE     (TRUE)
#define PORTA_PIN1_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTA_PIN1_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTA_PIN1_MODE                     (PORT_PIN_MODE_DIO)
#define PORTA_PIN1_MODE_CHANGEABLE          (TRUE)

#define PORTA_PIN2_ID                       (2U)
#define PORTA_PIN2_DIRECTION                (PORT_PIN_IN)
#define PORTA_PIN2_DIRECTION_CHANGEABLE     (TRUE)
#define PORTA_PIN2_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTA_PIN2_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTA_PIN2_MODE                     (PORT_PIN_MODE_DIO)
#define PORTA_PIN2_MODE_CHANGEABLE          (TRUE)

#define PORTA_PIN3_ID                       (3U)
#define PORTA_PIN3_DIRECTION                (PORT_PIN_IN)
#define PORTA_PIN3_DIRECTION_CHANGEABLE     (TRUE)
#define PORTA_PIN3_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTA_PIN3_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTA_PIN3_MODE                     (PORT_PIN_MODE_DIO)
#define PORTA_PIN3_MODE_CHANGEABLE          (TRUE)

#define PORTA_PIN4_ID                       (4U)
#define PORTA_PIN4_DIRECTION                (PORT_PIN_IN)
#define PORTA_PIN4_DIRECTION_CHANGEABLE     (TRUE)
#define PORTA_PIN4_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTA_PIN4_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTA_PIN4_MODE                     (PORT_PIN_MODE_DIO)
#define PORTA_PIN4_MODE_CHANGEABLE          (TRUE)

#define PORTA_PIN5_ID                       (5U)
#define PORTA_PIN5_DIRECTION                (PORT_PIN_IN)
#define PORTA_PIN5_DIRECTION_CHANGEABLE     (TRUE)
#define PORTA_PIN5_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTA_PIN5_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTA_PIN5_MODE                     (PORT_PIN_MODE_DIO)
#define PORTA_PIN5_MODE_CHANGEABLE          (TRUE)

#define PORTA_PIN6_ID                       (6U)
#define PORTA_PIN6_DIRECTION                (PORT_PIN_IN)
#define PORTA_PIN6_DIRECTION_CHANGEABLE     (TRUE)
#define PORTA_PIN6_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTA_PIN6_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTA_PIN6_MODE                     (PORT_PIN_MODE_DIO)
#define PORTA_PIN6_MODE_CHANGEABLE          (TRUE)

#define PORTA_PIN7_ID                       (7U)
#define PORTA_PIN7_DIRECTION                (PORT_PIN_IN)
#define PORTA_PIN7_DIRECTION_CHANGEABLE     (TRUE)
#define PORTA_PIN7_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTA_PIN7_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTA_PIN7_MODE                     (PORT_PIN_MODE_DIO)
#define PORTA_PIN7_MODE_CHANGEABLE          (TRUE)


/*******************************************************************************************
 *                                           PORTB
 ******************************************************************************************/

/* The number of specified PortPins in this PortB. */
#define PortContainer_PORT_B_NUM_OF_PINS (8U)


#define PORTB_PIN0_ID                       (8U)
#define PORTB_PIN0_DIRECTION                (PORT_PIN_IN)
#define PORTB_PIN0_DIRECTION_CHANGEABLE     (TRUE)
#define PORTB_PIN0_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTB_PIN0_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTB_PIN0_MODE                     (PORT_PIN_MODE_DIO)
#define PORTB_PIN0_MODE_CHANGEABLE          (TRUE)

#define PORTB_PIN1_ID                       (9U)
#define PORTB_PIN1_DIRECTION                (PORT_PIN_IN)
#define PORTB_PIN1_DIRECTION_CHANGEABLE     (TRUE)
#define PORTB_PIN1_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTB_PIN1_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTB_PIN1_MODE                     (PORT_PIN_MODE_DIO)
#define PORTB_PIN1_MODE_CHANGEABLE          (TRUE)

#define PORTB_PIN2_ID                       (10U)
#define PORTB_PIN2_DIRECTION                (PORT_PIN_IN)
#define PORTB_PIN2_DIRECTION_CHANGEABLE     (TRUE)
#define PORTB_PIN2_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTB_PIN2_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTB_PIN2_MODE                     (PORT_PIN_MODE_DIO)
#define PORTB_PIN2_MODE_CHANGEABLE          (TRUE)

#define PORTB_PIN3_ID                       (11U)
#define PORTB_PIN3_DIRECTION                (PORT_PIN_IN)
#define PORTB_PIN3_DIRECTION_CHANGEABLE     (TRUE)
#define PORTB_PIN3_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTB_PIN3_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTB_PIN3_MODE                     (PORT_PIN_MODE_DIO)
#define PORTB_PIN3_MODE_CHANGEABLE          (TRUE)

#define PORTB_PIN4_ID                       (12U)
#define PORTB_PIN4_DIRECTION                (PORT_PIN_IN)
#define PORTB_PIN4_DIRECTION_CHANGEABLE     (TRUE)
#define PORTB_PIN4_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTB_PIN4_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTB_PIN4_MODE                     (PORT_PIN_MODE_DIO)
#define PORTB_PIN4_MODE_CHANGEABLE          (TRUE)

#define PORTB_PIN5_ID                       (13U)
#define PORTB_PIN5_DIRECTION                (PORT_PIN_IN)
#define PORTB_PIN5_DIRECTION_CHANGEABLE     (TRUE)
#define PORTB_PIN5_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTB_PIN5_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTB_PIN5_MODE                     (PORT_PIN_MODE_DIO)
#define PORTB_PIN5_MODE_CHANGEABLE          (TRUE)

#define PORTB_PIN6_ID                       (14U)
#define PORTB_PIN6_DIRECTION                (PORT_PIN_IN)
#define PORTB_PIN6_DIRECTION_CHANGEABLE     (TRUE)
#define PORTB_PIN6_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTB_PIN6_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTB_PIN6_MODE                     (PORT_PIN_MODE_DIO)
#define PORTB_PIN6_MODE_CHANGEABLE          (TRUE)

#define PORTB_PIN7_ID                       (15U)
#define PORTB_PIN7_DIRECTION                (PORT_PIN_IN)
#define PORTB_PIN7_DIRECTION_CHANGEABLE     (TRUE)
#define PORTB_PIN7_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTB_PIN7_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTB_PIN7_MODE                     (PORT_PIN_MODE_DIO)
#define PORTB_PIN7_MODE_CHANGEABLE          (TRUE)


/*******************************************************************************************
 *                                           PORTC
 ******************************************************************************************/
/* The number of specified PortPins in this PortC. */
#define PortContainer_PORT_C_NUM_OF_PINS (8)


#define PORTC_PIN0_ID                       (16U)
#define PORTC_PIN0_DIRECTION                (PORT_PIN_IN)
#define PORTC_PIN0_DIRECTION_CHANGEABLE     (TRUE)
#define PORTC_PIN0_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTC_PIN0_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTC_PIN0_MODE                     (PORT_PIN_MODE_DIO)
#define PORTC_PIN0_MODE_CHANGEABLE          (TRUE)

#define PORTC_PIN1_ID                       (17U)
#define PORTC_PIN1_DIRECTION                (PORT_PIN_IN)
#define PORTC_PIN1_DIRECTION_CHANGEABLE     (TRUE)
#define PORTC_PIN1_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTC_PIN1_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTC_PIN1_MODE                     (PORT_PIN_MODE_DIO)
#define PORTC_PIN1_MODE_CHANGEABLE          (TRUE)

#define PORTC_PIN2_ID                       (18U)
#define PORTC_PIN2_DIRECTION                (PORT_PIN_IN)
#define PORTC_PIN2_DIRECTION_CHANGEABLE     (TRUE)
#define PORTC_PIN2_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTC_PIN2_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTC_PIN2_MODE                     (PORT_PIN_MODE_DIO)
#define PORTC_PIN2_MODE_CHANGEABLE          (TRUE)

#define PORTC_PIN3_ID                       (19U)
#define PORTC_PIN3_DIRECTION                (PORT_PIN_IN)
#define PORTC_PIN3_DIRECTION_CHANGEABLE     (TRUE)
#define PORTC_PIN3_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTC_PIN3_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTC_PIN3_MODE                     (PORT_PIN_MODE_DIO)
#define PORTC_PIN3_MODE_CHANGEABLE          (TRUE)

#define PORTC_PIN4_ID                       (20U)
#define PORTC_PIN4_DIRECTION                (PORT_PIN_IN)
#define PORTC_PIN4_DIRECTION_CHANGEABLE     (TRUE)
#define PORTC_PIN4_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTC_PIN4_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTC_PIN4_MODE                     (PORT_PIN_MODE_DIO)
#define PORTC_PIN4_MODE_CHANGEABLE          (TRUE)

#define PORTC_PIN5_ID                       (21U)
#define PORTC_PIN5_DIRECTION                (PORT_PIN_IN)
#define PORTC_PIN5_DIRECTION_CHANGEABLE     (TRUE)
#define PORTC_PIN5_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTC_PIN5_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTC_PIN5_MODE                     (PORT_PIN_MODE_DIO)
#define PORTC_PIN5_MODE_CHANGEABLE          (TRUE)

#define PORTC_PIN6_ID                       (22U)
#define PORTC_PIN6_DIRECTION                (PORT_PIN_IN)
#define PORTC_PIN6_DIRECTION_CHANGEABLE     (TRUE)
#define PORTC_PIN6_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTC_PIN6_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTC_PIN6_MODE                     (PORT_PIN_MODE_DIO)
#define PORTC_PIN6_MODE_CHANGEABLE          (TRUE)

#define PORTC_PIN7_ID                       (23U)
#define PORTC_PIN7_DIRECTION                (PORT_PIN_IN)
#define PORTC_PIN7_DIRECTION_CHANGEABLE     (TRUE)
#define PORTC_PIN7_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTC_PIN7_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTC_PIN7_MODE                     (PORT_PIN_MODE_DIO)
#define PORTC_PIN7_MODE_CHANGEABLE          (TRUE)


/*******************************************************************************************
 *                                           PORTD
 ******************************************************************************************/
/* The number of specified PortPins in this PortD. */
#define PortContainer_PORT_D_NUM_OF_PINS (8U)


#define PORTD_PIN0_ID                       (24U)
#define PORTD_PIN0_DIRECTION                (PORT_PIN_IN)
#define PORTD_PIN0_DIRECTION_CHANGEABLE     (TRUE)
#define PORTD_PIN0_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTD_PIN0_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTD_PIN0_MODE                     (PORT_PIN_MODE_DIO)
#define PORTD_PIN0_MODE_CHANGEABLE          (TRUE)

#define PORTD_PIN1_ID                       (25U)
#define PORTD_PIN1_DIRECTION                (PORT_PIN_IN)
#define PORTD_PIN1_DIRECTION_CHANGEABLE     (TRUE)
#define PORTD_PIN1_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTD_PIN1_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTD_PIN1_MODE                     (PORT_PIN_MODE_DIO)
#define PORTD_PIN1_MODE_CHANGEABLE          (TRUE)

#define PORTD_PIN2_ID                       (26U)
#define PORTD_PIN2_DIRECTION                (PORT_PIN_IN)
#define PORTD_PIN2_DIRECTION_CHANGEABLE     (TRUE)
#define PORTD_PIN2_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTD_PIN2_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTD_PIN2_MODE                     (PORT_PIN_MODE_DIO)
#define PORTD_PIN2_MODE_CHANGEABLE          (TRUE)

#define PORTD_PIN3_ID                       (27U)
#define PORTD_PIN3_DIRECTION                (PORT_PIN_IN)
#define PORTD_PIN3_DIRECTION_CHANGEABLE     (TRUE)
#define PORTD_PIN3_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTD_PIN3_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTD_PIN3_MODE                     (PORT_PIN_MODE_DIO)
#define PORTD_PIN3_MODE_CHANGEABLE          (TRUE)

#define PORTD_PIN4_ID                       (28U)
#define PORTD_PIN4_DIRECTION                (PORT_PIN_IN)
#define PORTD_PIN4_DIRECTION_CHANGEABLE     (TRUE)
#define PORTD_PIN4_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTD_PIN4_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTD_PIN4_MODE                     (PORT_PIN_MODE_DIO)
#define PORTD_PIN4_MODE_CHANGEABLE          (TRUE)

#define PORTD_PIN5_ID                       (29U)
#define PORTD_PIN5_DIRECTION                (PORT_PIN_IN)
#define PORTD_PIN5_DIRECTION_CHANGEABLE     (TRUE)
#define PORTD_PIN5_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTD_PIN5_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTD_PIN5_MODE                     (PORT_PIN_MODE_DIO)
#define PORTD_PIN5_MODE_CHANGEABLE          (TRUE)

#define PORTD_PIN6_ID                       (30U)
#define PORTD_PIN6_DIRECTION                (PORT_PIN_IN)
#define PORTD_PIN6_DIRECTION_CHANGEABLE     (TRUE)
#define PORTD_PIN6_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTD_PIN6_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTD_PIN6_MODE                     (PORT_PIN_MODE_DIO)
#define PORTD_PIN6_MODE_CHANGEABLE          (TRUE)

#define PORTD_PIN7_ID                       (31U)
#define PORTD_PIN7_DIRECTION                (PORT_PIN_IN)
#define PORTD_PIN7_DIRECTION_CHANGEABLE     (TRUE)
#define PORTD_PIN7_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTD_PIN7_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTD_PIN7_MODE                     (PORT_PIN_MODE_DIO)
#define PORTD_PIN7_MODE_CHANGEABLE          (TRUE)

/*******************************************************************************************
 *                                           PORTE
 ******************************************************************************************/
/* The number of specified PortPins in this PortE. */
#define PortContainer_PORT_E_NUM_OF_PINS (8U)


#define PORTE_PIN0_ID                       (32U)
#define PORTE_PIN0_DIRECTION                (PORT_PIN_IN)
#define PORTE_PIN0_DIRECTION_CHANGEABLE     (TRUE)
#define PORTE_PIN0_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTE_PIN0_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTE_PIN0_MODE                     (PORT_PIN_MODE_DIO)
#define PORTE_PIN0_MODE_CHANGEABLE          (TRUE)

#define PORTE_PIN1_ID                       (33U)
#define PORTE_PIN1_DIRECTION                (PORT_PIN_IN)
#define PORTE_PIN1_DIRECTION_CHANGEABLE     (TRUE)
#define PORTE_PIN1_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTE_PIN1_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTE_PIN1_MODE                     (PORT_PIN_MODE_DIO)
#define PORTE_PIN1_MODE_CHANGEABLE          (TRUE)

#define PORTE_PIN2_ID                       (34U)
#define PORTE_PIN2_DIRECTION                (PORT_PIN_IN)
#define PORTE_PIN2_DIRECTION_CHANGEABLE     (TRUE)
#define PORTE_PIN2_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTE_PIN2_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTE_PIN2_MODE                     (PORT_PIN_MODE_DIO)
#define PORTE_PIN2_MODE_CHANGEABLE          (TRUE)

#define PORTE_PIN3_ID                       (35U)
#define PORTE_PIN3_DIRECTION                (PORT_PIN_IN)
#define PORTE_PIN3_DIRECTION_CHANGEABLE     (TRUE)
#define PORTE_PIN3_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTE_PIN3_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTE_PIN3_MODE                     (PORT_PIN_MODE_DIO)
#define PORTE_PIN3_MODE_CHANGEABLE          (TRUE)

#define PORTE_PIN4_ID                       (36U)
#define PORTE_PIN4_DIRECTION                (PORT_PIN_IN)
#define PORTE_PIN4_DIRECTION_CHANGEABLE     (TRUE)
#define PORTE_PIN4_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTE_PIN4_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTE_PIN4_MODE                     (PORT_PIN_MODE_DIO)
#define PORTE_PIN4_MODE_CHANGEABLE          (TRUE)

#define PORTE_PIN5_ID                       (37U)
#define PORTE_PIN5_DIRECTION                (PORT_PIN_IN)
#define PORTE_PIN5_DIRECTION_CHANGEABLE     (TRUE)
#define PORTE_PIN5_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTE_PIN5_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTE_PIN5_MODE                     (PORT_PIN_MODE_DIO)
#define PORTE_PIN5_MODE_CHANGEABLE          (TRUE)

#define PORTE_PIN6_ID                       (38U)
#define PORTE_PIN6_DIRECTION                (PORT_PIN_IN)
#define PORTE_PIN6_DIRECTION_CHANGEABLE     (TRUE)
#define PORTE_PIN6_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTE_PIN6_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTE_PIN6_MODE                     (PORT_PIN_MODE_DIO)
#define PORTE_PIN6_MODE_CHANGEABLE          (TRUE)

#define PORTE_PIN7_ID                       (39U)
#define PORTE_PIN7_DIRECTION                (PORT_PIN_IN)
#define PORTE_PIN7_DIRECTION_CHANGEABLE     (TRUE)
#define PORTE_PIN7_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTE_PIN7_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTE_PIN7_MODE                     (PORT_PIN_MODE_DIO)
#define PORTE_PIN7_MODE_CHANGEABLE          (TRUE)


/*******************************************************************************************
 *                                           PORTF
 ******************************************************************************************/
/* The number of specified PortPins in this PortF. */
#define PortContainer_PORT_F_NUM_OF_PINS (8U)

#define PORTF_PIN0_ID                       (40U)
#define PORTF_PIN0_DIRECTION                (PORT_PIN_IN)
#define PORTF_PIN0_DIRECTION_CHANGEABLE     (TRUE)
#define PORTF_PIN0_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTF_PIN0_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTF_PIN0_MODE                     (PORT_PIN_MODE_DIO)
#define PORTF_PIN0_MODE_CHANGEABLE          (TRUE)

#define PORTF_PIN1_ID                       (41U)
#define PORTF_PIN1_DIRECTION                (PORT_PIN_OUT)
#define PORTF_PIN1_DIRECTION_CHANGEABLE     (FALSE)
#define PORTF_PIN1_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTF_PIN1_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTF_PIN1_MODE                     (PORT_PIN_MODE_DIO)
#define PORTF_PIN1_MODE_CHANGEABLE          (FALSE)

#define PORTF_PIN2_ID                       (42U)
#define PORTF_PIN2_DIRECTION                (PORT_PIN_IN)
#define PORTF_PIN2_DIRECTION_CHANGEABLE     (TRUE)
#define PORTF_PIN2_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTF_PIN2_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTF_PIN2_MODE                     (PORT_PIN_MODE_DIO)
#define PORTF_PIN2_MODE_CHANGEABLE          (TRUE)

#define PORTF_PIN3_ID                       (43U)
#define PORTF_PIN3_DIRECTION                (PORT_PIN_IN)
#define PORTF_PIN3_DIRECTION_CHANGEABLE     (TRUE)
#define PORTF_PIN3_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTF_PIN3_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTF_PIN3_MODE                     (PORT_PIN_MODE_DIO)
#define PORTF_PIN3_MODE_CHANGEABLE          (TRUE)

#define PORTF_PIN4_ID                       (44U)
#define PORTF_PIN4_DIRECTION                (PORT_PIN_IN)
#define PORTF_PIN4_DIRECTION_CHANGEABLE     (FALSE)
#define PORTF_PIN4_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTF_PIN4_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTF_PIN4_MODE                     (PORT_PIN_MODE_DIO)
#define PORTF_PIN4_MODE_CHANGEABLE          (FALSE)

#define PORTF_PIN5_ID                       (45U)
#define PORTF_PIN5_DIRECTION                (PORT_PIN_IN)
#define PORTF_PIN5_DIRECTION_CHANGEABLE     (TRUE)
#define PORTF_PIN5_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTF_PIN5_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTF_PIN5_MODE                     (PORT_PIN_MODE_DIO)
#define PORTF_PIN5_MODE_CHANGEABLE          (TRUE)

#define PORTF_PIN6_ID                       (46U)
#define PORTF_PIN6_DIRECTION                (PORT_PIN_IN)
#define PORTF_PIN6_DIRECTION_CHANGEABLE     (TRUE)
#define PORTF_PIN6_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTF_PIN6_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTF_PIN6_MODE                     (PORT_PIN_MODE_DIO)
#define PORTF_PIN6_MODE_CHANGEABLE          (TRUE)

#define PORTF_PIN7_ID                       (47U)
#define PORTF_PIN7_DIRECTION                (PORT_PIN_IN)
#define PORTF_PIN7_DIRECTION_CHANGEABLE     (TRUE)
#define PORTF_PIN7_INITIAL_MODE             (PORT_PIN_MODE_DIO)
#define PORTF_PIN7_LEVEL_VALUE              (PORT_PIN_LEVEL_HIGH)
#define PORTF_PIN7_MODE                     (PORT_PIN_MODE_DIO)
#define PORTF_PIN7_MODE_CHANGEABLE          (TRUE)


#endif /* PORT_CFG_H_ */
