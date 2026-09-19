#include "ofApp.h"
#include "RayGenerator.h"

/*
PROMPT #1:
set 640x480 canvas size

PROMPT #2:

is the code in ofApp.h correct also what's the difference between .h and .cpp

PROMPT #3:

declare ofImage/ofpixels object and allocate it in setup(). call img.draw(0, 0) n draw()

PROMPT #4:

for (int j = 0; j < 480; j++) {
    for (int i = 0; i < 640; i++) {
        Ray ray = generateRay(i, j, 640, 480, perspectiveMode);
    }
}

add this to a render() function


*/

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(640, 480);
    img.allocate(640, 480, OF_IMAGE_COLOR);
    perspectiveMode = false;
    rendered = false;
    redSphere = new Sphere(0.75f, Vec3(0, 0, 3), Vec3(1, 0, 0));
    greenEllipsoid = new Ellipsoid(Vec3(-1, 0.5f, 2.5f), 0.5f, 0.6f, 0.8f, Vec3(0, 1, 0));
    blueEllipsoid = new Ellipsoid(Vec3(1.5f, -0.5f, 1.8f), 0.7f, 0.5f, 0.6f, Vec3(0, 0, 1));

    grayPlane = new Plane(Vec3(0, -1.4f, 0), Vec3(0, 1, 0), Vec3(0.5f, 0.5f, 0.5f));

    scene.push_back(redSphere);
    scene.push_back(greenEllipsoid);
    scene.push_back(blueEllipsoid);
    scene.push_back(grayPlane);

    render();
    rendered = true;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::render(){
    Vec3 bgColor(0.2f, 0.2f, 0.2f);
    ofPixels pixels;
    pixels.allocate(640, 480, OF_IMAGE_COLOR);

    for (int j = 0; j < 480; j++) {
        for (int i = 0; i < 640; i++) {
            Ray ray = generateRay(i, j, 640, 480, perspectiveMode);

            float closestT = -1.0f;
            Object* closestObject = nullptr;
            Vec3 hitPoint;
            Vec3 hitNormal;

            float t;

            t = redSphere->intersect(ray);
            if (t > 0 && (closestT < 0 || t < closestT)) {
                closestT = t;
                closestObject = redSphere;
                hitPoint = ray.evaluate(t);
                hitNormal = redSphere->getNormal(hitPoint);
            }

            t = greenEllipsoid->intersect(ray);
            if (t > 0 && (closestT < 0 || t < closestT)) {
                closestT = t;
                closestObject = greenEllipsoid;
                hitPoint = ray.evaluate(t);
                hitNormal = greenEllipsoid->getNormal(hitPoint);
            }

            t = blueEllipsoid->intersect(ray);
            if (t > 0 && (closestT < 0 || t < closestT)) {
                closestT = t;
                closestObject = blueEllipsoid;
                hitPoint = ray.evaluate(t);
                hitNormal = blueEllipsoid->getNormal(hitPoint);
            }

            t = grayPlane->intersect(ray);
            if (t > 0 && (closestT < 0 || t < closestT)) {
                closestT = t;
                closestObject = grayPlane;
                hitPoint = ray.evaluate(t);
                hitNormal = grayPlane->getNormal(hitPoint);
            }

            Vec3 color;
            if (closestT < 0) {
                color = bgColor;
            } else {
                color = shade(hitPoint, hitNormal, closestObject, scene);
            }

            Vec3 clampedColor = clampColor(color);
            int r = (int)clampedColor.x;
            int g = (int)clampedColor.y;
            int b = (int)clampedColor.z;

            pixels.setColor(i, j, ofColor(r, g, b));
        }
    }

    img.setFromPixels(pixels);
    img.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    img.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
