/*

  MusicXML Library
  Copyright (C) 2006,2007  Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#include <iostream>

#include "ARChord.h"
#include "ARNote.h"
#include "counteventsvisitor.h"
#include "tree_browser.h"

using namespace std;

namespace guido 
{

//______________________________________________________________________________
int counteventsvisitor::count(const Sguidoelement& elt)
{
	fInChord = false;
	fCount = 0;
	if (elt) {
		tree_browser<guidoelement> tb(this);
		tb.browse (*elt);
	}
	return fCount;
}

void counteventsvisitor::visitStart(SARNote& elt)	{ if (!fInChord) fCount++; }
void counteventsvisitor::visitStart(SARChord& elt)	{ fInChord = true; }
void counteventsvisitor::visitEnd  (SARChord& elt)	{ fInChord = false; fCount++; }


//______________________________________________________________________________
std::vector<int> countvoiceseventsvisitor::count(const Sguidoelement& elt)
{
	fVoicesCount.clear();
	counteventsvisitor::count(elt);
	return fVoicesCount;
}

void countvoiceseventsvisitor::visitStart(SARVoice& elt)	{ fCount = 0; }
void countvoiceseventsvisitor::visitEnd  (SARVoice& elt)	{ fVoicesCount.push_back(fCount); }


}