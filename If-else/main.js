// Declaring a variable 'a'
var a=5;


// creating a function named myFunct1()
function myFunc1()
{
   
   if(a==1)
   {
   var VText=document.getElementById('ChangeText').value;
   document.getElementById('paragrapgh').innerHTML=VText;
   }
else if(a==2)
{
alert("Best Case"); // changed the value from 'Very Good'

}

else if(a==4)
{
alert("Average Case"); // changed the value from 'Good'

}

   
   else if(a==5)
{
alert("Worst Case");

}

else
{

   var VText="Hello World";
   document.getElementById('paragrapgh').innerHTML=VText;


}



}


