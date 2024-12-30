// Wenchen Shi UID: 505453951
// Project 3
#include <iostream>

#include <string>

using namespace std;

bool isValidResultString(string results);

bool isNaturalNumber (char myChar);

bool isInteger (char myChar);

// returns the Size for each R

int getRSize(char ch, string results, int position);
int getRSize2(int startPosition, int endPosition, string results);
// The following function extracts the first number.
int extractNumber (string results, int nextPosition);
// returns the sign
int returnSignPosition(int startPos, string results);
int positiveTests(string results);
int returnPositiveNumber (int PosOfPlus, string results);
int negativeTests(string results);
int returnNegativeNumber (int PosOfNeg, string results);
int totalTests(string results);
int batches(string results);

int main(int argc, const char * argv[]) {
    
    bool checkIfValid = true;
    
    string result;
    
    cout << "Enter the Result: " << endl;
    
    getline(cin, result);
    
    checkIfValid = isValidResultString(result);
    
    
    
    if(checkIfValid == true)
        
    {
        
        cout << "Valid Result " << endl;
        
    }
    
    else
        
    {
        
        cout << "Invalid Result" << endl;
        
    }
    int RPosTest = 0;
    RPosTest = positiveTests(result);
    cout << "PositiveTests: " << RPosTest << endl;
    int RNegTest = 0;
    RNegTest = negativeTests(result);
    cout << "NegativeTests: " << RNegTest << endl;
    int RTotalTests = 0;
    RTotalTests = totalTests(result);
    cout << "Tt: " << RTotalTests << endl;
    cout << "Batches: " << batches(result) << endl;
    return 0;
    
}





bool isValidResultString(string results)

{
    
    // TODO:
    
    // Check results[0] == R and size >= 6
    
    // Check if results[1] is > 0
    
    // Save the size of result[1]
    
    
    
    int RSize = 0;
    
    int checkNumbers = 0;
    
    int nextPosition = 0;
    
    bool isValidResult = true;
    
    
    
    //Check results[0] == R and size >= 6
    
    if (results[0] == 'R' && results.size() >= 6)
        
    {
        // Diag:
        //cout << "Level 1"<< endl;
        
        //Check if results[1] is > 0
        
        if(isNaturalNumber(results[1]))
            
        {
            // Diag:
            //cout << "Level 2"<< endl;
            
            // Loop starting from index-2
            
            for (int i = 1; i < results.size() - 1; i++)
                
            {
                // Diag:
                //cout << "In Loop "<< endl;
                
                /* if results[i-1] == 'R' and isNN(results[i])
                 
                 call getRSize
                 
                 */
                
                if (results[i-1] == 'R' && isNaturalNumber(results[i]))
                    
                {
                    
                    RSize = getRSize(results[i], results, i);
                    // Diag:
                   // cout << "RSize: " << RSize << endl;
                    
                    nextPosition = returnSignPosition(i,results);
                    
                    checkNumbers = extractNumber (results, nextPosition);
                    
                    if(checkNumbers != RSize)
                        
                    {
                        
                        isValidResult = false;
                        
                        return isValidResult;
                        
                    }
                    
                    else if (checkNumbers == RSize)
                        
                    {
                        
//                        cout << checkNumbers << " Matches " << RSize << endl;
                        
                    }
                    
                    
                    
                }
                
            }
            
            
            
        }
        
        else
            
        {
            
            isValidResult = false;
            
        }
        
    }
    
    else
        
    {
        
        isValidResult = false;
        
    }
    
    
    
    
    
    return isValidResult;
    
}



// Checks if the i-index in string is > 0

bool isNaturalNumber (char myChar)

{
    
    bool isNN = true;
    
    
    
    if (myChar > '0')
        
    {
        
        isNN = true;
        
    }
    
    else
        
    {
        
        isNN = false;
        
    }
    
    return isNN;
    
}

// Checks if its an Integer

bool isInteger (char myChar)

{
    
    bool isInt = true;
    
    
    
    if (myChar >= '0')
        
    {
        
        isInt = true;
        
    }
    
    else
        
    {
        
        isInt = false;
        
    }
    
    return isInt;
    
}

//Get the test size

int getRSize(char ch, string results, int position)

