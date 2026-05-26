// app.js
var backendAPI = "http://localhost:8080/api";
async function loadStats() {
  const cpu = await fetch(backendAPI + "/test")
    .then((r) => r.json())
    .then(() => {
      document.getElementById("cpu").textContent = "api test successful";
    });
}

async function loadTemp() {
  await fetch(backendAPI + "/temperature")
    .then((r) => r.json())
    .then((data) => {
      document.getElementById("templb").textContent = data.temperature;
    });
}

async function loadPayload() {
  const payLoad = fetch(backendAPI + "/payload")
    .then((res) => res.json())
    .then((data) => {
      document.getElementById("payLoad").textContent = data.payload;
    });
}
document.getElementById("refresh").addEventListener("click", loadStats);
document.getElementById("temp").addEventListener("click", loadTemp);
