import rospy
import time
from std_msgs.msg import String
 
def talker():
    pub = rospy.Publisher('chatter', String, queue_size=10) # what does queue_size mean here?
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        # hello_str = "hello world %s" % rospy.get_time()
        str_time = '%s' % rospy.get_time() # 
        rospy.loginfo('Published time: ' + str_time)
        # rospy.loginfo('Real time: ' + real_time) # within 1e-5, should be the same
        pub.publish(str_time)
        rate.sleep()
        

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass