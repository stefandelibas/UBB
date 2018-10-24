class Node:
    def __init__(self, key, value):
        self.pos = 0
        self.key = key
        self.value = value

    def setPos(self, pos):
        self.pos = pos

    def __str__(self):
        return "\n" + str(self.key) + " on pos " + str(self.pos)

    def __eq__(self, other):
        othernode = ()

class Hashtable:
    def __init__(self, capacity=100):
        self.capacity = capacity
        self.size = 0
        self.buckets = []
        [self.buckets.append([]) for i in range(self.capacity)]

    def insert(self, key, value):
        pos = self.getHash(key)
        node = Node(key, value)
        if node not in self.buckets:
            if len(self.buckets[pos]) != 0:
                node.setPos(len(self.buckets[pos]))
            self.buckets[pos].append(node)
        return pos

    def getValue(self, key):
        hashvalue = self.getHash(key)
        for node in self.buckets[hashvalue]:
            if node.key == key:
                return node.value

    def getHash(self, key):
        return sum(ord(ch) for ch in key) % self.capacity

    def __str__(self):
        str1 = ""
        for bucket in self.buckets:
            for node in bucket:
                str1 += str(node) + " "
        return str1
