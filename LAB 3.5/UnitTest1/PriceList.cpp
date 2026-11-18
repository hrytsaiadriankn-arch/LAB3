#include "pch.h"
#include "PriceList.h"
#include <stdexcept>
#include <limits>

// ==================== MODEL ====================

Model::Model()
{
    brand = "Unknown";
    processorType = "Unknown";
    processorFrequency = 1.0;
    ram = 1;
    hardDisk = 1;
    videoMemory = 0;
    price = 1.0;
    quantity = 0;
}

Model::Model(string brand, string processorType,
    double processorFrequency, int ram,
    int hardDisk, int videoMemory,
    double price, int quantity)
{
    SetBrand(brand);
    SetProcessorType(processorType);
    SetProcessorFrequency(processorFrequency);
    SetRAM(ram);
    SetHardDisk(hardDisk);
    SetVideoMemory(videoMemory);
    SetPrice(price);
    SetQuantity(quantity);
}

string Model::GetBrand() const
{
    return brand;
}

string Model::GetProcessorType() const
{
    return processorType;
}

double Model::GetProcessorFrequency() const
{
    return processorFrequency;
}

int Model::GetRAM() const
{
    return ram;
}

int Model::GetHardDisk() const
{
    return hardDisk;
}

int Model::GetVideoMemory() const
{
    return videoMemory;
}

double Model::GetPrice() const
{
    return price;
}

int Model::GetQuantity() const
{
    return quantity;
}

void Model::SetBrand(string value)
{
    if (value.empty())
        throw invalid_argument("Brand cannot be empty!");

    brand = value;
}

void Model::SetProcessorType(string value)
{
    if (value.empty())
        throw invalid_argument("Processor type cannot be empty!");

    processorType = value;
}

void Model::SetProcessorFrequency(double value)
{
    if (value <= 0)
        throw invalid_argument("Processor frequency must be positive!");

    processorFrequency = value;
}

void Model::SetRAM(int value)
{
    if (value <= 0)
        throw invalid_argument("RAM must be positive!");

    ram = value;
}

void Model::SetHardDisk(int value)
{
    if (value <= 0)
        throw invalid_argument("Hard disk capacity must be positive!");

    hardDisk = value;
}

void Model::SetVideoMemory(int value)
{
    if (value < 0)
        throw invalid_argument("Video memory cannot be negative!");

    videoMemory = value;
}

void Model::SetPrice(double value)
{
    if (value <= 0)
        throw invalid_argument("Price must be positive!");

    price = value;
}

void Model::SetQuantity(int value)
{
    if (value < 0)
        throw invalid_argument("Quantity cannot be negative!");

    quantity = value;
}

void Model::Read()
{
    string text;
    double doubleValue;
    int intValue;

    cout << "Brand: ";
    getline(cin >> ws, text);
    SetBrand(text);

    cout << "Processor type: ";
    getline(cin, text);
    SetProcessorType(text);

    cout << "Processor frequency (GHz): ";
    if (!(cin >> doubleValue))
        throw invalid_argument("Invalid frequency!");
    SetProcessorFrequency(doubleValue);

    cout << "RAM (GB): ";
    if (!(cin >> intValue))
        throw invalid_argument("Invalid RAM!");
    SetRAM(intValue);

    cout << "Hard disk (GB): ";
    if (!(cin >> intValue))
        throw invalid_argument("Invalid hard disk!");
    SetHardDisk(intValue);

    cout << "Video memory (GB): ";
    if (!(cin >> intValue))
        throw invalid_argument("Invalid video memory!");
    SetVideoMemory(intValue);

    cout << "Price (conditional units): ";
    if (!(cin >> doubleValue))
        throw invalid_argument("Invalid price!");
    SetPrice(doubleValue);

    cout << "Quantity: ";
    if (!(cin >> intValue))
        throw invalid_argument("Invalid quantity!");
    SetQuantity(intValue);
}

void Model::Display() const
{
    cout << "Brand: " << brand << endl;
    cout << "Processor: " << processorType << endl;
    cout << "Frequency: " << processorFrequency << " GHz" << endl;
    cout << "RAM: " << ram << " GB" << endl;
    cout << "Hard disk: " << hardDisk << " GB" << endl;
    cout << "Video memory: " << videoMemory << " GB" << endl;
    cout << "Price: " << price << " units" << endl;
    cout << "Quantity: " << quantity << endl;
}

Model::operator string() const
{
    return brand + " | " + processorType +
        " | RAM: " + to_string(ram) +
        " GB | Disk: " + to_string(hardDisk) +
        " GB | Video: " + to_string(videoMemory) +
        " GB | Price: " + to_string(price);
}

bool Model::operator==(const Model& other) const
{
    return brand == other.brand;
}

// ==================== PRICE LIST ====================

PriceList::PriceList()
    : Array<Model>()
{
    creationDate = "18.11.2026";
    currencyRate = 41.50;
}

PriceList::PriceList(string date, double rate)
    : Array<Model>()
{
    SetCreationDate(date);
    SetCurrencyRate(rate);
}

PriceList::PriceList(const PriceList& other)
    : Array<Model>()
{
    creationDate = other.creationDate;
    currencyRate = other.currencyRate;
    count = other.count;

    for (int i = 0; i < count; i++)
        elements[i] = other.elements[i];
}

string PriceList::GetCreationDate() const
{
    return creationDate;
}

double PriceList::GetCurrencyRate() const
{
    return currencyRate;
}

