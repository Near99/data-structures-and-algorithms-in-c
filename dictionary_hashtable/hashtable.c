/**
 * Just got an idea of what dictionary actually is with this super basic and simple
 * implementation. Didn't do chaining as there's not much fun of coding linked list,
 * and it won't help much as well so I'll just leave it there and move on ;).
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define MAP_SIZE 73
#define STRING_LENGTH 30
#define HASH_TRUE 1
#define HASH_FALSE 0

typedef struct hash_node
{
    const char *key;
    char *value;
} hash_node;

typedef struct hash_map
{
    hash_node **map; // define a pointer to a pointer pointing to the type of hash_node.
    int size;
} Hash_map;

Hash_map *hashmap_create(int size);
void hashmap_insert(Hash_map *map, const char *key, char *value);
char *hashmap_search(Hash_map *map, const char *key);
void hashmap_delete(Hash_map *map, const char *key);
int hashmap_exist(Hash_map *map, const char *key);
int _hashing(const char *key);
void test_all();

int main()
{
    test_all();
    return 0;
}

Hash_map *hashmap_create(int size)
{
    Hash_map *new_hashmap = malloc(sizeof(Hash_map));
    new_hashmap->map = malloc(sizeof(hash_node) * size);
    new_hashmap->size = size;
    for (int i = 0; i < size; i++)
    {
        new_hashmap->map[i] = NULL;
    }
    return new_hashmap;
}

void hashmap_insert(Hash_map *map, const char *key, char *value)
{
    int index = _hashing(key);
    hash_node *new_node = malloc(sizeof(hash_node));
    new_node->key = key;
    new_node->value = value;
    map->map[index] = new_node;
}

char *hashmap_search(Hash_map *map, const char *key)
{
    if (map->map[_hashing(key)])
    {
        return map->map[_hashing(key)]->value;
    }
    else
    {
        printf("Empty result!\n");
        exit(EXIT_FAILURE);
    }
}

void hashmap_delete(Hash_map *map, const char *key)
{
    int index = _hashing(key);
    if (map->map[index])
    {
        hash_node *tmp = map->map[index];
        map->map[index] = NULL;
        free(tmp);
    }
    else
    {
        printf("Empty result!\n");
        exit(EXIT_FAILURE);
    }
}

int hashmap_exist(Hash_map *map, const char *key)
{
    return map->map[_hashing(key)] == NULL ? HASH_FALSE : HASH_TRUE;
}

int _hashing(const char *key)
{
    int hash = 0, i = 0;
    while (key[i] != '\0')
    {
        hash = hash * 31 + key[i];
        i++;
    }
    return abs(hash % MAP_SIZE);
}

void test_all()
{
    printf("Running all the tests...\n");
    Hash_map *new_map = hashmap_create(MAP_SIZE);
    for (int i = 0; i < MAP_SIZE; i++)
    {
        assert(new_map->map[i] == NULL);
    }
    printf("Test Case: hashmap_create() - Passed.\n");
    assert(hashmap_exist(new_map, "Canada") == HASH_FALSE);
    hashmap_insert(new_map, "Canada", "I am coming!");
    assert(hashmap_exist(new_map, "Canada") == HASH_TRUE);
    printf("Test Case: hashmap_exist() - Passed.\n");
    assert(hashmap_search(new_map, "Canada") == "I am coming!");
    printf("Test Case: hashmap_search() - Passed.\n");
    hashmap_delete(new_map, "Canada");
    assert(hashmap_exist(new_map, "Canada") == HASH_FALSE);
    for (int i = 0; i < MAP_SIZE; i++)
    {
        assert(new_map->map[i] == NULL);
    }
    printf("Test Case: hashmap_delete() - Passed.\n");
}