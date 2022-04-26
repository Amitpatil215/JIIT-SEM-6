const express = require('express')
const fs = require('fs')
const app = express()
const port = 9090

app.listen(port, () => console.log(`Q2,3,4 app listening on port ${port}!`))

app.get('/', (req, res) => {
    name = req.query.name;
    res.send(`Hello ${name}`);
})

app.get('/file', (req, res) => {
    fs.writeFile('abc.txt', "I love my India", function (err) {
        if (err) {

            return;
        }
        console.log(`File Created Successfully`);
    })

    fs.appendFile('abc.txt', 'My name is Amit', function (err) {
        if (err) throw err;
        console.log('Append content Success');
    });

    fs.writeFile('abc.txt', "New content after replacing", function (err) {
        if (err) {
            res.send("filed to replace content of the file");
            return;
        }

        console.log(`New content added in the file`);


    })
    res.send("New content added in the file\n Done all operations");
})

app.get('/rfile', (req, res) => {
    fs.rename("old_file.txt", " old_file_renamed.txt", function (err) {
        res.send("File Cant be renamed");
        throw err;
        return;
    })
    res.send("File rename success");

})

app.get('/dfile', (req, res) => {
    fs.unlink("file_to_be_deleted.txt", function (err) {
        res.send("File Cant be deleted");
        return;
    })
    res.send("File Delete success");

})

function bblSort(arr) {

    for (var i = 0; i < arr.length; i++) {

        for (var j = 0; j < (arr.length - i - 1); j++) {


            if (arr[j] > arr[j + 1]) {


                var temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
            }
        }
    }
    console.log(arr);
}


app.get('/bsort', (req, res) => {

    // This is our unsorted array
    var arr = [234, 43, 55, 63, 5, 6, 235, 547];

    var copyarr = arr;
    // Now pass this array to the bblSort() function
    bblSort(arr);
    res.send(`Initla array arr ${copyarr} After bubble sort ${arr}`);

})