{
    
    // We'll use -1, so when we run it then we know something is wrong.
    
    string testSizeString = "";
    
    int testSize = -1;
    
    int startPosition = 0;
    
    int endPosition = 0;
    //Diag
   // cout << "Top of getRSize" << endl;
    
   // cout << "Position: " << position << endl;
    
   // cout << "Size:" << results.size()<< endl;
    
    for (int i = position; i < results.size(); i++)
        
    {
        
       // cout << "IN FUNCTION LOOP" << endl;
        
        //cout << "i: " << i << endl;
        
        if (results[i+1] == '+')
            
        {
            
            // Got to starting position and loop through till we hit a '+' or '-'
            
            endPosition = i;
            
            startPosition = position;
            
           // cout << "--> Start Position: " << startPosition << endl;
            
            //cout << "--> EndPosition: " << endPosition << endl;
            
            testSize = getRSize2(position, endPosition,results);
            
            return testSize;
            
        }
        
        
        
        else if (results[i+1] == '-')
            
        {
            
            // Got to starting position and loop through till we hit a '+' or '-'
            
            endPosition = i - 1;
            
            testSize = getRSize2(position, endPosition,results);
            
            //cout << "--> Start Position: " << startPosition << endl;
            
            //cout << "--> EndPosition: " << endPosition << endl;
            
            return testSize;
            
        }
        
    }
    
    
    
    return testSize;
    
}



int getRSize2 (int startPosition, int endPosition, string results)

{
    
    string testSizeString;
    
    int testSize = 0;
    
    for (int i = startPosition; i <= results[endPosition]; i++)
        
    {
        
        //(int)results[i] will convert results[i] to integer
        
        // each character from our length range to string
        
        testSizeString += results[i];
        
        // stoi converts string to int
        
        testSize = stoi(testSizeString);
        
        //cout << "index[" << i << "]" << ": " << testSize << endl;
        
    }
    
    return testSize;
    
}



int returnSignPosition(int startPos, string results)

{
    
    int endPos = 0;
    
    //int j = 0;
    
//    cout << "ReturnSignPos Start: " << startPos << endl;
    
    for(int i = startPos; i <= results.size(); i++)
        
    {
        
        if (!(isInteger(results[i])))
            
        {
            
            endPos = i;
            //Diag
           // cout << "In return sign position: " << endPos << endl;
            
            return endPos;
            
            
            
        }
        
        
        
    }
    
    
    // Diag:
    //cout << "In return sign position: " << endPos << endl;
    
    return endPos;
    
}



int extractNumber (string results, int nextPosition)

{
    
    // provide string of results R1300+300-1000R2+1-1
    
    // The next position must be a + or -
    
    // Also, it must end with a - or +
    
    // each character after the + or - must be checked by is Integer
    
    
    
    //int j = 0;
    
    string number;
    
    string number2;
    
    string TotalNumber;
    
    int extractNumberResult = 0;
    
    char nextPositionChar;
    // Diag:
    //cout << "In extract Number Function " << endl;
    
    
    
    nextPositionChar = results[nextPosition];
    
    
    
    // if the first sign is a '+' and no R after number sequence
    
    if(nextPositionChar == '+')
        
    {
        
        // loop through till next sign
        
        // make sure all are integers and that the next sign is a -
        
        // Problem: leading zeros are still allowed TODO:
        
        if (results[nextPosition+1] == '0' && isNaturalNumber(results[nextPosition+2]))
            
        {
            // Diag:
            //cout << "Leading 0: " << endl;
            return extractNumberResult = -1;
            
        }
        else{
        
        for(int i = nextPosition + 1; i <= (results.size()); i++)
            
        {
            
            if(isInteger(results[i]) && results[i] != '-')
                
            {
                
                number += results[i];
                // Diag:
                //cout << "Number In Loop: " << number << endl;
                
                
                
            }
            
            else if (results[i] == '-')
                
            {
                
                if (results[i+1] == '0' && isNaturalNumber(results[i+2]))
                    
                {
                    
                    return extractNumberResult = -1;
                    
                }
                
                i = i + 1;
                
                for (int j = i; j <= results.size(); j++)
                    
                {
                    
                    if(isInteger(results[j]) && results[j] != 'R')
                        
                    {
                        
                        number2 += results[j];
                        
                        //cout << "Number2 In Loop: " << number2 << endl;
                        
                    }
                    
                    else
                        
                    {
                        
                       // cout << "Number1: " << number << " Number2: " << number2 << endl;
                        
                        extractNumberResult = stoi(number) + stoi(number2);
                        
                       // cout << "extractNumberResult: " << extractNumberResult << endl;
                        
                        return extractNumberResult;
                        
                    }
                    
                }
                
            }
            
        }
      }
        
    }
    // if the first sign is a '+' and no R after number sequence
    
    else if (nextPositionChar == '-')
        
    {
        
        if (results[nextPosition+1] == '0' && isNaturalNumber(results[nextPosition+2]))
            
        {
            
            return extractNumberResult = -1;
            
        }
        else{
        
        for(int i = nextPosition + 1; i <= (results.size()); i++)
            
        {
            
            if(isInteger(results[i]) && results[i] != '+')
                
            {
                
                number += results[i];
                // Diag:
               // cout << "Number In Loop: " << number << endl;
                
                
                
            }
            
            
            
            else if (results[i] == '+')
                
            {
                
                if (results[i+1] == '0' && isNaturalNumber(results[i+2]))
                    
                {
                    
                    return extractNumberResult = -1;
                    
                }
                
                i = i + 1;
                
                for (int j = i; j <= results.size(); j++)
                    
                {
                    
                    if(isInteger(results[j]) && results[j] != 'R')
                        
                    {
                        
                        number2 += results[j];
                        //Diag
                        //cout << "Number2 In Loop: " << number2 << endl;
                        
                    }
                    
                    else
                        
                    {
                        // Diag:
                        //cout << "Number1: " << number << " Number2: " << number2 << endl;
                        
                        extractNumberResult = stoi(number) + stoi(number2);
                        //Diag:
                        //cout << "extractNumberResult: " << extractNumberResult << endl;
                        
                        return extractNumberResult;
                        
                    }
                    
                }
                
            }
            
        }
        
      }
        
    }
    
    else
        
    {
        
        return extractNumberResult = -1;
        
    }
    
    return extractNumberResult;
    
}
int positiveTests(string results){
    
    int PosOfPlus = 0;
    int eachNumber = 0;
    int PosNumbSum = 0;
    if (isValidResultString(results)==false)
        return PosNumbSum = -1;
    else if (isValidResultString(results)==true)
    {
        // R1300+300-1000R2+1-1......
        // R1300-300+1000R2+1-1......
       
        for (int i = 1; i < results.size()-1; i++)
        {
            if(results[i] == '+')
            {
                PosOfPlus = i+1;
                eachNumber += returnPositiveNumber(PosOfPlus, results);
//                cout << "Positive Numbers: " << eachNumber << endl;
            }
        }
        PosNumbSum = eachNumber;
//        cout << "Total Positive Numbers: " << PosNumbSum << endl;
        
    }
    
    return PosNumbSum;
    
}

