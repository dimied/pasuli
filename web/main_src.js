
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


