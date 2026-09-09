import { backendAPI } from "./config.js"

async function loadSensors() {
  const response = fetch(backendAPI + "/sensor")
    .then((r) => r.json()).then((data) => { console.log(data); data.reduce((acc,item)=>{ if (!item.chip){}},{});
    });
}

loadSensors();
