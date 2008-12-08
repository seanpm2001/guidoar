/*
  GUIDO Library
  Copyright (C) 2006  Grame

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

#include "guidovalue.h"
//#include "guidoValPrinter.h"
#include "tree_browser.h"
#include "visitor.h"

using namespace std;
using namespace guido;

namespace guidolang 
{

//______________________________________________________________________________
// guidovalue
//______________________________________________________________________________
void guidovalue::acceptIn(basevisitor& v) {
	if (visitor<Sguidovalue>* p = dynamic_cast<visitor<Sguidovalue>*>(&v)) {
		Sguidovalue ge = this;
		p->visitStart (ge);
	}
}

//______________________________________________________________________________
void guidovalue::acceptOut(basevisitor& v) {
	if (visitor<Sguidovalue>* p = dynamic_cast<visitor<Sguidovalue>*>(&v)) {
		Sguidovalue ge = this;
		p->visitEnd (ge);
	}
}

//______________________________________________________________________________
void guidovalue::print(ostream& os) 
{
	os << "guidovalue";
}

//______________________________________________________________________________
ostream& operator << (ostream& os, const Sguidovalue& elt) {
	elt->print(os);
	return os;
}

} // namespace
