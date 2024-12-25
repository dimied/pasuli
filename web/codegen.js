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
        var seen = {}, res = '', vIdx = 0;
        if (vals && vals.length > 0) {
            indent = indent || '';
            res = '';
            for (; vIdx < vals.length; vIdx++) {
                var c = vals[vIdx];
                if (seen[c]) {
                    continue;
                }
                res += indent + 'var ' + c.name + "=(" + c.op + ");\n";
                seen[c] = true;
            }
        }
        return res;
    }
    var i, ops = [
        { op: 'PI', real: 'Math.PI', 'constant': true },
        { op: 'abs' },
        { op: 'acos' },
        { op: 'acosh' },
        { op: 'asin' },
        { op: 'asinh' },
        { op: 'atan' },
        { op: 'atanh' },
        { op: 'cbrt' },
        { op: 'ceil' },
        { op: 'cos' },
        { op: 'cosh' },
        { op: 'exp' },
        { op: 'log' },
        { op: 'round' },
        { op: 'sign' },
        { op: 'sin' },
        { op: 'sinh' },
        { op: 'sqrt' },
        { op: 'tan' },
        { op: 'tanh' },

    ];
    //Adapt to Math.*
    for (i = 0; i < ops.length; i++) {
        if (!ops[i].real) {
            ops[i].real = 'Math.' + ops[i].op;
        }
    }
    function adaptToJs(op) {
        var i = 0, idx, currentOp, realOp, res = op;
        //Remove empty space
        while (res.indexOf(' ') >= 0) {
            res = res.replaceAll(' ', '');
        }

        for (; i < ops.length; i++) {

            currentOp = ops[i].op;
            realOp = ops[i].real;
            if (!ops[i].constant) {
                currentOp += '(';
                realOp += '(';
            }
            idx = res.indexOf(currentOp);
            if (idx >= 0) {
                res = res.replaceAll(currentOp, realOp);
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
            var indent = "  ";
            //console.log('S:', content);
            var funcCode = 'function ' + generateFuncName(content.name) + "(u,v, params) {\n"
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

