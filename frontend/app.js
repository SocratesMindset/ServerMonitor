// app.js
async function loadStats() {
  const cpu = await fetch("http://localhost:8080/api/test")
    .then((r) => r.json())
    .then(() => {
      document.getElementById("cpu").textContent = "api test successful";
    });
}

async function loadTemp() {
  const temperature = fetch("http://localhost:8080/api/temperature")
    .then((r) => r.json())
    .then((data) => {
      document.getElementById("templb").textContent = data.temperature;
    });
}
document.getElementById("refresh").addEventListener("click", loadStats);
document.getElementById("temp").addEventListener("click", loadTemp);
