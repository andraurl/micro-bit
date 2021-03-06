#include <stdint.h>
#include "uart.h"
#include "gpio.h"


#define UART ((NRF_UART_REG*)0x40002000)


typedef struct {

//Tasks;
volatile uint32_t STARTRX;
volatile uint32_t STOPRX;
volatile uint32_t STARTTX;
volatile uint32_t STOPTX;
volatile uint32_t fill_1[3];
volatile uint32_t SUSPEND;
volatile uint32_t fill_2[56];

//Events;
volatile uint32_t CTS; 
volatile uint32_t NCTS;
volatile uint32_t RXDRDY;
volatile uint32_t fill_3[4];
volatile uint32_t TXDRDY;
volatile uint32_t fill_4[1];
volatile uint32_t ERROR;
volatile uint32_t fill_5[7];
volatile uint32_t RXTO;
volatile uint32_t fill_6[110];

//Registers;
volatile uint32_t INTEN;
volatile uint32_t INTENSET;
volatile uint32_t INTENCLR;
volatile uint32_t fill_7[93];
volatile uint32_t ERRORSRC;
volatile uint32_t fill_8[31];
volatile uint32_t ENABLE;
volatile uint32_t fill_9[1];
volatile uint32_t PSELRTS;
volatile uint32_t PSELTXD;
volatile uint32_t PSELCTS;
volatile uint32_t PSELRXD;
volatile uint32_t RXD;
volatile uint32_t TXD;
volatile uint32_t fill_10[1];
volatile uint32_t BAUDRATE;
volatile uint32_t fill_11[17];
volatile uint32_t CONFIG;

} NRF_UART_REG;


void uart_init()
{
	GPIO->PIN_CNF[25] = 0; // 0 er input - altså TGT RXD
	GPIO->PIN_CNF[24] = 1; // 1 er output - altså TGT TXD
	GPIO->BAUDRATE = 9600;

	GPIO->PSELcts =  0    ;
	GPIO->PSELTXD =   0   ;
	GPIO->ENABLE  =     1  ; 
	GPIO->STARTRX = 1; 
}


void uart_send(char letter)
{

}


char uart_read();
{

}
