#ifndef WRITER_H
#define WRITER_H

char* writer_log;

void init_log(void);
void destroy_log(void);
void reset_log(void);

void write(char* string);
void write_char(char* string, char sub);

#endif
