//
// APlayer.cpp for hey in /home/cailla_o/Work/C++/cpp_indie_studio/game
// 
// Made by Oihan Caillaud
// Login   <cailla_o@epitech.net>
// 
// Started on  Mon May 16 16:56:15 2016 Oihan Caillaud
// Last update Sun Jun  5 18:57:20 2016 turnu angelo
//

#include "APlayer.hh"

APlayer::APlayer(int x, int y, int nb, std::string name)
{
  for (std::string::iterator it = name.begin(); it != name.end(); ++it)
    {
      if (*it == ' ')
	*it = '_';
    }
  this->_x = (x * 35) + 17;
  this->_y = (y * 35) + 17;
  this->_nb = nb;
  this->_score = 0;
  this->_nbBomb = 1;
  this->_fBomb = 1;
  this->_speed = 0;
  this->_isOnBomb = false;
  this->_isAlive = true;
  this->_name = name;
}

APlayer::~APlayer()
{

}

APlayer::APlayer(APlayer const *ap)
{
  this->_x = ap->_x;
  this->_y = ap->_y;
  this->_nb = ap->_nb;
  this->_score = ap->_score;
  this->_nbBomb = ap->_nbBomb;
  this->_fBomb = ap->_fBomb;
  this->_speed = ap->_speed;
  this->_isOnBomb = ap->_isOnBomb;
  this->_isAlive = ap->_isAlive;
  this->_name = ap->_name;
}

void APlayer::updateScoreEnd(std::vector<int> &scores, std::vector<std::string> &names) const
{
  std::ofstream score("./game/.score/.score.txt");
  if (score.is_open())
    {
      while (scores.size() != 1)
	{
	  int ct = 0;
	  while (scores[ct] != *std::max_element(scores.begin(), scores.end()))
	    ct++;
	  score << names[ct] << " " << *std::max_element(scores.begin(), scores.end()) << "\n";
	  scores.erase(scores.begin() + ct);
	  names.erase(names.begin() + ct);
	}
      score.close();
    }
}

void APlayer::updateScore() const
{
  std::vector<int> scores;
  std::vector<std::string> names;
  std::ifstream score("./game/.score/.score.txt");
  std::string line;

  if (score && score.is_open() && this->_name != "IA")
    {
      while (getline(score, line))
	{
	  std::size_t pos = line.find(" ");
	  std::string scoref = line.substr(pos + 1);
	  std::string name = line.substr(0, pos);
	  int scoretmp = std::stoi(scoref);
	  scores.push_back(scoretmp);
	  names.push_back(name);
	}
      scores.push_back(this->_score);
      names.push_back(this->_name);
      score.close();
      updateScoreEnd(scores, names);
    }
  else if (!score)
    throw GameErrors("score file not found");
}

void APlayer::setScore(int const score)
{
  this->_score = score;
}

int APlayer::getNb() const
{
  return(this->_nb);
}

int APlayer::getScore() const
{
  return (this->_score);
}

void APlayer::speed()
{
  this->_speed = 3;
}

void APlayer::fBomb()
{
  this->_fBomb = this->_fBomb + 1;
}

void APlayer::notOnBomb()
{
  this->_isOnBomb = false;
}

void APlayer::nBomb()
{
  this->_nbBomb = this->_nbBomb + 1;
}

int APlayer::getX() const
{
  return (this->_x);
}

int APlayer::getY() const
{
  return (this->_y);
}

int APlayer::getForce() const
{
  return (this->_fBomb);
}

bool APlayer::getStatus() const
{
  return (this->_isAlive);
}

int APlayer::getSpeed() const
{
  return (this->_speed);
}

int APlayer::getDirection() const
{
  return (this->_direction);
}

bool APlayer::getOnBomb() const
{
  return (this->_isOnBomb);
}

void APlayer::savePlayer(std::ofstream *file)
{
  *file << this->_name << ";" << (this->_x / 35) << ";" << (this->_y / 35) << ";" << this->_nb << ";" << this->_nbBomb << ";" << this->_fBomb << ";" << this->_score << ";" << this->_speed << ";" << static_cast<int>(this->_isOnBomb) << ";" << this->_direction << ";\n";
}

void APlayer::setX(int const x)
{
  this->_x = x;
}

void APlayer::setY(int const y)
{
  this->_y = y;
}

void APlayer::setNb(int const nb)
{
  this->_nb = nb;
}

void APlayer::setForce(int const force)
{
  this->_fBomb = force;
}

void APlayer::setSpeed(int const speed)
{
  this->_speed = speed;
}

void APlayer::setDirection(int const direction)
{
  this->_direction = direction;
}

int APlayer::getNbBomb() const
{
  return (this->_nbBomb);
}

void APlayer::setOnBomb(bool const isOnBomb)
{
  this->_isOnBomb = isOnBomb;
}

void APlayer::setNbBomb(int const nbBomb)
{
  this->_nbBomb = nbBomb;
}
