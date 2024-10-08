/*
 * Module : PORT
 *
 * File name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Micro-controller - Port Driver
 *
 * Author: Mario Kaldas
 */

#ifndef PORT_H_
#define PORT_H_

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID    (1000U)

/* Port Module Id */
#define PORT_MODULE_ID    (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)


/* Module Version 4.0.3 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/* AUTOSAR Version 4.0.3 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)


/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)


/* include standard types */
#include"Std_Types.h"

/* Check if Port and Std_Types SW versions are compatible */
#if((PORT_SW_MAJOR_VERSION != STD_TYPES_SW_MAJOR_VERSION) || \
    (PORT_SW_MINOR_VERSION != STD_TYPES_SW_MINOR_VERSION) || \
    (PORT_SW_PATCH_VERSION != STD_TYPES_SW_PATCH_VERSION)    \
)
#error " The SW version of Std_Types doesn't match the expected version"
#endif

/* Check if Port and Std_Types AUTOSAR versions are compatible */
#if((PORT_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
    (PORT_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION) || \
    (PORT_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION)    \
)
#error " The AUTOSAR version of Std_Types doesn't match the expected version"
#endif



/* include static configurations */
#include"Port_Cfg.h"

/* Check if Port and Port_Cfg SW versions are compatible */
#if((PORT_SW_MAJOR_VERSION != PORT_CFG_SW_MAJOR_VERSION) || \
    (PORT_SW_MINOR_VERSION != PORT_CFG_SW_MINOR_VERSION) || \
    (PORT_SW_PATCH_VERSION != PORT_CFG_SW_PATCH_VERSION)    \
)
#error " The SW version of Port_Cfg doesn't match the expected version"
#endif

/* Check if Port and Port_Cfg AUTOSAR versions are compatible */
#if((PORT_AR_RELEASE_MAJOR_VERSION != PORT_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PORT_AR_RELEASE_MINOR_VERSION != PORT_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PORT_AR_RELEASE_PATCH_VERSION != PORT_CFG_AR_RELEASE_PATCH_VERSION)    \
)
#error " The AUTOSAR version of Port_Cfg doesn't match the expected version"
#endif

/*********************************************************************************************
 *                                      Development error codes
 **********************************************************************************************/

#define PORT_E_PARAM_PIN                         (uint8)0x0A
#define PORT_E_DIRECTION_UNCHANGEABLE            (uint8)0x0B
#define PORT_E_PARAM_CONFIG                      (uint8)0x0C
#define PORT_E_PARAM_INVALID_MODE                (uint8)0x0D
#define PORT_E_MODE_UNCHANGEABLE                 (uint8)0x0E
#define PORT_E_UNINIT                            (uint8)0x0F
#define PORT_E_PARAM_POINTER                     (uint8)0x10


/*********************************************************************************************
 *                                      API Service IDs
 **********************************************************************************************/

/* Service ID for Port_Init API */
#define PORT_INIT_SID                   0x00

/* Service ID for Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_SID      0x01

/* Service ID for Port_RefreshPinDirection API */
#define PORT_REFRESH_PIN_DIRECTION_SID  0x02

/* Service ID for Port_GetVersionInfo API */
#define PORT_GET_VERSION_INFO_SID       0x03

/* Service ID for Port_SetPinMode API */
#define PORT_SET_PIN_MODE_SID           0x04

/*********************************************************************************************
 *                                      'Port' types definition
 **********************************************************************************************/

/* shall be used for the symbolic name of a Port Pin */
typedef uint8 Port_PinType;

/* Possible directions of a port pin */
typedef enum{

    PORT_PIN_IN,PORT_PIN_OUT
}Port_PinDirectionType;

/* This type defines the mode that can be configured for a pin */
typedef uint8 Port_PinModeType;


