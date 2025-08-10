#include <iostream>	
#include <string>
#include <vector>
#include <sstream>
#include "canvas.h"
#include "rectangle.h"
#include "shape.h"
#include "circle.h"
#include "cross.h"
void commandsShow();
std::vector<std::string> getCommands();
void doCommand(const std::vector<std::string>& v, Canvas& c, bool& quit);
void checkCommands(Canvas& c);
