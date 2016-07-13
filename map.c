#include "map.h"

t_map *new_map()
{
  return (0);
}

t_map *map_push(t_map *map, void *key, void *elem)
{
  t_map	*node;

  if (!(node = malloc(sizeof(*node))))
    return (0);
  node->key = key;
  node->elem = elem;
  node->next = map;
  return (node);
}

void map_for_each(t_map *map, void (*fx)(void *key, void *elem, void *data), void *data)
{
  t_map	*tmp;
  t_map	*tmp_n;

  tmp = map;
  while (tmp)
    {
      tmp_n = tmp->next;
      fx(tmp->key, tmp->elem, data);
      tmp = tmp_n;
    }
}

void *map_get_node(t_map *map, void *key)
{
  t_map *tmp;

  tmp = map;
  while (tmp)
  {
    if (tmp->key == key)
      return (tmp->elem);
    tmp = tmp->next;
  }
  return (0);
}

t_map *map_delete_node(t_map *map, void *key)
{
  t_map	*tmp;
  t_map	*tmp_n;

  tmp = map;
  if (tmp && tmp->key == key)
    {
      tmp_n = tmp->next;
      free(tmp);
      return (tmp_n);
    }
  while (tmp)
    {
      if (tmp->next && tmp->next->key == key)
       {
         tmp_n = tmp->next->next;
         free(tmp->next);
         tmp->next = tmp_n;
       }
      if (tmp)
       tmp = tmp->next;
    }
  return (map);
}

t_map *map_delete(t_map *map)
{
  if (map)
    map_delete(map->next);
  free(map);
  return (0);
}


int map_size(t_map *map)
{
  t_map	*tmp;
  int		i;

  tmp = map;
  i = 0;
  while (tmp)
    {
      ++i;
      tmp = tmp->next;
    }
  return (i);
}

int map_empty(t_map *map)
{
  return (!!map);
}

t_map *map_clear(t_map *map)
{
  return (map_delete(map));
}
