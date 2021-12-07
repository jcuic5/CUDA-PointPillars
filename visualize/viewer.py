"""
author: hova88
date: 2021/03/16
"""
import numpy as np
from visual_tools import draw_clouds_with_boxes
import open3d as o3d

if __name__ == "__main__":
    # cloud_path = '../data/000008.bin'
    # cloud_path = '../data_painted/000007.bin'
    # cloud_path = '../data_painted_no_intensity_vlp16/000007.bin'
    cloud_path = '../data_painted_no_intensity_kitti/000006.bin'
    # boxes_path = '../data/box_prediction/result_8.txt'
    # boxes_path = '../data_painted/box_prediction/result_7.txt'
    # boxes_path = '../data_painted_no_intensity_vlp16/box_prediction/result_7.txt'
    boxes_path = '../data_painted_no_intensity_kitti/box_prediction/result_000006.txt'
    cloud = np.fromfile(cloud_path, dtype=np.float32).reshape(-1,4)
    # cloud = np.fromfile(cloud_path, dtype=np.float32).reshape(-1,5)
    boxes = np.loadtxt(boxes_path).reshape(-1,9)
    boxes = boxes[boxes[:, -1] > 0.3][:, :7] # score threshold = 0.3
    draw_clouds_with_boxes(cloud, boxes)
