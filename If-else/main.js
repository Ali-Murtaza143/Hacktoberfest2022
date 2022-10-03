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
alert("Excellent"); // changed the value from 'Very Good'

}

else if(a==4)
{
alert("Average"); // changed the value from 'Good'

}

   
   else if(a==5)
{
alert("bad");

}

else
{

   var VText="Hello world";
   document.getElementById('paragrapgh').innerHTML=VText;


}



}


