const express = require('express');
const path = require('path');
const bodyParser = require('body-parser');
const database = require('../config/database');

const router = express.Router();

router.use(bodyParser.urlencoded({ extended: true }));

router.get('/edit', (req, res) => {
  const boxId = req.query.champion;
  database.connect();

  const selectQuery = 'SELECT name, comment FROM champion WHERE box_id = ?';
  database.query(selectQuery, [boxId], (error, results) => {
    if (error) {
      console.error('Error retrieving champion:', error);
      res.status(500).send('Error retrieving champion');
    } else {
      const champion = results[0];

      const filePath = path.join(__dirname, 'edit.html');
      res.sendFile(filePath);
    }
  });
});

router.post('/edit', (req, res) => {
  const name = req.body.name;
  const comment = req.body.comment;
  const boxId = req.body.boxId;
  const file_name = req.body.file_name;
  database.connect();

  const updateQuery = 'UPDATE champion SET name = ?, file_name = ?, comment = ? WHERE box_id = ?';

  database.query(updateQuery, [name, file_name, comment, boxId], (error, results, fields) => {
    if (error) {
      console.error('Error updating champion:', error);
      res.status(500).send('Error updating champion');
    } else {
      console.log('Champion updated successfully');
      res.redirect('/play');
    }
  });
});

module.exports = router;
