#ifndef SCANNER_H
#define SCANNER_H

#include <QObject>

class ScannerSignals : public QObject {
    Q_OBJECT
public:
    ScannerSignals() = default;
    ~ScannerSignals() = default;
signals:
    void codeScanned(QString code);
    void scannerStopped();
};

class Scanner {
public:
    Scanner() = default;
    virtual ~Scanner() = default;
public:
    virtual void scan() = 0;
    virtual void stop() = 0;
public:
    ScannerSignals _signals;
};

#endif // SCANNER_H
