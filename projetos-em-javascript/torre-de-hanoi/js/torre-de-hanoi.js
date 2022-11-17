var base = {
  width: 100,
  largura: 100,
  elemento: function () {
    let el = document.getElementById('base');
    el.style.backgroundColor = 'blue';
    el.style.width = '150px';
  }
}

base.elemento();

class pino {
  constructor(baseSize) {
    this.tamanho = 3;
    this.altura = 10;
  }

  mover() {

  }
}

const pino1 = new pino(base.largura);
const pino2 = new pino(base.largura);
const pino3 = new pino(base.largura);
