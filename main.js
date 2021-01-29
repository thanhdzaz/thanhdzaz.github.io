var rota = null;
flag = true;
i = 0;
audio = document.getElementById("audio_hie");
match = null;

document.getElementById('img').onclick = () => {
    var bar = document.getElementById("control_bar");
    if (flag == true) {
        if (i < 1) {
            context = new AudioContext();
            match = context.createAnalyser();
            context.createMediaElementSource(audio).connect(match);
            match.connect(context.destination);
            i = 100;
        }
        bar.style.opacity = "1";
        bar.style.bottom = "100px";
        audio.play();
        loop();
        flag = false;
        rota = setInterval(rotator, 70);
    } else {
        clearInterval(rota);
        audio.pause();
        bar.style.opacity = "0";
        bar.style.bottom = "-100px";
        flag = true;
    }
};
function loop() {
    window.requestAnimationFrame(loop);

    fbc = new Uint8Array(match.frequencyBinCount);
    match.getByteFrequencyData(fbc);
    avg = fbc.reduce((a, b) => a + b, 0) / fbc.length;

    // document.body.style.backgroundColor =
    //   "rgb(" + 2 * avg + "," + avg + "," + avg * 1.2 + ")";
    // x.SPEED = (avg!==0) ? avg/7 : 3;  // incree Speed
    // console.log(x.SPEED);
    document.getElementById("img").style.boxShadow = "0 0 " + avg * 1.4 + "px rgb(167, 77, 77,0.8)";
    document.getElementsByClassName('horizon')[0].style.boxShadow = "0 0 " + avg * 1.2 + "px rgb(114, 245, 250)";
    document.getElementsByClassName('horizon')[1].style.boxShadow = "0 0 " + avg * 1.2 + "px rgb(114, 245, 250)";
    document.getElementById('audio_hie').style.boxShadow = "0 0 "+avg / 2 + "px rgb(114, 245, 250)";
    // document.getElementById("img").style.height = avg * 5 + "px";
}
var hie = true;
var deg = 0;
function rotator() {
    var div = document.getElementById("img");
    deg = deg + 1;

    if (audio.paused) {
        clearInterval(rota);
        hie = !hie;
        flag = !flag;
    } else {
        if (hie == false) {
            console.log("haha");
            rota = setInterval(rotator, 70);
            hie = !hie;
        }
    }
    div.style.webkitTransform = "rotate(" + deg + "deg)";
    div.style.mozTransform = "rotate(" + deg + "deg)";
    div.style.msTransform = "rotate(" + deg + "deg)";
    div.style.oTransform = "rotate(" + deg + "deg)";
    div.style.transform = "rotate(" + deg + "deg)";
    // console.log(deg);
}


function delay(URL) {
    x.SPEED = 40;
    setTimeout(function () { window.location = URL }, 400);
}