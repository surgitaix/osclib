/*
 * DPWSClient.cpp
 *
 *  Created on: 11.12.2015
 *      Author: matthias
 */

#include <algorithm>

#include "NormalizedMessageModel.hxx"
#include "wsdd-discovery-1.1-schema-os.hxx"

#include "OSELib/DPWS/DPWSClient.h"
#include "OSELib/DPWS/DPWSCommon.h"
#include "OSELib/DPWS/DPWSDiscoveryClientSocketImpl.h"
#include "OSELib/DPWS/MessageAdapter.h"

namespace OSELib {
namespace DPWS {

DPWSClient::DPWSClient() :
	_impl(new Impl::DPWSDiscoveryClientSocketImpl(*this, *this, *this, *this))
{
}

DPWSClient::~DPWSClient() = default;

void DPWSClient::addProbeMatchEventHandler(const ProbeType & filter, ProbeMatchCallback & callback) {
	std::lock_guard<std::mutex> lock(_mutex);
	_probeMatchHandlers.push_back(ProbeMatchHandler(filter, &callback));
	_impl->sendProbe(filter);
}

void DPWSClient::removeProbeMatchEventHandler(ProbeMatchCallback & callback) {
	std::lock_guard<std::mutex> lock(_mutex);
	auto iterator = std::find_if(_probeMatchHandlers.begin(), _probeMatchHandlers.end(), [&](const ProbeMatchHandler & handler) { return std::get<1>(handler) == &callback; } );
	if (iterator != _probeMatchHandlers.end()) {
		_probeMatchHandlers.erase(iterator);
	}
}

void DPWSClient::addResolveMatchEventHandler(const ResolveType & filter, ResolveMatchCallback & callback) {
	std::lock_guard<std::mutex> lock(_mutex);
	_resolveMatchHandlers.push_back(ResolveMatchHandler(filter, &callback));
	_impl->sendResolve(filter);
}

void DPWSClient::removeResolveMatchEventHandler(ResolveMatchCallback & callback) {
	std::lock_guard<std::mutex> lock(_mutex);
	auto iterator = std::find_if(_resolveMatchHandlers.begin(), _resolveMatchHandlers.end(), [&](const ResolveMatchHandler & handler) { return std::get<1>(handler) == &callback; } );
	if (iterator != _resolveMatchHandlers.end()) {
		_resolveMatchHandlers.erase(iterator);
	}
}

void DPWSClient::addHelloEventHandler(HelloCallback & callback) {
	std::lock_guard<std::mutex> lock(_mutex);
	_helloHandlers.push_back(&callback);
}

void DPWSClient::removeHelloEventHandler(HelloCallback & callback) {
	std::lock_guard<std::mutex> lock(_mutex);
	auto iterator = std::find(_helloHandlers.begin(), _helloHandlers.end(), &callback);
	if (iterator != _helloHandlers.end()) {
		_helloHandlers.erase(iterator);
	}
}

void DPWSClient::addByeEventHandler(ByeCallback & callback) {
	std::lock_guard<std::mutex> lock(_mutex);
	_byeHandlers.push_back(&callback);
}

void DPWSClient::removeByeEventHandler(ByeCallback & callback) {
	std::lock_guard<std::mutex> lock(_mutex);
	auto iterator = std::find(_byeHandlers.begin(), _byeHandlers.end(), &callback);
	if (iterator != _byeHandlers.end()) {
		_byeHandlers.erase(iterator);
	}
}

void DPWSClient::dispatch(const ProbeMatchType & notification) {
	std::lock_guard<std::mutex> lock(_mutex);
	std::vector<ProbeMatchHandler> matchingHandlers;
	for (const auto & handler : _probeMatchHandlers) {
		if (Impl::compare(std::get<0>(handler), notification)) {
			matchingHandlers.push_back(handler);
		}
	};
	for (const auto & handler : matchingHandlers) {
		std::get<1>(handler)->probeMatch(notification);
	}
}

void DPWSClient::dispatch(const ResolveMatchType & notification) {
	std::lock_guard<std::mutex> lock(_mutex);
	std::vector<ResolveMatchHandler> matchingHandlers;
	for (const auto & handler : _resolveMatchHandlers) {
		if (Impl::compare(std::get<0>(handler), notification)) {
			matchingHandlers.push_back(handler);
		}
	};
	for (const auto & handler : matchingHandlers) {
		std::get<1>(handler)->resolveMatch(notification);
	}
}

void DPWSClient::dispatch(const ByeType & notification) {
	std::lock_guard<std::mutex> lock(_mutex);
	for (auto & callback : _byeHandlers) {
		callback->bye(notification);
	}
}

void DPWSClient::dispatch(const HelloType & notification) {
	std::lock_guard<std::mutex> lock(_mutex);
	for (auto & callback : _helloHandlers) {
		callback->hello(notification);
	}
}

} /* namespace DPWS */
} /* namespace OSELib */
