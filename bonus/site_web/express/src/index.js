const express = require("express");
const path = require("path");
const play = require('./play/play');
const contrib = require('./contributors/contributeur');
const tuto = require('./playable/playable');
const edit = require('./edit/edit');
const fileUpload = require('express-fileupload');
const execute = require('./execute/execute')

const app = express();

app.use(fileUpload());
app.use(fileUpload({
  limits: { fileSize: 10 * 1024 * 1024 }
}));
app.use(express.json());
app.use(play);
app.use(contrib);
app.use(tuto);
app.use(edit);
app.use(execute);
app.use(express.static('../site_web/express/style'));
app.use(express.static('../site_web/express/pictures'));

const port = 3000;

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'corewar.html'));
  });

  app.listen(port, () => {
    console.log(`Server listening on port ${port}`);
  });
