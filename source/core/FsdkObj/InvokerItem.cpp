// Copyright (c) 2020 FengSheng.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//    http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <FsdkObj/inner/InvokerItem.h>

using namespace FsdkObj;

InvokerItem::InvokerItem(
	const char* _name, IInvoker* _invoker) : m_name(_name), m_invoker(_invoker)
{

}

MetaType InvokerItem::type() const
{
	return InvokerMeta;
}

const std::string& InvokerItem::name() const
{
	return m_name;
}

IInvoker* InvokerItem::invoker() const
{
	return m_invoker;
}