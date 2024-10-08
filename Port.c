/*
 * Module : PORT
 *
 * File name: Port.c
 *
 * Description: source file for TM4C123GH6PM Micro-controller - Port Driver
 *
 * Author: Mario Kaldas
 */

#include"Port.h"
#include"Port_Regs.h"
#include"common_macros.h"



#include"Det.h"

/* Check if Port and Det SW versions are compatible */
#if((PORT_SW_MAJOR_VERSION != DET_SW_MAJOR_VERSION) ||\
        (PORT_SW_MINOR_VERSION != DET_SW_MINOR_VERSION) ||\
        (PORT_SW_PATCH_VERSION != DET_SW_PATCH_VERSION)   \
)
#error " The SW version of Det doesn't match the expected version "
#endif

/* Check if Port and Det AUTOSAR versions are compatible */
#if((PORT_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||\
        (PORT_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION) ||\
        (PORT_AR_RELEASE_PATCH_VERSION != DET_AR_RELEASE_PATCH_VERSION)   \
)
#error " The AUTOSAR version of Det doesn't match the expected version "
#endif
/*********************************************************************************************
 *                                      External variables
 **********************************************************************************************/

STATIC const Port_PinConfigs* pinsConfig;
STATIC volatile boolean state = PORT_NOT_INITIALIZED;

/*********************************************************************************************
 *                                     'Port' functions definition
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
void Port_Init(const Port_ConfigType* ConfigPtr){

    /* Index to loop over the 48 pins */
    uint8 i;

    /* hold the base address of the required port */
    uint32* baseAddress;

#if(PORT_DEV_ERROR_DETECT == (STD_ON))

    if(ConfigPtr == NULL_PTR){

        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_CONFIG);
    }

    else

