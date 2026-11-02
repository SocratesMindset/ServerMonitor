import { loadPayload } from "./getPayload.js";

async function setPayload()
{
	const parentEl = document.getElementById("stat");
	const payloadTuple = await loadPayload();
	let tempEl=document.createElement("div");
	tempEl.classList.add("stat");
	const texts = [
    	`load1: ${payloadTuple.load1}`,
    	`load5: ${payloadTuple.load5}`,
    `load15: ${payloadTuple.load15}`,
    `cores: ${payloadTuple.cores}`,
  		];

  texts.forEach(text => {
  			const p = document.createElement("p");
  			p.textContent=text;
  			p.classList.add("cardStat");
  			tempEl.appendChild(p);
  		});
  		parentEl.appendChild(tempEl);
    // console.log(sensor.label, sensor.input, sensor.chip,sensor.channel,sensor.driverName);
}

setPayload();
