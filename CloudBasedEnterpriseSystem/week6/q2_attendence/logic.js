let studentList = [];
function onAttendenceSaved() {

    let count = 0;
    for (let i = 0; i < studentList.length; i++) {
        let each = studentList[i];
        let percent = (each.totalSet / 10) * 100;
        each.percent = percent;
    }
    renderResultOnScreen();
}

function renderResultOnScreen() {
    let ul = document.createElement('ul')
    document.getElementById('resultDiv').appendChild(ul)

    studentList.forEach(function (items) {
        let li = document.createElement('li')

        li.innerHTML += items.name + " " + items.percent+ "%";

        ul.appendChild(li);
    })
}
function student(name) {
    return { 'name': name, 1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 'totalSet': 0, 'percent': 0 }
}
function makeList() {

    for (let i = 0; i < 7; i++) {
        studentList.push(student('student' + (i + 1)))
    }
    let ul = document.createElement('ul')
    ul.id = "innsersl"
    document.getElementById('slist').appendChild(ul)
    studentList.forEach(function (items) {
        let li = document.createElement('li')
        var radiobox = document.createElement('input');
        radiobox.type = 'radio';
        radiobox.id = '${Object.keys(items)[1]}';
        radiobox.value = 0;
        radiobox.onclick = function fun(a) {

            items["${radiobox.id}"] = !items["${radiobox.id}"];
            radiobox.checked = items["${radiobox.id}"];
            //if item is checked increase the count
            if (items["${radiobox.id}"]) {
                items['totalSet']++;
            } else {
                items['totalSet']--;
            }
        }
        li.innerHTML += items.name;
        li.appendChild(radiobox);
        ul.appendChild(li);
    })

    let button = document.createElement('button')
    button.innerHTML = "Submit Attendence"
    button.id = "subAtt"
    button.onclick = function fun() {
        onAttendenceSaved()
    }
    document.getElementById('slist').appendChild(button)


}