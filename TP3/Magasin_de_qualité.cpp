#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MINIMUMLEVEL = 0;
const int MAXIMUMLEVEL = 20;
const int WORKINGDAYS = 6;
class Item {
private:
    string mName;
    int mExpiresIn;
    int mQuality;

public:
    Item(string name, int expiresIn, int quality) : mName(name), mExpiresIn(expiresIn), mQuality(quality) {}

    string getName() {
    	return mName;
    }
    
    int getExpiresIn() {
    	return mExpiresIn;
    }
    
    int getQuality() {
    	return mQuality;
    }
    
    void setQuality(int quality) {
    	mQuality = quality;
    }
    
    void setExpiresIn(int expiresIn) {
    	mExpiresIn = expiresIn;
    }
};

class Shop {
private:
    vector<Item> & items;
    void updateCheeseItem(Item& item){
		if (item.getExpiresIn()>0) item.setQuality(item.getQuality()+1);
		else item.setQuality(item.getQuality()+2);
        item.setExpiresIn(item.getExpiresIn()-1);
        
    }
    void updateNormalItem(Item& item){
        if (item.getExpiresIn()>0) item.setQuality(item.getQuality()-1);
		else item.setQuality(item.getQuality()-2);
        item.setExpiresIn(item.getExpiresIn()-1);
        
    }
    void updateConcertTicketItem(Item& item){
        if (item.getExpiresIn()>0) item.setQuality(item.getQuality()+2);
		else item.setQuality(item.getQuality());
        item.setExpiresIn(item.getExpiresIn()-1);
        
    }
    void updateExcaliburItem(Item& item){
        if (item.getExpiresIn()>0) item.setQuality(item.getQuality());
		else item.setQuality(item.getQuality());
        
    }
	void resetQualityToWithinRange(Item& item){
		if(item.getQuality()>MAXIMUMLEVEL) item.setQuality(20);
		else if(item.getQuality()<MINIMUMLEVEL) item.setQuality(0);

	}
    
public:
    Shop(vector<Item> & itemsInStock) : items(itemsInStock) {}
    
    vector<Item> getItems() {
    	return items;
    }
    void updateItems(){

		for (size_t i = 0; i < items.size(); i++)
		{
			Item item= items[i];            
			string nomItem = item.getName();
			int quality = item.getQuality();
            item.setExpiresIn(item.getExpiresIn()-1);
			if (nomItem==string("Cheese"))
			{
				updateCheeseItem(item);
			}
			else if (nomItem==string("ConcertTicket"))
			{
				updateConcertTicketItem(item);
			}
			else if (nomItem==string("Normal"))
			{
				updateNormalItem(item);
			}
			else
			{
				updateExcaliburItem(item);
			}    	
		}
    }

};

int main() {
    Item normalItem("Normal", 4, 6);
    Item cheese("Cheese", 4, 10);
    Item concertTicket("Concert Ticket", 4, 14);
    Item excalibur("Excalibur", 4, 10);
    vector<Item> itemsInStock = {normalItem, cheese, concertTicket, excalibur};
    Shop qualityShop(itemsInStock);
	const int SIZESTOCK = qualityShop.getItems().size();
    
    
    
    
    for (int i = 0; i < WORKINGDAYS; i++) {
        cout << "Day " << i+1 << endl;
    	qualityShop.updateItems();
    	for (int j = 0; j < SIZESTOCK ; j++) {
            cout << qualityShop.getItems()[j].getName() << ": Quality(" << qualityShop.getItems()[j].getQuality() << "), expires in " << qualityShop.getItems()[j].getExpiresIn() << " days." << endl;
    	}
    }

    return 0;
}