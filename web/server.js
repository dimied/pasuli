//import { readFile, accessSync, constants } from 'fs';
//import { createServer } from 'http';
//import { join, normalize, resolve, extname } from 'path';
const fs = require('fs');
const path = require('path');
const http = require('http');

const types = {
    html: 'text/html',
    css: 'text/css',
    js: 'application/javascript',
    json: 'application/json',
};

const pasuliRoot = path.normalize(path.resolve(path.join(__dirname, '..')));
const scriptRoot = __dirname;

console.log("Script path: " + scriptRoot);
console.log("Root: '" + pasuliRoot);

const otherScripts = [];
//Iterate in scriptRoot
//get JS and CSS files
//check them first and deliver.


const server = http.createServer((req, res) => {
    console.log(`${req.method} ${req.url}`);

    const extension = path.extname(req.url).slice(1);
    const type = extension ? types[extension] : types.html;
    const supportedExtension = Boolean(type);


    let fileName = req.url;
    if (req.url === '/') fileName = 'index.html';
    else if (!extension) {
        try {
            accessSync(join(scriptRoot, req.url + '.html'), constants.F_OK);
            fileName = req.url + '.html';
        } catch (e) {
            fileName = path.join(req.url, 'index.html');
        }
    }

    const filePath = path.join(scriptRoot, fileName);
    const isPathUnderRoot = path.normalize(path.resolve(filePath)).startsWith(scriptRoot);

    if (!isPathUnderRoot) {
        res.writeHead(404, { 'Content-Type': 'text/html' });
        res.end('404: File not found "' + filePath + '"');
        return;
    }

    fs.readFile(filePath, (err, data) => {
        if (err) {
            res.writeHead(404, { 'Content-Type': 'text/html' });
            res.end('404: File not found');
        } else {
            res.writeHead(200, { 'Content-Type': type });
            res.end(data);
        }
    });
});

function getCustomPort() {
    if (fs.existsSync('./package.json')) {
        let myPort = require("./package.json").server_port;
        if (myPort) {
            let result = parseInt("" + myPort, 10);
            if (typeof result === 'number' && ("" + result === "" + myPort)) {
                return result;
            }
        }
    }
}

const port = getCustomPort() || 8000;

server.listen(port, () => {
    console.log(`Server is listening on port http://localhost:${port}`);
});