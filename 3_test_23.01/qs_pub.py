import rospy
from std_msgs.msg import String

# test on queue size

if __name__ == '__main__':
    rospy.init_node('simple_talker')
    rate = rospy.Rate(5)

    pub = rospy.Publisher('simple_talker', String, queue_size=5)
    i = 0
    while not rospy.is_shutdown():
        msg = String(str(i))
        pub.publish(msg)
        print(msg)
        i += 1
        rate.sleep()