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

#ifndef __seqOperation__
#define __seqOperation__

#include "export.h"
#include "ARTypes.h"
#include "ARTag.h"
#include "clonevisitor.h"
#include "guidoelement.h"
#include "operation.h"
#include "rational.h"

namespace guido 
{

/*!
\addtogroup operations
@{
*/

//______________________________________________________________________________
/*!
\brief	A visitor to print the gmn description
*/
class export seqOperation : 
	public clonevisitor,
	public operation,
	public visitor<SARClef>,
	public visitor<SAREndBar>,
	public visitor<SARKey>,
	public visitor<SARMeter>
{
    private:
		rational fCurrentDuration;
		// current key, meter and clef are maintained to be avoid useless repetitions
		Sguidotag	fCurrentKey, fCurrentMeter, fCurrentClef;
		void checkHeader(Sguidotag tag, Sguidotag& target);

	protected:
		enum state { kInFirstScore, kInSecondScore, kRemainVoice };
		state	fState;
		
		void visitStart ( SARClef& elt );
		void visitStart ( SAREndBar& elt );
		void visitStart ( SARKey& elt );
		void visitStart ( SARMeter& elt );
		void visitStart ( SARNote& elt );
		void visitStart ( SARVoice& elt );
		void visitEnd	( SARVoice& elt );

    public:
				 seqOperation() {}
		virtual ~seqOperation() {}

		SARMusic operator() ( const SARMusic& score1, const SARMusic& score2 );
};

/*! @} */

} // namespace

#endif
