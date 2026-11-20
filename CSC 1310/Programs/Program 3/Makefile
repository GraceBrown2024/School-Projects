
#WIPPPPPPPPPPPPPPPPPPPPPPPPPPPP
#COMPILATION FOR FOOD TRACKER 1310
#in your terminal, you will type "make" then "make run"
#Windows: Ensure MinGW is installed before compilation ... You will have to rename the command!
#MacOS: Ensure Make is installed before compilation ... Use Homebrew to install and update!


all:		Tracker

Tracker:	Driver.cpp
			g++ -Wall -o tracker Driver.cpp food.cpp calculations.cpp UserInfo.cpp

run:		tracker
			./tracker

clean:		tracker
			rm -f ./tracker