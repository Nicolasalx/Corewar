const express = require('express');
const path = require('path');
const database = require('../config/database');
const { exec } = require('child_process');
const fs = require('fs');

const router = express.Router();

router.get('/execute', (req, res) => {
  database.connect();
  const sqlQuery = "SELECT name, file_name, comment FROM champion WHERE name NOT LIKE 'Champion%' AND file_name NOT LIKE 'file_name%' AND comment NOT LIKE 'Description%'";

  database.query(sqlQuery, (err, results) => {
    if (err) {
      console.error('Error executing the query:', err);
      res.status(500).send('Internal Server Error');
      return;
    }

    let tableHtml = '<table><tr><th>Name</th><th>File Name</th><th>Comment</th></tr>';
    results.forEach(row => {
      tableHtml += `<tr><td>${row.name}</td><td>${row.file_name}</td><td>${row.comment}</td></tr>`;
    });
    tableHtml += '</table>';

    const filePath = path.join(__dirname, 'execute.html');
    fs.readFile(filePath, 'utf8', (err, htmlFileContent) => {
      if (err) {
        console.error('Error reading file:', err);
        res.status(500).send('Internal Server Error');
        return;
      }
      const combinedHtml = htmlFileContent.replace('{{TABLE_CONTENT}}', tableHtml);
      res.send(combinedHtml);
    });
  });
});

router.post('/execute', (req, res) => {
  const sqlQuery = "SELECT name, file_name, comment FROM champion WHERE name NOT LIKE 'Champion%' AND file_name NOT LIKE 'file_name%' AND comment NOT LIKE 'Description%'";
  database.query(sqlQuery, (err, results) => {
    if (err) {
      console.error('Error executing the query:', err);
      res.status(500).send('Internal Server Error');
      return;
    }

    const asmCommands = results.map(row => `../../asm/asm ../../champions/${row.file_name}`);

    executeCommands(asmCommands, () => {
      const corFiles = results.map(row => `../../champions/${row.file_name.replace('.s', '')}.cor`);
      const corewarCommand = `./corewar ${corFiles.join(' ')}`;
      exec(corewarCommand, (error, stdout, stderr) => {
        if (error) {
          console.error('Error executing corewar command:', error);
          return;
        }

        console.log('Corewar command output:', stdout);
        console.error('Corewar command error:', stderr);
      });
    });
  });
});

function executeCommands(commands, callback) {
  if (commands.length === 0) {
    callback();
    return;
  }

  const command = commands.shift();
  console.log('Executing command:', command);

  exec(command, (error, stdout, stderr) => {
    if (error) {
      console.error('Error executing command:', error);
      return;
    }

    console.log('Command output:', stdout);
    console.error('Command error:', stderr);

    executeCommands(commands, callback);
  });
}

module.exports = router;
