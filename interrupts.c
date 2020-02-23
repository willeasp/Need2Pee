#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"

void user_isr ( void ){
	display_string(0, "Lyckad interrupt");
	display_update();
}