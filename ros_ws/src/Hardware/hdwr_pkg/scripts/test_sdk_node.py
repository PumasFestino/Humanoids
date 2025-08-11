#!/usr/bin/env python3

import time
import rclpy
from rclpy.node import Node
from hardware.srv import HumanSrv
from rocs_client import Human
from rocs_client.robot.human import ArmAction

human = None

# Websocket fuctions
async def on_connected():
    print("WebSocket opened...")

# SDK functions
# The startup process of control server will normally take some time.
def control_server_start():
    human._control_svr_start()
    time.sleep(10)

def start():
    res = human.start()
    print(f'start: {res}')

def stand():
    res = human.stand()
    print(f'stand: {res}')

def upper_body_arm():
    res = human.upper_body(arm=ArmAction.HELLO)
    print(f'arm: {res}')

class HumanActionsServer(Node):
	def __init__(self):
		super().__init__('human_actions_server')

		# Create the service
		self.srv = self.create_service(
			HumanSrv,
			'human_actions',
			self.human_actions_callback
		)

		control_server_start()
		start()

		self.get_logger().info('Human actions server is ready.')

	def human_actions_callback(self, request, response):
		try:
			match request.human_action:
				case 'stand':
					stand()
					response.success = True
				case 'wave':
					upper_body_arm()
					response.success = True
				case 'close':
					raise KeyboardInterrupt("Automated shutdown!")
					response.success = True
				case _:
					response.success = False
		except Exception as e:
			self.get_logger().error(f'Error callback: {str(e)}')
			response.success = False

		return response

def main():
	rclpy.init()

	global human

	# Instance creation of Human class
	# human = Human(on_connected=on_connected, host="192.168.12.1")
	human = Human(on_connected=on_connected, host="127.0.0.1")
	time.sleep(1)

	human_actions_server = HumanActionsServer()

	try:
		rclpy.spin(human_actions_server)
	except KeyboardInterrupt:
		pass
	finally:
		# After 'close' command is executed, the workflow will come to the Ending phase.
		print('close_control_svr: ', human._control_svr_close())
		human.exit()
		human_actions_server_server.destroy_node()
		rclpy.shutdown()

if __name__ == '__main__':
	main()