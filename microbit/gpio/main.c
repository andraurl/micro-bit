#include <stdint.h>

#define GPIO ((NRF_GPIO_REGS*)0x50000000)

typedef struct {
	volatile uint32_t RESERVED0[321]; // 1284 byte = 321 words
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR; // begynner på 0x51C og slutter på 0x51F 
	volatile uint32_t RESERVED1[120]; // Begynner på 0x520 - slutter på 0x6FF 479
	volatile uint32_t PIN_CNF[32]; // Begynner på 0x700
} NRF_GPIO_REGS;

int main(){
	// Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons
	// PIN_CNF[] = 0 gir input. 
	// 1 gir output
	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;

	
	//uint32_t button_A_maske =  0x00020000;
	//uint32_t button_B_maske =  0x04000000;
	uint32_t button_A_maske =  1 << 17;
	uint32_t button_B_maske =  1 << 26;

	uint32_t cols = 0x00001FF0;
	uint32_t rows = 0x0001E000;


	

	int sleep = 0;
	while(1){

		
		uint32_t A_pressed = ( (GPIO->IN & button_A_maske) != button_A_maske);
		if (A_pressed)
		{
			GPIO->OUTCLR = rows; 
			GPIO->OUTSET = cols; 

		


		}
		uint32_t B_pressed = ( (GPIO->IN & button_B_maske) != button_B_maske);
		if (B_pressed)
		{
			GPIO->OUTCLR = cols; 
			GPIO->OUTSET = rows; 
		}

		

		

		sleep = 10000;
		while(--sleep);
	}
	return 0;
}
