function calcu() {
  let val1 = document.getElementById("val1").value;
  let val2 = document.getElementById("val2").value;
  let result = parseInt(val1) + parseInt(val2);
  let ans = document.getElementById("result");
  ans.innerHTML = `Result = ${result}`;

  // <p>create a new paragraph</p>
  let ptag = document.createElement("p");
  let txt = document.createTextNode(`${val1} + ${val2} = ${result}`);
  ptag.appendChild(txt);

  // select a parent node to append
  let parent1 = document.getElementById("div1");
  parent1.appendChild(ptag);
}
