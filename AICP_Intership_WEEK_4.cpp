#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct auction_sys {
    string item_no;
    int noBids=0;
    string description;
    int resPrice=0;
    double highest_bid=0;
    bool sold=false;
};

struct buyer {
    int buyer_no=0;
    string item_no;
    int Bid=0;
};

void printBoard(auction_sys s[], int size) {
    cout << "-----------------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t\t&******WELCOME To IntEraCTivE AucTioN BOARD******&\n";
    cout << "-----------------------------------------------------------------------------------------------------------------\n";
    cout << "See Our PRODUCTs and Place BiDs:\n (Be Fast as time is running!)\n";
    cout << left << setw(10) << "Item no." << setw(55) << "Item Description" << setw(20) << "Reserve Price" << setw(20) 
        << "No. of Bids" << "Highest Bid\n";

    for (int i = 0; i < size; ++i) {
        cout << left << setw(10) << s[i].item_no
            << setw(55) << s[i].description
            << "$" << setw(20) << s[i].resPrice
            << setw(20) << s[i].noBids;
        if (s[i].highest_bid == 0)
            cout << setw(20) << "N/A";
        else
            cout << setw(20) << s[i].highest_bid;
        cout << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------------------\n";

}

int main() {
    auction_sys s[10];
    int size = 10;

    // Initialization
    s[0] = { "p01", 0, "Charred Glyph", 100, 0, false };
    s[1] = { "p02", 0, "Deck Sandals of the Feverflare (170)", 150, 0, false };
    s[2] = { "p03", 0, "Dubious Cheese Platter", 200, 0, false };
    s[3] = { "p04", 0, "Consumables", 120, 0, false };
    s[4] = { "p05", 0, "Empty Poison Vial", 180, 0, false };
    s[5] = { "p06", 0, "Glyphs", 160, 0, false };
    s[6] = { "p07", 0, "Empty Poison Vial", 220, 0, false };
    s[7] = { "p08", 0, "Trade Goods", 130, 0, false };
    s[8] = { "p09", 0, "Recipes", 190, 0, false };
    s[9] = { "p10", 0, "Profession Equipment", 170, 0, false };

    printBoard(s, size);

    char input;
    do {
        system("cls");
        printBoard(s, size);
        // Task 2 - Buyer bids
        int numBuyers;
        cout << "Enter the number of buyers: ";
        cin >> numBuyers;

        buyer* buyers = new buyer[numBuyers];

       
        for (int i = 0; i < numBuyers; i++) {
            cout << "\nEnter details for buyer " << i + 1 << ":\n";
            cout << "Buyer Number: ";
            cin >> buyers[i].buyer_no;
            cout << "Item Number: ";
            cin >> buyers[i].item_no;
            cout << "Bid: $";
            cin >> buyers[i].Bid;

          
            for (int j = 0; j < size; j++) {
                if (s[j].item_no == buyers[i].item_no && buyers[i].Bid > s[j].highest_bid) {
                    s[j].highest_bid = buyers[i].Bid;
                    s[j].noBids++;
                    break;
                }
            }
        }

        // Task 3 - End of auction
        int totalFee = 0;
        int numSold = 0;
        int numNotMeetingReserve = 0;
        int numNoBids = 0;

        for (int i = 0; i < size; ++i) {
            if (s[i].noBids > 0 && s[i].highest_bid >= s[i].resPrice) {
                s[i].sold = true;
                totalFee += 0.1 * s[i].highest_bid;
                numSold++;
            }
            else if (s[i].noBids > 0 && s[i].highest_bid < s[i].resPrice) {
                numNotMeetingReserve++;
            }
            else if (s[i].noBids == 0) {
                numNoBids++;
            }
        }
        cout << "------------------------------------------------------------------------------------------------------------------\n";

        cout << "\nEnd of Auction Summary:\n";
        cout << "Total Fee for Sold Items: $" << totalFee << endl;
        cout << "Items Sold: " << numSold << endl;
        cout << "Items Not Meeting Reserve Price: " << numNotMeetingReserve << endl;
        cout << "Items with No Bids: " << numNoBids << endl;
        cout << "------------------------------------------------------------------------------------------------------------------\n";

        delete[] buyers;  // Free memory allocated for buyers array

        cout << "Want to bid again? (y/n): ";
        cin >> input;
    } while (input == 'y');
    cout << "*****************************************\n";
    cout << "Thanks for coming!\n";
    cout << "SEE YOU AGAIN " << (char)1<<endl;
    cout << "*****************************************\n";

    return 0;
}
