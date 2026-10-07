import { loadSensors } from "./getSensors.js";

async function setSensors()
{
	const parentEl = document.getElementById("stat");
	const groupedSensors = await loadSensors();
	for (const sensor of Object.values(groupedSensors)) {
		let tempEl=document.createElement("div");
		tempEl.classList.add("stat");
		const texts = [
    	`Название: ${sensor.driverName}`,
    	`Чип: ${sensor.chip}`,
    	`Канал: ${sensor.channel}`,
    	`Тип: ${sensor.label}`,
    	`Значение: ${sensor.input}`,
  		];
  		texts.forEach(text=>{
  			const p = document.createElement("p");
  			p.textContent=text;
  			p.classList.add("cardStat");
  			tempEl.appendChild(p);
  		});
  		parentEl.appendChild(tempEl);
    // console.log(sensor.label, sensor.input, sensor.chip,sensor.channel,sensor.driverName);
	}
}

setSensors();