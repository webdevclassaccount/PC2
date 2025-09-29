#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Starting shield power level
int shield_power = 50;  

int main() {
    pid_t pid;
    int maxProc = 4;
    int charNum = 0;

    printf("Millennium Falcon: Initial shield power level: %d%%\n\n", shield_power);

    // Create 4 child processes - 4 different characters adjusting shield power

            // Luke increases the shield power by 25
            // Han increases the shield power by 20
            // Chewbacca increases the shield power by 30
            // Leia increases the shield power by 15

    for (int i = 0; i < maxProc; i++)
    {
        pid = fork();

        // Check if process creation failed
        // -----> Write you code here 
        if (pid < 0)
        {
            printf("fork() failed\n");
            return 1;
        }
        else if (pid == 0)
        {
            charNum = getpid() - getppid();
            switch (charNum)
            {
                case 1:
                    shield_power += 25;
                    printf("Luke: Adjusting Shields...\nLuke: Shield power level now at %%%d\n", shield_power);
                    break;
                case 2:
                    shield_power += 20;
                    printf("Han: Adjusting Shields...\nHan: Shield power level now at %%%d\n", shield_power);
                    break;
                case 3:
                    shield_power += 30;
                    printf("Chewbacca: Adjusting Shields...\nChewbacca: Shield power level now at %%%d\n", shield_power);
                    break;
                case 4:
                    shield_power += 15;
                    printf("Leia: Adjusting Shields...\nLeia: Shield power level now at %%%d\n", shield_power);
                    break;
            }
            return 0;
        }
    }

    // Make parent process wait for all child processes to complete
    // -----> Write you code here 
    while (wait(NULL) > 0);


    // Parent process reports final state
    printf("\nFinal shield power level on the Millennium Falcon: %d%%\n", shield_power);
    printf("\nMay the forks be with you!\n");
    return 0;
}
