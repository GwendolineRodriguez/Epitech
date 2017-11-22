
#ifndef COMMUNICATION_HPP_
#define COMMUNICATION_HPP_

#include <string>
#include <vector>
#include <istream>
#include <ostream>

// This API provides a way to communicate between Houston and the rover.
class CommunicationAPI
{
    public:

        // Create a CommunicationAPI's instance from valid input and output
        // stream or throw an exception otherwise.
        CommunicationAPI(std::istream &input, std::ostream &output);

        ~CommunicationAPI();

        // Start a mission from its name. A valid mission name is at least 1
        // character, an exception will be thrown otherwise.
        void startMission(std::string const &missionName);

        // Register the given user to this API. It will fail if the name is
        // invalid or if there is already too many users.
        void addUser(std::string const &userName);

        // Receive a message. The given user should be valid and the mission
        // started as well.
        void receiveMessage(std::string const &name, std::string &msg) const;

        // Send a message. The given user should be valid and the mission
        // started as well.
        void sendMessage(std::string const &userName,
                std::string const &message) const;

        // Check wheter the given user is registered.
        bool hasUser(std::string const &name) const;

    private:

        // The implementation required a fixed number of users. If this value is
        // overflown, an exception will be thrown.
        static const size_t MAX_USERS = 5;

    private:
        size_t _usersOffset;
        std::istream &_input;
        std::ostream &_output;
        std::string _missionName;
        std::string _users[MAX_USERS];

};

#endif // COMMUNICATION_HPP_
