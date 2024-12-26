//Main
var allFunctions = {};

(function () {
    console.log('INIT MAIN');
    var cssUtil = {
        add: function (elem, cls) {
            if (elem && cls) {
                cls = cls.trim();
                if (cls && elem.className.indexOf(cls) >= 0) {
                    return;
                }
                elem.className = (elem.className + ' ' + cls).trim();
            }
        },
        remove: function (elem, cls) {
            if (!elem || !cls) {
                return;
            }
            cls = cls.trim();
            if (!cls) {
                return;
            }
            var className = elem.className;
            var idx = className.indexOf(cls);
            if (idx >= 0) {
                var newCls = className.substring(0, idx).trim();
                idx += cls.length + 1;
                if (idx < className.length) {
                    newCls += " " + className.substring(idx).trim();
                }
                elem.className = newCls.trim();
            }
        }
    },
        docUtil = {
            byId: function (id) {
                return document.getElementById(id);
            }
        }, validViewTypes = ['3d', 'math'], currentType = 'math', allSurfaces = [];

    function addClickHandler(e, f) {
        e && f && e.addEventListener('click', f);
    }

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

    function selectView(type) {
        console.log('Type:', type);
        if (!type || !validViewTypes.includes(type)) {
            console.error('Invalid type:', type);
            return;
        }
        currentType = type;
        var elem1 = docUtil.byId('math'), elem2 = docUtil.byId('view3d');
        //return;
        if (currentType === '3d') {
            cssUtil.add(elem1, 'hidden');
            //cssUtil.remove(elem2, 'hidden');
        } else {
            //cssUtil.add(elem2, 'hidden');
            cssUtil.remove(elem1, 'hidden');
        }
    }

    function addButtonHandlers() {
        var elem, idx = 0, ids = ['select3d', 'selectmath'], f = docUtil.byId;

        for (; idx < ids.length; idx++) {
            elem = f(ids[idx]);
            if (elem) {
                elem.addEventListener('click', (function (type, otherElemId) {
                    return function (e) {
                        selectView(type);
                        cssUtil.remove(f(otherElemId), 'selected');
                        cssUtil.add(e.target, 'selected');
                    };

                }(validViewTypes[idx], ids[1 - idx])));
            }
        }
    }

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

    function findSurfaceByFile(fileName) {
        var i = 0, sIdx, cat, surface;
        if (fileName) {
            //console.log('ALLS:', allSurfaces);
            for (; i < allSurfaces.length; i++) {
                cat = allSurfaces[i];
                if (cat && cat.files) {
                    for (sIdx = 0; sIdx < cat.files.length; sIdx++) {
                        surface = cat.files[sIdx];
                        if (surface && surface.file === fileName) {
                            return surface;
                        }
                    }
                }
            }
        }
    }

    function loadSurfaceIntoView(surface) {
        console.log('Load-Surface:', surface);
        var surfaceFile;
        if (surface instanceof HTMLElement) {
            console.log('IS ELEM!');
            surfaceFile = surface.getAttribute('data-file');
        }
        if (surface.file) {
            surfaceFile = surface.file;
        }
        if (surfaceFile) {
            surface = findSurfaceByFile(surfaceFile);
        } else {
            console.warn("Can't recognize surface file!");
            return;
        }

        console.log('Surface:', surface);
    }

    function findElementByClassName(elem, cls) {
        if (!elem) {
            return;
        }
        if (elem.className.indexOf(cls) >= 0) {
            return elem;
        }
        return findElementByClassName(elem.parentElement, cls);
    }

    function findCategoryElement(elem) {
        return findElementByClassName(elem, 'category');
    }

    function findSurfaceElement(elem) {
        return findElementByClassName(elem, 'surface-desc');
    }

    function toggleButtonClass(elem, cls) {
        if (elem.className.indexOf(cls) >= 0) {
            cssUtil.remove(elem, cls);
            return '-';

        }
        cssUtil.add(elem, cls);
        return '+';
    }

    function toggleCategory(cat) {
        if (!cat) {
            return;
        }
        var catId = createCatId(cat);
        var elem = docUtil.byId(catId);
        if (!elem) {
            console.error('No cat HTML element', cat, catId);
            return;
        }
        var toggleButtonValue = toggleButtonClass(elem, 'closed'),
            controls = elem.getElementsByClassName('cat-control');

        if (controls.length) {
            controls.item(0).innerHTML = toggleButtonValue;
        }
    }

    function createSurfaceParamsHTML(surface) {
        var i, p, range, ex,res = '', rangeHTML = '', parts = [], paramName, value;
        if (surface.params && surface.params.length) {
            var ranges = surface.ranges || {},
                examples = surface.examples || [];

            for (i = 0; i < surface.params.length; i++) {
                paramName = surface.params[i];
                value='';
                if (paramName && ranges[paramName]) {
                    range = ranges[paramName];
                    rangeHTML = '<div class="surface-param-range">';
                    rangeHTML += range.min + ' - ' + range.max;
                    rangeHTML += '</div>';
                    if (range.max === range.min) {
                        value = '' + range.min;
                    }
                }
                if (!value && examples.length > 0) {
                    ex = examples[0];
                    if (ex && ex[paramName]) {
                        value = ex[paramName];
                    }
                }


                p = '<div class="surface-param">';
                p += '<div class="surface-param-name">' + paramName + '</div>';
                p += '<input type="text" class="surface-param-' + i + '" value="' + value + '" />';
                p += '</div>';


                p += rangeHTML;

                parts.push(p);
            }
            res += '<div class="surface-params">' + parts.join('') + '</div>';
        }
        return res;
    }

    function createSurfaceValsHTML(surface) {
        var i = 0, p, parts = [], res = '';
        if (isArray(surface.vals)) {

            for (; i < surface.vals.length; i++) {
                if (surface.vals[i].name && surface.vals[i].op) {
                    p = '<div>' + surface.vals[i].name;
                    p += '<span style="display:inline-block; margin: 0 0.5rem">:';
                    p += '</span>';
                    p += surface.vals[i].op;
                    p += '</div>';
                    parts.push(p);
                }
            }
            res = parts.join('');
        }
        return res;
    }

    function createSurfaceHTML(surface, desc) {
        //console.log('GEN-HTML:', surface, desc)
        var res = '', id = ' id="' + createSurfaceDescId(surface) + '" ';
        if (desc && desc.file) {
            res = ' data-file="' + desc.file + '" ';
        }

        res = '<div class="surface-desc closed" ' + id + res + '>';
        res += '<div class="surface-title">';
        res += '<div><button class="surface-control">+</button></div>';
        res += '<div class="surface-name"'
        if (desc) {
            if (desc.id) {
                res += 'id="' + desc.id + '"';
            } else if (desc.file) {
                res += 'id="' + desc.file + '"';
            }
        }

        res += '>' + surface.name + '</div>';
        res += '</div>';

        res += '<div class="surface-content">';

        var c = createSurfaceParamsHTML(surface);
        if (c) {
            res += '<div class="surface-conf">' + c + '</div>';
        }

        c = createSurfaceValsHTML(surface);
        if (c) {
            res += '<div class="surface-vals">' + c + '</div>';
        }

        res += '</div>';

        res += '</div>';
        return res;
    }
    function createCategoryHTML(cat) {
        var catCode = '<div class="category closed" id=' + createCatId(cat) + '>';
        catCode += '<div class="title"><span class="text">' + cat.catname + '</span>';
        catCode += '<div class="controls"><button class="cat-control">+</button></div>'
        catCode += '</div>';
        catCode += '<div class="surfaces">';

        var fIdx = 0, file, surfaceCodes = [];
        //console.log('FILES:', cat.files);
        if (isArray(cat.files)) {
            for (; fIdx < cat.files.length; fIdx++) {
                file = cat.files[fIdx];
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
        var parentElem, i, elems, elem = e.target;
        if (!elem) {
            return;
        }
        parentElem = findSurfaceElement(elem);
        if (!parentElem) {
            return;
        }
        if (elem.className.indexOf('surface-control') >= 0) {
            elem.innerHTML = toggleButtonClass(parentElem, 'closed');
            return;
        }
        if (elem.className.indexOf('surface-name') >= 0) {
            elems = document.getElementsByClassName('surface-name');
            for (i = 0; i < elems.length; i++) {
                cssUtil.remove(elems.item(i), 'selected');
            }
            cssUtil.add(elem, 'selected');
            loadSurfaceIntoView(parentElem);
        }
    }

    function addCategoryHandlers() {
        var sIdx, elems, f, handlerMapping = {
            'cat-control': categoryToggleHandler,
            'surface-name': surfaceClickHandler,
            'surface-control': surfaceClickHandler
        };

        for (var cls in handlerMapping) {
            if (handlerMapping.hasOwnProperty(cls)) {
                f = handlerMapping[cls];
                elems = document.getElementsByClassName(cls)
                for (sIdx = 0; sIdx < elems.length; sIdx++) {
                    addClickHandler(elems.item(sIdx), f);
                }
            }
        }
    }

    function removeCategoryHandlers() {

    }

    function isString(v) {
        return typeof v === 'string';
    }

    function isArray(v) {
        return !!v && Array.isArray(v);
    }

    function parseSurfaceDesc(surfaceDesc, fileDesc) {
        if (!surfaceDesc) {
            return;
        }
        if (surfaceDesc.params) {
            if (isString(surfaceDesc.params)) {
                surfaceDesc.params = surfaceDesc.params.split(',');
            }
        }
        var range, rName, min, max, numConstRanges = 0, numRanges = 0;
        if (surfaceDesc.ranges) {
            for (rName in surfaceDesc.ranges) {
                if (!surfaceDesc.ranges.hasOwnProperty(rName)) {
                    continue;
                }
                if (rName === 'u' || rName === 'v') {
                    continue;
                }
                range = surfaceDesc.ranges[rName];
                if (isArray(range)) {
                    if (range.length !== 2) {
                        console.error("Wrong range length: ", range.length, rName, surfaceDesc.name);
                    } else {
                        min = range[0];
                        max = range[1];
                        range = {
                            'min': min,
                            'max': max
                        };
                    }
                } else if (typeof range === 'number') {
                    range = {
                        'min': range,
                        'max': range
                    };
                    ++numConstRanges;
                }
                ++numRanges;
                surfaceDesc.ranges[rName] = range;
            }
        }
        if (surfaceDesc.params && numRanges > 0 && (numRanges != numConstRanges) && (!surfaceDesc.examples || !surfaceDesc.examples.length)) {
            console.warn("Missing examples: ", surfaceDesc.name, fileDesc);
        }
    }

    function parseCategory(cat) {
        if (!cat || !Array.isArray(cat.files)) {
            return;
        }
        var fIdx = 0, fileDesc, surfaceDesc;
        //console.log('PARSE-CAT:', cat);
        for (var fIdx = 0; fIdx < cat.files.length; fIdx++) {
            fileDesc = cat.files[fIdx];
            if (fileDesc && fileDesc.content) {
                surfaceDesc = fileDesc.content;
                //console.log(cat.catname, surfaceDesc.name, surfaceDesc);
                parseSurfaceDesc(surfaceDesc, fileDesc);
            }
        }
    }


    function loadAllSurfacesImpl(data) {
        if (!data.success || !data.data) {
            return;
        }
        let catIdx, category, sIdx, f, elem, fIdx = 0, fLimit = 10, catCodes = [];

        allSurfaces = data.data;

        for (catIdx = 0; catIdx < data.data.length; catIdx++) {
            category = data.data[catIdx];
            console.log('CAT:', category);
            parseCategory(category);

            if (category.files) {
                for (sIdx = 0; sIdx < category.files.length; sIdx++) {
                    f = category.files[sIdx];

                    if (fIdx < fLimit) {
                        var content = codeGenerator.generate(f);
                        //console.log('S:', content);
                    }
                    fIdx++;
                }
            }
            catCodes.push(createCategoryHTML(category));
        }

        elem = document.getElementById("sidebar-content");
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
        console.log('DOM loaded');
        addButtonHandlers();
        loadAllSurfaces();
        setTimeout(function () {
            if (!window.my3d) {
                console.error("Missing: my3d");
                return;
            }
            window.my3d.myInit3D('view3d', true);
        }, 2000);
    });
}());


