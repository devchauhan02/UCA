const express = require("express")

const app = express();

app.use("/",express.static("./frontend"))

app.listen(8080,()=>{
  console.log("server started")
})