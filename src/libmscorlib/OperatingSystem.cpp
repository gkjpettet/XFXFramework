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

#include <System/OperatingSystem.h>
#include <System/String.h>
#include <System/Type.h>

namespace System
{
	const Type OperatingSystemTypeInfo("OperatingSystem", "System::OperatingSystem", TypeCode::Object);

	OperatingSystem::OperatingSystem(const PlatformID_t platform, const System::Version version)
		: Platform(platform), Version(version)
	{
	}

	OperatingSystem::OperatingSystem(const System::OperatingSystem &obj)
		: Platform(obj.Platform), Version(obj.Version)
	{
	}

	OperatingSystem OperatingSystem::Clone() const
	{
		return OperatingSystem(Platform, Version);
	}

	bool OperatingSystem::Equals(const OperatingSystem other) const
	{
		return ((Platform == other.Platform) && (Version == other.Version));
	}

	int OperatingSystem::GetHashCode() const
	{
		return (int)Platform + Version.GetHashCode();
	}

	const Type& OperatingSystem::GetType()
	{
		return OperatingSystemTypeInfo;
	}

	const String OperatingSystem::ToString() const
	{
		// TODO: implement
	}

	bool OperatingSystem::operator !=(const OperatingSystem& right) const
	{
		return !Equals(right);
	}

	bool OperatingSystem::operator ==(const OperatingSystem& right) const
	{
		return Equals(right);
	}
}
