//Code gen
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

