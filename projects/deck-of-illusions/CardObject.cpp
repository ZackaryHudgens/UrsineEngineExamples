#include "CardObject.hpp"

#include "CardMovementComponent.hpp"

#include <cmrc/cmrc.hpp>

CMRC_DECLARE(ShaderLib_Deck);

using UrsineRenderer::MeshComponent;
using UrsineRenderer::MeshVertex;
using UrsineRenderer::Shader;

using DeckOfIllusions::CardMovementComponent;
using DeckOfIllusions::CardObject;

CardObject::CardObject(const CardData& aData)
  : GameObject(aData.mDescription)
  , mData(aData)
{
  // Handle invalid data due to Jokers
  if(mData.mRank == Rank::eJOKER && mData.mSuit != Suit::eJOKER)
  {
    mData.mSuit = Suit::eJOKER;
  }
  if(mData.mSuit == Suit::eJOKER && mData.mRank != Rank::eJOKER)
  {
    mData.mRank = Rank::eJOKER;
  }

  auto cardMesh = std::make_unique<MeshComponent>();
  SetupShaders(*cardMesh.get());
  SetupVertexInfo(*cardMesh.get());
  cardMesh->SetCurrentShader("cardShader");
  AddComponent(std::move(cardMesh));

  auto cardMovement = std::make_unique<CardMovementComponent>();
  AddComponent(std::move(cardMovement));
}

glm::vec2 CardObject::GetTextureCoords(const Texture& aTexture,
                                       const CardData& aData,
                                       const Corner& aCorner,
                                       bool aBack)
{
  int row, column = 0;

  if(aBack)
  {
    row = 5;
    column = 2;
  }
  else
  {
    // Suits are organized in the deck texture by row.
    switch(mData.mSuit)
    {
      case Suit::eCLUBS:
      {
        row = 1;
        break;
      }
      case Suit::eDIAMONDS:
      {
        row = 2;
        break;
      }
      case Suit::eSPADES:
      {
        row = 3;
        break;
      }
      case Suit::eHEARTS:
      {
        row = 4;
        break;
      }
      case Suit::eJOKER:
      {
        row = 5;
        break;
      }
    }

    // Each row of a suit is placed in ascending order by rank.
    switch(mData.mRank)
    {
      case Rank::eTWO:
      case Rank::eJOKER:
      {
        column = 1;
        break;
      }
      case Rank::eEIGHT:
      {
        column = 2;
        break;
      }
      case Rank::eNINE:
      {
        column = 3;
        break;
      }
      case Rank::eTEN:
      {
        column = 4;
        break;
      }
      case Rank::eJACK:
      {
        column = 5;
        break;
      }
      case Rank::eQUEEN:
      {
        column = 6;
        break;
      }
      case Rank::eKING:
      {
        column = 7;
        break;
      }
      case Rank::eACE:
      {
        column = 8;
        break;
      }
    }
  }

  // Use the row and column to determine the card's texture coordinates.
  double width = aTexture.GetWidth();
  double height = aTexture.GetHeight();
  double cardWidth = 539.0;
  double cardHeight = 766.0;
  double xCoord, yCoord = 0.0;

  switch(aCorner)
  {
    case Corner::eTOP_LEFT:
    {
      xCoord = (cardWidth * (column - 1)) / width;
      yCoord = (cardHeight * (6 - row)) / height;
      break;
    }
    case Corner::eTOP_RIGHT:
    {
      xCoord = (cardWidth * column) / width;
      yCoord = (cardHeight * (6 - row)) / height;
      break;
    }
    case Corner::eBOTTOM_LEFT:
    {
      xCoord = (cardWidth * (column - 1)) / width;
      yCoord = (cardHeight * (5 - row)) / height;
      break;
    }
    case Corner::eBOTTOM_RIGHT:
    {
      xCoord = (cardWidth * column) / width;
      yCoord = (cardHeight * (5 - row)) / height;
      break;
    }
    default:
    {
      break;
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
