import { backendAPI } from "./config.js";

function groupSensors(data) {
  const resp = data.reduce((acc, item) => {
    if (!acc[`${item.chip}_${item.driverName}_${item.channel}`]) {
      if (item.type == "input") {
        acc[`${item.chip}_${item.driverName}_${item.channel}`] = {
          chip: item.chip,
          driverName: item.driverName,
          channel: item.channel,
          input: item.value,
        };
      } else if (item.type == "label") {
        acc[`${item.chip}_${item.driverName}_${item.channel}`] = {
          chip: item.chip,
          driverName: item.driverName,
          channel: item.channel,
          label: item.value,
        };
      }
    } else {
      if (item.type == "input") {
        acc[`${item.chip}_${item.driverName}_${item.channel}`].input =
          item.value;
      } else if (item.type == "label") {
        acc[`${item.chip}_${item.driverName}_${item.channel}`].label =
          item.value;
      }
    }
    return acc;
  }, {});
  return resp;
}

async function loadSensors() {
  const response = fetch(backendAPI + "/sensor")
    .then((r) => r.json())
    .then((data) => {
      console.log(groupSensors(data));
    });
}

loadSensors();