void PriceList::SetCreationDate(string date)
{
    if (date.empty())
        throw invalid_argument("Date cannot be empty!");

    creationDate = date;
}

void PriceList::SetCurrencyRate(double rate)
{
    if (rate <= 0)
        throw invalid_argument("Currency rate must be positive!");

    currencyRate = rate;
}

int PriceList::FindIndexByBrand(string brand) const
{
    for (int i = 0; i < count; i++)
    {
        if (elements[i].GetBrand() == brand)
            return i;
    }

    return -1;
}

void PriceList::AddModel(const Model& model)
{
    if (count >= MAX_SIZE)
        throw overflow_error("Price list is full!");

    if (FindIndexByBrand(model.GetBrand()) != -1)
        throw invalid_argument("Model with this brand already exists!");

    elements[count] = model;
    count++;
}

void PriceList::ChangeModel(string oldBrand, const Model& model)
{
    int index = FindIndexByBrand(oldBrand);

    if (index == -1)
        throw runtime_error("Model not found!");

    int duplicateIndex = FindIndexByBrand(model.GetBrand());

    if (duplicateIndex != -1 && duplicateIndex != index)
        throw invalid_argument("This brand already exists!");

    elements[index] = model;
}

void PriceList::DeleteModel(string brand)
{
    int index = FindIndexByBrand(brand);

    if (index == -1)
        throw runtime_error("Model not found!");

    for (int i = index; i < count - 1; i++)
        elements[i] = elements[i + 1];

    count--;
}

Model PriceList::FindByBrand(string brand) const
{
    int index = FindIndexByBrand(brand);

    if (index == -1)
        throw runtime_error("Model not found!");

    return elements[index];
}

vector<Model> PriceList::SearchByRAM(int value, bool exact) const
{
    if (value <= 0)
        throw invalid_argument("RAM value must be positive!");

    vector<Model> result;

    for (int i = 0; i < count; i++)
    {
        int current = elements[i].GetRAM();

        if (exact ? current == value : current >= value)
            result.push_back(elements[i]);
    }

    return result;
}

vector<Model> PriceList::SearchByHardDisk(int value, bool exact) const
{
    if (value <= 0)
        throw invalid_argument("Disk value must be positive!");

    vector<Model> result;

    for (int i = 0; i < count; i++)
    {
        int current = elements[i].GetHardDisk();

        if (exact ? current == value : current >= value)
            result.push_back(elements[i]);
    }

    return result;
}

vector<Model> PriceList::SearchByVideoMemory(int value, bool exact) const
{
    if (value < 0)
        throw invalid_argument("Video memory cannot be negative!");

    vector<Model> result;

    for (int i = 0; i < count; i++)
    {
        int current = elements[i].GetVideoMemory();

        if (exact ? current == value : current >= value)
            result.push_back(elements[i]);
    }

    return result;
}

double PriceList::CalculateTotal() const
{
    double total = 0;

    for (int i = 0; i < count; i++)
        total += elements[i].GetPrice() * elements[i].GetQuantity();

    return total;
}

double PriceList::CalculateTotalUAH() const
{
    return CalculateTotal() * currencyRate;
}

void PriceList::Read()
{
    int number;

    cout << "Enter creation date: ";
    getline(cin >> ws, creationDate);
    SetCreationDate(creationDate);

    cout << "Enter currency rate: ";
    if (!(cin >> currencyRate))
        throw invalid_argument("Invalid currency rate!");
    SetCurrencyRate(currencyRate);

    cout << "Enter number of models: ";
    if (!(cin >> number))
        throw invalid_argument("Invalid number!");

    if (number < 0 || number > MAX_SIZE)
        throw invalid_argument("Invalid number of models!");

    count = 0;

    for (int i = 0; i < number; i++)
    {
        cout << "\nModel " << i + 1 << ":\n";

        Model model;
        model.Read();
        AddModel(model);
    }
}

void PriceList::Display() const
{
    cout << "\n========== PRICE LIST ==========\n";
    cout << "Creation date: " << creationDate << endl;
    cout << "Currency rate: " << currencyRate << " UAH\n";
    cout << "Number of models: " << count << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "\nModel " << i + 1 << ":\n";
        elements[i].Display();
    }

    cout << "\nTotal: " << CalculateTotal()
        << " conditional units\n";

    cout << "Total in UAH: " << CalculateTotalUAH()
        << " UAH\n";
}

// ==================== SET OPERATIONS ====================

// UNION
PriceList PriceList::operator+(const PriceList& other) const
{
    PriceList result(*this);

    for (int i = 0; i < other.count; i++)
    {
        if (result.FindIndexByBrand(other.elements[i].GetBrand()) == -1)
            result.AddModel(other.elements[i]);
    }

    return result;
}

// INTERSECTION
PriceList PriceList::operator&(const PriceList& other) const
{
    PriceList result(*this);

    result.count = 0;

    for (int i = 0; i < count; i++)
    {
        if (other.FindIndexByBrand(elements[i].GetBrand()) != -1)
            result.AddModel(elements[i]);
    }

    return result;
}

// DIFFERENCE
PriceList PriceList::operator-(const PriceList& other) const
{
    PriceList result(*this);

    result.count = 0;

    for (int i = 0; i < count; i++)
    {
        if (other.FindIndexByBrand(elements[i].GetBrand()) == -1)
            result.AddModel(elements[i]);
    }

    return result;
}
