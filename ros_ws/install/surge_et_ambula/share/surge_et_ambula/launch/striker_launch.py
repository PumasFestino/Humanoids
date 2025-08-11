import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='task_manager',
            executable='striker_node',
            name='striker',
            output='screen',
            parameters=[{
                'striker_position.x': 1.5,
                'striker_position.y': 0.0,
                'striker_position.theta': 0.0,
                'game_active': True,
                'max_ball_search_attempts': 30,
                'ball_approach_timeout': 5.0,
                'alignment_threshold': 0.1
            }],
            emulate_tty=True
        )
    ])