from enum import Enum 

class Follow_Person_State(Enum): 
    STARTED = 0
    LOOK_FOR_PERSON_TO_FOLLOW = 1
    FOUND_PERSON_TO_FOLLOW = 2
    FOLLOW_PERSON = 3
    STOP_FOLLOW_PERSON = 4