#include<iostream>
using namespace std;
 
class link{
    private:
    string name;
    int age;
    float height;
    
    
    public: //to reach it in the second class
    link* pnext; //constuctor- to initialize
   	
   	//CONSTRUCTOR...
    link(string n, int a, float h){
        name = n;
        age = a;
        height = h;
        pnext=NULL;
    }
    
    //FUNCTION TO DISPLAY CONTENTS OF THE OBJECT
    void display(){
        cout<<"Name: "<<name<<"  Age: "<<age<<"  Height: "<<height<<"m"<<endl;
    }
    
    
    string retName(){
     	return name;
 	}
 
	int retAge(){
		return age;
	}
 
	float retHeight(){
		return height;
	}  
};
 
//LINKED LISTS,(HAVE MECHANISMS SIMILAR TO A STACK) 
class linkedlist{
    private:
    link*pfirst; //pointer to the first node
    
    
    public:   	
    //CONSTRUCTOR	
    linkedlist(){
    	pfirst=NULL;
    }
    
    //INSERT ELEMENTS INTO THE LIST
    void insert(string n, int a, float h){
        link* pnewlink= new link(n, a, h); //create a link
        pnewlink->pnext=pfirst; //point at next item
        pfirst=pnewlink; //make first point at the new link
    }
    
    //DISPLAY ELEMENTS OF THE LIST
    void displaylist(){
        link*pcurrent=pfirst;
        while (pcurrent!=NULL){
            pcurrent->display();
            pcurrent=pcurrent->pnext;
        }
    }
    
    //DELETE FIRST ITEM FROM THE LIST
	void delete_item(){
	  	pfirst = pfirst -> pnext;
	}
 	
 	//FIND A SPECIFIC ITEM IN THE LINKED LIST
	void find(string x){
	  link* pcurrent=pfirst;
	  
	  while (pcurrent!=NULL){
            if(pcurrent->retName() == x){
	            pcurrent->display();
	            break;
	   		}
	        pcurrent=pcurrent->pnext;
	    }            
	}
 	
 	//DELETE ELEMENTS FROM THE LINKED LIST UNDER A SPECIFIC CRITERIA
	void remove_errors(){
		link* pcurrent=pfirst;
		link* prev=pfirst;
		int num=1;
		
		while (pcurrent!=NULL){
		    if(pcurrent->retHeight() > 3 || pcurrent->retHeight() < .3){
		    	cout<<pcurrent->retName()<<"\tHeight: "<<pcurrent->retHeight()<<"m has been deleted..."<<endl;
		    	prev->pnext = pcurrent->pnext;
		   	}
		    prev=pcurrent;
		    pcurrent=pcurrent->pnext;
		}     
	}
	
	//DELETE SPECIFIC ELEMENTS FROM THE LINKED LIST 
	void delete_element(string n, int a, float h){
		link* pcurrent=pfirst;
		link* prev=pfirst;
		
		while (pcurrent!=NULL){
		    if(pcurrent->retName() == n && pcurrent->retAge() == a && pcurrent->retHeight() == h){
		    	prev->pnext = pcurrent->pnext;
		   	}
		    prev=pcurrent;
		    pcurrent=pcurrent->pnext;
		}     
	}
	 
	//FUNCTION THAT ORDERS DATA WHILE BEING INSERTED
	void orderedinsert(string n, int a, float h){
		link* pNewLink = new link(n, a, h); //make new link
		link* pPrevious = NULL; //have a pointer to the previous link
		link* pCurrent = pfirst; //start at first
		//until end of list,
		while(pCurrent != NULL && n > pCurrent->retName()){ 
		   pPrevious = pCurrent; //remember previous link
		   pCurrent = pCurrent->pnext; //go to next item
		}
	
		if(pPrevious==NULL) //if at beginning of list
			pfirst = pNewLink; //insert newLink at pFirst
		else //mid correct spot
		   pPrevious->pnext = pNewLink; //make previous point newLink
		   pNewLink->pnext = pCurrent; //make newLink point current
	} 
 	
