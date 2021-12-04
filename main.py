import cv2
import numpy as np

im1 = cv2.imread('./image/myImageSample2.png', cv2.IMREAD_COLOR)
print(type(im1))
print(im1.shape)
print(im1.size)
print(im1.dtype)
print(im1[391,4])
print(type(im1[391, 4]))

file = open('./pixelCode.txt','w')
np.save('./npy_test', arr=im1)
npy_array = np.load(file="npy_test.npy")
print(npy_array[325,52])

