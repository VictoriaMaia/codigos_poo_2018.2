#ifndef IMAGES
#define IMAGES

#include <iostream>
#include <sstream>
using namespace std;

string printInit(){
    stringstream img;
    img << "          ______          " << endl 
        << "      ___|      |___      " << endl
        << "    _|    _         |_    " << endl
        << "   |    _| |          |   " << endl
        << "  _|   |  _|          |_  " << endl
        << " |     |_|              | " << endl
        << " |                      | " << endl
        << " |_                    _| " << endl
        << "   |                  |   " << endl
        << "   |_                _|   " << endl
        << "     |_            _|     " << endl
        << "       |__________|       " << endl;
    return img.str();
}

string printShowDeBoas(){
    stringstream img; 
    img << "      _________      " << endl     
        << "    _|         |_    " << endl    
        << "  _|   _     _   |_  " << endl    
        << " |    | |   | |    | " << endl
        << " |                 | " << endl
        << " |_               _| " << endl
        << "   |_____________|   " << endl;
    return img.str();
}


string printShowCansado(){
    stringstream img;
    img << "      _________      " << endl     
        << "    _|         |_    " << endl    
        << "  _|             |_  " << endl    
        << " |    |_|  |_|     | " << endl
        << " |                 | " << endl
        << " |_     ____      _| " << endl
        << "   |_____________|   " << endl;

    return img.str();
}

string printShowFaminto(){
    stringstream img;
    img << "      _________      " << endl     
        << "    _|         |_    " << endl    
        << "  _|             |_  " << endl    
        << " |    ==   ==      | " << endl 
        << " |           °     | " << endl 
        << " |_   _______ °   _| " << endl 
        << "   |_____________|   " << endl; 

    return img.str();
}

string printShowSujo(){
    stringstream img;
    img << "      _________      " << endl     
        << "    _|#    ##  |_    " << endl    
        << "  _|##      ###  |_  " << endl    
        << " |#   ==   ==   #  | " << endl
        << " | ##            # | " << endl
        << " |### _______    ##| " << endl
        << "   |#___________#|   " << endl;   

    return img.str();
}

string printShowSujoFaminto(){
    stringstream img;
    img << "      _________      " << endl     
        << "    _|#    ##  |_    " << endl    
        << "  _|##      ###  |_  " << endl    
        << " |#   ==   ==   #  | " << endl
        << " | ##        °   # | " << endl
        << " |### _______ °  ##| " << endl
        << "   |#___________#|   " << endl;   

    return img.str();
}

string printPlay(){
    stringstream img;
    img << "      _________      " << endl      
        << "    _|         |_    " << endl    
        << "  _|   _     _   |_  " << endl    
        << " |    | |   | |    | " << endl 
        << " |     _______     | " << endl 
        << " |    |       |    | " << endl 
        << " |_   ＼______/   _| " << endl  
        << "   |_____________|   " << endl;

    return img.str();
}

string printEat(){
    stringstream img;
    
    img << "                             ________       "<<endl
        << "                           _|        |_     "<<endl
        << "              ___        _|  _     _   |_   "<<endl
        << "            _| __|      |   | |   | |    |  "<<endl
        << "          _|  _|        |       _        |  "<<endl
        << "         |  _|          |_     |_|      _|  "<<endl
        << "  _______| |______        |____________|    "<<endl
        << " |_            _|                           "<<endl
        << "  |            |                            "<<endl
        << "  |            |                            "<<endl
        << "  |############|                            "<<endl
        << "    |########|                              "<<endl
        << "    |########|                              "<<endl
        << "    |########|                              "<<endl;

    return img.str();
}

string printSleep(){
    stringstream img;
    img << "                       _____   " << endl               
        << "                      |___  /  " << endl           
        << "      ________           / /   " << endl                  
        << "    _|        |_        / /__  " << endl             
        << "  _|            |_     /_____| " << endl           
        << " |   __     __    |            " << endl      
        << " |                |            " << endl            
        << " |_              _|            " << endl          
        << "   |____________|              " << endl;
    
    return img.str();
}

string printClean(){
    stringstream img;
    img << "          _________________    " << endl               
        << "         |    _____________|   " << endl            
        << "        /    ＼                " << endl    
        << "       /______＼               " << endl       
        << "        ´ ' ' `                " << endl       
        << "       ´  ' '  `               " << endl            
        << "      ´   ' '   `              " << endl          
        << "      _________                " << endl              
        << "    _|         |_              " << endl             
        << "  _|   _     _   |_            " << endl              
        << " |    | |   | |    |           " << endl              
        << " |                 |           " << endl             
        << " |_   ＼______/   _|           " << endl             
        << "   |_____________|             " << endl;
    
    return img.str();
}

string printDied(){
    stringstream img;
            
    img << "          _          " << endl    
        << "         | |         " << endl     
        << "     ____| |____     " << endl         
        << "    |____   ____|    " << endl       
        << "         | |         " << endl         
        << "         | |         " << endl         
        << "      ___|_|___      " << endl           
        << "    _|         |_    " << endl         
        << "  _|             |_  " << endl            
        << " |_________________| " << endl;
    
    return img.str();
}

#endif