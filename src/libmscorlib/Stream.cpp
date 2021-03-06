// Copyright (C) XFX Team
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
//* Redistributions of source code must retain the above copyright 
//notice, this list of conditions and the following disclaimer.
//* Redistributions in binary form must reproduce the above copyright 
//notice, this list of conditions and the following disclaimer in the 
//documentation and/or other materials provided with the distribution.
//* Neither the name of the copyright holder nor the names of any 
//contributors may be used to endorse or promote products derived from 
//this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.

#include <System/IO/Stream.h>
#include <System/IO/StreamAsyncResult.h>
#include <System/FrameworkResources.h>
#include <System/String.h>
#include <System/Type.h>

#include <xboxkrnl/xboxkrnl.h>

#include <sassert.h>

namespace System
{
	namespace IO
	{
		const Stream* Stream::Null = new Stream();
		const Type StreamTypeInfo("Stream", "System::IO::Stream", TypeCode::Object);

		Stream::Stream()
		{
			_asyncActiveCount = 1;
		}

		Stream::~Stream()
		{
		}

		bool Stream::CanTimeOut()
		{
			return false;
		}

		IAsyncResult* Stream::BeginRead(byte buffer[], int offset, int count, AsyncCallback callback, Object* state)
		{
			// TODO: implement using ReadFileEx
		}

		void Stream::Close()
		{
			Dispose(true);
		}

		void Stream::Dispose()
		{
			Close();
		}

		void Stream::EndWrite(IAsyncResult* asyncResult)
		{
			sassert(asyncResult, String::Format("asyncResult: %s", FrameworkResources::ArgumentNull_Generic));

			// TODO: implement
		}

		const Type& Stream::GetType()
		{
			return StreamTypeInfo;
		}

		int Stream::ReadByte()
		{
			byte* buffer = new byte[1];
			if (Read(buffer, 0, 1) == 0)
			{
				return -1;
			}
			return buffer[0];
		}

		void Stream::WriteByte(byte value)
		{
			byte buffer[] = { value };
			Write(buffer, 0, 1);
		}
	}
}
