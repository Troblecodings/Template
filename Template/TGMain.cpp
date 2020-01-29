#include "TGMain.h"
#include <TGEngine.hpp>
#include <gamecontent/PlayerController.hpp>
#include <gamecontent/Actor.hpp>
#include <pipeline/buffer/Texturebuffer.hpp>

using namespace tge::gmc;
using namespace tge::tex;

int main() {
	initEngine();

	playercontroller = [](Input* in){};

	TextureInputInfo texture;
	texture.data = new uint8_t[4]{ 1, 1, 1, 1};
	texture.x = 1;
	texture.y = 1;
	texture.comp = 1;

	Texture tex;
	TextureBindingInfo bindinginfo[2048];
	createTextures(&texture, 1, &tex, bindinginfo);
	bindTextures(bindinginfo, 1, 0);

	createdMaterials = new Material[1];
	createdMaterials[0].color = { 1, 0, 0, 1};
	createdMaterials[0].diffuseTexture = 0;

	ActorInputInfo actor;
	actor.pProperties.localTransform = {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};
	actor.pProperties.material = 0;
	actor.pProperties.layer = 0;
	actor.indexCount = 3;
	actor.pIndices = new uint32_t[3]{ 1, 2, 3};
	actor.vertexCount = 3;
	actor.pVertices = (uint8_t*)new glm::vec4[3]{ { 0, 0, 0, 0}, { 0, 1, 0, 1}, { 1, 1, 1, 1} };
	createActor(&actor, 1);

	startTGEngine();
	return 0;
}