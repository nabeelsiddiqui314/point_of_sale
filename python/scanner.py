from pyzbar.pyzbar import decode
import cv2

capture = cv2.VideoCapture(0)

def captureBarcode():
	flag, frame = capture.read()
	barcodes = decode(frame)
	
	if barcodes:
		return barcodes[0].data.decode("utf-8")
	return "0"
        
    
