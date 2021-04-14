#ifndef CARDOBJECT_HPP
#define CARDOBJECT_HPP

#include <UrsineEngine/GameObject.hpp>
#include <UrsineEngine/MeshComponent.hpp>

using UrsineRenderer::Texture;

namespace DeckOfIllusions
{
  enum Rank
  {
    eTWO,
    eEIGHT,
    eNINE,
    eTEN,
    eJACK,
    eQUEEN,
    eKING,
    eACE
  };

  enum Suit
  {
    eCLUBS,
    eDIAMONDS,
    eSPADES,
    eHEARTS
  };

  struct CardData
  {
    Rank mRank;
    Suit mSuit;
    std::string mDescription;
  };

  class CardObject : public UrsineCore::GameObject
  {
    public:
      CardObject(const CardData& aData);

    private:
      enum Corner
      {
        eTOP_LEFT,
        eTOP_RIGHT,
        eBOTTOM_LEFT,
        eBOTTOM_RIGHT
      };

      glm::vec2 GetTextureCoords(const Texture& aTexture,
                                 const CardData& aData,
                                 const Corner& aCorner,
                                 bool aBack = false);

      void SetupShaders(UrsineRenderer::MeshComponent& aMesh);
      void SetupVertexInfo(UrsineRenderer::MeshComponent& aMesh);

      CardData mData;
  };
}

#endif
