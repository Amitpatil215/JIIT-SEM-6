function splitAmount() {
    var amount = document.getElementById("amount").value;
    var peoples = document.getElementById("peoples").value;
    let perPersonAmt=amount/peoples;
    const para = document.createElement("p");
    para.innerText = "Amount Per Person is " + perPersonAmt;
    para.id="result"
    document.body.appendChild(para);
}