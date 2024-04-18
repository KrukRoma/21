#include <iostream>
#include <string>
using namespace std;

struct Vagon 
{
    int number; 
    int totalSeats; 
    int passengers; 

    Vagon() : number(0), totalSeats(0), passengers(0) {}

    Vagon(int num, int seats, int pass) : number(num), totalSeats(seats), passengers(pass) {}
};

class Train 
{
private:
    string model; 
    int numVagons; 
    Vagon* vagons; 

public:
    Train() : model(""), numVagons(0), vagons(nullptr) {}

    Train(const string& mdl, int numVags)
        : model(mdl), numVagons(numVags) 
    {
        vagons = new Vagon[numVags];
    }

    Train(const Train& other)
        : model(other.model), numVagons(other.numVagons) 
    {
        vagons = new Vagon[numVagons];
        for (int i = 0; i < numVagons; i++) 
        {
            vagons[i] = other.vagons[i];
        }
    }

    void Show() const 
    {
        cout << "Model: " << model << endl;
        cout << "Number of vagons: " << numVagons << endl;
        for (int i = 0; i < numVagons; i++) 
        {
            cout << "Vagon " << vagons[i].number
                << ": Total seats - " << vagons[i].totalSeats
                << ", Passengers - " << vagons[i].passengers << endl;
        }
    }

    void AddVagon(const Vagon& vagon) 
    {
        Vagon* newVagons = new Vagon[numVagons + 1];
        for (int i = 0; i < numVagons; i++) 
        {
            newVagons[i] = vagons[i];
        }
        newVagons[numVagons] = vagon;
        delete[] vagons;
        vagons = newVagons;
        numVagons++;
    }

    void AddPassengerToVagon(int vagonNumber) 
    {
        for (int i = 0; i < numVagons; i++) 
        {
            if (vagons[i].number == vagonNumber) 
            {
                if (vagons[i].passengers < vagons[i].totalSeats) 
                {
                    vagons[i].passengers++;
                    cout << "Passenger added to vagon " << vagonNumber << endl;
                }
                else 
                {
                    cout << "Vagon " << vagonNumber << " is full" << endl;
                }
                return;
            }
        }
        cout << "Vagon " << vagonNumber << " not found" << endl;
    }

    ~Train() 
    {
        delete[] vagons;
    }
};

int main() 
{
    Train train("Express", 2);

    Vagon vagon1(1, 50, 0);
    Vagon vagon2(2, 60, 0);

    train.AddVagon(vagon1);
    train.AddVagon(vagon2);

    train.Show();

    train.AddPassengerToVagon(1);
    train.AddPassengerToVagon(2);

    train.Show();
}