int returnPositiveNumber (int PosOfPlus, string results)
{
    int i = PosOfPlus;
    string StringPosNum = "";
    int IntPosNum = 0;
    
    while (results[i] != '-' && results[i] != 'R' )
    {
//        cout << "In While Loop:" << endl;
        StringPosNum += results[i];
//        cout << "Result: " << StringPosNum << endl;
        i++;
    }
    IntPosNum = stoi(StringPosNum);
    return IntPosNum;
}

int negativeTests(string results){
    
    int PosOfNeg = 0;
    int eachNumber = 0;
    int NegNumbSum = 0;
    if (isValidResultString(results)==false)
        return NegNumbSum = -1;
    else if (isValidResultString(results)==true)
    {
        // R1300+300-1000R2+1-1......
        // R1300-300+1000R2+1-1......
       
        for (int i = 1; i < results.size()-1; i++)
        {
            if(results[i] == '-')
            {
                PosOfNeg = i+1;
                eachNumber += returnNegativeNumber(PosOfNeg, results);
//                cout << "Negative Numbers: " << eachNumber << endl;
            }
        }
        NegNumbSum = eachNumber;
//        cout << "Total Negative Numbers: " << NegNumbSum << endl;
        
    }
    
    return NegNumbSum;
    
}

int returnNegativeNumber (int PosOfNeg, string results)
{
    int i = PosOfNeg;
    string StringNegNum = "";
    int IntNegNum = 0;
    
    while (results[i] != '+' && results[i] != 'R' )
    {
//        cout << "In While Loop:" << endl;
        StringNegNum += results[i];
//        cout << "Result: " << StringNegNum << endl;
        i++;
    }
    IntNegNum = stoi(StringNegNum);
    return IntNegNum;
}
int totalTests(string results){
    int RSize = 0;
    if (isValidResultString(results)==true)
    {
        for (int i = 1; i < results.size() - 1; i++)
        {
//        cout << "In Total Test "<< endl;
        
          if (results[i-1] == 'R' && isNaturalNumber(results[i]))

        {
            RSize += getRSize(results[i], results, i);
        }
        }
    }
    else if (isValidResultString(results)==false)
    {
        return -1;
    }
    return RSize;
}
int batches(string results){
    int count = 0;
    for (int i = 0; i < results.size(); i++)
    {
        if (results[i] == 'R')
            count ++;
    }
    return count;
}