#endif
    {

        state = PORT_INITIALIZED;

        pinsConfig = (Port_PinConfigs*)(ConfigPtr->pins);

        for(i=0; i<TOTAL_NUMBER_OF_PINS; i++){

            /* To know which port is the current pin at */
            switch( i / NUMBER_OF_PINS_PER_PORT ){

            case PORTA_ID:

                baseAddress = (uint32*)GPIO_PORTA_BASE_ADDRESS;
                break;

            case PORTB_ID:

                baseAddress = (uint32*)GPIO_PORTB_BASE_ADDRESS;
                break;

            case PORTC_ID:

                if( ((i % PortContainer_PORT_C_NUM_OF_PINS) >= 0) && ((i % PortContainer_PORT_C_NUM_OF_PINS) <= 3) )
                {
                    /* These are JTAG pins *DON'T USE THEM* */
                    continue;
                }

                baseAddress = (uint32*)GPIO_PORTC_BASE_ADDRESS;
                break;

            case PORTD_ID:

                baseAddress = (uint32*)GPIO_PORTD_BASE_ADDRESS;

                if(i % PortContainer_PORT_D_NUM_OF_PINS == 7){

                    *((uint32*)((uint8*)baseAddress + PORT_LOCK_REG_OFFSET)) =  0x4C4F434B;
                    SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_COMMIT_REG_OFFSET)), 7);
                }

                break;

            case PORTE_ID:

                baseAddress = (uint32*)GPIO_PORTE_BASE_ADDRESS;
                break;

            case PORTF_ID:

                baseAddress = (uint32*)GPIO_PORTF_BASE_ADDRESS;

                if(i % PortContainer_PORT_F_NUM_OF_PINS == 0){

                    *((uint32*)((uint8*)baseAddress + PORT_LOCK_REG_OFFSET)) =  0x4C4F434B;
                    SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_COMMIT_REG_OFFSET)), 0);
                }

                break;
            }

            /* Set up the direction
             *
             * Input: choose the resistor type (no resistor is an option)
             * Output: set the initial value
             *
             *  */
            if(pinsConfig[i].direction == PORT_PIN_IN){

                /* Set pin as input pin */
                CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_DIR_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );

                /* Set the resistor type */
                switch(pinsConfig[i].internalResistor){

                case PULLUP_RESISTOR:

                    SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_PULL_UP_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );
                    break;

                case PULLDOWN_RESISTOR:

                    SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_PULL_DOWN_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );
                    break;

                case NO_RESISTOR:

                    CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_PULL_UP_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );
                    CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_PULL_DOWN_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );
                    break;
                }
            }
            else{

                /* Set pin as output pin */
                SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_DIR_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );

                /* Set the initial value */
                if(pinsConfig[i].initialValue == PORT_PIN_LEVEL_HIGH){

                    SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_DATA_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );
                }
                else{

                    CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_DATA_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );
                }
            }

            /* Set other parameters (digital and analog) */
            switch( pinsConfig[i].initialMode ){

            case PORT_PIN_MODE_DIO:
            case PORT_PIN_MODE_CAN:
            case PORT_PIN_MODE_PWM:
            case PORT_PIN_MODE_SPI:

                SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_DIGITAL_ENABLE_REG_OFFSET)), (i%NUMBER_OF_PINS_PER_PORT));
                CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_ANALOG_MODE_SEL_REG_OFFSET)), (i%NUMBER_OF_PINS_PER_PORT));

                break;

            case PORT_PIN_MODE_ADC:

                if( ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB4 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB5 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 0) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD0 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 1) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD1 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 2) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD2 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 3) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD3 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 0) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE0 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 1) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE1 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 2) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE2 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 3) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE3 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE4 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) )    /* PDE */
                )
                {
                    CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_DIGITAL_ENABLE_REG_OFFSET)), (i%NUMBER_OF_PINS_PER_PORT));
                    SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_ANALOG_MODE_SEL_REG_OFFSET)), (i%NUMBER_OF_PINS_PER_PORT));
                }
                else
                {
                    /* Do nothing */
                }
                break;

            }


            /* In case of DIO mode : clear the alternative mode corresponding bit */
            if(pinsConfig[i].initialMode == PORT_PIN_MODE_DIO){

                CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_ALT_FUNC_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );
            }
            else{

                /* In case of any other mode : set the alternative mode corresponding bit */
                SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_ALT_FUNC_REG_OFFSET)), i % NUMBER_OF_PINS_PER_PORT);

                /* Set PMCx value corresponding for the required mode  */
                switch( pinsConfig[i].initialMode ){

                case PORT_PIN_MODE_CAN:

                    if( ( ((i % NUMBER_OF_PINS_PER_PORT) == 0) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA0 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 1) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA1 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB4 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB5 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PE4 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) )    /* PE4 */
                    )
                    {

                        *((uint32*)((uint8*)baseAddress + PORT_CTL_REG_OFFSET)) |= (8<< (i%NUMBER_OF_PINS_PER_PORT) );
                    }
                    else if( ( ((i % NUMBER_OF_PINS_PER_PORT) == 0) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) ) || /* PF0 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 3) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) )     /* PB3 */
                    )
                    {

                        *((uint32*)((uint8*)baseAddress + PORT_CTL_REG_OFFSET)) |= (3<< (i%NUMBER_OF_PINS_PER_PORT) );
                    }
                    else{

                        /* Do nothing */
                    }
                    break;

                case PORT_PIN_MODE_SPI :

                    if( ( ((i % NUMBER_OF_PINS_PER_PORT) == 2) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA2 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 3) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA3 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA4 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA5 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB4 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB5 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 6) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB6 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 7) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB7 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 0) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD0 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 1) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD1 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 2) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD2 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 3) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) )    /* PD3 */
                    )
                    {
                        *((uint32*)((uint8*)baseAddress + PORT_CTL_REG_OFFSET)) |= (2<< (i%NUMBER_OF_PINS_PER_PORT) );
                    }
                    else{

                        /* Do nothing */
                    }
                    break;

                case PORT_PIN_MODE_PWM :

                    if( ( ((i % NUMBER_OF_PINS_PER_PORT) == 6) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA6 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 7) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA7 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 0) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD0 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 1) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD1 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 0) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) ) || /* PF0 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 1) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) ) || /* PF1 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 2) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) ) || /* PF2 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 3) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) )    /* PF3 */
                    )
                    {
                        *((uint32*)((uint8*)baseAddress + PORT_CTL_REG_OFFSET)) |= (5<< (i%NUMBER_OF_PINS_PER_PORT) );
                    }
                    else if (  ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB4 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB5 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 6) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB6 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 7) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB7 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTC_ID) ) || /* PC4 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTC_ID) ) || /* PC5 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE4 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) )    /* PE5 */
                    )
                    {
                        *((uint32*)((uint8*)baseAddress + PORT_CTL_REG_OFFSET)) |= (4<< (i%NUMBER_OF_PINS_PER_PORT) );
                    }
                    else
                    {
                        /* Do nothing */
                    }
                    break;
                }
            }
        }
    }
}



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
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction){

    /* hold the base address of the required port */
    uint32* baseAddress;

#if (PORT_DEV_ERROR_DETECT == STD_ON)

    if((pinsConfig[Pin].directionChangeable != STD_ON) ){

        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
    }
    else if(state == PORT_NOT_INITIALIZED){

        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
    }
    else if(Pin >= TOTAL_NUMBER_OF_PINS){

        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
    }

    else

#endif
    {

        /* To know which port is the current pin at */
        switch( Pin / NUMBER_OF_PINS_PER_PORT ){

        case PORTA_ID:

            baseAddress = (uint32*)GPIO_PORTA_BASE_ADDRESS;
            break;

        case PORTB_ID:

            baseAddress = (uint32*)GPIO_PORTB_BASE_ADDRESS;
            break;

        case PORTC_ID:

            if( ((Pin % PortContainer_PORT_C_NUM_OF_PINS) >= 0) && ((Pin % PortContainer_PORT_C_NUM_OF_PINS) <= 3) )
            {
                /* These are JTAG pins *DON'T USE THEM* */
                return;
            }

            baseAddress = (uint32*)GPIO_PORTC_BASE_ADDRESS;
            break;

        case PORTD_ID:

            baseAddress = (uint32*)GPIO_PORTD_BASE_ADDRESS;

            break;

        case PORTE_ID:

            baseAddress = (uint32*)GPIO_PORTE_BASE_ADDRESS;
            break;

        case PORTF_ID:

            baseAddress = (uint32*)GPIO_PORTF_BASE_ADDRESS;

            break;
        }

        if(Direction == PORT_PIN_IN){

            CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_DIR_REG_OFFSET)), (Pin%NUMBER_OF_PINS_PER_PORT));
        }
        else{

            SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_DIR_REG_OFFSET)), (Pin%NUMBER_OF_PINS_PER_PORT));
            CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_DATA_REG_OFFSET)), (Pin%NUMBER_OF_PINS_PER_PORT));
        }
    }
}

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
void Port_RefreshPortDirection(void){


    /* Index to loop over the 48 pins */
    uint8 i;

    /* hold the base address of the required port */
    uint32* baseAddress;

#if(PORT_DEV_ERROR_DETECT == (STD_ON))

    if(PORT_NOT_INITIALIZED == state){

        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PIN_DIRECTION_SID,PORT_E_UNINIT );
    }

    else

