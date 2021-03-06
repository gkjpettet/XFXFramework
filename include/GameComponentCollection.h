/*****************************************************************************
 *	GameComponentCollection.h												 *
 *																			 *
 *	XFX GameComponentCollection definition file 							 *
 *	Copyright (c) XFX Team. All Rights Reserved 							 *
 *****************************************************************************/
#ifndef _XFX_GAMECOMPONENTCOLLECTION_
#define _XFX_GAMECOMPONENTCOLLECTION_

#include "Interfaces.h"
#include <System/Event.h>
#include <System/Collections/Generic/List.h>
#include <GameComponentCollectionEventArgs.h>

using namespace System;
using namespace System::Collections::Generic;

namespace XFX
{
	/**
	 * A collection of game components.
	 */
	class GameComponentCollection : public Object
	{
	private:
		List<IGameComponent*> _components;

	protected:
		void ClearItems();
		void InsertItem(const int index, IGameComponent * const item);
		void RemoveItem(const int index);
		void SetItem(const int index, IGameComponent * const item);
		
	public:
		int Count() const;

		GameComponentCollection();
		virtual ~GameComponentCollection();
		IGameComponent* operator[](const int index);

		static const Type& GetType();

		Event<Object * const, GameComponentCollectionEventArgs * const> ComponentAdded;
		Event<Object * const, GameComponentCollectionEventArgs * const> ComponentRemoved;
	};
}

#endif //_XFX_GAMECOMPONENTCOLLECTION_
