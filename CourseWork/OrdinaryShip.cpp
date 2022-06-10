#include "OrdinaryShip.h"
#include <iostream>
#include <stdexcept>

Ship::Ship(double eP, double d, std::string sN, std::string hP, int cN, std::vector<CrewMember> m) {
	enginePower = eP, displacement = d, shipName = sN, homePort = hP, crewNumber = cN, members = m;
}

bool Ship::isCaptainPresent() const {
	for (int i = 0; i < crewNumber; i++) {
		if (members[i].getRank() == CrewMemberRank::Captain) return true;
	}
}

std::string Ship::infoMember() const {
	std::string info;
	info = "\nNumber of crew members: " + std::to_string(crewNumber) + "\n";
	std::cout << std::endl;
	for (int i = 0; i < crewNumber; i++) {
		info += "\nCrew member #" + std::to_string(i + 1) + "\n" + "Fullname: " + members[i].getFullname() + "\n" + "Age: "
			+ std::to_string(members[i].getAge()) + " years." + "\n" + "Work experience: " + std::to_string(members[i].getWorkExp())
			+ " years." + "\n";
		const CrewMemberRank rank = members[i].getRank();
		switch (rank) {
		case CrewMemberRank::Captain:
			info += "Rank: Captain\n";
			break;
		case CrewMemberRank::CaptainAssistant:
			info += "Rank: Captain Assistant\n";
			break;
		case CrewMemberRank::ChiefEngineer:
			info += "Rank: Chief Engineer\n";
			break;
		case CrewMemberRank::EngineerAssistant:
			info += "Rank: Engineer Assistant\n";
			break;
		case CrewMemberRank::Sailor:
			info += "Rank: Sailor\n";
			break;
		case CrewMemberRank::Cook:
			info += "Rank: Cook\n";
			break;
		case CrewMemberRank::Doctor:
			info += "Rank: Doctor\n";
			break;
		}
	}
	return info;
}

std::string Ship::infoShip() const {
	std::string info = ("Engine power: " + std::to_string(enginePower) + " kW" + "\n" + "Displacemnt: " +
		std::to_string(displacement) + " tons" + "\n" + "Ship name: " + shipName + "\n" + "Homeport: " +
		homePort);
	return info;
}

double Ship::getEnginePower() const { return enginePower; }
double Ship::getDisplacement() const { return displacement; }
std::string Ship::getShipName() const { return shipName; }
std::string Ship::getHomePort() const { return homePort; }
int Ship::getCrewNumber() const { return crewNumber; }

void Ship::setEnginePower(double eP) { enginePower = eP; }
void Ship::setDisplacement(double d) { displacement = d; }
void Ship::setShipName(std::string sN) { shipName = sN; }
void Ship::setHomePort(std::string hP) { homePort = hP; }