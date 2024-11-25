const executeCpp = require('./cppExecutor');

const addBranch = (branchName, managerName, callback) => {
    const command = `./bin/AddBranch "${branchName}" "${managerName}"`;
    executeCpp(command, callback);
};

module.exports = { addBranch };
