from main.utils.goal_state import GoalState
from main.utils.person_pose_classifier import classify_pose
import main.utils.config as Config

class GoalStateMachine:
    def __init__(self):
        self.state = GoalState.STARTED
        self.last_pose = Config.DEFAULT_POSE  # Initial default pose

    def update_state_based_on_pose(self, keypointToRealWorld):
        pose = classify_pose(keypointToRealWorld)


        if pose == Config.DEFAULT_POSE:
            pose = self.last_pose
        else:
            self.last_pose = pose

        if pose == Config.BOTH_HANDS_UP_POSE:
            self.state = GoalState.FOLLOW_PERSON_STOPPED
        elif self.state == GoalState.FOLLOW_PERSON_STOPPED and (pose == Config.RIGHT_HAND_UP_POSE or pose == Config.LEFT_HAND_UP_POSE):
            self.state = GoalState.FOUND_PERSON_TO_FOLLOW
        elif self.state == GoalState.FOUND_PERSON_TO_FOLLOW and pose == Config.NO_HAND_UP:
            self.state = GoalState.FOLLOW_PERSON
        else:
            self.state = GoalState.FOLLOW_PERSON_STOPPED

    def get_state(self):
        return self.state

    # Methods to check if a specific state is active
    def is_started(self):
        return self.state == GoalState.STARTED

    def is_follow_person_stopped(self):
        return self.state == GoalState.FOLLOW_PERSON_STOPPED

    def is_found_person_to_follow(self):
        return self.state == GoalState.FOUND_PERSON_TO_FOLLOW

    def is_follow_person(self):
        return self.state == GoalState.FOLLOW_PERSON

    def is_lost_person_to_follow(self):
        return self.state == GoalState.LOST_PERSON_TO_FOLLOW
