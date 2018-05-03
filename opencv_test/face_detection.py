import numpy as np
import cv2

import indicoio

indicoio.config.api_key = "b57606da653f10a89fe88740d7a74164"

# face_cascade = cv2.CascadeClassifier('./opencv-3.4.1/data/haarcascades_cuda/haarcascade_frontalface_default.xml')
# eye_cascade = cv2.CascadeClassifier('./opencv-3.4.1/data/haarcascades_cuda/haarcascade_eye.xml')

# load the training set
face_cascade = cv2.CascadeClassifier('./haarcascade_frontalface_default.xml')
eye_cascade = cv2.CascadeClassifier('./haarcascade_eye.xml')

#Images to analyze
img = cv2.imread('kid.jpg')
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# face detection
faces = face_cascade.detectMultiScale(gray, 1.3, 5)
for (x,y,w,h) in faces:
    img = cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
    roi_gray = gray[y:y+h, x:x+w]
    roi_color = img[y:y+h, x:x+w]

    # sentiment analysis
    out = indicoio.fer(roi_color)
    print(out)

    # eye detection
    eyes = eye_cascade.detectMultiScale(roi_gray)
    for (ex,ey,ew,eh) in eyes:
        cv2.rectangle(roi_color,(ex,ey),(ex+ew,ey+eh),(0,255,0),2)

#Wait time and quit 
cv2.waitKey(0)
cv2.destroyAllWindows()
