function renderProduct(){
  var productList = [];
  
function init(){
  document.getElementById("jsworld").innerHTML = "hello world from javascript"
}

function getProductList(){
  console.log("fetching producta list")
  productList = productList1
  initProduct()
}

function initProduct(){
  document.getElementById("product-menu").innerHTML = 
  `
   <h1>List of Product </h1>
  <table>
      <thead>
        <tr>
          <th>Sr. No</th>
          <th>product Name </th>
          <th>details </th>
          <th>price </th>
        </tr>
        <tbody>
      ${getProductListHTMLUsingMap()}
        </tbody>
      </thead>
    </table>`
}

// join methid is to change any 
// ${} -> use java script in `` under 



function getProductListHTMLUsingMap(){
  if(productList.length==0){
    return "loading data";
  }
  rowsOfproduct = productList.map((item,index)=>{
    return `<tr>
            <td>${index+1}</td>
            <td>${item.name}</td>
            <td>${item.discription}</td>
            <td>${item.price}</td>
          </tr>
    `
  })
  return rowsOfproduct.join("")
}



function getPoductListHTML(){
  var row = "";
  for(let i = 0; i<productList.length; i++){
    row  = row+
    `
          <tr>
            <td>${i+1}</td>
            <td>${productList[i].name}</td>
            <td>${productList[i].discription}</td>
            <td>${productList[i].price}</td>
          </tr>`
  }
  return row.join("");
}

initProduct()
setTimeout(getProductList,10000);
init();

}

renderProduct();

