import cv2
import numpy as np
import os
import pickle

# Step 1: Collect a set of images of faces and their corresponding names to use as a database
dataset_path = "dataset"
embeddings_path = "output/embeddings.pickle"
recognizer_path = "output/recognizer.pickle"
label_encoder_path = "output/le.pickle"

# Step 2: Use OpenCV's pre-trained Haar Cascades to detect facial features
face_detector = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

# Step 3: Extract the facial features using the detected coordinates
def extract_face_features(image):
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    faces = face_detector.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

    if len(faces) == 0:
        return None, None

    (x, y, w, h) = faces[0]
    face = gray[y:y + h, x:x + w]
    return face, (x, y, w, h)

# Step 4: Calculate facial embeddings using a pre-trained deep learning model such as FaceNet or VGGFace
embeddings_model = cv2.dnn.readNetFromTorch("openface_nn4.small2.v1.t7")
def get_face_embedding(face):
    faceBlob = cv2.dnn.blobFromImage(face, 1.0 / 255, (96, 96), (0, 0, 0), swapRB=True, crop=False)
    embeddings_model.setInput(faceBlob)
    embedding = embeddings_model.forward()
    return embedding.flatten()

# Step 5: Create a database to store the facial embeddings and their corresponding names
embeddings = []
labels = []
image_paths = []

for subdir in os.listdir(dataset_path):
    subdir_path = os.path.join(dataset_path, subdir)

    if not os.path.isdir(subdir_path):
        continue

    for filename in os.listdir(subdir_path):
        image_path = os.path.join(subdir_path, filename)

        image = cv2.imread(image_path)
        face, face_bbox = extract_face_features(image)

        if face is None:
            continue

        label = subdir
        face_embedding = get_face_embedding(face)

        embeddings.append(face_embedding)
        labels.append(label)
        image_paths.append(image_path)

# Step 6: Save the embeddings and labels to disk
data = {"embeddings": embeddings, "labels": labels, "image_paths": image_paths}
f = open(embeddings_path, "wb")
f.write(pickle.dumps(data))
f.close()
