#include <unistd.h>
main()
{
    execl("ls" ,"-al", (char *)0);
}