 	//COMPUTE AVERAGE AGE FOR ITEMS IN THE LINKED LIST
	int average_age(){
		int sum = 0; 
		int counter = 0;
		link*pcurrent=pfirst;
		
		while (pcurrent!=NULL){
		    sum += pcurrent->retAge();
		    pcurrent=pcurrent->pnext;
		    counter+=1;
		}
		return sum/counter;
	}
 	
 	
 	
 	
 	//FIND DUPLICATES OF A SPECIFIC ITEM IN THE LIST
	void find_duplicates(){
		link* pcurrent=pfirst;
		link* pinner=pfirst;
		string name;
		int counter,age;
		float height;
		
		while (pcurrent!=NULL){
			name = pcurrent->retName();
			age = pcurrent->retAge();
			height = pcurrent->retHeight();
			counter=0;
			
			while(pinner!=NULL){
				if(pinner->retName() == name){
					counter+=1;
				}
				pinner=pinner->pnext;
			}
			
			pinner = pfirst;
			
			if(counter>1){
				while(pinner!=NULL){
					if(pinner->retName()==name && pinner->retAge() == age && pinner->retHeight() == height){
						pinner->display();
						break;
					}
					pinner=pinner->pnext;
				}
			}
		    pcurrent=pcurrent->pnext;
		}        
	}
	
	 	//FIND DUPLICATES AND DELETES DUPLICATES LEAVING ONLY THE FIRST INSTANCE OF THE ITEM
	void delete_duplicates(){
		link* pcurrent=pfirst;
		link* pinner=pfirst;
		string name;
		int counter,age;
		float height;
		
		while (pcurrent!=NULL){
			name = pcurrent->retName();
			age = pcurrent->retAge();
			height = pcurrent->retHeight();
			counter=0;
			
			while(pinner!=NULL){
				if(pinner->retName() == name){
					counter+=1;
					if(counter>1){
						delete_element(pinner->retName(), pinner->retAge(), pinner->retHeight());
						counter-=1;
					}	
				}
				pinner=pinner->pnext;
			}	
			pinner = pfirst;
		    pcurrent=pcurrent->pnext;
		}        
	}
	
	//list of available functions....
	
	//lINK CLASS
//	display() - displays contents of the object
//	retName()
//	retAge()
//	retHeight()


	//LINKED LIST CLASS
//	insert(n,a,h)
//	displaylist() - displayes all elements in the list
//	delete_item() - removes first item from list
//	find(n)
//	remove_errors() - removes elements that satisfy a specific criteria(s)
//	delete_element(n,a,h) - removes specific element from list
//	orderedinsert(n,a,h) - orders the insertion of elements with a specific criteria
//	average_age()
//	find_duplicates() - finds duplicate instances of an element
//	delete_duplicates() - removes all duplicates of an element leaving only the first instance of the element
};


int main(){
    linkedlist test;
    test.insert("Mike", 10, 1.5);
    test.insert("Banice", 20, 1.5);
    test.insert("Banice", 50, 1.5);
    test.insert("Banice", 50, .1);
    test.insert("Jeff", 10, 1.5);
    test.insert("Lolla", 10, 1.5);
    test.insert("Banice", 10, 1.5);
    test.insert("Tindi", 20, 1.5);
    test.insert("Tindi", 50, 1.5);
    test.insert("Tindi", 70, 1.5);
    test.insert("Jeff", 20, 1.1);
    test.insert("Jeff", 50, 1.5);
    test.insert("Jeff", 15, .2);//erroneous element
    test.insert("Jeff", 20, 1.1);
    test.insert("Jeff", 50, 6.0);//erroneous element
    test.insert("Jeff", 15, 1.4);
    
    cout<<"\n\n **QUESTION 1**\n";
    cout<<"Average age: "<<test.average_age()<<endl;//question 1
    cout<<"\n\n **QUESTION 2**\n";
    test.remove_errors();//question 2
    cout<<"\n\n **QUESTION 3**\n";
    test.find_duplicates(); //question 3
    cout<<"\n\n **QUESTION 4**\n";
    test.delete_duplicates(); //question 4
    test.displaylist();//question 4
    
}