#endif
    {

        state = PORT_INITIALIZED;


        for(i=0; i<TOTAL_NUMBER_OF_PINS; i++){

            /* The function Port_RefreshPortDirection shall exclude
             *  those port pins from refreshing that are configured as ‘pin direction changeable during runtime */
            if(TRUE == pinsConfig[i].directionChangeable){

                continue;
            }

            /* To know which port is the current pin at */
            switch( i / NUMBER_OF_PINS_PER_PORT ){

            case PORTA_ID:

                baseAddress = (uint32*)GPIO_PORTA_BASE_ADDRESS;
                break;

            case PORTB_ID:

                baseAddress = (uint32*)GPIO_PORTB_BASE_ADDRESS;
                break;

            case PORTC_ID:

                if( ((i % PortContainer_PORT_C_NUM_OF_PINS) >= 0) && ((i % PortContainer_PORT_C_NUM_OF_PINS) <= 3) )
                {
                    /* These are JTAG pins *DON'T USE THEM* */
                    continue;
                }

                baseAddress = (uint32*)GPIO_PORTC_BASE_ADDRESS;
                break;

            case PORTD_ID:

                baseAddress = (uint32*)GPIO_PORTD_BASE_ADDRESS;

                if(i % PortContainer_PORT_D_NUM_OF_PINS == 7){

                    *((uint32*)((uint8*)baseAddress + PORT_LOCK_REG_OFFSET)) =  0x4C4F434B;
                    SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_COMMIT_REG_OFFSET)), 7);
                }

                break;

            case PORTE_ID:

                baseAddress = (uint32*)GPIO_PORTE_BASE_ADDRESS;
                break;

            case PORTF_ID:

                baseAddress = (uint32*)GPIO_PORTF_BASE_ADDRESS;

                if(i % PortContainer_PORT_F_NUM_OF_PINS == 0){

                    *((uint32*)((uint8*)baseAddress + PORT_LOCK_REG_OFFSET)) =  0x4C4F434B;
                    SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_COMMIT_REG_OFFSET)), 0);
                }

                break;
            }

            /* Set up the direction
             *
             * Input: choose the resistor type (no resistor is an option)
             * Output: set the initial value
             *
             *  */
            if(pinsConfig[i].direction == PORT_PIN_IN){

                /* Set pin as input pin */
                CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_DIR_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );

                /* Set the resistor type */
                switch(pinsConfig[i].internalResistor){

                case PULLUP_RESISTOR:

                    SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_PULL_UP_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );
                    break;

                case PULLDOWN_RESISTOR:

                    SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_PULL_DOWN_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );
                    break;

                case NO_RESISTOR:

                    CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_PULL_UP_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );
                    CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_PULL_DOWN_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );
                    break;
                }
            }
            else{

                /* Set pin as output pin */
                SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_DIR_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );

                /* Set the initial value */
                if(pinsConfig[i].initialValue == PORT_PIN_LEVEL_HIGH){

                    SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_DATA_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );
                }
                else{

                    CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_DATA_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );
                }
            }

            /* Set other parameters (digital and analog) */
            switch( pinsConfig[i].initialMode ){

            case PORT_PIN_MODE_DIO:
            case PORT_PIN_MODE_CAN:
            case PORT_PIN_MODE_PWM:
            case PORT_PIN_MODE_SPI:

                SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_DIGITAL_ENABLE_REG_OFFSET)), (i%NUMBER_OF_PINS_PER_PORT));
                CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_ANALOG_MODE_SEL_REG_OFFSET)), (i%NUMBER_OF_PINS_PER_PORT));

                break;

            case PORT_PIN_MODE_ADC:

                if( ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB4 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB5 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 0) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD0 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 1) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD1 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 2) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD2 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 3) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD3 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 0) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE0 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 1) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE1 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 2) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE2 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 3) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE3 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE4 */
                        ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) )    /* PDE */
                )
                {
                    CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_DIGITAL_ENABLE_REG_OFFSET)), (i%NUMBER_OF_PINS_PER_PORT));
                    SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_ANALOG_MODE_SEL_REG_OFFSET)), (i%NUMBER_OF_PINS_PER_PORT));
                }
                else
                {
                    /* Do nothing */
                }
                break;

            }


            /* In case of DIO mode : clear the alternative mode corresponding bit */
            if(pinsConfig[i].initialMode == PORT_PIN_MODE_DIO){

                CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_ALT_FUNC_REG_OFFSET)), (i % NUMBER_OF_PINS_PER_PORT) );
            }
            else{

                /* In case of any other mode : set the alternative mode corresponding bit */
                SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_ALT_FUNC_REG_OFFSET)), i % NUMBER_OF_PINS_PER_PORT);

                /* Set PMCx value corresponding for the required mode  */
                switch( pinsConfig[i].initialMode ){

                case PORT_PIN_MODE_CAN:

                    if( ( ((i % NUMBER_OF_PINS_PER_PORT) == 0) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA0 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 1) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA1 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB4 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB5 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PE4 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) )    /* PE4 */
                    )
                    {

                        *((uint32*)((uint8*)baseAddress + PORT_CTL_REG_OFFSET)) |= (8<< (i%NUMBER_OF_PINS_PER_PORT) );
                    }
                    else if( ( ((i % NUMBER_OF_PINS_PER_PORT) == 0) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) ) || /* PF0 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 3) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) )     /* PB3 */
                    )
                    {

                        *((uint32*)((uint8*)baseAddress + PORT_CTL_REG_OFFSET)) |= (3<< (i%NUMBER_OF_PINS_PER_PORT) );
                    }
                    else{

                        /* Do nothing */
                    }
                    break;

                case PORT_PIN_MODE_SPI :

                    if( ( ((i % NUMBER_OF_PINS_PER_PORT) == 2) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA2 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 3) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA3 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA4 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA5 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB4 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB5 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 6) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB6 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 7) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB7 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 0) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD0 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 1) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD1 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 2) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD2 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 3) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) )    /* PD3 */
                    )
                    {
                        *((uint32*)((uint8*)baseAddress + PORT_CTL_REG_OFFSET)) |= (2<< (i%NUMBER_OF_PINS_PER_PORT) );
                    }
                    else{

                        /* Do nothing */
                    }
                    break;

                case PORT_PIN_MODE_PWM :

                    if( ( ((i % NUMBER_OF_PINS_PER_PORT) == 6) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA6 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 7) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA7 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 0) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD0 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 1) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD1 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 0) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) ) || /* PF0 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 1) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) ) || /* PF1 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 2) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) ) || /* PF2 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 3) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) )    /* PF3 */
                    )
                    {
                        *((uint32*)((uint8*)baseAddress + PORT_CTL_REG_OFFSET)) |= (5<< (i%NUMBER_OF_PINS_PER_PORT) );
                    }
                    else if (  ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB4 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB5 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 6) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB6 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 7) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB7 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTC_ID) ) || /* PC4 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTC_ID) ) || /* PC5 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 4) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE4 */
                            ( ((i % NUMBER_OF_PINS_PER_PORT) == 5) && ((i/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) )    /* PE5 */
                    )
                    {
                        *((uint32*)((uint8*)baseAddress + PORT_CTL_REG_OFFSET)) |= (4<< (i%NUMBER_OF_PINS_PER_PORT) );
                    }
                    else
                    {
                        /* Do nothing */
                    }
                    break;
                }
            }
        }
    }
}


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
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo){

#if (PORT_DEV_ERROR_DETECT == STD_ON)

    if((NULL_PTR == versioninfo) ){

        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
    }
    else if(state == PORT_NOT_INITIALIZED){

        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_GET_VERSION_INFO_SID , PORT_E_UNINIT);
    }

    else

