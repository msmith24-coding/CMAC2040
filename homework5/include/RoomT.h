#pragma once

#include <string>
#include <vector>
#include "EncounterT.h"
#include <map>


class ActionT {
   public:
       ActionT(std::string newName="Exit", EncounterT * enc = nullptr );

       ~ActionT();

       ActionT(const ActionT & other);
       ActionT & operator =(ActionT & other) = delete;
       ActionT & operator =(ActionT && other) = delete;
       ActionT(ActionT && other) = delete;

       std::string GetName() const;
       void SetEncounter(EncounterT * enc);
       EncounterT * GetEncounter() const;
   private:
       std::string name;
       EncounterT * encounter;
};


class RoomT {
   public:
      RoomT();
      RoomT(const RoomT & ) = default;
      RoomT & operator =(const RoomT & ) = delete;

      RoomT(RoomT && ) = delete;
      RoomT & operator =(RoomT && ) = delete;

      ~RoomT() = default;

      void AddEncounter(std::string eName, EncounterT * enc);
      const std::vector<std::string> GetEncounterNames() const;
      bool DoEncounter(std::string ename, PlayerT & player);
   private:
      std::vector<std::string> encounterTypes;
      std::vector<ActionT> encounters;
};

using BoardT = std::vector<RoomT>;