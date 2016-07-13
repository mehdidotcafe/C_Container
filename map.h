#ifndef C_MAP_
# define C_MAP_
# include <stdlib.h>

typedef struct s_map
{
  void *key;
  void *elem;
  struct s_map *next;
} t_map;

// init the map
t_map *new_map();
// push in the map
t_map *map_push(t_map *map, void *key, void *elem);
// iterate throught the map and apply the function on each node
void map_for_each(t_map *map, void (*fx)(void *key, void *elem, void *data), void *data);
// get node of the map with a key
void *map_get_node(t_map *map, void *key);
// delete node in the map with a key
t_map *map_delete_node(t_map *map, void *key);
// delete all map, this function will not free the element if it's malloced
t_map *map_delete(t_map *mao);
// get length of the map
int map_size(t_map *);
// return 1 if map is empty, 0 otherwise
int map_empty(t_map *);
// clear the map, this also delete map node but not elements and keys
t_map *map_clear(t_map *);

#endif /* !C_MAP_ */
