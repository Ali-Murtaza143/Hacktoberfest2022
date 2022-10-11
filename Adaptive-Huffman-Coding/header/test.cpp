#include<bits/stdc++.h>
#include "AdaptiveHuffman.h"

int main(int argc, char const *argv[])
{

	std::string testDecodedString1 = "aardvark";
	std::string testDecodedString2 = "x";
	std::string testDecodedString3 = "saurav";

	std::string testEncodedString1 = "00000101000100000110001011010110001010";
	std::string testEncodedString2 = "1101";
	std::string retrievedString = "";

	int passCount = 0;
	int total = 7;

	AdaptiveHuffman AH;

	std::cout<<"\n";
	std::cout<<"\n\n----------Encode Test1:------------";
	std::cout<<"\nInput String:\t"<<testDecodedString1;
	std::string encodedTestString1 = AH.encode(testDecodedString1);
	if(encodedTestString1 == testEncodedString1){
		std::cout<<"\n\nPASSED!\n";
		passCount++;
	} else {
		std::cout<<"\n\nFAILED!\n";
	}
	std::cout<<"\nActual output:\t\t"<< encodedTestString1;
	std::cout<<"\nExpected output:\t"<< testEncodedString1;

	std::cout<<"\n";
	std::cout<<"\n\n----------Encode Test2:------------";
	std::cout<<"\nInput String:\t"<<testDecodedString2;
	std::string encodedTestString2 = AH.encode(testDecodedString2);
	if(encodedTestString2 == testEncodedString2){
		std::cout<<"\n\nPASSED!\n";
		passCount++;
	} else {
		std::cout<<"\n\nFAILED!\n";
	}
	std::cout<<"\nActual output:\t\t"<< encodedTestString2;
	std::cout<<"\nExpected output:\t"<< testEncodedString2;


	std::cout<<"\n";
	std::cout<<"\n\n----------Decode Test1:------------";
	std::cout<<"\nInput String:\t"<<testEncodedString1;
	std::string decodedTestString1 = AH.decode(testEncodedString1);
	if(decodedTestString1 == testDecodedString1){
		std::cout<<"\n\nPASSED!\n";
		passCount++;
	} else {
		std::cout<<"\n\nFAILED!\n";
	}
	std::cout<<"\nActual output:\t\t"<< decodedTestString1;
	std::cout<<"\nExpected output:\t"<< testDecodedString1;

	std::cout<<"\n";
	std::cout<<"\n\n----------Decode Test2:------------";
	std::cout<<"\nInput String:\t"<<testEncodedString2;
	std::string decodedTestString2 = AH.decode(testEncodedString2);
	if(decodedTestString2 == testDecodedString2){
		std::cout<<"\n\nPASSED!\n";
		passCount++;
	} else {
		std::cout<<"\n\nFAILED!\n";
	}
	std::cout<<"\nActual output:\t\t"<< decodedTestString2;
	std::cout<<"\nExpected output:\t"<< testDecodedString2;


	std::cout<<"\n";
	std::cout<<"\n\n----------Encode-Decode Test1:------------";
	std::cout<<"\nInput String:\t"<<testDecodedString3;
	retrievedString = AH.decode(AH.encode(testDecodedString3));
	if(retrievedString == testDecodedString3){
		std::cout<<"\n\nPASSED!\n";
		passCount++;
	} else {
		std::cout<<"\n\nFAILED!\n";
	}
	std::cout<<"\nActual output:\t\t"<< retrievedString;
	std::cout<<"\nExpected output:\t"<< testDecodedString3;


	std::string testDecompressedString1 = "a";
	std::cout<<"\n";
	std::cout<<"\n\n----------Compress-Decompress Test1:------------";
	std::cout<<"\nInput String:\t"<<testDecompressedString1;
	retrievedString = AH.decompress(AH.compress(testDecompressedString1));
	if(retrievedString == testDecompressedString1){
		std::cout<<"\n\nPASSED!\n";
		passCount++;
	} else {
		std::cout<<"\n\nFAILED!\n";
	}
	std::cout<<"\nActual output:\t\t"<< retrievedString;
	std::cout<<"\nExpected output:\t"<< testDecompressedString1;


	std::string testDecompressedString2 = "aardvark";
	std::cout<<"\n";
	std::cout<<"\n\n----------Compress-Decompress Test2:------------";
	std::cout<<"\nInput String:\t"<<testDecompressedString2;
	retrievedString = AH.decompress(AH.compress(testDecompressedString2));
	if(retrievedString == testDecompressedString2){
		std::cout<<"\n\nPASSED!\n";
		passCount++;
	} else {
		std::cout<<"\n\nFAILED!\n";
	}
	std::cout<<"\nActual output:\t\t"<< retrievedString;
	std::cout<<"\nExpected output:\t"<< testDecompressedString2;


	std::cout<<"\n\n\n\tResult: "<<passCount<<" / "<<total;

	std::cout<<"\n\n";
	system("pause");
	return 0;
}