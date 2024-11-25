const express = require('express');
const router = express.Router();
const branchController = require('../controllers/branchController');

router.post('/add', branchController.addBranch);
router.get('/list', branchController.getBranches);

module.exports = router;
