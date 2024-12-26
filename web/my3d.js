import * as THREE from '/three.module.js';
//import Stats from 'three/addons/libs/stats.module.js';
function loadMesh(state, mesh) {
    state.mesh = mesh;
}

function ThreeRenderer(containerId) {
    var state = {
        containerId: containerId,
        getSizes: function () {
            var container = document.getElementById(containerId);
            return container.getBoundingClientRect();
        }
    };

}

function myInit3D(containerId, useElementSizes) {

    let state = {
        container: document.getElementById(containerId)
    };

    function getSizes() {
        if (useElementSizes) {
            return state.container.getBoundingClientRect();
        }
        return {
            width: window.innerWidth,
            height: window.innerWidth
        };
    }

    let aspect;

    let camera, scene, renderer, mesh;
    let cameraRig, activeCamera, activeHelper;
    let cameraPerspective, cameraOrtho;
    let cameraPerspectiveHelper, cameraOrthoHelper;
    const frustumSize = 600;

    function updateAspectRatio() {
        var sizes = getSizes();
        aspect = sizes.width / sizes.height;
    }

    updateAspectRatio();
    init();

    function init() {
        scene = new THREE.Scene();
        camera = new THREE.PerspectiveCamera(50, 0.5 * aspect, 1, 10000);
        camera.position.z = 2500;

        cameraPerspective = new THREE.PerspectiveCamera(50, 0.5 * aspect, 150, 1000);

        cameraPerspectiveHelper = new THREE.CameraHelper(cameraPerspective);
        scene.add(cameraPerspectiveHelper);

        //
        cameraOrtho = new THREE.OrthographicCamera(0.5 * frustumSize * aspect / - 2, 0.5 * frustumSize * aspect / 2, frustumSize / 2, frustumSize / - 2, 150, 1000);

        cameraOrthoHelper = new THREE.CameraHelper(cameraOrtho);
        scene.add(cameraOrthoHelper);

        //
        activeCamera = cameraPerspective;
        activeHelper = cameraPerspectiveHelper;

        // counteract different front orientation of cameras vs rig
        cameraOrtho.rotation.y = Math.PI;
        cameraPerspective.rotation.y = Math.PI;

        cameraRig = new THREE.Group();

        cameraRig.add(cameraPerspective);
        cameraRig.add(cameraOrtho);

        scene.add(cameraRig);

        //
        /*
                mesh = new THREE.Mesh(
                    new THREE.SphereGeometry(100, 16, 8),
                    new THREE.MeshBasicMaterial({ color: 0xffffff, wireframe: true })
                );
                scene.add(mesh);
                */
        //

        const geometry = new THREE.BufferGeometry();
        const vertices = [];

        for (let i = 0; i < 10000; i++) {

            vertices.push(THREE.MathUtils.randFloatSpread(2000)); // x
            vertices.push(THREE.MathUtils.randFloatSpread(2000)); // y
            vertices.push(THREE.MathUtils.randFloatSpread(2000)); // z

        }

        geometry.setAttribute('position', new THREE.Float32BufferAttribute(vertices, 3));

        const particles = new THREE.Points(geometry, new THREE.PointsMaterial({ color: 0x888888 }));
        scene.add(particles);

        //

        var sizes = getSizes();
        renderer = new THREE.WebGLRenderer({ antialias: true });
        renderer.setPixelRatio(window.devicePixelRatio);
        renderer.setSize(sizes.width, sizes.height);
        renderer.setAnimationLoop(animate);
        state.container.appendChild(renderer.domElement);

        renderer.setScissorTest(true);

        //
        //stats = new Stats();
        //container.appendChild(stats.dom);
        //
        window.addEventListener('resize', onWindowResize);
        document.addEventListener('keydown', onKeyDown);

        console.log("myInit3D done!");
    }

    //

    function onKeyDown(event) {

        switch (event.keyCode) {

            case 79: /*O*/

                activeCamera = cameraOrtho;
                activeHelper = cameraOrthoHelper;
                break;

            case 80: /*P*/

                activeCamera = cameraPerspective;
                activeHelper = cameraPerspectiveHelper;

                break;
        }
    }

    //

    function onWindowResize() {

        var sizes = getSizes();
        updateAspectRatio();

        renderer.setSize(sizes.width, sizes.height);

        camera.aspect = 0.5 * aspect;
        camera.updateProjectionMatrix();

        cameraPerspective.aspect = 0.5 * aspect;
        cameraPerspective.updateProjectionMatrix();

        cameraOrtho.left = - 0.5 * frustumSize * aspect / 2;
        cameraOrtho.right = 0.5 * frustumSize * aspect / 2;
        cameraOrtho.top = frustumSize / 2;
        cameraOrtho.bottom = - frustumSize / 2;
        cameraOrtho.updateProjectionMatrix();
    }

    //
    function animate() {

        render();
        //stats.update();

    }

    function render() {

        const r = Date.now() * 0.0005;
        if (!state.mesh) {
            return;
        }
        var mesh = state.mesh;

        mesh.position.x = 700 * Math.cos(r);
        mesh.position.z = 700 * Math.sin(r);
        mesh.position.y = 700 * Math.sin(r);

        mesh.children[0].position.x = 70 * Math.cos(2 * r);
        mesh.children[0].position.z = 70 * Math.sin(r);

        if (activeCamera === cameraPerspective) {

            cameraPerspective.fov = 35 + 30 * Math.sin(0.5 * r);
            cameraPerspective.far = mesh.position.length();
            cameraPerspective.updateProjectionMatrix();

            cameraPerspectiveHelper.update();
            cameraPerspectiveHelper.visible = true;

            cameraOrthoHelper.visible = false;

        } else {

            cameraOrtho.far = mesh.position.length();
            cameraOrtho.updateProjectionMatrix();

            cameraOrthoHelper.update();
            cameraOrthoHelper.visible = true;

            cameraPerspectiveHelper.visible = false;

        }

        cameraRig.lookAt(mesh.position);
        //
        activeHelper.visible = false;
        var sizes = getSizes();
        var width = sizes.width/2, height = sizes.height;

        renderer.setClearColor(0x000000, 1);
        renderer.setScissor(0, 0, width, height);
        renderer.setViewport(0, 0, width, height);
        renderer.render(scene, activeCamera);
        //
        activeHelper.visible = true;

        renderer.setClearColor(0x111111, 1);
        renderer.setScissor(width, 0, width, height);
        renderer.setViewport(width, 0, width, height);
        renderer.render(scene, camera);

    }

    state.scene = scene;
    state.renderer = renderer;
    return state;
}

console.log('my3d loaded');

window.my3d = {
    myInit3D: myInit3D,
    loadMesh: loadMesh
};
