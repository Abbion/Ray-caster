#include "RayCaster.h"
#include "VectorMath.h"
#include <limits>

extern const int WindowWidth;
extern const int WindowHeight;
extern const int SampleCount;

RayCaster::RayCaster(Map& v_map)
{
    p_Map = &v_map;
}

RayCaster::~RayCaster()
{

}

void RayCaster::StartCastingForPlayer(const Player& v_player)
{
    m_IntersectionsWithWalls.clear();
    m_RayLengths.clear();
    CastRays(v_player);
    CreateProperRayLengths(v_player);
}

const std::vector<sf::Vector2f>  RayCaster::getIntersectionsWithWalls() const
{
    return m_IntersectionsWithWalls;
}

const std::vector<float> RayCaster::getRayLengths() const
{
    return m_RayLengths;
}

void RayCaster::CastRays(const Player& v_player)
{
    for (int i = 0; i <= SampleCount; i++)
	{
        float RayLength = 0;
        sf::Vector2f RayStartPos = v_player.PlayerObject.getPosition();
        float MinDistance = std::numeric_limits<float>::max();

        float RayRotation = v_player.m_Pov / 2.0f;
        float RotPerCircle = v_player.m_Pov/SampleCount; 

        //Distace estimator
        while (MinDistance > 2 && RayLength < m_MaxRayLength)
        {
            MinDistance = std::numeric_limits<float>::max();
            //Check circles
            MinDistance = std::min(p_Map->m_CircleWalls.GetMinimalDistance(RayStartPos), MinDistance);
            //Check all rectangles
            MinDistance = std::min(p_Map->m_RectangleWalls.GetMinimalDistance(RayStartPos), MinDistance);
            RayLength += MinDistance;
            RayStartPos = v_player.getStartPointForRay((RayRotation - (RotPerCircle * i)), RayLength);
        }

        m_IntersectionsWithWalls.push_back(RayStartPos);
    }
}

void RayCaster::CreateProperRayLengths(const Player& v_player)
{
    for (int i = 0; i < m_IntersectionsWithWalls.size(); i++)
    {
        sf::Vector2f RayFromPlayer = SubVectors(m_IntersectionsWithWalls.at(i), v_player.PlayerObject.getPosition());

        if(GetVectorLength(RayFromPlayer) >= m_MaxRayLength)
            m_RayLengths.push_back(m_MaxRayLength);
        else
        {
            float ScreenVec = getVectorProjectionLength(ScaleVector(v_player.getLookAt(), v_player.PlayerObject.getRadius() * 1.5f), RayFromPlayer);
            m_RayLengths.push_back(getVectorProjectionLength(RayFromPlayer, v_player.getLookAt()) - ScreenVec);
        }
    }
}