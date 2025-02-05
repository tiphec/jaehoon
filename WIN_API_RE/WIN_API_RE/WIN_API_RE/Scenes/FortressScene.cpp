#include "framework.h"
#include "FortressScene.h"

#include "Contents/GameObject/cannon.h"

FortressScene::FortressScene()
{
	_cannon1 = make_shared<Cannon>();

}