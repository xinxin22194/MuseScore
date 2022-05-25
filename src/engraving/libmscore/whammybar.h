/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __WHAMMYBAR_H__
#define __WHAMMYBAR_H__

#include "textlinebase.h"

namespace Ms {
class WhammyBar;

//---------------------------------------------------------
//   @@ WhammyBarSegment
//---------------------------------------------------------

class WhammyBarSegment final : public TextLineBaseSegment
{
public:
    WhammyBarSegment(WhammyBar* sp, System* parent);

    WhammyBarSegment* clone() const override { return new WhammyBarSegment(*this); }

    WhammyBar* whammyBar() const { return (WhammyBar*)spanner(); }

    void layout() override;

    friend class WhammyBar;
};

//---------------------------------------------------------
//   @@ WhammyBar
//---------------------------------------------------------

class WhammyBar final : public TextLineBase
{
protected:
    mu::PointF linePos(Grip, System**) const override;

public:
    WhammyBar(EngravingItem* parent);

    WhammyBar* clone() const override { return new WhammyBar(*this); }

    void read(XmlReader&) override;
    LineSegment* createLineSegment(System* parent) override;

    mu::engraving::PropertyValue propertyDefault(Pid propertyId) const override;
    Sid getPropertyStyle(Pid) const override;
};
}     // namespace Ms
#endif