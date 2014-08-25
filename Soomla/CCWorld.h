//
// Created by Shubin Fedor on 22/08/14.
// Copyright (c) 2014 SOOMLA. All rights reserved.
//


#ifndef __CCWorld_H_
#define __CCWorld_H_

#include "CCSoomlaEntity.h"
#include "CCGate.h"
#include "CCScore.h"
#include "CCMission.h"
#include "CCReward.h"

namespace soomla {

    class CCWorld: public CCSoomlaEntity {
        CC_SYNTHESIZE_RETAIN(CCGate *, mGate, Gate);
        CC_SYNTHESIZE_RETAIN(cocos2d::__Dictionary *, mInnerWorldsMap, InnerWorldsMap);
        CC_SYNTHESIZE_RETAIN(cocos2d::__Dictionary *, mScores, Scores);
        CC_SYNTHESIZE_RETAIN(cocos2d::__Array*, mMissions, Missions);
    public:
        CCWorld(): CCSoomlaEntity(), mGate(NULL), mInnerWorldsMap(NULL), mScores(NULL), mMissions(NULL) {
        }

        static CCWorld *create(cocos2d::__String *id);
        static CCWorld *create(cocos2d::__String *id, CCGate *gate,
                cocos2d::__Dictionary *innerWorldsMap, cocos2d::__Dictionary *scores, cocos2d::__Array *missions);

        SL_CREATE_WITH_DICTIONARY(CCWorld);

        virtual bool init(cocos2d::__String *id);
        virtual bool init(cocos2d::__String *id, CCGate *gate,
                cocos2d::__Dictionary *innerWorldsMap, cocos2d::__Dictionary *scores, cocos2d::__Array *missions);

        virtual bool initWithDictionary(cocos2d::__Dictionary* dict);

        virtual cocos2d::__Dictionary *toDictionary();

        virtual char const *getType() const;

        virtual ~CCWorld();

    public:
        void addInnerWorld(CCWorld *world);
        void addMission(CCMission *mission);
        void addScore(CCScore *score);

        void batchAddLevelsWithTemplates(int numLevels, CCGate *gateTemplate, CCScore *scoreTemplate, CCMission *missionTemplate);
        void batchAddLevelsWithTemplates(int numLevels, CCGate *gateTemplate, cocos2d::__Array *scoreTemplates, cocos2d::__Array *missionTemplates);

        void setSingleScoreValue(double amount);
        void decSingleScore(double amount);
        void incSingleScore(double amount);
        CCScore *getSingleScore();

        void resetScores(bool save);
        void decScore(char const *scoreId, double amount);
        void incScore(char const *scoreId, double amount);

        cocos2d::__Dictionary *getRecordScores();
        cocos2d::__Dictionary *getLatestScores();

        void setScoreValue(char const *id, double scoreVal);
        void setScoreValue(char const *id, double scoreVal, bool onlyIfBetter);

        bool isCompleted();
        void setCompleted(bool completed);
        void setCompleted(bool completed, bool recursive);

        void assignReward(CCReward *reward);
        cocos2d::__String *getAssignedRewardId();

        bool canStart();
    private:
        char const *getIdForAutoGeneratedLevel(char const *id, int idx);
        char const *getIdForAutoGeneratedScore(char const *id, int idx);
        char const *getIdForAutoGeneratedGate(char const *id);
        char const *getIdForAutoGeneratedMission(char const *id, int idx);

        double sumInnerWorldsRecords();
    };
}

#endif //__CCWorld_H_
