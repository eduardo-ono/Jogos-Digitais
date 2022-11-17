
var jogador = document.getElementById('jogador');
var bloco = document.getElementById('bloco');

function pular() {
    if (jogador.classList != 'animate')
        jogador.classList.add('animate');
    setTimeout(() => {
        jogador.classList.remove('animate');
    }, 500);
}

document.onclick = () => {
    pular();
}

var checarMorte = setInterval(() => {
    jogadorTop = parseInt(window.getComputedStyle(jogador).getPropertyValue('top'));
    blocoLeft = parseInt(window.getComputedStyle(bloco).getPropertyValue('left'));
    if (blocoLeft > 0 && blocoLeft < 20 && jogadorTop >= 300)
        bloco.style.animation = 'none';
}, 10);
