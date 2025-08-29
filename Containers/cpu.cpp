#include <iostream>	
#include <string>
#include <map>
#include <utility>
#include <memory>
class RAM
{
		private:
				std::map<int , std::pair<std::string, int> > m_ram;
		public:
				RAM(){}
				RAM(const std::map<int, std::pair<std::string, int>>& m): m_ram(m){}

				std::pair<std::string, int > readFromRAM(int row) 
				{
						if(m_ram.find(row) != m_ram.end())
								return m_ram[row];
						else return {"", 0};
				};

				void writeInRAM(int row, const std::string& value1, int value2)
				{
						m_ram[row]={value1, value2};
				}
//for dbg   
				void printRam()const
				{
						for(auto& [key, value] :m_ram)
								std::cout<<key<<' '<< value.first<<' '<<value.second<<std::endl;
				}
};
class Command{
	public:
		virtual void doCommand(RAM& ram, int& ACC, int& PC, int rAddress, bool& run)=0;
		virtual ~Command(){};
};
class LDA: public Command {
	public:
		void doCommand(RAM& ram , int& ACC, int& , int rAddress, bool& /*run*/)override{
			std::pair<std::string, int> data= ram.readFromRAM(rAddress);
			ACC=data.second;
		}
};

class SUB: public Command{
	public:
		void doCommand(RAM& ram , int& ACC, int& /*PC*/ , int rAddress, bool& /*run*/)override{
			std::pair<std::string, int> data= ram.readFromRAM(rAddress);
			ACC -= data.second;
		}
};

class STA: public Command{
	public:
		void doCommand(RAM& ram , int& ACC, int& /*PC*/, int rAddress, bool& /*run*/)override{
			ram.writeInRAM(rAddress,"DAT",ACC);
		}
};
class BRZ: public Command{
	public:
		void doCommand(RAM& /*ram*/, int& ACC, int& PC, int rAddress, bool& /*run*/)override{
			if(ACC==0) PC=rAddress;
		}
};
class BRA: public Command{
	public:
		void doCommand(RAM& /*ram*/, int& /*ACC*/ , int& PC, int rAddress, bool& /*run*/)override{
			PC=rAddress;
		}
};
class HLT: public Command{
	public:
		void doCommand(RAM& /*ram*/, int& /*ACC*/, int& /*PC*/, int , bool& run)override{
			run=false;
		}
};

class Manage{
	public:
		static std::unique_ptr<Command> getCommand(const std::string& textCommand)
		{
			if(textCommand=="LDA") return std::make_unique<LDA>();
			if(textCommand=="SUB") return std::make_unique<SUB>();
			if(textCommand=="STA") return std::make_unique<STA>();
			if(textCommand=="BRZ") return std::make_unique<BRZ>();
			if(textCommand=="BRA") return std::make_unique<BRA>();
			if(textCommand=="HLT") return std::make_unique<HLT>();
			return nullptr;
		}
};
class CPU{
	public:
		CPU(RAM& x) : m_ram(x){}
		void execute(){
				while(m_run){
						int oldPC=m_PC;
						std::pair<std::string, int> IR = fetch();
						std::unique_ptr<Command> step=Manage::getCommand(IR.first);

						if(step){
								step->doCommand(m_ram ,m_ACC ,m_PC , IR.second, m_run);
						}
						else m_run=false;	

						if(oldPC==m_PC)m_PC++;
				}
		}
	private:
		int m_ACC=0;
		int m_PC=0;
		bool m_run= true;
		RAM& m_ram;

		std::pair<std::string, int> fetch()
		{
			return m_ram.readFromRAM(m_PC);
		}
};

int main()
{
	RAM ram ({
			{00, {"LDA", 80}},
			{01, {"SUB", 10}},
			{02, {"STA", 80}},
			{03, {"BRZ", 05}},
			{04, {"BRA", 00}},
			{05, {"HLT", 0 }},
			{10, {"DAT", 10}},
			{80, {"DAT", 5000}}
			});
//for dbg 
	ram.printRam();
	std::cout<<std::endl;

	CPU cpu(ram);
	cpu.execute();
//for dbg    
	ram.printRam();
	return 0;
}	
