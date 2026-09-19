// app.js
import { loadSensors } from "./getSensors.js";

async function Sensors() {
  const payload = await loadSensors();

}

document.getElementById("temp").addEventListener("click", Sensors);
