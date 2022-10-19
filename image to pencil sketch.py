import cv2

# Reading the original image
image = cv2.imread('./dog.jpg')
# Displaying Original Image
cv2.imshow("Original Image", image)
cv2.waitKey(0)

# Reading the black and white image
b_and_w_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
# Displaying Black And White Image
cv2.imshow("Black and White Image", b_and_w_image)
cv2.waitKey(0)

# Inverting the image
inverted_image = 255 - b_and_w_image
# Displaying Inverted Image
cv2.imshow("Inverted Image", inverted_image)
cv2.waitKey()

# Blurring the image
blurred = cv2.GaussianBlur(inverted_image, (21, 21), 0)

# Inverting the Blurred Image
inverted_blurred = 255 - blurred
# Creating the Pencil Sketch image
pencil_sketch = cv2.divide(b_and_w_image, inverted_blurred, scale=256.0)
# Displaying Sketch Image
cv2.imshow("Sketch Image", pencil_sketch)
cv2.waitKey(0)

# Displaying Original Image
cv2.imshow("Original Image", image)
# Displaying Sketch Image
cv2.imshow("Pencil Sketch Image", pencil_sketch)
cv2.waitKey(0)
