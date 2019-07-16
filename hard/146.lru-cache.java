/*
 * @lc app=leetcode id=146 lang=java
 *
 * [146] LRU Cache
 */
class LRUCache {

    class CacheUnit{
        public int key;
        public int value;
        public CacheUnit(int key,int value){
            this.key = key;
            this.value = value;
        }
    }
    
    LinkedList<CacheUnit> list;
    HashMap<Integer,CacheUnit> map;
    int maxCapacity;
    int currentCapacity;
    public LRUCache(int capacity) {
        maxCapacity = capacity;
        currentCapacity = 0;
        list = new LinkedList<>();
        map = new HashMap<>();
    }
    
    public int get(int key) {
        CacheUnit res = map.get(key);
        if(res == null){
            return -1;
        }
        list.remove(res);
        list.addFirst(res);
        return res.value;
    }
    
    public void put(int key, int value) {
        CacheUnit res = map.get(key);
        if(res != null){
            CacheUnit unit = new CacheUnit(key,value);
            map.put(key,unit);
            list.remove(res);
            list.addFirst(unit);
        }else{
            if(currentCapacity == maxCapacity){
                CacheUnit unit = list.getLast();
                list.removeLast();
                map.remove(unit.key);
            }else{
                currentCapacity++;
            }
            CacheUnit unit = new CacheUnit(key,value);
            map.put(key,unit);
            list.addFirst(unit);
        }
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

