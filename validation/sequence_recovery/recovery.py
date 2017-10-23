class SequenceRecoverer:
    def __init__(self, seq):
        '''
        Sequence recoverer.

        Get a sequence of comparable elements and return missing elements.
        For example sequence [1, 2, 4, 5, 7] is missing [3, 6].

        Arguments:
            seq: sequence to recover
        '''
        self.seq = seq
    
    def recover(self):
        min, max = self._find_bounds()
        counter = 0
        missing = []

        for i in range(min, max):
            if not (self.seq[counter] == i):
                missing.append(i)
            else:
                counter += 1

        return missing    
    
    def _find_bounds(self):
        min = self.seq[0]
        max = self.seq[0]
        for elem in self.seq:
            if elem > max:
                max = elem
            if elem < min:
                min = elem
        
        return (min, max)


def recover(seq):
    return SequenceRecoverer(seq).recover()

if __name__ == '__main__':
    s = [1,2,4,5,7,9,11,12]
    print(recover(s))