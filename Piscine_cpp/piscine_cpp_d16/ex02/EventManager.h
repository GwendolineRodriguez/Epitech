/*
** EventManager.h for eventmanager in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d16/ex02
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.eu>
**
** Started on  Thu Jan 21 18:00:34 2016 Gwendoline Rodriguez
** Last update Thu Jan 21 18:05:40 2016 Gwendoline Rodriguez
*/

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <iostream>
#include <string>
#include <list>
#include "Event.h"

class EventManager {
public:
    EventManager() : _currentTime(0){}
    ~EventManager() {}
    EventManager(EventManager const &copy) : _currentTime(0){
        for (std::list<Event>::const_iterator it = copy._list.begin(); it != copy._list.end(); ++it) {
            _list.push_back(*it);
        }
    }
    EventManager& operator=(EventManager const &copy) {
        if (this != &copy) {
            _currentTime = copy._currentTime;
            if (!_list.empty())
                _list.clear();
            for (std::list<Event>::const_iterator it = copy._list.begin(); it != copy._list.end(); ++it) {
                _list.push_back(*it);
            }
        }
        return *this;
    }
    void addEvent(const Event& event) {
        std::list<Event>::iterator it;
        if (event.getTime() >= _currentTime) {
            it = _list.begin();
            while (it != _list.end() && it->getTime() <= event.getTime())
                ++it;
            _list.insert(it, event);
        }
    }
    void removeEventsAt(unsigned int time) {
        std::list<Event>::iterator it;
        if (!_list.empty()) {
            it = _list.begin();
            while (it != _list.end() && it->getTime() != time)
                ++it;
            if (it != _list.end() && it->getTime() == time) {
                while (it != _list.end() && it->getTime() == time) {
                    it = _list.erase(it);
                }
            }
        }
    }
    void dumpEvents(void) const {
        for (std::list<Event>::const_iterator it = _list.begin(); it != _list.end(); ++it) {
            std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
        }
    }
    void dumpEventAt(unsigned int time) const {
        for (std::list<Event>::const_iterator it = _list.begin(); it != _list.end(); ++it) {
            if (it->getTime() == time)
                std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
        }
    }
    void addTime(unsigned int time) {
        std::list<Event>::iterator it;
        it = _list.begin();
        _currentTime += time;
        while (it != _list.end() && it->getTime() <= _currentTime) {
            std::cout << it->getEvent() << std::endl;
            it = _list.erase(it);
        }
    }
    void addEventList(std::list<Event>& list) {
        std::list<Event>::const_iterator it = list.begin();
        while (it != list.end()) {
            if (it->getTime() >= _currentTime) {
                std::list<Event>::iterator tmp = _list.begin();
                while (tmp != _list.end() && tmp->getTime() <= it->getTime())
                    ++tmp;
                _list.insert(tmp, *it);
                }
            ++it;
        }
    }
private:
    unsigned int _currentTime;
    std::list<Event> _list;
};

#endif
