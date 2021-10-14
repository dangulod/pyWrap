from ._animal import Animal as Animal

Animal.__str__ = lambda self: self.greetings()

Animal.__repr__ = lambda self: self.greetings()