#endif
    {
        versioninfo->moduleID = PORT_MODULE_ID;
        versioninfo->vendorID = PORT_VENDOR_ID;
        versioninfo->sw_major_version = PORT_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = PORT_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = PORT_SW_PATCH_VERSION;

    }
}
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
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode){

    /* hold the base address of the required port */
    uint32* baseAddress;

#if (PORT_DEV_ERROR_DETECT == STD_ON)

    if((pinsConfig[Pin].modeChangeable != STD_ON) ){

        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
    }
    else if(state == PORT_NOT_INITIALIZED){

        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
    }
    else if(Pin >= TOTAL_NUMBER_OF_PINS){

        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
    }

    else

#endif

    {

        /* To know which port is the current pin at */
        switch( Pin / NUMBER_OF_PINS_PER_PORT ){

        case PORTA_ID:

            baseAddress = (uint32*)GPIO_PORTA_BASE_ADDRESS;
            break;

        case PORTB_ID:

            baseAddress = (uint32*)GPIO_PORTB_BASE_ADDRESS;
            break;

        case PORTC_ID:

            if( ((Pin % PortContainer_PORT_C_NUM_OF_PINS) >= 0) && ((Pin % PortContainer_PORT_C_NUM_OF_PINS) <= 3) )
            {
                /* These are JTAG pins *DON'T USE THEM* */
                return;
            }

            baseAddress = (uint32*)GPIO_PORTC_BASE_ADDRESS;
            break;

        case PORTD_ID:

            baseAddress = (uint32*)GPIO_PORTD_BASE_ADDRESS;

            break;

        case PORTE_ID:

            baseAddress = (uint32*)GPIO_PORTE_BASE_ADDRESS;
            break;

        case PORTF_ID:

            baseAddress = (uint32*)GPIO_PORTF_BASE_ADDRESS;

            break;
        }
    }

    switch( Mode ){

    case PORT_PIN_MODE_DIO:
    case PORT_PIN_MODE_CAN:
    case PORT_PIN_MODE_PWM:
    case PORT_PIN_MODE_SPI:

        SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_DIGITAL_ENABLE_REG_OFFSET)), (Pin%NUMBER_OF_PINS_PER_PORT));
        CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_ANALOG_MODE_SEL_REG_OFFSET)), (Pin%NUMBER_OF_PINS_PER_PORT));

        break;

    case PORT_PIN_MODE_ADC:

        if( ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 4) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB4 */
                ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 5) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB5 */
                ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 0) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD0 */
                ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 1) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD1 */
                ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 2) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD2 */
                ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 3) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD3 */
                ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 0) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE0 */
                ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 1) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE1 */
                ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 2) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE2 */
                ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 3) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE3 */
                ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 4) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE4 */
                ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 5) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) )    /* PDE */
        )
        {
            CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_DIGITAL_ENABLE_REG_OFFSET)), (Pin%NUMBER_OF_PINS_PER_PORT));
            SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_ANALOG_MODE_SEL_REG_OFFSET)), (Pin%NUMBER_OF_PINS_PER_PORT));
        }
        else
        {
            Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
        }
        break;

    }


    /* In case of DIO mode : clear the alternative mode corresponding bit */
    if(Mode == PORT_PIN_MODE_DIO){

        CLEAR_BIT(*((uint32*)((uint8*)baseAddress + PORT_ALT_FUNC_REG_OFFSET)), (Pin % NUMBER_OF_PINS_PER_PORT) );
    }
    else{

        /* In case of any other mode : set the alternative mode corresponding bit */
        SET_BIT(*((uint32*)((uint8*)baseAddress + PORT_ALT_FUNC_REG_OFFSET)), Pin % NUMBER_OF_PINS_PER_PORT);

        /* Set PMCx value corresponding for the required mode  */
        switch( Mode ){

        case PORT_PIN_MODE_CAN:

            if( ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 0) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA0 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 1) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA1 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 4) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB4 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 5) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB5 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 4) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PE4 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 5) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) )    /* PE4 */
            )
            {

                *((uint32*)((uint8*)baseAddress + PORT_CTL_REG_OFFSET)) |= (8<< (Pin%NUMBER_OF_PINS_PER_PORT) );
            }
            else if( ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 0) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) ) || /* PF0 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 3) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) )     /* PB3 */
            )
            {

                *((uint32*)((uint8*)baseAddress + PORT_CTL_REG_OFFSET)) |= (3<< (Pin%NUMBER_OF_PINS_PER_PORT) );
            }
            else{

                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
            }
            break;

        case PORT_PIN_MODE_SPI :

            if( ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 2) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA2 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 3) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA3 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 4) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA4 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 5) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA5 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 4) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB4 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 5) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB5 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 6) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB6 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 7) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB7 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 0) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD0 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 1) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD1 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 2) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD2 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 3) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) )    /* PD3 */
            )
            {
                *((uint32*)((uint8*)baseAddress + PORT_CTL_REG_OFFSET)) |= (2<< (Pin%NUMBER_OF_PINS_PER_PORT) );
            }
            else{

                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
            }
            break;

        case PORT_PIN_MODE_PWM :

            if( ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 6) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA6 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 7) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTA_ID) ) || /* PA7 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 0) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD0 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 1) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTD_ID) ) || /* PD1 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 0) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) ) || /* PF0 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 1) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) ) || /* PF1 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 2) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) ) || /* PF2 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 3) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTF_ID) )    /* PF3 */
            )
            {
                *((uint32*)((uint8*)baseAddress + PORT_CTL_REG_OFFSET)) |= (5<< (Pin%NUMBER_OF_PINS_PER_PORT) );
            }
            else if (  ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 4) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB4 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 5) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB5 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 6) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB6 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 7) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTB_ID) ) || /* PB7 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 4) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTC_ID) ) || /* PC4 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 5) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTC_ID) ) || /* PC5 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 4) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) ) || /* PE4 */
                    ( ((Pin % NUMBER_OF_PINS_PER_PORT) == 5) && ((Pin/NUMBER_OF_PINS_PER_PORT) == PORTE_ID) )    /* PE5 */
            )
            {
                *((uint32*)((uint8*)baseAddress + PORT_CTL_REG_OFFSET)) |= (4<< (Pin%NUMBER_OF_PINS_PER_PORT) );
            }
            else
            {
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
            }
            break;
        }

    }
}
#endif
