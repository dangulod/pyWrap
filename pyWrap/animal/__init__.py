from ._animal import Animal
from .animal_greetings import animal_greetings

Animal.__str__ = lambda self: self.greetings()

Animal.__repr__ = lambda self: self.greetings()
