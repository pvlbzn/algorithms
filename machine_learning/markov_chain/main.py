import random


class MarkovChain:
    def __init__(self, fname):
        self.chain = self.build(self.to_list(self.read(fname)))
    
    def read(self, fname):
        with open(fname) as txt:
            text = txt.read()
        
        return text
    
    def to_list(self, text):
        return [word.lower() for word in text.split(' ') if word != '' and word.isalpha()]

    def build(self, tlist):
        chain = {}
        index = 1

        for word in tlist[index:]:
            key = tlist[index-1]
            if key in chain:
                chain[key].append(word)
            else:
                chain[key] = [word]
            
            index += 1
        
        return chain

    def generate(self, length=140):
        word = random.choice(list(self.chain.keys()))
        message = word.capitalize()

        while len(message.split(' ')) < length:
            second_word = random.choice(self.chain[word])
            word = second_word
            message += ' ' + second_word
        
        return message


if __name__ == '__main__':
    fname = ''

    if fname == '':
        raise Exception('Text file path is missing')
    