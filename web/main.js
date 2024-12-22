

var codeGenerator = (function () {
    function generateFuncName(name) {
        return name.trim().replaceAll(' ', '_') + 'Func';
    }
    function generateParamsLine(params, indent) {
        var res = '';
        if (params) {
            var entries = [];
            indent = indent || '';
            for (var pIdx = 0; pIdx < params.length; pIdx++) {
                entries.push(params[pIdx] + "=params[" + pIdx + "]");
            }
            if (entries.length > 0) {
                res += indent + 'var ' + entries.join(', ') + ";\n";
            }
        }
        return res;
    }
    function generateValsLines(vals, indent) {
        var res = '';
        if (vals && vals.length > 0) {
            indent = indent || '';
            res = '';
            for (var vIdx = 0; vIdx < vals.length; vIdx++) {
                var c = vals[vIdx];
                res += indent + 'var ' + c.name + "=(" + c.op + ");\n";
            }
        }
        return res;
    }
    var ops = [
        { op: 'PI', real: 'Math.PI' },
        { op: 'abs', real: 'Math.abs' },
        { op: 'acos', real: 'Math.acos' },
        { op: 'asin', real: 'Math.asin' },
        { op: 'atan', real: 'Math.atan' },
        { op: 'ceil', real: 'Math.ceil' },
        { op: 'cos', real: 'Math.cos' },
        { op: 'log' },
        { op: 'round' },
        { op: 'sin', real: 'Math.sin' },
        { op: 'sqrt' },
        { op: 'tan', real: 'Math.tan' },
        
    ];
    //Adapt to Math.*
    for(var i=0; i< ops.length; i++) {
        if(!ops[i].real) {
            ops[i].real = 'Math.'+ops[i].op;
        }
    }
    function adaptToJs(op) {
        var res = op;
        for (var i = 0; i < ops.length; i++) {
            var idx = res.indexOf(ops[i].op);
            if (idx >= 0) {
                res = res.replaceAll(ops[i].op, ops[i].real);
            }
        }
        return res;
    }
    function generatePositionCode(surfaceDesc, indent) {
        var res = '';
        if (!surfaceDesc) {
            return '';
        }
        indent = indent || '';
        var codes = [], keys = ['x', 'y', 'z'];

        for (var kIdx = 0; kIdx < keys.length; kIdx++) {
            var k = keys[kIdx];
            if (surfaceDesc[k]) {
                codes.push(indent + '  ' + k + ': ' + adaptToJs(surfaceDesc[k]));
            }
        }
        var nl = codes.length > 0 ? "\n" : '';
        res = '{' + nl;
        res += codes.join(",\n");
        res += nl + indent + '};'
        return indent + 'return ' + res;
    }
    return {
        generateName: generateFuncName,
        generate: function (surfaceDesc) {
            if (!surfaceDesc) {
                return '';
            }
            const content = surfaceDesc.content;
            if (!content) {
                return '';
            }

            console.log('S:', content);
            var funcCode = 'function ' + generateFuncName(content.name) + "(u,v, params) {\n"
            var indent = "  ";
            var c = generateParamsLine(content.params, indent);
            funcCode += c ? c + "\n" : '';

            c = generateValsLines(content.vals, indent);
            funcCode += c ? c + "\n" : '';

            c = generatePositionCode(content, indent);
            funcCode += c ? c + "\n" : '';
            funcCode += "}\n";

            return funcCode;
        }
    };
}());
var allFunctions = {};

(function () {
    console.log('INIT MAIN');
    var cssUtil = {
        add: function (elem, cls) {
            if (elem && cls) {
                //console.log('ADD:', elem, cls);
                if (elem.className.indexOf(cls) >= 0) {
                    return;
                }
                elem.className = (elem.className + ' ' + cls).trim();
            }
        },
        remove: function (elem, cls) {
            if (elem && cls) {
                //console.log('REM:', elem, cls);
                var className = elem.className;
                var idx = className.indexOf(cls);
                if (idx >= 0) {
                    var newCls = className.substring(0, idx);
                    idx += cls.length + 1
                    if (idx < className.length) {
                        newCls += className.substring(idx);
                    }
                    elem.className = newCls.trim();
                }
            }
        }
    };

    function isJSON(headers) {
        return headers && headers.get('content-type') === 'application/json';
    }

    function access(path, onSuccess, onError) {
        fetch(path).catch(function (e) {
            console.error("No...")
            onError && onError(e);
        }).then(function (data) {
            if (isJSON(data.headers)) {

                data.json().then(function (res) {
                    onSuccess(res);
                }).catch(function (e) {
                    console.error("ERROR:", e);
                });
                return;
            }
            onSuccess(data);
        });
    }

    var validViewTypes = ['3d', 'math'], currentType = 'math';

    function selectView(type) {
        console.log('Type:', type);
        if (!type || !validViewTypes.includes(type)) {
            console.error('Invalid type:', type);
            return;
        }
        currentType = type;
    }



    function addButtonHandlers() {
        var ids = ['select3d', 'selectmath'];

        for (var idx = 0; idx < ids.length; idx++) {
            var elem = document.getElementById(ids[idx]);
            if (elem) {
                elem.addEventListener('click', (function (type, otherElemId) {
                    return function (e) {
                        selectView(type);
                        var other = document.getElementById(otherElemId);
                        cssUtil.remove(other, 'selected');
                        cssUtil.add(e.target, 'selected');
                    };

                }(validViewTypes[idx], ids[1 - idx])));
            }
        }
    }


    function loadAllSurfacesImpl(data) {
        if (!data.success) {
            return;
        }
        if (!data.data) {
            return;
        }
        let fIdx = 0;
        for (var catIdx = 0; catIdx < data.data.length; catIdx++) {
            var category = data.data[catIdx];
            for (var sIdx = 0; sIdx < category.files.length; sIdx++) {
                var f = category.files[sIdx];
                if (fIdx < 10) {
                    var content = codeGenerator.generate(f);
                    console.log('S:', content);
                }
                fIdx++;
            }
        }
    }

    function loadAllSurfaces() {
        access('/pasuli', loadAllSurfacesImpl, function (err) {
            console.error('ERR:', err);
        });
    }

    document.addEventListener('DOMContentLoaded', function () {
        addButtonHandlers();
        loadAllSurfaces();
    });
}());


