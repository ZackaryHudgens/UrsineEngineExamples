#include "CardObject.hpp"

#include <cmrc/cmrc.hpp>

CMRC_DECLARE(ShaderLib_Deck);

using UrsineRenderer::MeshComponent;
using UrsineRenderer::MeshVertex;
using UrsineRenderer::Shader;

using DeckOfIllusions::CardObject;

CardObject::CardObject(const CardData& aData)
  : GameObject()
  , mData(aData)
{
  auto cardMesh = std::make_unique<MeshComponent>();

  SetupShaders(*cardMesh.get());
  SetupVertexInfo(*cardMesh.get());

  cardMesh->SetCurrentShader("cardShader");

  AddComponent(std::move(cardMesh));
}

glm::vec2 CardObject::GetTextureCoords(const Texture& aTexture,
                                       const CardData& aData,
                                       const Corner& aCorner,
                                       bool aBack)
{
  int row, column = 0;
  int cardWidth = 539;
  int cardHeight = 766;

  double xCoord, yCoord = 0.0;

  // TODO: fix the deck texture so this makes sense
  if(!aBack)
  {
    switch(aCorner)
    {
      case Corner::eTOP_LEFT:
      {
        xCoord = 0.0;
        yCoord = 766.0 / 5362.0;
        break;
      }
      case Corner::eTOP_RIGHT:
      {
        xCoord = 539.0 / 2695.0;
        yCoord = 766.0 / 5362.0;
        break;
      }
      case Corner::eBOTTOM_LEFT:
      {
        xCoord = 0.0;
        yCoord = 0.0;
        break;
      }
      case Corner::eBOTTOM_RIGHT:
      {
        xCoord = 539.0 / 2695.0;
        yCoord = 0.0;
        break;
      }
      default:
      {
        break;
      }
    }
  }
  else
  {
    switch(aCorner)
    {
      case Corner::eTOP_LEFT:
      {
        xCoord = 1617.0 / 2695.0;
        yCoord = 766.0 / 5362.0;
        break;
      }
      case Corner::eTOP_RIGHT:
      {
        xCoord = 2156.0 / 2695.0;
        yCoord = 766.0 / 5362.0;
        break;
      }
      case Corner::eBOTTOM_LEFT:
      {
        xCoord = 1617.0 / 2695.0;
        yCoord = 0.0;
        break;
      }
      case Corner::eBOTTOM_RIGHT:
      {
        xCoord = 2156.0 / 2695.0;
        yCoord = 0.0;
        break;
      }
      default:
      {
        break;
      }
    }
  }

  return glm::vec2(xCoord, yCoord);
}

void CardObject::SetupShaders(MeshComponent& aMesh)
{
  auto fs = cmrc::ShaderLib_Deck::get_filesystem();
  auto vertexFile = fs.open("resources/shaders/CardShader.vert");
  auto fragmentFile = fs.open("resources/shaders/CardShader.frag");

  Shader cardShader(vertexFile.begin(), fragmentFile.begin());
  cardShader.SetInt("texSampler", 0);
  aMesh.AddShader("cardShader", cardShader);
}

void CardObject::SetupVertexInfo(MeshComponent& aMesh)
{
  // Create the 3D vertices for thix card.
  MeshVertex vertex;

  // Add the deck texture to this card.
  Texture deck;
  deck.LoadImageFromFile("resources/textures/deck.png");
  aMesh.AddTexture(deck);

  // Determine the NDC for a single card.
  double magnitude = sqrt((pow(539, 2) + pow(766, 2)));
  double xVal = 539.0 / magnitude;
  double yVal = 766.0 / magnitude;

  // Front side
  vertex.mPosition = glm::vec3(-xVal, -yVal, 0.0);
  vertex.mColor = glm::vec3(1.0, 0.0, 0.0);
  vertex.mTexCoords = GetTextureCoords(deck, mData, Corner::eBOTTOM_LEFT);
  aMesh.AddVertex(vertex);
  vertex.mPosition = glm::vec3(xVal, -yVal, 0.0);
  vertex.mColor = glm::vec3(0.0, 1.0, 0.0);
  vertex.mTexCoords = GetTextureCoords(deck, mData, Corner::eBOTTOM_RIGHT);
  aMesh.AddVertex(vertex);
  vertex.mPosition = glm::vec3(xVal, yVal, 0.0);
  vertex.mColor = glm::vec3(0.0, 0.0, 1.0);
  vertex.mTexCoords = GetTextureCoords(deck, mData, Corner::eTOP_RIGHT);
  aMesh.AddVertex(vertex);
  vertex.mPosition = glm::vec3(-xVal, yVal, 0.0);
  vertex.mColor = glm::vec3(1.0, 0.0, 0.0);
  vertex.mTexCoords = GetTextureCoords(deck, mData, Corner::eTOP_LEFT);
  aMesh.AddVertex(vertex);

  // Back side
  vertex.mPosition = glm::vec3(-xVal, -yVal, -0.01);
  vertex.mColor = glm::vec3(0.0, 1.0, 0.0);
  vertex.mTexCoords = GetTextureCoords(deck, mData, Corner::eBOTTOM_LEFT, true);
  aMesh.AddVertex(vertex);
  vertex.mPosition = glm::vec3(xVal, -yVal, -0.01);
  vertex.mColor = glm::vec3(0.0, 0.0, 1.0);
  vertex.mTexCoords = GetTextureCoords(deck, mData, Corner::eBOTTOM_RIGHT, true);
  aMesh.AddVertex(vertex);
  vertex.mPosition = glm::vec3(xVal, yVal, -0.01);
  vertex.mColor = glm::vec3(1.0, 0.0, 0.0);
  vertex.mTexCoords = GetTextureCoords(deck, mData, Corner::eTOP_RIGHT, true);
  aMesh.AddVertex(vertex);
  vertex.mPosition = glm::vec3(-xVal, yVal, -0.01);
  vertex.mColor = glm::vec3(0.0, 1.0, 0.0);
  vertex.mTexCoords = GetTextureCoords(deck, mData, Corner::eTOP_LEFT, true);
  aMesh.AddVertex(vertex);

  // Specify the order in which to draw these vertices.
  // Front side
  aMesh.AddIndex(0);
  aMesh.AddIndex(1);
  aMesh.AddIndex(2);
  aMesh.AddIndex(2);
  aMesh.AddIndex(3);
  aMesh.AddIndex(0);

  // Right side
  aMesh.AddIndex(1);
  aMesh.AddIndex(5);
  aMesh.AddIndex(6);
  aMesh.AddIndex(6);
  aMesh.AddIndex(2);
  aMesh.AddIndex(1);

  // Back side
  aMesh.AddIndex(7);
  aMesh.AddIndex(6);
  aMesh.AddIndex(5);
  aMesh.AddIndex(5);
  aMesh.AddIndex(4);
  aMesh.AddIndex(7);

  // Left side
  aMesh.AddIndex(4);
  aMesh.AddIndex(0);
  aMesh.AddIndex(3);
  aMesh.AddIndex(3);
  aMesh.AddIndex(7);
  aMesh.AddIndex(4);

  // Bottom
  aMesh.AddIndex(4);
  aMesh.AddIndex(5);
  aMesh.AddIndex(1);
  aMesh.AddIndex(1);
  aMesh.AddIndex(0);
  aMesh.AddIndex(4);

  // Top
  aMesh.AddIndex(3);
  aMesh.AddIndex(2);
  aMesh.AddIndex(6);
  aMesh.AddIndex(6);
  aMesh.AddIndex(7);
  aMesh.AddIndex(3);
}
