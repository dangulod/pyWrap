from ._animal import Animal as Animal

def animal_greetings(name, age):
    return Animal(name, age).greetings()

