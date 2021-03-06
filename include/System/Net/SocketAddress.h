/*****************************************************************************
 *	SocketAddress.h 														 *
 *																			 *
 *	System::Net::SocketAddress class definition file.						 *
 *	Copyright (c) XFX Team. All rights reserved.							 *
 *****************************************************************************/
#ifndef _SYSTEM_NET_SOCKETADDRESS_
#define _SYSTEM_NET_SOCKETADDRESS_

#include <System/Array.h>
#include <System/Object.h>
#include <System/Types.h>
#include <System/Net/Sockets/Enums.h>

using namespace System::Net::Sockets;

namespace System
{
	namespace Net
	{
		/**
		 * Stores serialized information from System::Net::EndPoint derived classes.
		 */
		class SocketAddress : public Object
		{
		private:
			Array<byte> data;

		public:
			AddressFamily_t getFamily();
			int getSize();

			SocketAddress(AddressFamily_t family);
			SocketAddress(AddressFamily_t family, int size);

			bool Equals(Object const * const obj) const;
			int GetHashCode() const;
			static const Type& GetType();
			const String ToString();

			const byte& operator[](const int index) const;
			      byte& operator[](const int index);
		};
	}
}

#endif //_SYSTEM_NET_SOCKETADDRESS_
