#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main() {
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);
    syslog(LOG_DEBUG, "Writing %s to %s", "Hello, World!", "output.txt");

    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Error opening file");
        closelog();
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Hello, World!\n");
    fclose(file);

    syslog(LOG_DEBUG, "Write successful");
    closelog();
    return 0;
}
