//
//  FCAttackAction.cpp
//  LHCocosFirstGame
//
//  Created by user on 15-1-14.
//
//

#include "FCAttackAction.h"

void FCAttackAction::initFrom(json_t *jt){
    const char *msg = json_string_value(jt);
    auto r = fcsplit(msg);
    ftag = atoi(r[1].c_str());
    ttag = atoi(r[2].c_str());
}