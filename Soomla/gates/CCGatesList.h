//
// Created by Shubin Fedor on 20/08/14.
// Copyright (c) 2014 SOOMLA. All rights reserved.
//


#ifndef __CCGatesList_H_
#define __CCGatesList_H_

#include "CCGate.h"
#include "CCLevelUpConsts.h"
#include "CCBalanceMission.h"
#include "CCVirtualCurrency.h"
#include "CCVirtualGood.h"

namespace soomla {

    class CCGatesList: public CCGate {
        friend class CCGateListEventHandler;
        CC_SYNTHESIZE_RETAIN(cocos2d::__Array *, mGates, Gates);
        CC_SYNTHESIZE_RETAIN(CCLevelUpEventHandler *, mEventHandler, EventHandler);
    public:
        CCGatesList(): CCGate(), mGates(NULL), mEventHandler(NULL) {
        }

        bool init(cocos2d::__String *id, cocos2d::__Array *gates = NULL);
        bool init(cocos2d::__String *id, CCGate *gate);

        virtual bool initWithDictionary(cocos2d::__Dictionary* dict);

        virtual cocos2d::__Dictionary *toDictionary();

        virtual ~CCGatesList();

        unsigned int count();
        void add(CCGate *gate);
        void remove(CCGate *gate);
    protected:
        virtual bool openInner();

        virtual void registerEvents();

        virtual void unregisterEvents();
    };

    class CCGateListEventHandler: public CCSimpleLevelUpEventHandler {
    private:
        CCGatesList *mGatesList;
    public:
        static CCGateListEventHandler *create(CCGatesList *gatesList);

        virtual void onGateOpened(CCGate *gate);
    };
}

#endif //__CCGatesList_H_
