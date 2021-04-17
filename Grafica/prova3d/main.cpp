#include <bits/stdc++.h>
#include <graphics.h>
#include <strstream>
using namespace std;

struct vec3d {
    float x,y,z;
};

struct triangle {
    vec3d p[3];

    wchar_t sym;
    short col;
};

struct mesh {
    vector<triangle> tris;

    bool LoadFromObjectFile(string sFileName) {
        ifstream f(sFileName);
        if(!f.is_open())
            return false;

        vector<vec3d> verts;

        while(!f.eof()) {
            char line[128];
            f.getline(line,128);

            strstream s;
            s << line;

            char junk;

            if(line[0] == 'v') {
                vec3d v;
                s >> junk >> v.x >> v.y >> v.z;
                verts.push_back(v);
            }

            if(line[0] == 'f') {
                int f[3];
                s >> junk >> f[0] >> f[1] >> f[2];
                tris.push_back({verts[f[0]-1], verts[f[1]-1], verts[f[2]-1]});
            }
        }
        return true;
    }
};

struct mat4x4 {
    float m[4][4] = {0};
};

void multiplyMatrixVector(vec3d &i, vec3d &o, mat4x4 &m) {
    o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
    o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
    o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
    float w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];

    if(w != 0.0f) {
        o.x /= w;
        o.y /= w;
        o.z /= w;
    }
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int c1, int c2) {
    setcolor(c1);

    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);

    return;

    if(y2 < y1) {
        int temp = y1;
        y1 = y2;
        y2 = temp;

        temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if(y3 < y1) {
        int temp = y1;
        y1 = y3;
        y3 = temp;

        temp = x1;
        x1 = x3;
        x3 = temp;
    }
    if(y3 < y2) {
        int temp = y3;
        y3 = y2;
        y2 = temp;

        temp = x3;
        x3 = x2;
        x2 = temp;
    }
}

