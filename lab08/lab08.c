#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int mygetch()
{
    struct termios oldt, newt;
    int c;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    c = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return c;
}

int is_functional()
{
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    char c;
    int nofchars = 0;
    //read all pending func-key's codes not to handle them in main loop
    do {
        c = getchar();
        nofchars++;
    } while (c!=EOF);

    fcntl(STDIN_FILENO, F_SETFL, flags);
    return nofchars!=1;
}

int main()
{
    char x = 0;
    printf("Введите последовательность цифр\n");
    while(1)
    {
        x = mygetch();
        if(!isalnum(x) && !ispunct(x))
        {
            if((x == 0x7f || !is_functional()) && x != 0x1b)
                break;
            continue;
        }
        else
        {
            if (isdigit(x) && !ispunct(x))
            {
                if (x == 57)
                    x = 48;
                else
                    x++;
                printf("%c", x);
            }
            else
            printf("%c", x);
        }
    }
    printf("\n");
    return 0;
}
