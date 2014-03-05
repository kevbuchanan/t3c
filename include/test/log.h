#ifndef LOG_H
#define LOG_H

extern char* writer_log;

void init_log(void);
void add_to_log(char* string);
void destroy_log(void);
void reset_log(void);

#endif
