#include "../../src/main.hpp"
#include <SDL2/SDL.h>
#include <coreinit/foreground.h>
#include <coreinit/thread.h>
#include <proc_ui/procui.h>
#include <romfs-wiiu.h>

int main() {
    ProcUIInit(OSSavesDone_ReadyToRelease);
    romfsInit();
    init();

    unsigned int a = SDL_GetTicks();
    unsigned int b = SDL_GetTicks();
    while (!quit) {
        a = SDL_GetTicks();
        delta = a - b;

        switch (ProcUIProcessMessages(true)) {
			case PROCUI_STATUS_IN_FOREGROUND:
				if (delta > 1000 / MAX_FPS) {
                    fps = 1000 / delta;
                    b = a;

                    update();
                }

				break;
			case PROCUI_STATUS_RELEASE_FOREGROUND:
				ProcUIDrawDoneRelease();
				break;
			case PROCUI_STATUS_IN_BACKGROUND:
				OSSleepTicks(OSMillisecondsToTicks(20));
				break;
			case PROCUI_STATUS_EXITING:
				quit = true;
				break;
		}
    }

    romfsExit();
    ProcUIShutdown();
    quit_sdl();
}