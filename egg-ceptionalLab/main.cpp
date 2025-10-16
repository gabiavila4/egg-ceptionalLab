//
//  main.cpp
//  egg-ceptionalLab
//
//  Created by Gabriela Avila on 10/14/25.
//

#include <iostream>
#include <vector>
using namespace std;


class bad_egg : public exception{
public:
    virtual const char* what() const throw() {
        return "You shouldn't eat a bad egg!";
    }
}be;

class Egg{
    
protected:
    int size;
    string flavor;
public:
    Egg(){
    }
    Egg(int s, string f){
        size = s;
        flavor = f;
    }
    virtual int getSize() = 0;
    virtual string getFlavor() = 0;
    virtual void eat_egg() = 0;
    
};

class RottenEgg : public Egg{
    
protected:
public:
    
    RottenEgg(int s, string f){
        size = s;
        flavor = f;
    }
    int getSize(){
        return size;
    }
    string getFlavor(){
        return flavor;
    }
    void eat_egg(){
        cout << "When eggs decompose, proteins in both the white and yolk break down. The albumin (the clear part) loses its gel-like structure and turns thin and watery, sometimes slimy as bacterial colonies grow. The yolk membrane weakens and can rupture easily, mixing with the liquid white. Chemical reactions with sulfur and iron compounds can make the yolk gritty or pasty rather than smooth. These are all strong signs of spoilage and decomposition. anyway.... \n";
        throw be;
        
    }
    
};

class PoachedEgg : public Egg{
    
protected:
public:
    
    PoachedEgg(int s, string f){
        size = s;
        flavor = f;
    }
    int getSize(){
        return size;
    }
    string getFlavor(){
        return flavor;
    }
    void eat_egg(){
        cout << "Airy and Soft" << endl;
    }
    
};

class DeviledEgg : public Egg{
    
protected:
public:
    
    DeviledEgg(int s, string f){
        size = s;
        flavor = f;
    }
    int getSize(){
        return size;
    }
    string getFlavor(){
        return flavor;
    }
    void eat_egg(){
        cout << "Smooth and Rich" << endl;
    }
    
};

class Carton{
    
protected:
    vector<Egg*> eggs;
public:
    Carton(){
        
    }
    
   void add_egg(Egg& e){
        if (eggs.size() < 12)
        {
            eggs.push_back(&e);
        }else
        {
            cout << "Carton is full!";
        }
    }
    
    void eat_egg(){
        if (eggs.size() == 0)
        {
            cout << "Carton is empty!" << endl;
        }else {
            
            try{
                eggs[eggs.size() -1]->eat_egg();
                
            }catch(bad_egg& be){
                cout << be.what() << endl;
            }
            eggs.pop_back();
        }
        
    }
    
};





int main() {
    Carton carton;
    RottenEgg r1 = RottenEgg(2, "Nastyy");
    PoachedEgg p1 = PoachedEgg(3, "Yummy");
    DeviledEgg d1 = DeviledEgg(4, "Savory");
    
    carton.add_egg(r1);
    carton.add_egg(p1);
    carton.add_egg(d1);
    
    carton.eat_egg();
    carton.eat_egg();
    carton.eat_egg();
    carton.eat_egg();
    
    
    
}
