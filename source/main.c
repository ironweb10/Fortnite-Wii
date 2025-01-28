#include <grrlib.h>
#include <ogc/lwp_watchdog.h>
#include <wiiuse/wpad.h>
#include <stdio.h>
#include <stdlib.h>
#include "background_jpg.h" 

int main(void) {
   
    if (GRRLIB_Init() < 0) {
        printf("Error al inicializar GRRLIB\n");
        exit(1);
    }
    WPAD_Init();

   
    GRRLIB_texImg *background = GRRLIB_LoadTexture(background_jpg);
    if (!background) {
        printf("Error al cargar la textura desde array\n");
        GRRLIB_Exit();
        exit(1);
    }

    printf("Inicio exitoso, mostrando escena...\n");

    while (1) {
        WPAD_ScanPads();
        u32 pressed = WPAD_ButtonsDown(0);

        if (pressed & WPAD_BUTTON_HOME) break;  

     
        GRRLIB_FillScreen(0x000000FF);  
        GRRLIB_DrawImg(0, 0, background, 0, 1, 1, 0xFFFFFFFF); 

        
        GRRLIB_Render();
    }

 
    GRRLIB_FreeTexture(background);
    GRRLIB_Exit();
    return 0;
}
