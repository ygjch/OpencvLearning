import cv2 as cv
import numpy as np
img = cv.imread("Q:\\python++\\untitled\\1.jpg")

img_origin = np.array(cv.imread("Q:\\python++\\untitled\\1.jpg"))
cv.namedWindow("bmp_img")
cv.imshow("bmp_img", img_origin)

rgb_img = np.array([img_origin.shape[0], img_origin.shape[1], cv.CV_8UC3])
tmp = 0
for y in range(img_origin.shape[0]):
    for x in range(img_origin.shape[1]):
        tmpss = img_origin[y][x]
        rgb_img[y][x][0] = abs(255 - tmpss)
        rgb_img[y][x][1] = abs(127 - tmpss)
        rgb_img[y][x][2] = abs(0 - tmpss)

cv.namedWindow("rgb_img")
cv.imshow("rgb_img", rgb_img)
