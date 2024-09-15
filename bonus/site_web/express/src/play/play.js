const express = require('express');
const path = require('path');
const fs = require('fs');
const database = require('../config/database');

const router = express.Router();

router.get('/play', (req, res) => {
  database.connect();
  database.query('SELECT * FROM champion', (err, results) => {
    if (err) {
      console.error('Error retrieving data:', err);
      res.status(500).send('Internal Server Error');
    } else {
      const champions = results;
      const filePath = path.join(__dirname, 'jouer.html');
      fs.readFile(filePath, 'utf8', (err, data) => {
        if (err) {
          console.error('Error reading HTML file:', err);
          res.status(500).send('Internal Server Error');
        } else {
          const modifiedHTML = replacePlaceholders(data, champions);
          res.send(modifiedHTML);
        }
      });
    }
  });
});

router.get('/champions', (req, res) => {
  database.connect();
  database.query('SELECT * FROM champion', (err, results) => {
    if (err) {
      console.error('Error retrieving data:', err);
      res.status(500).send('Internal Server Error');
    } else {
      res.json(results);
    }
  });
});

function replacePlaceholders(html, champions) {
  let modifiedHTML = html;
  for (let i = 0; i < champions.length; i++) {
    const championIndex = i + 1;
    const champion = champions[i];
    modifiedHTML = modifiedHTML.replace(`Champion ${championIndex}`, `${champion.name}`);
    modifiedHTML = modifiedHTML.replace(`Description ${championIndex}`, `${champion.comment}`);
  }
  return modifiedHTML;
}

module.exports = router;
