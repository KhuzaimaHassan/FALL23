#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

class DataFrame
{
private:
    map<size_t, map<string, string>> data;
    vector<string> column_names;

public:
    // Constructor
    DataFrame() {}

    // Add a row to the DataFrame
    void addRow(const vector<string> &row)
    {
        if (row.size() != column_names.size())
        {
            cerr << "Error: Row size does not match the number of columns." << endl;
            return;
        }

        map<string, string> row_map;
        for (size_t i = 0; i < row.size(); ++i)
        {
            row_map[column_names[i]] = row[i];
        }

        data[data.size()] = row_map;
    }

    // Display the DataFrame shape
    void shape() const
    {
        cout << "Rows: " << data.size() << ", Columns: " << column_names.size() << endl;
    }

    // Display the DataFrame
    void display() const
    {
        vector<int> column_widths(column_names.size(), 0);

        // Calculate maximum column widths
        for (size_t i = 0; i < column_names.size(); ++i)
        {
            column_widths[i] = column_names[i].length();

            for (const auto &row : data)
            {
                auto cell = row.second.find(column_names[i]);
                if (cell != row.second.end() && cell->second.length() > static_cast<size_t>(column_widths[i]))
                {
                    column_widths[i] = cell->second.length();
                }
            }
        }

        // Display column names
        for (size_t i = 0; i < column_names.size(); ++i)
        {
            cout << setw(column_widths[i] + 2) << left << column_names[i];
        }
        cout << endl;

        // Display data
        for (const auto &row : data)
        {
            for (size_t i = 0; i < column_names.size(); ++i)
            {
                auto cell = row.second.find(column_names[i]);
                cout << setw(column_widths[i] + 2) << left << (cell != row.second.end() ? cell->second : "");
            }
            cout << endl;
        }
    }

    // Read data from a CSV file
    void readCSV(const string &filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cerr << "Error: Unable to open file " << filename << endl;
            return;
        }

        string line;

        // Read the header line
        if (getline(file, line))
        {
            istringstream iss(line);
            string column;
            while (getline(iss, column, ','))
            {
                column_names.push_back(column);
            }
        }

        // Read the data lines
        while (getline(file, line))
        {
            istringstream iss(line);
            vector<string> row;
            string value;
            while (getline(iss, value, ','))
            {
                row.push_back(value);
            }
            addRow(row);
        }

