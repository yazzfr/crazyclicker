#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define KEY_F6 0x75

int main() {
    printf("%c]0;%s%c", '\033', "CrazyClicker by yaz.fr on discord", '\007');
    printf("..######..########.....###....########.##....##....######..##.......####..######..##....##.########.########.\n");
    printf(".##....##.##.....##...##.##........##...##..##....##....##.##........##..##....##.##...##..##.......##.....##\n");
    printf(".##.......##.....##..##...##......##.....####.....##.......##........##..##.......##..##...##.......##.....##\n");
    printf(".##.......########..##.....##....##.......##......##.......##........##..##.......#####....######...########.\n");
    printf(".##.......##...##...#########...##........##......##.......##........##..##.......##..##...##.......##...##..\n");
    printf(".##....##.##....##..##.....##..##.........##......##....##.##........##..##....##.##...##..##.......##....##.\n");
    printf("..######..##.....##.##.....##.########....##.......######..########.####..######..##....##.########.##.....##\n");
    printf("CrazyClicker by yaz.fr\n");
    printf("Press F6 to toggle \n");
    srand(time(NULL)); 
    bool crazyClickerEnabled = false;

    while (true) {
        if (GetAsyncKeyState(VK_F6) & 0x8000) { 
            crazyClickerEnabled = !crazyClickerEnabled; 
            if (crazyClickerEnabled) {
                printf("CrazyClicker Toggled!\n");
            } else {
                printf("CrazyClicker Disabled\n");
            }
            Sleep(50); 
        }

        if (crazyClickerEnabled) {
            int randomDelay = rand() % 7 + 15; 
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); 
            Sleep(randomDelay); 
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); 
            Sleep(randomDelay);
        }
    }

    return 0;
}