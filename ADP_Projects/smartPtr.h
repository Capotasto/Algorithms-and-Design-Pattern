//
//  smartPtr.h
//  ADP_Projects
//
//  Created by Norio Egi on 4/27/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef smartPtr_h
#define smartPtr_h

extern unsigned int g_uniqueID;
template <class T>
class smartPtr
{
public:
    smartPtr() : objPointer(0) {m_UID=g_uniqueID++;}
    smartPtr( T* ptrClass ) : objPointer(ptrClass){}
    ~smartPtr() { delete objPointer;}
    
    T* operator->() { return objPointer;}
    T& operator*() { return objPointer; }
    T* operator=(T* rhs) {
        objPointer = rhs;
        m_refCount++;
        //rhs.AddRef();
        return objPointer;
    }
    unsigned int AddRef() { return ++m_refCount; }
    unsigned int DecRef() { return --m_refCount; }

    
protected:
    T* objPointer;
    static int refcount;
    unsigned int m_refCount;
    unsigned int m_UID;
};

#endif /* smartPtr_h */
