const express = require('express');
const path = require('path');

const router = express.Router();

router.use(express.static('style'));

router.get('/playable', (req, res) => {
    res.sendFile(path.join(__dirname, "jouabilité.html"));
});

module.exports = router;