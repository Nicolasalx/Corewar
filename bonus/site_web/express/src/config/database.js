const mysql = require('mysql2');
const dotenv = require('dotenv');

dotenv.config();

const database = mysql.createConnection({
  host: "127.0.0.1",
  user: "root",
  password: "root",
  database: "corewar"
});

module.exports = database;
