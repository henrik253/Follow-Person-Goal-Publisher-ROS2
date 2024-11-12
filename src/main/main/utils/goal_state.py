from enum import Enum 


class GoalState(Enum): 
    STARTED = 0
    LOOK_FOR_PERSON_TO_FOLLOW = 1
    FOUND_PERSON_TO_FOLLOW = 2
    FOLLOW_PERSON = 3
    LOST_PERSON_TO_FOLLOW = 4
    FOLLOW_PERSON_STOPPED = 4
