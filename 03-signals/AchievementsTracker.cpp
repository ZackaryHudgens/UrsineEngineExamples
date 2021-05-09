#include "AchievementsTracker.hpp"

#include <iostream>

#include "PlayerSignals.hpp"

using example_three::AchievementsTracker;

AchievementsTracker::AchievementsTracker()
  : UrsineCore::Observer()
{
  /**
   * Connect to the QPressed signal. By doing this, whenever the signal
   * is notified, this lambda function will be called.
   */
  QPressed.Connect(*this, [this](PlayerObject* aPlayer)
  {
    /**
     * If the player hasn't pressed Q yet, give them a new entry in the map.
     * If they have, update their Q count. If their Q count is 5, award them
     * the Q Count achievement.
     */
    auto player = mQPressMap.find(aPlayer->GetName());
    if(player == mQPressMap.end())
    {
      mQPressMap.emplace(aPlayer->GetName(), 1);
    }
    else
    {
      player->second++;
      if(player->second == 5)
      {
        AwardAchievement(aPlayer->GetName() +
                         " has pressed the Q key 5 times!");
      }
    }
  });
}

void AchievementsTracker::AwardAchievement(const std::string& aMessage)
{
  std::cout << aMessage << std::endl;
}
