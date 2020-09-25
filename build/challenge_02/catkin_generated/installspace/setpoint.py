#!/usr/bin/env python2
#!/usr/bin/env python2

import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from math import pow, atan2, sqrt

class TurtleBot:
	def __init__(self):
		#Create node and make it unique
		rospy.init_node('turtlebot_controller', anonymous=True)

		#Publisher to turtle vel
		self.velocity_publisher = rospy.Publisher('/turtle1/cmd_vel', Pose, queue_size=10)

		#Subscriber to pose - self update when Pose type message is received
		self.pose_subscriber = rospy.Subscriber('/turtle/pose', Pose, self.update_pose)

		self.pose = Pose()
		self.rate = rospy.Rate(10)

	def update_pose(self, data):
		#Callback function when Pose type message is receied by subscriber
		self.pose = data
		self.pose.x = round(self.pose.x, 4)
		self.pose.y = round(self.pose.y, 4)

	def euclidean_distance(self, goal_pose):
		#Euclidean distance from current pose to goal
		return sqrt(pow((goal_pose.x - self.pose.x), 2) + pow((goal_pose.y - self.pose.y), 2))

	def linear_vel(self, goal_pose, constant=1.5):
		return constant * self.euclidean_distance(goal_pose)

	def steering_angle(self, goal_pose, constant=1.5):
		return atan2(goal_pose.y - self.pose.y, goal_pose.x - self.pose.x)

	def angular_vel(self, goal_pose, constant=6):
		return constant * (self.steering_angle(goal_pose) - self.pose.theta)

	def setpos(self):
		#Moves turtle to goal
		goal_pose = Pose()

		#Save user input
		goal_pose.x = input("Set your x goal: ")
		goal_pose.y = input("Set your y goal: ")

		#Hardcode tolerance
		distance_tolerance = 0.1

		vel_msg = Twist()

		while self.euclidean_distance(goal_pose) >= distance.tolerance:

			#Linear velocity in the x-axis
			vel_msg.linear.x = self.linear_vel(goal_pose)
			vel_msg.linear.y = 0
			vel_msg.linear.z = 0

			#Angular velocity in the z-axis
			vel_msg.linear.x = 0
                        vel_msg.linear.y = 0
                        vel_msg.linear.z = self.angular_vel(goal_pose)

			#Publishing vel_msg
			self.velocity_publisher.publish(vel_msg)
			self.rate.sleep()

		#Stop turtle after movement is over
		vel_msg.linear.x = 0
		vel_msg.linear.z = 0
		self.velocity_publisher.publish(vel_msg)

		#Create the option to close with HOME+C
		rospy.spin()

if __name__ == '__main__':
	try:
		x = TurtleBot()
		x = setpos()
	except rospy.ROSInterruptException
		pass
