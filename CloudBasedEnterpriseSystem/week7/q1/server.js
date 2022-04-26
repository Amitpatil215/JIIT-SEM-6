const express = require('express')
const app = express()
const port = 9090

app.listen(port, ()=> console.log(`Q1 app listening on port ${port}!`))

app.get('/',(req,res)=>{
    res.send("Hello World");
})