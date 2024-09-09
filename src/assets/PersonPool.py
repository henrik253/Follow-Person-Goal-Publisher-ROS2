import Person
import heapq 

class PersonPool: 
    def __init__(self, capacity): 
        self.capicity = capacity
        self.pool = {}
        self.max_heap
    
    def add_person(self, person):
        if person.person_id in self.pool: 
            self._remove_person(person.person.id)
        
        if len(self.pool) >= self.capicity:
            self._remove_farthest_person()

        self.pool(person.person_id) = person
        heapq.heappush(self.max_heap, (-person.position['z'], person.person_id))
    
    def _remove_person(self,person_id):
        if person_id in self.pool:
            del self.pool[person_id]
            # Remove oudtaed entrys in max heap 
            self.max_heap = [entry for entry in self.max_heap if entry[1] != person_id]
            heapq.heapify(self.max_heap) # Reahipfiy to maintain heap prio
    
    def _remove_farthest_person(self):
        while(self.max_heap):
            z_value, person_id = heapq.heappop(self.max_heap)
            if person_id in self.pool: 
                self._remove_farthest_person(person_id)
                break 
    
    def get_clostest_person(self):
        if not self.pool:
            return None 
        return min(self.pool.values(), key=lambda p: p.position['z'])
    
    def __repre__(self):
        return f"PersonPool({list(self.pool.values())})"
        
        
