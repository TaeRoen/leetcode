import java.util.ArrayList;
import java.util.HashMap;

import com.sun.xml.internal.bind.v2.schemagen.xmlschema.List;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList<>();
        HashMap<String, List<String>> m = new HashMap<>();
        for (String str : strs) {
            char[] cs = str.toCharArray();
            Arrays.sort(cs);
            String s = new String(cs);
            List<String> list = m.get(s);
            if (list == null) {
                list = new ArrayList<String>();
                m.put(s, list);
            }
            list.add(str);
        }
        for (String k : m.keySet()) {
            res.add(m.get(k));
        }
        return res;
    }
}