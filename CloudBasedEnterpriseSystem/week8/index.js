
const express = require('express')
var xml = require('xml');
var js2xmlparser = require("js2xmlparser");
const app = express()
const port = 3000

app.get('/', (req, res) => {
    res.send('Hello World!')
})

app.get('/createTB', (req, res) => {
    let mysql = require('mysql');
    let connection = mysql.createConnection({
        host: 'localhost',
        user: 'root',
        password: 'root',
        database: 'studentdb'
    });

    // connect to the MySQL server
    connection.connect(function (err) {
        if (err) {
            return console.error('error: ' + err.message);
        }

        let createStudent = `create table if not exists student(
                              title varchar(255) not null,
                              Fname varchar(20),
                              Middle varchar (20),
                              Lname varchar (20),
                              Course varchar (20) default "BTech",
                              Branch varchar (20) default "IT",
                              Mobile int(10),
                              DoB DATE,
                              Address varchar(20),
                              City varchar (20),
                              State varchar (20),
                              Country varchar (20) default "India"
                          )`;

        connection.query(createStudent, function (err, results, fields) {
            if (err) {
                console.log(err.message);
            }
            if (results) {
                console.log("table Creat Success " + results)
            }
            if (fields) {
                console.log(fields);
            }
        });

        connection.end(function (err) {
            if (err) {
                return console.log(err.message);
            }
        });
    });

    res.send('Table Created succesfully')
})


// Add new values

app.get('/insertValues', (req, res) => {
    let mysql = require('mysql');
    let connection = mysql.createConnection({
        host: 'localhost',
        user: 'root',
        password: 'root',
        database: 'studentdb'
    });

    connection.connect(function (err) {
        if (err) {
            return console.error('error: ' + err.message);
        }
        console.log("Connected!");
        var sql = "INSERT INTO student VALUES ?";
        var values = [
            [19104001, 'John', 'kumar', 'singh', 'B.Tech', 'IT', 9857578442, '2000-12-12', 'Highway 71', 'ny', 'dsds', 'usa'],
            [19104002, 'amit', 'kumar', 'singh', 'B.Tech', 'IT', 9857578442, '2000-12-12', 'Highway 71', 'ny', 'dsds', 'INDIA'],
            [19104003, 'sanjoli', 'kumar', 'singh', 'B.Tech', 'IT', 9857578442, '2000-12-12', 'Highway 71', 'ny', 'dsds', 'usa'],
            [19104004, 'saransh', 'kumar', 'singh', 'B.Tech', 'IT', 9857578442, '2000-12-12', 'Highway 71', 'ny', 'dsds', 'usa'],
            [19104005, 'Jkd', 'kumar', 'singh', 'B.Tech', 'IT', 9857578442, '2000-12-12', 'Highway 71', 'ny', 'dsds', 'INDIA'],
            [19104006, 'muskan', 'kumar', 'singh', 'B.Tech', 'IT', 9857578442, '2000-12-12', 'Highway 71', 'ny', 'dsds', 'usa'],
            [19104007, 'kritika', 'kumar', 'singh', 'B.Tech', 'IT', 9857578442, '2000-12-12', 'Highway 71', 'ny', 'dsds', 'usa'],
            [19104008, 'jdnfjsf', 'kumar', 'singh', 'B.Tech', 'IT', 9857578442, '2000-12-12', 'Highway 71', 'ny', 'dsds', 'usa'],
            [19104009, 'mamam', 'kumar', 'singh', 'B.Tech', 'IT', 9857578442, '2000-12-12', 'Highway 71', 'ny', 'dsds', 'usa'],
            [19104010, 'jdh', 'kumar', 'singh', 'B.Tech', 'IT', 9857555552, '2000-12-12', 'Highway 71', 'ny', 'dsds', 'usa']
        ];
        connection.query(sql, [values], function (err, result) {
            if (err) throw (err);
            console.log("Number of records inserted: " + result.affectedRows);
        });
    });
    res.send("Records Inserted Successfully")
})

//TODO: this function giving error on repeated calls ....json and xml function working fine  
app.get('/show', async (req, res) => {
    let isXml = req.query.isXml; //other wise bydefault JSON
    let isDonwload = req.query.isDonwload;
    let mysql = require('mysql');
    let connection = mysql.createConnection({
        host: 'localhost',
        user: 'root',
        password: 'root',
        database: 'studentdb'
    });

    var rows = []

    // connect to the MySQL server
    connection.connect(function (err) {
        if (err) {
            return console.error('error: ' + err.message);
        }

        let getAllRows = `SELECT * FROM student`;

        connection.query(getAllRows, function (err, results, fields) {
            if (err) {
                console.log(err.message);
            }
            if (results) {
                console.log("Fetched Rows Success " + results)
                Object.keys(results).forEach(function (key) {
                    var row = results[key];
                    rows.push(row);
                    // console.log(row)
                });
                if (isXml == true) {
                    console.log("in XML")
                    res.set('Content-Type', 'application/xml');
                    xml_resultArray = js2xmlparser.parse("student", rows)
                    console.log(xml_resultArray)
                    return res.send(xml_resultArray);
                } 
                // else {
                //     console.log("in JSON")
                //     resultArray = Object.values(JSON.parse(JSON.stringify(rows)))
                //     res.send(resultArray)
                //     return res.send(resultArray);

                // }
            }
            if (fields) {
                // console.log(fields);
            }

        });

        connection.end(function (err) {
            if (err) {
                console.log(err.message);
            }
        });
    });
})





app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})