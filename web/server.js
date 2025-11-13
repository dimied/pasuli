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
    map: 'application/javascript',
    json: 'application/json',
    ico: 'image/x-icon'
};

const pasuliRoot = path.normalize(path.resolve(path.join(__dirname, '..')));
const scriptRoot = __dirname;

console.log("Script path: " + scriptRoot);
console.log("Root: '" + pasuliRoot);

function writeJsHead(res) {
    res.writeHead(200, { 'Content-Type': types.json });
}

var pasuliDirectories = [
    {
        catname: "Cylinder",
        folder: 'cylinder'
    },
    {
        catname: "Fruits",
        folder: 'fruits'
    },
    {
        catname: "Shell",
        folder: 'shells'
    },
    {
        catname: "Sphere",
        folder: 'sphere'
    },
    {
        catname: "Spiral",
        folder: 'spiral'
    },
    {
        catname: "Surfaces",
        folder: 'surfaces'
    },
    {
        catname: "Torus",
        folder: 'torus'
    }
];

function loadDirectory(desc) {
    return new Promise((resolve, reject) => {
        const result = Object.assign({}, desc);
        const folders = [
            path.join(pasuliRoot, desc.folder),
            path.join(pasuliRoot, desc.folder, 'json')
        ];
        let found = false;
        for (var dirIdx = 0; dirIdx < folders.length; dirIdx++) {
            const folder = path.normalize(path.resolve(folders[dirIdx]));
            if (fs.existsSync(folder)) {
                const filenames = fs.readdirSync(folder);
                //console.log("F:", filenames);
                result.files = [];

                for (var idx = 0; idx < filenames.length; idx++) {
                    const filePath = path.join(folder, filenames[idx]);
                    if (!filePath.endsWith(".json")) {
                        continue;
                    }
                    const fileContent = fs.readFileSync(filePath);
                    const o = {
                        file: filenames[idx],
                        fullpath: filePath,
                        success: false
                    };
                    try {
                        const asJSON = JSON.parse(fileContent);
                        o.success = true;
                        o.content = asJSON;
                    } catch (e) {
                        o.error = e.toString();
                    }
                    result.files.push(o);
                }
                found = true;
            }
        }

        if (!found) {
            result.success = false;
            result.message = 'Folder missing';
        }

        resolve(result);
    });
}

function sendJsonResponse(data, res) {
    const json = JSON.stringify(data);
    writeJsHead(res);
    res.end(json);
}

function pasuli(req, res) {
    const obj = {
        "a": "Hallo"
    };

    var promises = [];

    for (var idx = 0; idx < pasuliDirectories.length; idx++) {
        promises.push(loadDirectory(pasuliDirectories[idx]));
    }

    Promise.allSettled(promises).catch((err) => {
        const result = {
            success: false,
            message: 'Failed to load descriptions'
        }
        sendJsonResponse(result, res);
    }).then((results) => {
        const webResult = {
            success: true,
            message: 'Found',
            data: []
        }

        for (var i = 0; i < results.length; i++) {
            webResult.data.push(results[i].value);
        }
        console.log('RES?', results, typeof results);
        console.log('RES!', webResult);
        sendJsonResponse(webResult, res);
    });
}

const apis = {
    pasuli: pasuli
};


const server = http.createServer((req, res) => {
    console.log(`${req.method} ${req.url}`);

    const extension = path.extname(req.url).slice(1);
    const type = extension ? types[extension] : types.html;
    //const supportedExtension = Boolean(type);
    console.log("headers:", req.headers);

    if (req.url) {
        const endpoint = req.url.substring(1);
        if (endpoint && apis[endpoint]) {
            console.log("Endpoint:", endpoint);
            apis[endpoint](req, res);
            return;
        }
    }


    let fileName = req.url;
    if (req.url === '/') {
        fileName = 'index.html';
    } else if (!extension) {
        try {
            accessSync(join(scriptRoot, req.url + '.html'), constants.F_OK);
            fileName = req.url + '.html';
        } catch (e) {
            fileName = path.join(req.url, 'index.html');
        }
    }

    const filePath = path.join(scriptRoot, fileName);
    //console.log('Path:', filePath);
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