class Person: 
    def __init__(self, person_id, x, y, z = float('nan')):
        self.person_id = person_id
        self.position = {'x': x, 'y': y, 'z': z}

    