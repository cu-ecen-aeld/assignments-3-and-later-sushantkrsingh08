#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    // Open syslog with LOG_USER facility
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    // Check if the correct number of arguments is provided
    if (argc != 3) {
        syslog(LOG_ERR, "Incorrect number of arguments provided. Usage: <writefile> <writestr>");
        fprintf(stderr, "Error: Incorrect number of arguments. Expected 2 arguments.\n");
        closelog();
        exit(1);
    }

    // Get the arguments
    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // Attempt to open the file for writing
    FILE *file = fopen(writefile, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Failed to create or open the file: %s", writefile);
        fprintf(stderr, "Error: Could not create or open file %s\n", writefile);
        closelog();
        exit(1);
    }

    // Write the string to the file
    if (fprintf(file, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Failed to write to the file: %s", writefile);
        fprintf(stderr, "Error: Could not write to file %s\n", writefile);
        fclose(file);
        closelog();
        exit(1);
    }

    // Log the successful write operation
    syslog(LOG_DEBUG, "Writing \"%s\" to \"%s\"", writestr, writefile);

    // Close the file
    fclose(file);

    // Close syslog
    closelog();

    return 0;
}