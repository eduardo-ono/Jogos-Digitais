/*
  Referências: https://editor.p5js.org/Jeff-Aporta/sketches/Md52rRziS
               https://www.youtube.com/watch?v=noe_P35Md5M
*/

function setup() {
  createCanvas(1280, 720);
}

function draw() {
  background("lightgray");
  dibujarArbol(width / 2, height, 0, 100);
}

function dibujarArbol(x, y, angulo, radio) {
  if (radio < 1) {
    return;
  }
  if (radio < 5) {
    stroke("darkgreen");
  } else {
    stroke("black");
  }
  let x2 = x + radio * cos(angulo - PI / 2);
  let y2 = y + radio * sin(angulo - PI / 2);
  strokeWeight(radio / 10);
  line(x, y, x2, y2);
  for (let i = 0; i < 3; i++) {
    dibujarArbol(
      x2,
      y2,
      angulo + random(-PI / 4, PI / 4),
      radio * random(0.2, 1)
    );
  }
}
