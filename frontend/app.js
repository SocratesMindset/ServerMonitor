// app.js
import {getSensors} from "./getSensors.js";
import {backendAPI} from "./config.js"

async function loadSensors() {
  const payload = await getSensors();
  
}

document.getElementById("temp").addEventListener("click", loadSensors);
