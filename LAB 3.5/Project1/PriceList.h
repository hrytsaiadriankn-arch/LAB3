
#pragma once

#include "Array.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Model
{
private:
    string brand;
    string processorType;
    double processorFrequency;
    int ram;
    int hardDisk;
    int videoMemory;
    double price;
    int quantity;

public:
    Model();
    Model(string brand, string processorType,
        double processorFrequency, int ram,
        int hardDisk, int videoMemory,
        double price, int quantity);

    string GetBrand() const;
    string GetProcessorType() const;
    double GetProcessorFrequency() const;
    int GetRAM() const;
    int GetHardDisk() const;
    int GetVideoMemory() const;
    double GetPrice() const;
    int GetQuantity() const;

    void SetBrand(string value);
    void SetProcessorType(string value);
    void SetProcessorFrequency(double value);
    void SetRAM(int value);
    void SetHardDisk(int value);
    void SetVideoMemory(int value);
    void SetPrice(double value);
    void SetQuantity(int value);

    void Read();
    void Display() const;

    operator string() const;

    bool operator==(const Model& other) const;
};

class PriceList : public Array<Model>
{
private:
    string creationDate;
    double currencyRate;

    int FindIndexByBrand(string brand) const;

public:
    PriceList();
    PriceList(string date, double rate);

    PriceList(const PriceList& other);
    PriceList& operator=(const PriceList& other) = default;

    string GetCreationDate() const;
    double GetCurrencyRate() const;

    void SetCreationDate(string date);
    void SetCurrencyRate(double rate);

    void AddModel(const Model& model);
    void ChangeModel(string oldBrand, const Model& model);
    void DeleteModel(string brand);

    Model FindByBrand(string brand) const;

    vector<Model> SearchByRAM(int value, bool exact = false) const;
    vector<Model> SearchByHardDisk(int value, bool exact = false) const;
    vector<Model> SearchByVideoMemory(int value, bool exact = false) const;

    double CalculateTotal() const;
    double CalculateTotalUAH() const;

    void Read();
    void Display() const;

    PriceList operator+(const PriceList& other) const;
    PriceList operator&(const PriceList& other) const;
    PriceList operator-(const PriceList& other) const;
};
