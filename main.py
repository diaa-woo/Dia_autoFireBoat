import cv2
import numpy as np

im1 = cv2.imread('./image/myImageSample.png', cv2.IMREAD_COLOR)
print(type(im1))
print(im1.shape)
print(im1.size)
print(im1.dtype)

file = open('./pixelCode.txt','w')

for i in range(0,im1.shape[0]):
    for j in range(0,im1.shape[1]):
        data = file[i,j]
        file.write("%d " % data)
    file.write("\n")