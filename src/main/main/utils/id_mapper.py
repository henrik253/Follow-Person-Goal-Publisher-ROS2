class idMapper:
    def __init__(self):
        self.key_to_value = {}  # Maps keys to values

    def put(self, key, value):
        for (k,v) in  list(self.key_to_value.items()): # make copy in list to not change size during iteration
            if v == value:
                del self.key_to_value[k]
                self.key_to_value[key] = value
                return

        self.key_to_value[key] = value # value is not in map

    def get(self, key):
        return self.key_to_value[key]

    def keys(self):
        return self.key_to_value.keys()

    def values(self):
        return self.key_to_value.values()

    def items(self):
        return self.key_to_value.items()
    
    def get_key_from_value(self,value):
        for k,v in self.key_to_value.items():
            if(value == v):
                return k
        return None
