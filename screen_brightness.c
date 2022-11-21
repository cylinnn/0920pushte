//yum -y install xrandr//
#include<stdio.h>
#include <string.h>

int getscreenstatus()
{
    // FILE *screen_verbose;
    // screen_verbose = popen("xrandr | grep -v disconnected > string ./screen_verbose.txt", "w");
    // pclose(screen_verbose);

    FILE *screen_chose;
    screen_chose = popen("xrandr | grep -v disconnected | grep connected | cut -d ' ' -f1 > ./screenDEV_chose.txt", "w");
    pclose(screen_chose);
    return 0;
}

int main()
{
    int CHANGE_SCREEN_BRIGHTNESS;
    scanf("%d",&CHANGE_SCREEN_BRIGHTNESS);
    double brightness_value = CHANGE_SCREEN_BRIGHTNESS / 100.00;
    char itoc_CHANGE_SCREEN_BRIGHTNESS[20];
    sprintf(itoc_CHANGE_SCREEN_BRIGHTNESS, "%.2f", brightness_value);

    getscreenstatus();

    freopen("./screenDEV_chose.txt","r",stdin);
    
    char dev[300] = "\0";
    while (scanf("%s", dev) != EOF)
        puts(dev);

    //printf("%s", dev);
    
    char *first = "xrandr --output ";
    char *second = " --brightness ";
    //char *screenBrightness = "0.4"; //GET THE INPUT//
    
    char command[100] = "\0";

    strcat(command, first);
    strcat(command, dev);
    strcat(command, second);
    strcat(command, itoc_CHANGE_SCREEN_BRIGHTNESS);    
    
    printf("%s\n",command);

    FILE *BRIGHTNESS;
    BRIGHTNESS = popen(command, "w");
    
    fclose(stdin);
    pclose(BRIGHTNESS);

    FILE *rm_screen_chose;
    rm_screen_chose = popen("rm -rf ./screenDEV_chose.txt", "w");
    pclose(rm_screen_chose);
    return 0;
}

