/*
 * Inline.cpp
 *
 *  Created on: 24.04.2014
 *      Author: baudenri
 */




#include <World/Inline.h>
#include <Parser/X3DFileManager.h>
#include <Parser/X3DFile.h>
#include <World/Scene.h>

#include <World/Background.h>
#include <World/NavigationInfo.h>
#include <World/Viewpoint.h>
#include <World/WorldInfo.h>
#include <World/Transform.h>


using namespace X3D;

Ogre::NameGenerator Inline::_nameGenerator("Inline_");

void Inline::url(const std::string& url) {
	_url = url;
}

void Inline::load(const bool& load) {
	_load = load;
}

const std::string Inline::nameSpace() {
	if(_nameSpace.empty()) {
		_nameSpace = _nameGenerator.generate();
	}
	return _nameSpace;
}

void Inline::initialise(World& world) {
    if (_load) {
        _scene.reset(new Scene);
        _scene->attachTo(_groupParent);
        X3DFileManager::getSingleton().load(_url, "X3D", _scene, _nameSpace);
        _scene->initialise(world);
    }
}

const std::string& Inline::url() const {
	return _url;
}