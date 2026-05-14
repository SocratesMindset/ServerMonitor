// app.js
async function loadStats() {
  const cpu = await fetch("http://localhost:8080/api/test")
    .then((r) => r.json())
    .then(() => {
      document.getElementById("cpu").textContent = "api test successful";
    });
}
document.getElementById("refresh").addEventListener("click", loadStats);
