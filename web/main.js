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

//Main
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

    var surfaces = [];

    function createCatId(cat) {
        if (typeof cat === 'string') {
            return 'cat-' + cat;
        }
        return "cat-" + cat.catname;
    }

    function clearSurfaceName(name) {
        return name.replaceAll(' ', '_');
    }

    function createSurfaceDescId(surface) {
        if (typeof surface === 'string') {
            return 'surface-' + clearSurfaceName(surface);
        }
        return "surface-" + clearSurfaceName(surface.name);
    }

    function findCategoryElement(elem) {
        if (!elem) {
            return;
        }
        if (elem.className.indexOf('category') >= 0) {
            return elem;
        }
        return findCategoryElement(elem.parentElement);
    }

    function findSurfaceElement(elem) {
        if (!elem) {
            return;
        }
        if (elem.className.indexOf('surface-desc') >= 0) {
            return elem;
        }
        return findSurfaceElement(elem.parentElement);
    }

    function toggleCategory(cat) {
        console.log('Toggle:', cat);
        if (!cat) {
            return;
        }
        var catId = createCatId(cat);
        var elem = document.getElementById(catId);
        if (!elem) {
            console.error('No cat HTML element', cat, catId);
            return;
        }
        var toggleButtonValue;
        if (elem.className.indexOf('closed') >= 0) {
            toggleButtonValue = '-';
            cssUtil.remove(elem, 'closed');

        } else {
            toggleButtonValue = '+';
            cssUtil.add(elem, 'closed');
        }
        var controls = elem.getElementsByClassName('cat-control');

        if (controls.length) {
            controls.item(0).innerHTML = toggleButtonValue;
        }
    }

    function loadSurfaceIntoView(surface) {
        console.log('Load-Surface:', surface);
    }

    function createSurfaceHTML(surface,desc) {
        console.log('GEN-HTML:', surface)
        var res = '<div class="surface-desc closed" id="' + createSurfaceDescId(surface) + '">';
        res += '<div class="surface-title">';
        res +='<div><button class="surface-control">+</button></div>';
        res += '<div class="surface-name"'
        if(desc) {
            if (desc.id) {
                res += 'id="' + desc.id + '"';
            } else if (desc.file) {
                res += 'id="' + desc.file + '"';
            }
        }
        
        res += '>' + surface.name + '</div>';
        res += '</div>';
        res += '<div class="surface-conf">';
        res += '</div>';
        res += '</div>';
        return res;
    }
    function createCategoryHTML(cat) {
        var catCode = '<div class="category" id=' + createCatId(cat) + '>';
        catCode += '<div class="title"><span class="text">' + cat.catname + '</span>';
        catCode += '<div class="controls"><button class="cat-control">-</button></div>'
        catCode += '</div>';
        catCode += '<div class="surfaces">';

        var surfaceCodes = [];
        console.log('FILES:', cat.files);
        if (cat.files) {
            for (var fIdx = 0; fIdx < cat.files.length; fIdx++) {
                var file = cat.files[fIdx];
                if (file.success && file.content) {
                    surfaceCodes.push(createSurfaceHTML(file.content, file));
                } else {
                    console.error('Missing surface', fIdx);
                }
            }
        }
        catCode += surfaceCodes.join('');
        catCode += '</div>';
        catCode += '</div>';
        return catCode;
    }

    function categoryToggleHandler(e) {
        var catElem = findCategoryElement(e.target);
        if (catElem && catElem.id) {
            var cat = catElem.id.replace('cat-', '');
            cat && toggleCategory(cat);
        }
    }
    function surfaceClickHandler(e) {
        console.log('Click:', e.target);
        var elem = e.target;
        if(!elem) {
            return;
        }
        if(elem.className.indexOf('surface-control')>=0) {
            var parentElem = findSurfaceElement(elem);
            console.log('Control!');
            if(parentElem.className.indexOf('closed')>=0) {
                cssUtil.remove(parentElem, 'closed');
                elem.innerHTML = '-';
            } else {
                cssUtil.add(parentElem, 'closed');
                elem.innerHTML = '+';
            }
            return;
        }
        if(elem.className.indexOf('surface-name')>=0) {
            var parentElem = findSurfaceElement(elem);
            console.log('Select!', parentElem);
            var elems = document.getElementsByClassName('surface-name');
            for(var i=0; i < elems.length; i++) {
                var e = elems.item(i);
                cssUtil.remove(e, 'selected');
            }
            cssUtil.add(elem, 'selected');
            return;
        }
    }

    function addCategoryHandlers() {
        var elems = document.getElementsByClassName('cat-control');
        for (var sIdx = 0; sIdx < elems.length; sIdx++) {
            var e = elems.item(sIdx);
            e.addEventListener('click', categoryToggleHandler);
        }
        //todo add surface handlers
        elems = document.getElementsByClassName('surface-name');
        for (var sIdx = 0; sIdx < elems.length; sIdx++) {
            var e = elems.item(sIdx);
            e.addEventListener('click', surfaceClickHandler);
        }
        elems = document.getElementsByClassName('surface-control');
        for (var sIdx = 0; sIdx < elems.length; sIdx++) {
            var e = elems.item(sIdx);
            e.addEventListener('click', surfaceClickHandler);
        }
    }

    function removeCategoryHandlers() {

    }


    function loadAllSurfacesImpl(data) {
        if (!data.success || !data.data) {
            return;
        }
        let fIdx = 0, fLimit = 10;
        var catCodes = [];

        surfaces = data.data;


        for (var catIdx = 0; catIdx < data.data.length; catIdx++) {
            var category = data.data[catIdx];
            console.log('CAT:', category);

            for (var sIdx = 0; sIdx < category.files.length; sIdx++) {
                var f = category.files[sIdx];

                if (fIdx < fLimit) {
                    var content = codeGenerator.generate(f);
                    console.log('S:', content);
                }
                fIdx++;
            }
            catCodes.push(createCategoryHTML(category));
        }

        var elem = document.getElementById("sidebar");
        if (elem) {
            elem.innerHTML = catCodes.join("\n");
        }
        addCategoryHandlers();
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


