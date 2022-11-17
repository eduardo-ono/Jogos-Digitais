function cssVar(name, value) {
  // if (name[0] != '-') name = '-' + name;
  if (value) document.documentElement.style.setProperty(name, value);
  return getComputedStyle(document.documentElement).getPropertyValue(name);
}

const defaultTileBackgroundColor = cssVar('--default-tile-background-color');
const tileBackgroundColor = cssVar('--tile-background-color');
const selectedTileBackgroundColor = cssVar('--selected-tile-background-color');
const crossTilesBackgroundColor = cssVar('--cross-tiles-background-color');

var numSelecionado = null;
var tileSelecionao = null;
var erros = 0;

var board = [
  '63-----81',
  '-2---3---',
  '----1743-',
  '-964--57-',
  '---762---',
  '---------',
  '---------',
  '---------',
  '---------'
];

var solucao = [
  '---------',
  '---------',
  '---------',
  '---------',
  '---------',
  '---------',
  '---------',
  '---------',
  '---------'
];

window.onload = () => setGame();
var selectedTile = null;

function setGame() {
  // Tabuleiro
  let board_div = document.getElementById('board');
  for (let row = 1; row <= 9; row++) {
    for (let col = 1; col <= 9; col++) {
      let tile = document.createElement('div');
      tile.id = row.toString() + col.toString();
      tile.classList.add('tile');
      // Set tile numbers
      setTileNumbers(tile);
      // OnMouseOver
      tile.addEventListener('mouseover', (ev) => {
        const el = ev.target;
        for (let j = 1; j <= 9; j++) {
          const elementId = document.getElementById(el.id[0] + j.toString());
          elementId.style.backgroundColor = crossTilesBackgroundColor;
        }
        for (let i = 1; i <= 9; i++) {
          const elementId = document.getElementById(i.toString() + el.id[1]);
          elementId.style.backgroundColor = crossTilesBackgroundColor;
        }
      });
      // OnMouseOut
      tile.addEventListener('mouseleave', (ev) => {
        const el = ev.target;
        for (let j = 1; j <= 9; j++) {
          const elementId = document.getElementById(el.id[0] + j.toString());
          elementId.style.backgroundColor = defaultTileBackgroundColor;
          console.log(elementId);
        }
        for (let i = 1; i <= 9; i++) {
          const elementId = document.getElementById(i.toString() + el.id[1]);
          elementId.style.backgroundColor = defaultTileBackgroundColor;
        }
      });
      // Tile OnClick
      tile.addEventListener('click', (ev) => {
        selectedTile = selectedTile ? null : ev.target;
      });
      board_div.appendChild(tile);
      // Tile DoubleClick
      tile.addEventListener('dblclick', (ev) => {
        if (selectedTile) {
          selectedTile.innerText = '';
          selectedTile = null;
        }
      });
    }
  }
  // Keypad
  let keypad = document.getElementById('keypad');
  for (let num = 1; num <= 9; num++) {
    let key = document.createElement('div');
    key.id = num;
    key.innerText = num;
    key.classList.add('key');
    key.addEventListener('dblclick', (ev) => {
      const clickedKey = ev.target;
      if (selectedTile) {
        selectedTile.innerText = clickedKey.id.toString();
      }
      selectedTile = null;
    }
    );
    keypad.appendChild(key);
  }
}

function setTileNumbers(tile) {
  for (let num = 1; num <= 9; num++) {
    let tileNumber = document.createElement('div');
    tileNumber.innerText = num.toString();
    tileNumber.classList.add('tile-number');
    tileNumber.id = 'num' + tile.id.toString();
    tile.appendChild(tileNumber);
  }
}
