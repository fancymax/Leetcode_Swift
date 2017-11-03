//
// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
//
//
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
//
// Follow up:
// Could you do both operations in O(1) time complexity?
//
// Example:
//
// LRUCache cache = new LRUCache( 2 /* capacity */ );
//
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4
//
//


public class LRUCache {
    Dictionary<int,int> dataCache;
    List<int> keyCache;
    int capacityOfKey;

    public LRUCache(int capacity) {
        keyCache = new List<int>();
        dataCache = new Dictionary<int,int>();
        capacityOfKey = capacity;
        
    }

    public int Get(int key) {
        if(!dataCache.ContainsKey(key))
        {
            return -1;
        }
        else
        {
            keyCache.Remove(key);
            keyCache.Add(key);
            return dataCache[key];
        }
    }

    public void Set(int key, int value) {
        if(dataCache.ContainsKey(key))
        {
            keyCache.Remove(key);
            keyCache.Add(key);

            dataCache[key]= value;
            return;
        }
        if(keyCache.Count() == capacityOfKey)
        {
            dataCache.Remove(keyCache[0]);
            keyCache.RemoveAt(0);
        }
        keyCache.Add(key);
        dataCache.Add(key,value);
    }
}