        file.close();
    }

    // Display the first few rows of the DataFrame
    void head(size_t n = 5) const
    {
        vector<int> column_widths(column_names.size(), 0);

        // Calculate maximum column widths
        for (size_t i = 0; i < column_names.size(); ++i)
        {
            column_widths[i] = column_names[i].length();

            for (const auto &row : data)
            {
                auto cell = row.second.find(column_names[i]);
                if (cell != row.second.end() && cell->second.length() > static_cast<size_t>(column_widths[i]))
                {
                    column_widths[i] = cell->second.length();
                }
            }
        }

        // Display column names
        for (size_t i = 0; i < column_names.size(); ++i)
        {
            cout << setw(column_widths[i] + 2) << left << column_names[i];
        }
        cout << endl;

        // Display first n rows of data
        size_t count = 0;
        for (const auto &row : data)
        {
            for (size_t i = 0; i < column_names.size(); ++i)
            {
                auto cell = row.second.find(column_names[i]);
                cout << setw(column_widths[i] + 2) << left << (cell != row.second.end() ? cell->second : "");
            }
            cout << endl;

            if (++count >= n)
            {
                break;
            }
        }
    }

    // Calculate and display value counts for a specific column
    void valueCounts(const string &column) const
    {
        auto columnIter = find(column_names.begin(), column_names.end(), column);
        if (columnIter == column_names.end())
        {
            cerr << "Error: Column '" << column << "' not found." << endl;
            return;
        }

        size_t columnIndex = distance(column_names.begin(), columnIter);

        map<string, size_t> counts;

        for (const auto &row : data)
        {
            auto cell = row.second.find(column_names[columnIndex]);
            if (cell != row.second.end())
            {
                counts[cell->second]++;
            }
        }

        cout << "Value Counts for Column '" << column << "':" << endl;
        for (const auto &entry : counts)
        {
            cout << entry.first << ": " << entry.second << endl;
        }
    }

    // Convert string to either int or double based on the content
    template <typename T>
    T convertToNumeric(const string &value) const
    {
        istringstream iss(value);
        T result;
        return (iss >> result) ? result : T();
    }

    // Calculate the mean of a specific column
    double calculateMean(const string &column) const
    {
        auto columnIter = find(column_names.begin(), column_names.end(), column);
        if (columnIter == column_names.end())
        {
            cerr << "Error: Column '" << column << "' not found." << endl;
            return 0.0;
        }

        size_t columnIndex = distance(column_names.begin(), columnIter);

        for (const auto &row : data)
        {
            auto cell = row.second.find(column_names[columnIndex]);
            if (cell != row.second.end() && !cell->second.empty() && (isdigit(cell->second[0]) || cell->second[0] == '-'))
            {
                vector<double> values;
                transform(data.begin(), data.end(), back_inserter(values),
                          [columnIndex, this](const pair<size_t, map<string, string>> &row)
                          {
                              auto cell = row.second.find(column_names[columnIndex]);
                              return convertToNumeric<double>(cell != row.second.end() ? cell->second : "");
                          });

                double mean = accumulate(values.begin(), values.end(), 0.0) / values.size();
                return mean;
            }
        }

        cerr << "Error: Column '" << column << "' does not contain numerical data." << endl;
        return 0.0;
    }

    // Calculate the median of a specific column
    double calculateMedian(const string &column) const
    {
        auto columnIter = find(column_names.begin(), column_names.end(), column);
        if (columnIter == column_names.end())
        {
            cerr << "Error: Column '" << column << "' not found." << endl;
            return 0.0;
        }

        size_t columnIndex = distance(column_names.begin(), columnIter);

        for (const auto &row : data)
        {
            auto cell = row.second.find(column_names[columnIndex]);
            if (cell != row.second.end() && !cell->second.empty() && (isdigit(cell->second[0]) || cell->second[0] == '-'))
            {
                vector<double> values;
                transform(data.begin(), data.end(), back_inserter(values),
                          [columnIndex, this](const pair<size_t, map<string, string>> &row)
                          {
                              auto cell = row.second.find(column_names[columnIndex]);
                              return convertToNumeric<double>(cell != row.second.end() ? cell->second : "");
                          });

                sort(values.begin(), values.end());

                size_t size = values.size();
                if (size == 0)
                {
                    return 0.0;
                }
                else if (size % 2 == 0)
                {
                    return (values[size / 2 - 1] + values[size / 2]) / 2.0;
                }
                else
                {
                    return values[size / 2];
                }
            }
        }

        cerr << "Error: Column '" << column << "' does not contain numerical data." << endl;
        return 0.0;
    }

    vector<float> getColumnValuesAsFloat(const string &column) const
    {
        auto columnIter = find(column_names.begin(), column_names.end(), column);
        if (columnIter == column_names.end())
        {
            cerr << "Error: Column '" << column << "' not found." << endl;
            return vector<float>(); // Return an empty vector in case of an error
        }

        size_t columnIndex = distance(column_names.begin(), columnIter);
        vector<float> values;

        for (const auto &row : data)
        {
            auto cell = row.second.find(column_names[columnIndex]);
            if (cell != row.second.end())
            {
                // Try to convert the string value to a float
                try
                {
                    float floatValue = stof(cell->second); // Convert string to float
                    values.push_back(floatValue);
                }
                catch (const invalid_argument &)
                {
                    cerr << "Error: Invalid argument for conversion to float: " << cell->second << endl;
                }
                catch (const out_of_range &)
                {
                    cerr << "Error: Out of range for conversion to float: " << cell->second << endl;
                }
            }
        }

        return values;
    }
    vector<string> merge(const vector<string> &left, const vector<string> &right) const
    {
        vector<string> result;
        size_t leftIdx = 0, rightIdx = 0;

        // Merge the two sorted vectors into one
        while (leftIdx < left.size() && rightIdx < right.size())
        {
            if (stof(left[leftIdx]) <= stof(right[rightIdx]))
            {
                result.push_back(left[leftIdx]);
                leftIdx++;
            }
            else
            {
                result.push_back(right[rightIdx]);
                rightIdx++;
            }
        }

        // Append the remaining elements, if any
        while (leftIdx < left.size())
        {
            result.push_back(left[leftIdx]);
            leftIdx++;
        }

        while (rightIdx < right.size())
        {
            result.push_back(right[rightIdx]);
            rightIdx++;
        }

        return result;
    }

    vector<string> mergeSort(const vector<string> &arr) const
    {
        if (arr.size() <= 1)
        {
            return arr; // Base case: array of size 1 or less is already sorted
        }

        // Divide the array into two halves
        size_t middle = arr.size() / 2;
        vector<string> left(arr.begin(), arr.begin() + middle);
        vector<string> right(arr.begin() + middle, arr.end());

        // Recursively sort the two halves
        left = mergeSort(left);
        right = mergeSort(right);

        // Merge the sorted halves
        return merge(left, right);
    }

    vector<string> sortColumn(const string &column) const
    {
        auto columnIter = find(column_names.begin(), column_names.end(), column);
        if (columnIter == column_names.end())
        {
            cerr << "Error: Column '" << column << "' not found." << endl;
            return vector<string>(); // Return an empty vector in case of an error
        }

        size_t columnIndex = distance(column_names.begin(), columnIter);
        vector<float> values = getColumnValuesAsFloat(column);

        // Sort the values
        sort(values.begin(), values.end());

        vector<string> sortedColumnValues;

        // Convert sorted float values to strings
        for (const auto &value : values)
        {
            sortedColumnValues.push_back(to_string(value));
        }

        return sortedColumnValues;
    }
    // Calculate and display descriptive statistics for a specific column
    void descriptiveStatistics() const
    {
        cout << "\nDescriptive Statistics for a Specific Column:\n";

        // Get user input for the column name
        string columnName;
        cout << "Enter the column name for descriptive statistics: ";
        cin >> columnName;

        auto columnIter = find(column_names.begin(), column_names.end(), columnName);

        if (columnIter != column_names.end())
        {
            size_t columnIndex = distance(column_names.begin(), columnIter);

            if (isNumericColumn(columnIndex))
            {
                cout << "\nColumn: " << columnName << endl;

                double mean = calculateMean(columnName);
                double median = calculateMedian(columnName);
                double minVal = calculateMin(columnName);
                double maxVal = calculateMax(columnName);
                double stdDev = calculateStdDev(columnName);

                cout << "Mean: " << mean << endl;
                cout << "Median: " << median << endl;
                cout << "Minimum: " << minVal << endl;
                cout << "Maximum: " << maxVal << endl;
                cout << "Standard Deviation: " << stdDev << endl;
            }
            else
            {
                cerr << "Error: The specified column does not contain numeric values." << endl;
            }
        }
        else
        {
            cerr << "Error: Column '" << columnName << "' not found." << endl;
        }
    }
    // Add a member function to display the top N entries of a specific column in descending order
    void displayTopNEntries(const string &column, size_t n) const
    {
        auto columnIter = find(column_names.begin(), column_names.end(), column);
        if (columnIter == column_names.end())
        {
            cerr << "Error: Column '" << column << "' not found." << endl;
            return;
        }

        size_t columnIndex = distance(column_names.begin(), columnIter);

        // Create a vector of pairs (value of the specified column, row index)
        vector<pair<string, size_t>> columnValues;
        for (const auto &row : data)
        {
            auto cell = row.second.find(column_names[columnIndex]);
            if (cell != row.second.end())
            {
                columnValues.emplace_back(cell->second, row.first);
            }
        }

        // Sort the vector of pairs based on the values of the specified column in descending order
        sort(columnValues.begin(), columnValues.end(), greater<pair<string, size_t>>());

        // Display the top N entries
        cout << "\nTop " << n << " Entries of Column '" << column << "' in Descending Order:\n";
        for (size_t i = 0; i < min(n, columnValues.size()); ++i)
        {
            const auto &entry = columnValues[i];
            cout << "Row " << entry.second << ": " << entry.first << endl;
        }
    }

