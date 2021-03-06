/*****************************************************************************
 *	Keyboard.h  															 *
 *																			 *
 *	XFX::Input::Keyboard class definition file. 							 *
 *	Copyright (c) XFX Team. All Rights Reserved.							 *
 *****************************************************************************/
#ifndef _XFX_INPUT_KEYBOARD_
#define _XFX_INPUT_KEYBOARD_

#include "Enums.h"

namespace XFX
{
	namespace Input
	{
		/**
		 * Represents a state of keystrokes recorded by a keyboard input device.
		 */
		struct KeyboardState
		{
			KeyboardState();
			KeyboardState(Keys_t keys[]);
			KeyboardState(const KeyboardState &obj);
				
			Keys_t* GetPressedKeys();
			bool IsKeyDown(Keys_t key);
			bool IsKeyUp(Keys_t key);

			/**
			 * Returns the state of a particular key.
			 *
			 * @param key
			 * Enumerated value representing the key to query.
			 */
			const KeyState_t operator[](const Keys_t key) const;

		private:
			Keys_t* pressedKeys;
		};

		/**
		 * Allows retrieval of keystrokes from a keyboard input device.
		 */
		class Keyboard
		{
		private:
			Keyboard(); //Private constructor to prevent instantiation.

		public:
			static KeyboardState GetState();
		};
	}
}

#endif //_XFX_INPUT_KEYBOARD_
