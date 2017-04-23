//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <ValueObjects/Position2d.h>
#include "MineJob.h"


void MineJob::doJob() {

}

void MineJob::removeWorker() {

}

MineJob::MineJob(const Ember::Position2d &m_position) : JobInterface(m_position) {}
