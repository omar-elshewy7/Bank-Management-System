const { exec } = require('child_process');

const executeCpp = (command, callback) => {
    exec(command, (error, stdout, stderr) => {
        if (error) {
            console.error(`Error: ${error.message}`);
            return callback(error, null);
        }
        if (stderr) {
            console.error(`Stderr: ${stderr}`);
            return callback(new Error(stderr), null);
        }
        callback(null, stdout);
    });
};

module.exports = executeCpp;
