/* Define tipos de datos booleanos y enteros. */
#include <stdbool.h>
#include <stdint.h>
/* Define la dirección base de las memorias y periféricos */
#include "inc/hw_memmap.h"
/* Define los tipos y macros comunes */
#include "inc/hw_types.h"
/* Definiciones y macros para GPIO API */
#include "driverlib/gpio.h"
/* Prototipos para el controlador de control del sistema */
#include "driverlib/sysctl.h"

int main(void)
{
/* Declaraciones de inicialización del sistema */
/* Ajuste el reloj para que se ejecute directamente desde el cristal a 16MHz */
SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
/* Declaración de Inicialización Periférica */
/* Ajuste el reloj para el puerto GPIO F */
SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

/* Declaración de Configuración Periférica */
/* Establecer el tipo de Pin GPIO */
GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);

/* GPIO Pin 3 en el PUERTO F inicializado a 0, el LED VERDE está apagado */
GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,0);

/* Loop de Aplicacion */
while(1)
{
/* Pone el pin en alto */
GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,GPIO_PIN_3);
/* Delay por 1s */
SysCtlDelay(SysCtlClockGet()/3);
/* Pone el pin en bajo */
GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,0);
/* Delay por 1s */
SysCtlDelay(SysCtlClockGet()/3);
}
}
