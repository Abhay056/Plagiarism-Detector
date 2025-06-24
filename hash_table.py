class HashTable:
    def __init__(self):
        self.table = {}

    def put(self, key, value):
        self.table[key] = value

    def get(self, key):
        return self.table.get(key, None)

    def keys(self):
        return self.table.keys()

    def values(self):
        return self.table.values()

    def items(self):
        return self.table.items()
