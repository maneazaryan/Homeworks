#include "getcommands.h"
void commandsShow()
{
	std::cout<<"===Shape Drawer==="<<std::endl;
	std::cout<<"Available commands ։ "<<std::endl;
	std::cout<<"	add rectangle x y width height"<<std::endl;
	std::cout<<"	add circle x y radius"<<std::endl;
	std::cout<<"	add cross x y size"<<std::endl;
	std::cout<<"	show"<<std::endl;
	std::cout<<"type ctrl+C to quit."<<std::endl;
}
std::vector<std::string> getCommands()
{
	std::string line;
	std::cout<<" <  : ";
	getline(std::cin,line);
	
	std::vector<std::string> commandsLine;
	std::string word;
	std::stringstream ss(line);
	
	while(ss>>word){
		commandsLine.push_back(word);
	}

	return commandsLine;
}
void doCommand(const std::vector<std::string>& v, Canvas& c, bool& quit){
	if(v[0]=="add")
	{
		if(v[1]=="rectangle" && v.size()==6)
		{
			int x=std::stoi(v[2]);	
			int y=std::stoi(v[3]);
			int w=std::stoi(v[4]);
			int h=std::stoi(v[5]);
			Shape* shape =new Rectangle(x,y,w,h);
			c.AddShape(shape);
		}
		else if(v[1]=="circle" && v.size()==5)
		{
			int x=std::stoi(v[2]);
			int y=std::stoi(v[3]);
			int r=std::stoi(v[4]);
			Shape* shape =new Circle(x,y,r);
			c.AddShape(shape);
		}
		else if(v[1]=="cross" && v.size()==5)
		{
			int x=std::stoi(v[2]);
			int y=std::stoi(v[3]);
			int s=std::stoi(v[4]);
			Shape* shape =new Cross(x,y,s);
			c.AddShape(shape);
		}
		else 
		{
			std::cout<<"Error: wrong command"<<std::endl;
			return;
		} 
	}
	else if(v[0]=="show")
	{
		c.Draw();
	}
	else if(v[0]=="ctrl+C")
	{
		quit=false;
	}
	else
	{
		std::cout<<"error: wrong command"<< std::endl;
		return;
	}
}
void checkCommands(Canvas& c){
	commandsShow();
	bool quit=true;
	while (quit){
		std::vector<std::string> v= getCommands();
		doCommand(v,c,quit);
	}
}
