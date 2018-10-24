from HashTable import Hashtable
import csv
import re


class PIFNODE:
    def __init__(self, atom, pos=-1, bucket_pos=-1):
        self.pos = pos
        self.atom = atom
        self.bucketPos = bucket_pos
    def __str__(self):
        return str(self.atom) + "       ->" + str(self.pos)

class Parser:
    def __init__(self):
        self.codes = {}
        self.fillCodes()
        self.fillSeparatorsOperators()
        self.SymbolTableConst = Hashtable()
        self.SymbolTableID = Hashtable()
        self.PIF = []

    def fillCodes(self):
        f = open("codes.csv", "r")
        line = f.readline().strip()
        while True:
            elems = line.split(",")
            self.codes[elems[0]] = int(elems[1])

            line = f.readline().strip()
            if line == '':
                break
        self.codes[","] = 24
        print(self.codes)

    def fillSeparatorsOperators(self):
        with open('reserved_words.csv', 'r') as f:
            reader = csv.reader(f)
            self.reservedWords = list(reader)[0]
        self.separators = ["[", "]", "{", "}", "(", ")", ":", ";",","]
        self.operators = ["+", "-", "*", "/", ":=", "<", "<=", "=", ">=", "lt", "le", "gt", "ge"]

    def intTryParse(self, value):
        try:
            int(value)
            return True
        except ValueError:
            return False

    def classifyAtom(self, atom):
        pattern = re.compile("^[a-zA-Z](_*[a-zA-Z]*[0-9]*)*(?<!_)$")

        if atom in self.separators:
            # print("separator:" + atom)
            return False, "separator"
        elif atom in self.reservedWords:
            # print("reserved word:" + atom)
            return False, "reserveed"
        elif atom in self.operators:
            # print("operator: " + atom)
            return False, "operator"
        elif len(atom) < 8 and pattern.match(atom):
            # print("valid identifier:" + atom)
            return True, "id"
        elif self.intTryParse(atom):
            # print("constant")
            return True, "const"
        else:
            print("error")

    def finditer_with_separators(self, regex, string):
        matches = []
        prev_end = 0
        for match in regex.finditer(string):
            match_start = match.start()
            if (prev_end != 0 or match_start > 0) and match_start != prev_end:
                matches.append(string[prev_end:match.start()])
            matches.append(match.group())
            prev_end = match.end()
        if prev_end < len(string):
            matches.append(string[prev_end:])
        return matches

    def lexicalAnalysis(self):

        f = open("source_code.txt", "r")
        line = f.readline().strip()
        while True:
            #atoms = list(filter(None, re.split("[[\]{}(); ]+", line)))
            regex = re.compile('[[\]{}(); ]+')
            atoms = self.finditer_with_separators(regex, line)
            #print(atoms)
            for atom in atoms:
                #print(atom)
                if atom != " ":
                    need_pos, atom_type = self.classifyAtom(atom)
                    if not need_pos:
                        node = PIFNODE(self.codes[atom])
                        self.PIF.append(node)
                    else:
                        if atom_type == "id":
                            # print("add to IDs")
                            pos = self.SymbolTableID.insert(atom, 0)
                            node = PIFNODE("1", pos)
                            self.PIF.append(node)
                        elif atom_type == "const":
                            # print("add to cosnts")
                            pos = self.SymbolTableConst.insert(atom, 0)
                            node = PIFNODE("2", pos)
                            self.PIF.append(node)



            # print()
            line = f.readline().strip()
            if line == '':
                break

        print("PIF:")
        for pifNode in self.PIF:
            print(str(pifNode))

        print("symbol table:")
        print(self.SymbolTableID)

        print("const table:")
        print(self.SymbolTableConst)




p = Parser()

p.lexicalAnalysis()
