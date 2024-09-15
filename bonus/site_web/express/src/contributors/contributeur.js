const express = require('express');
const path = require('path');

const router = express.Router();

router.use(express.static('style'));

router.get('/contributors', (req, res) => {
    res.sendFile(path.join(__dirname, "contributeurs.html"));
});

module.exports = router;