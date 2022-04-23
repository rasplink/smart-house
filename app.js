const status = document.getElementById("status");
const domain = "http://192.168.1.55/pin";
let isLightChecked = false;
let isFanChecked = false;
function light(elm) {
  if (!isLightChecked) {
    isLightChecked = true;
    elm.checked = true;
  } else {
    isLightChecked = false;
    elm.checked = false;
  }
  console.log(isLightChecked);
  if (isLightChecked) init(domain + "7/on");
  else init(domain + "7/off");
}
function fan(elm) {
  if (!isFanChecked) {
    isFanChecked = true;
    elm.checked = true;
  } else {
    isFanChecked = false;
    elm.checked = false;
  }
  console.log(isFanChecked);
  if (isFanChecked) init(domain + "6/on");
  else init(domain + "6/off");
}
function init(link) {
  fetch(link)
    .then(console.log)
    .catch(err => {
      status.innerHTML = err;
      status.style.display = "block";
      setTimeout(() => (status.style.display = "none"), 3000);
    });
}
