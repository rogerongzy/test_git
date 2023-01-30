import rospy
from std_msgs.msg import String

# test on queue size

class SimpleSubscriber():
    def __init__(self) -> None:
        self.node=rospy.init_node('simple_listener')
        self.rate = rospy.Rate(1)
        self.sub= rospy.Subscriber('simple_talker',String,self.callback,queue_size=5)

    def callback(self,msg):
        print(msg)
        self.rate.sleep()

if __name__ == '__main__':
    SimpleSubscriber()
    rospy.spin()