/* This type has all modes possible that can be configured to port pin */
typedef enum{

    PORT_PIN_MODE_ADC,
    PORT_PIN_MODE_CAN,
    PORT_PIN_MODE_DIO,
    PORT_PIN_MODE_DIO_GPT,
    PORT_PIN_MODE_DIO_WDG,
    PORT_PIN_MODE_FLEXRAY,
    PORT_PIN_MODE_ICU,
    PORT_PIN_MODE_LIN,
    PORT_PIN_MODE_MEM,
    PORT_PIN_MODE_PWM,
    PORT_PIN_MODE_SPI

}PortPin_Mode;

/* This type defines the logical voltage level for a pin */
typedef enum{

    PORT_PIN_LEVEL_LOW,
    PORT_PIN_LEVEL_HIGH

}PortPin_Level;

/* This type defines the internal resistor type in case of input pin */
typedef enum{

    NO_RESISTOR,PULLUP_RESISTOR,PULLDOWN_RESISTOR

}Port_internalResistor;

/* This type defines the type of the pin regarding digital or analog */
typedef enum{

    DIGITAL_PIN,ANALOG_PIN

}Port_digitalAnalogType;

typedef struct{

    Port_PinDirectionType direction;
    boolean directionChangeable;
    PortPin_Mode initialMode;
    boolean modeChangeable;
    PortPin_Mode newMode;
    PortPin_Level initialValue;
    Port_internalResistor internalResistor;

}Port_PinConfigs;

/*  type for the external data structure containing the initialization data for the PORT Driver.  */
typedef struct{

    Port_PinConfigs pins[TOTAL_NUMBER_OF_PINS];

}Port_ConfigType;


typedef enum{

    PORTA_ID,
    PORTB_ID,
    PORTC_ID,
    PORTD_ID,
    PORTE_ID,
    PORTF_ID

}Ports_IDs;
/*********************************************************************************************
 *                                     'Port' functions prototype
 **********************************************************************************************/

/**********************************************************************
 * Service name:  Port_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr --> Pointer to configuration set.
 * Parameters (inout):None
 * Parameters (out): None
 * Return value: None
 * Description: Initializes the Port Driver module.
********************************************************************* */
void Port_Init(
    const Port_ConfigType* ConfigPtr
);


#if(PORT_SET_PIN_DIRECTION_API == STD_ON)
/**********************************************************************
 * Service name: Port_SetPinDirection
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Pin       --> Port pin ID number
 *                  Direction --> Port pin direction
 * Parameters (inout):None
 * Parameters (out): None
 * Return value: None
 * Description: Sets the port pin direction.
********************************************************************* */
void Port_SetPinDirection(
    Port_PinType Pin,
    Port_PinDirectionType Direction
);
#endif


/**********************************************************************
 * Service name:  Port_RefreshPortDirection
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): None
 * Parameters (inout):None
 * Parameters (out): None
 * Return value: None
 * Description: Refreshes port direction
********************************************************************* */
void Port_RefreshPortDirection(
    void
);

#if(PORT_VERSION_INFO_API == STD_ON)
/**********************************************************************
 * Service name: Port_GetVersionInfo
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): None
 * Parameters (inout):None
 * Parameters (out): versioninfo --> Pointer to where to store the version information of this module.
 * Return value: None
 * Description: Returns the version information of this module.
********************************************************************* */
void Port_GetVersionInfo(
    Std_VersionInfoType* versioninfo
);
#endif

#if(PORT_SET_PIN_MODE_API == STD_ON)
/**********************************************************************
 * Service name: Port_SetPinMode
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Pin --> Port pin ID number
 *                  Mode --> New Port Pin mode to be set on port pin.
 * Parameters (inout):None
 * Parameters (out): None
 * Return value: None
 * Description: Sets the port pin mode
********************************************************************* */
void Port_SetPinMode(
    Port_PinType Pin,
    Port_PinModeType Mode
);
#endif

/*********************************************************************************************
 *                                      External variables
 **********************************************************************************************/

extern const Port_ConfigType Port_configurations;

#endif /* PORT_H_ */