private:
    // Check if a column contains numeric values
    bool isNumericColumn(size_t columnIndex) const
    {
        for (const auto &row : data)
        {
            auto cell = row.second.find(column_names[columnIndex]);
            if (cell != row.second.end() && !cell->second.empty() &&
                (isdigit(cell->second[0]) || (cell->second[0] == '-' && isdigit(cell->second[1]))))
            {
                return true;
            }
        }
        return false;
    }

    // Calculate the minimum value of a specific column
    double calculateMin(const string &column) const
    {
        auto columnIter = find(column_names.begin(), column_names.end(), column);
        if (columnIter == column_names.end())
        {
            cerr << "Error: Column '" << column << "' not found." << endl;
            return 0.0;
        }

        size_t columnIndex = distance(column_names.begin(), columnIter);

        vector<double> values;
        transform(data.begin(), data.end(), back_inserter(values),
                  [columnIndex, this](const pair<size_t, map<string, string>> &row)
                  {
                      auto cell = row.second.find(column_names[columnIndex]);
                      return convertToNumeric<double>(cell != row.second.end() ? cell->second : "");
                  });

        values.erase(remove_if(values.begin(), values.end(), [](double val)
                               { return isnan(val); }),
                     values.end());

        if (values.empty())
        {
            cerr << "Error: Column '" << column << "' does not contain valid numerical data." << endl;
            return 0.0;
        }

        return *min_element(values.begin(), values.end());
    }

    // Calculate the maximum value of a specific column
    double calculateMax(const string &column) const
    {
        auto columnIter = find(column_names.begin(), column_names.end(), column);
        if (columnIter == column_names.end())
        {
            cerr << "Error: Column '" << column << "' not found." << endl;
            return 0.0;
        }

        size_t columnIndex = distance(column_names.begin(), columnIter);

        vector<double> values;
        transform(data.begin(), data.end(), back_inserter(values),
                  [columnIndex, this](const pair<size_t, map<string, string>> &row)
                  {
                      auto cell = row.second.find(column_names[columnIndex]);
                      return convertToNumeric<double>(cell != row.second.end() ? cell->second : "");
                  });

        values.erase(remove_if(values.begin(), values.end(), [](double val)
                               { return isnan(val); }),
                     values.end());

        if (values.empty())
        {
            cerr << "Error: Column '" << column << "' does not contain valid numerical data." << endl;
            return 0.0;
        }

        return *max_element(values.begin(), values.end());
    }

    // Calculate the standard deviation of a specific column
    double calculateStdDev(const string &column) const
    {
        auto columnIter = find(column_names.begin(), column_names.end(), column);
        if (columnIter == column_names.end())
        {
            cerr << "Error: Column '" << column << "' not found." << endl;
            return 0.0;
        }

        size_t columnIndex = distance(column_names.begin(), columnIter);

        vector<double> values;
        transform(data.begin(), data.end(), back_inserter(values),
                  [columnIndex, this](const pair<size_t, map<string, string>> &row)
                  {
                      auto cell = row.second.find(column_names[columnIndex]);
                      return convertToNumeric<double>(cell != row.second.end() ? cell->second : "");
                  });

        values.erase(remove_if(values.begin(), values.end(), [](double val)
                               { return isnan(val); }),
                     values.end());

        if (values.empty())
        {
            cerr << "Error: Column '" << column << "' does not contain valid numerical data." << endl;
            return 0.0;
        }

        double mean = accumulate(values.begin(), values.end(), 0.0) / values.size();
        double sumSquaredDiff = accumulate(values.begin(), values.end(), 0.0,
                                           [mean](double acc, double val)
                                           {
                                               return acc + pow(val - mean, 2);
                                           });

        double variance = sumSquaredDiff / values.size();
        return sqrt(variance);
    }
};

// Overloaded operator<< for displaying DataFrame in tabular form
ostream &operator<<(ostream &os, const DataFrame &df)
{
    df.display();
    return os;
}