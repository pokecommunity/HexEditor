#ifndef HEXEDITOR_H
#define HEXEDITOR_H

#include <QAbstractScrollArea>

class HexEditor : public QAbstractScrollArea
{
    Q_OBJECT

public:
    Q_PROPERTY(QByteArray   Data                     READ data                     WRITE setData)
    Q_PROPERTY(Mode         Mode                     READ mode                     WRITE setMode)
    Q_PROPERTY(bool         ReadOnly                 READ isReadOnly               WRITE setReadOnly)
    Q_PROPERTY(qint64       Position                 READ position                 WRITE setPosition)
    Q_PROPERTY(int          CursorPosition           READ cursorPosition           WRITE setCursorPosition)
    Q_PROPERTY(QColor       AddressBackgroundColor   READ addressBackgroundColor   WRITE setAddressBackgroundColor)
    Q_PROPERTY(QColor       HighlightingColor        READ highlightingColor        WRITE setHighlightingColor)
    Q_PROPERTY(QColor       SelectionColor           READ selectionColor           WRITE setSelectionColor)
    Q_PROPERTY(bool         AddressVisible           READ isAddressVisible         WRITE setAddressVisible)
    Q_PROPERTY(bool         TextVisible              READ isTextVisible            WRITE setTextVisible)
    Q_PROPERTY(bool         HighlightingEnabled      READ isHighlightingEnabled    WRITE setHighlightingEnabled)



    Q_ENUMS(Mode)

    enum Mode
    {
        INSERT,
        OVERWRITE
    };



    HexEditor(QWidget *parent = 0);



    int indexOf(const QByteArray &aArray, int aFrom=0) const;
    int lastIndexOf(const QByteArray &aArray, int aFrom=0) const;
    void insert(int aIndex, const QByteArray &aArray);
    void insert(int aIndex, char aChar);
    void remove(int aPos, int aLength=1);
    void replace(int aPos, int aLength, const QByteArray &aArray);
    QString toString();

    // ------------------------------------------------------------------

    QByteArray data() const;
    void setData(QByteArray const &aData);

    Mode mode() const;
    void setMode(const Mode &aMode);

    bool isReadOnly() const;
    void setReadOnly(const bool &aReadOnly);

    int position() const;
    void setPosition(int aPosition);

    qint64 cursorPosition() const;
    void setCursorPosition(qint64 aCursorPos);

    QColor addressBackgroundColor() const;
    void setAddressBackgroundColor(QColor const &aColor);

    QColor highlightingColor() const;
    void setHighlightingColor(QColor const &aColor);

    QColor selectionColor() const;
    void setSelectionColor(QColor const &aColor);

    bool isAddressVisible() const;
    void setAddressVisible(const bool &aAddressVisible);

    bool isTextVisible() const;
    void setTextVisible(const bool &aTextVisible);

    bool isHighlightingEnabled() const;
    void setHighlightingEnabled(const bool &aEnable);

protected:
    QByteArray mData;
    Mode       mMode;
    bool       mReadOnly;
    qint64     mCursorPosition;
    QColor     mAddressBackgroundColor;
    QColor     mHighlightingColor;
    QColor     mSelectionColor;
    bool       mAddressVisible;
    bool       mTextVisible;
    bool       mHighlightingEnabled;

    void updateScrollBars();
    void paintEvent(QPaintEvent *event);

public slots:
    void undo();
    void redo();    

signals:
    void dataChanged();
    void sizeChanged(int aSize);
    void modeChanged(Mode aMode);
    void positionChanged(int aPosition);
};

#endif // HEXEDITOR_H
