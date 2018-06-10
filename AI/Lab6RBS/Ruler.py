'''
Created on 2 Jun 2018

@author: stefan
'''
class Ruler:
    def __init__(self):
        self.rules = {
            "very_cold": {
                "dry": "medium",
                "normal": "short",
                "wet": "short"
            },
            "cold": {
                "dry": "long",
                "normal": "medium",
                "wet": "short"
            },
            "normal": {
                "dry": "long",
                "normal": "medium",
                "wet": "short"
            },
            "warm": {
                "dry": "long",
                "normal": "medium",
                "wet": "short"
            },
            "hot": {
                "dry": "long",
                "normal": "long",
                "wet": "medium"
            }
        }
    def evaluate(self, t, h):
        tdic = t.toDiscrete()
        hdic = h.toDiscrete()
        resdic = {}
        for tkey, tvalue in tdic.items():
            for hkey, hvalue in hdic.items():
                res = self.rules[tkey][hkey]
                val = min(tvalue, hvalue)
                if res in resdic:
                    resdic[res] = max(resdic[res], val)
                else:
                    resdic[res] = val
        return resdic
    
    
    
    