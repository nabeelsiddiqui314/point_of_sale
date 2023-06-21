from pyzbar.pyzbar import decode
import cv2


def captureBarcode():
    noBarcode = True
    capture = cv2.VideoCapture(1)
    barcodeList = []

    while (noBarcode):
        flag, frame = capture.read()

        barcodes = decode(frame)
        if not barcodes:
            pass
        else:
            for barcode in barcodes:
                barcodeList.append(barcode.data)
            break
    return barcodeList

