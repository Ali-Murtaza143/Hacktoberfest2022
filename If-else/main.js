var a=5;


function myFunc1()
{
   
   if(a==1)
   {
   var VText=document.getElementById('ChangeText').value;
   document.getElementById('paragrapgh').innerHTML=VText;
   }
else if(a==2)
{
alert("very Good");

}

else if(a==4)
{
alert("Good");

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


