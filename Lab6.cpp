
#include <iomanip>

#include <string>

#include <fstream>

#include <cstdlib>

#include <cmath>

using namespace std;

float Median(float a, float b, float c)

{

float mean;

if (a < b)

{

    if (b < c)

        mean = b;

    else

        mean = (a < c ? c : a);

}

else

{

    if (a < c)

        mean = a;

    else

        mean = (b < c ? c : b);

}

return mean;

}



int main()

{

string file;
    
     // Get the name of the input file
cout << "Enter name of the input file: ";

    // Open the input file and check that it was successful
cin >> file;

ifstream in(file.c_str());

if (in.fail())

{

    cout << "Unble to open file to read" << endl;

    exit(1);

}

    
    // Get the name of the output file
cout << "Enter name of the output file: ";

cin >> file;

ofstream out(file.c_str());
    
    // Open the output file and check that it was successful

if (out.fail())

{

    out << "Unble to open file to write" << endl;

    exit(1);

}

float noisyNum[1000], smoothNum[1000];

int i=0, n;

//out << "Noisy Numbers: ";
    
    // read till the end of input file, counting the total number present in input file

while(!in.eof())
{

    in >> noisyNum[i];

    //out << noisyNum[i] << " ";

    i++;

}

out << endl;

n = i;

smoothNum[0] = noisyNum[0];

smoothNum[n-1] = noisyNum[n-1];

for(i=1; i < n-1; i++)
{

    smoothNum[i] = Median(noisyNum[i-1], noisyNum[i], noisyNum[i+1]);

}

float noisyAvg = 0, noisyVariance = 0, noisySD = 0, smoothAvg = 0, smoothVariance = 0, smoothSD = 0;

    // copy the first and last element from original data to smooth array data
//out << "Smoothed Numbers: ";
    


for(i=0; i < n; i++)
{

    noisyAvg += noisyNum[i];

    //out << smoothNum[i] << " ";

}

out << endl;

for(i=0; i < n; i++)
{

    smoothAvg += smoothNum[i];

    //out << smoothNum[i] << " ";

}

out << endl;

    
out << "Noisy Numbers" << "\t" << "Smooth Numbers" << endl;    
for(i=0; i < n; i++)
{
    
    out << fixed;
    out << setprecision(2);
    out << right << setw(8);
    out << noisyNum[i] << "\t\t  " << right << smoothNum[i] << endl;

}
    
noisyAvg /= n;    
smoothAvg /= n;
    
   
out << "Noisy Average: " << noisyAvg << endl;
out << "Smoothed Average: " << smoothAvg << endl;

for(i=0; i < n; i++)
{

    noisyVariance += pow((noisyNum[i] - noisyAvg), 2);

}
    
for(i=0; i < n; i++)
{

    smoothVariance += pow((smoothNum[i] - smoothAvg), 2);

}

noisyVariance /= (n-1);    
smoothVariance /= (n-1);

noisySD = sqrt(noisyVariance);    
smoothSD = sqrt(smoothVariance);

//out << "Smoothed Variance: " << smoothVariance << endl;
out << "Noisy standard Deviation: " << noisySD << endl;    
out << "Smoothed standard Deviation: " << smoothSD << endl;

out << endl;

return 0;

}