int main() {
    initwindow(1024,720);

    mesh meshCube;

    meshCube.LoadFromObjectFile("modello.obj");

    // projection matrix
    float fNear = 0.1f;
    float fFar = 1000.0f;
    float fFov = 90.0f;
    float fAspectRatio = (float)getmaxy()/(float)getmaxx();
    float fFovRad = 1.0f / tanf(fFov*0.5f/180.0f*3.1415);
    float fTheta = 0.0f;

    mat4x4 matProj, matRotZ, matRotX, matRotY;

    vec3d vCamera= {0,0,0};

    matProj.m[0][0] = fAspectRatio * fFovRad;
    matProj.m[1][1] = fFovRad;
    matProj.m[2][2] = fFar / (fFar - fNear);
    matProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
    matProj.m[2][3] = 1.0f;
    matProj.m[3][3] = 0.0f;

    do {


        fTheta -= 0.03f;

        matRotZ.m[0][0] = cosf(fTheta);
        matRotZ.m[0][1] = sinf(fTheta);
        matRotZ.m[1][0] = -sinf(fTheta);
        matRotZ.m[1][1] = cosf(fTheta);
        matRotZ.m[2][2] = 1;
        matRotZ.m[3][3] = 1;

        matRotX.m[0][0] = 1;
        matRotX.m[1][1] = cosf(fTheta * 0.5f);
        matRotX.m[1][2] = sinf(fTheta * 0.5f);
        matRotX.m[2][1] = -sinf(fTheta * 0.5f);
        matRotX.m[2][2] = cosf(fTheta * 0.5f);
        matRotX.m[3][3] = 1;

        matRotY.m[0][0] = cosf(fTheta * 0.5f);;
        matRotY.m[0][2] = sinf(fTheta * 0.5f);
        matRotY.m[1][1] = 1;
        matRotY.m[2][0] = -sinf(fTheta * 0.5f);
        matRotY.m[2][2] = cosf(fTheta * 0.5f);
        matRotY.m[3][3] = 1;

        vector<triangle> vecTrianglesToRaster;

        // draw triangles
        for(auto tri: meshCube.tris) {
            triangle triProjected, triTranslated, triRotatedZ, triRotatedZX, triRotatedZXY;

            multiplyMatrixVector(tri.p[0], triRotatedZ.p[0], matRotZ);
            multiplyMatrixVector(tri.p[1], triRotatedZ.p[1], matRotZ);
            multiplyMatrixVector(tri.p[2], triRotatedZ.p[2], matRotZ);

            multiplyMatrixVector(triRotatedZ.p[0], triRotatedZX.p[0], matRotX);
            multiplyMatrixVector(triRotatedZ.p[1], triRotatedZX.p[1], matRotX);
            multiplyMatrixVector(triRotatedZ.p[2], triRotatedZX.p[2], matRotX);

            multiplyMatrixVector(triRotatedZX.p[0], triRotatedZXY.p[0], matRotY);
            multiplyMatrixVector(triRotatedZX.p[1], triRotatedZXY.p[1], matRotY);
            multiplyMatrixVector(triRotatedZX.p[2], triRotatedZXY.p[2], matRotY);

            triTranslated = triRotatedZXY;
            triTranslated.p[0].z += 8.0f;
            triTranslated.p[1].z += 8.0f;
            triTranslated.p[2].z += 8.0f;

            vec3d normal, line1, line2;
			line1.x = triTranslated.p[1].x - triTranslated.p[0].x;
			line1.y = triTranslated.p[1].y - triTranslated.p[0].y;
			line1.z = triTranslated.p[1].z - triTranslated.p[0].z;

			line2.x = triTranslated.p[2].x - triTranslated.p[0].x;
			line2.y = triTranslated.p[2].y - triTranslated.p[0].y;
			line2.z = triTranslated.p[2].z - triTranslated.p[0].z;

			normal.x = line1.y * line2.z - line1.z * line2.y;
			normal.y = line1.z * line2.x - line1.x * line2.z;
			normal.z = line1.x * line2.y - line1.y * line2.x;

			// It's normally normal to normalise the normal
			float l = sqrtf(normal.x*normal.x + normal.y*normal.y + normal.z*normal.z);
			normal.x /= l; normal.y /= l; normal.z /= l;

			//if (normal.z < 0)
			if(normal.x * (triTranslated.p[0].x - vCamera.x) +
			   normal.y * (triTranslated.p[0].y - vCamera.y) +
			   normal.z * (triTranslated.p[0].z - vCamera.z) < -0.1f)
			{
			    vec3d light_direction = {0.0f, 0.0f, -1.0f};
			    float l = sqrtf(light_direction.x*light_direction.x + light_direction.y*light_direction.y + light_direction.z*light_direction.z);
			    light_direction.x /= l;
			    light_direction.y /= l;
			    light_direction.z /= l;

			    float dp = normal.x * light_direction.x + normal.y * light_direction.y + normal.z * light_direction.z;
                //cout << int(dp*13.0f) << endl;

                multiplyMatrixVector(triTranslated.p[0],triProjected.p[0],matProj);
                multiplyMatrixVector(triTranslated.p[1],triProjected.p[1],matProj);
                multiplyMatrixVector(triTranslated.p[2],triProjected.p[2],matProj);

                triProjected.p[0].x += 1.0f;
                triProjected.p[0].y += 1.0f;

                triProjected.p[1].x += 1.0f;
                triProjected.p[1].y += 1.0f;

                triProjected.p[2].x += 1.0f;
                triProjected.p[2].y += 1.0f;


                triProjected.p[0].x *= 0.5 *(float)getmaxx();
                triProjected.p[0].y *= 0.5 *(float)getmaxy();

                triProjected.p[1].x *= 0.5 *(float)getmaxx();
                triProjected.p[1].y *= 0.5 *(float)getmaxy();

                triProjected.p[2].x *= 0.5 *(float)getmaxx();
                triProjected.p[2].y *= 0.5 *(float)getmaxy();



                int triColor;
                switch (int(dp*3.0f)){
                    case 0:
                        triColor = DARKGRAY;
                        break;
                    case 1:
                        triColor = LIGHTGRAY;
                        break;
                    case 2:
                        triColor = WHITE;
                        break;
                    default:
                        triColor = RED;
                        break;
                }

                triProjected.col = triColor;
                vecTrianglesToRaster.push_back(triProjected);
            }
        }
        sort(vecTrianglesToRaster.begin(), vecTrianglesToRaster.end(), [](triangle &t1, triangle &t2) {
            float z1 = (t1.p[0].z + t1.p[1].z + t1.p[2].z) /3.0f;
            float z2 = (t2.p[0].z + t2.p[1].z + t2.p[2].z) /3.0f;
            return z1 > z2;
        });

        clearviewport();
        for(auto &triProjected : vecTrianglesToRaster) {
            /*setcolor(triProjected.col);
            setfillstyle(SOLID_FILL,triProjected.col);
            int arr[] {ù};
            fillpoly(3,arr);*/
            drawTriangle(triProjected.p[0].x, triProjected.p[0].y,
                         triProjected.p[1].x, triProjected.p[1].y,
                         triProjected.p[2].x, triProjected.p[2].y,
                         BLUE,WHITE);
        }

        delay(5);
    }while(!kbhit());
    getch();
    return 0;
}
