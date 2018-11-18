#ifndef _BITMAP_H_
#define _BITMAP_H_

#include <cstdio>
#include <stdlib.h>

#define BIT_ITME_TYPE       unsigned long

#define BIT_PER_BYTE        8
#define BIT_MODE(idx)       ( ( idx ) / BIT_PER_BYTE )
#define BIT_OFFSET(idx)     ( ( idx ) % BIT_PER_BYTE )
#define BIT_ITEM_SIZE       ( BIT_PER_BYTE * sizeof( BIT_ITME_TYPE ) )
#define BIT_ITEMS(idx)      ( ( ( idx ) / BIT_ITEM_SIZE ) + 1 )

#define PTR2NUM(x)          ((unsigned long)(x))

class CBitmap {
public:
    CBitmap(unsigned int x = 1000000000) {
        unsigned int item_size = BIT_ITEM_SIZE;
        maxbit = x;
        if (maxbit % item_size != 0) {
            maxbit = (maxbit + item_size) / item_size * item_size;
        }
        bytes = maxbit / BIT_PER_BYTE;
        items = maxbit / item_size;
        usedbit = 0;
        mem = NULL;
        data = NULL;
    }

    ~CBitmap() {
        if (NULL != data) {
            delete [] data;
            data = NULL;
        }
        mem = NULL;
    }

    bool init(bool z) {
        mem = NULL;
        data = new unsigned char [bytes];
        if (NULL == data) {
            return false;
        }
        mem = (BIT_ITME_TYPE*) data;
        clear(z);
        return true;
    }

    CBitmap& operator = (const CBitmap& other) {
        int index = 0;
        for (index = 0; index < items; index++) {
            mem[index] = other.mem[index];
        }
        usedbit = other.usedbit;
        //ILOG(ILOG_DEBUG,"this %p usedbit %d items %d",this,usedbit,items);
        return *this;
    }
    CBitmap& operator &= (const CBitmap& other) {
        int index = 0;
        int bit = usedbit <= other.usedbit ? usedbit : other.usedbit;
        int item = BIT_ITEMS(bit);
        for (index = 0; index < item; index++) {
            mem[index] &= other.mem[index];
        }
        usedbit = bit;
        //ILOG(ILOG_DEBUG,"this %p usedbit %d items %d",this,usedbit,item);
        return *this;
    }
    CBitmap& operator |= (const CBitmap& other) {
        int index = 0;
        int bit = usedbit >= other.usedbit ? usedbit : other.usedbit;
        int item = BIT_ITEMS(bit);
        for (index = 0; index < item; index++) {
            mem[index] |= other.mem[index];
        }
        usedbit = bit;
        //ILOG(ILOG_DEBUG,"this %p usedbit %d items %d",this,usedbit,item);
        return *this;
    }
    void clear(bool z) {
        int index = 0;
        for (index = 0; index < items; index++) {
            mem[index] = z ? ~0 : 0;
        }
        usedbit = z ? (maxbit - 1) : 0;
        //ILOG(ILOG_DEBUG,"this %p usedbit %d item %d",this,usedbit,items);
    }

    int bits(unsigned int* arr, int length) {
        unsigned int bit = 0;
        int ndoc = 0;
        for (bit = 0; (int) bit <= usedbit; bit++) {
            if ((data[BIT_MODE(bit)] >> (BIT_PER_BYTE - BIT_OFFSET(bit) - 1)) & 0x01) {
                if (ndoc < length) {
                    arr[ndoc++] = bit;
                    if (ndoc >= length) {
                        return ndoc;
                    }
                }
            }
        }
        return ndoc;
    }

    int bits(void** arr, int length) {
        unsigned int bit = 0;
        int ndoc = 0;
        for (bit = 0; (int) bit <= usedbit; bit++) {
            if ((data[BIT_MODE(bit)] >> (BIT_PER_BYTE - BIT_OFFSET(bit) - 1)) & 0x01) {
                if (ndoc < length) {
                    arr[ndoc++] = reinterpret_cast<void*>(bit);
                    if (ndoc >= length) {
                        //ILOG(ILOG_DEBUG,"this %p maxbit %d usedbit %d ndoc %d length %d",this,maxbit,usedbit,ndoc,length);
                        return ndoc;
                    }
                }
            }
        }
        //ILOG(ILOG_DEBUG,"this %p maxbit %d usedbit %d ndoc %d length %d",this,maxbit,usedbit,ndoc,length);
        return ndoc;
    }

    void bitscopy(const char* arr, int length) {
        length = length > bytes ? bytes : length;
        memcpy(data, arr, length);
        int index = 0;
        while (index < length * BIT_PER_BYTE) {
            if ((data[BIT_MODE(index)] >> (BIT_PER_BYTE - BIT_OFFSET(index) - 1)) & 0x01) {
                usedbit = index;
            }
            index++;
        }
    }

    bool set(unsigned int index, bool z) {
        if ((int)index < maxbit) {
            if (0 == z) {
                data[BIT_MODE(index)] &= ~(1 << (BIT_PER_BYTE - BIT_OFFSET(index) - 1));
            } else {
                data[BIT_MODE(index)] |= (1 << (BIT_PER_BYTE - BIT_OFFSET(index) - 1));
                if ((int)index > usedbit) {
                    usedbit = index;
                }
            }
            //ILOG(ILOG_DEBUG,"this %p usedbit %d index %u z %d",this,usedbit,index,z);
            return true;
        }
        return false;
    }

    inline bool get(unsigned int index) {
        if ((int)index < maxbit) {
            if ((data[BIT_MODE(index)] >> (BIT_PER_BYTE - BIT_OFFSET(index) - 1)) & 0x01) {
                return true;
            }
        }
        return false;
    }

    inline int max() {
        return maxbit;
    }

    inline int size() {
        return usedbit;
    }

    inline int nbyte() {
        return bytes;
    }

    inline unsigned char* addr() {
        return data;
    }
public:
    int maxbit; // max bit
    int usedbit;// used max bit, TODO
    int bytes;  // bytes
    int items;  // bytes / sizeof( BIT_ITME_TYPE )
    BIT_ITME_TYPE* mem;   // int mem[items]
    unsigned char* data;  // char data[bytes]
};

#endif // _BITMAP_H_
