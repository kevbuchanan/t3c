#ifndef CONFIG_H
#define CONFIG_H

typedef struct _Config {
  int size;
  int order;
  int difficulty;
} Config;

Config initialize_config(int argc, char* argv[]);

#endif
