from ._person import Person
from ._person import greet

Person.__str__ = lambda self: self.greetings()

Person.__repr__ = lambda self: self.greetings()
