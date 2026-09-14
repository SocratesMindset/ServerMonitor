import { backendAPI } from "./config.js";

const mockSensors = [
  {
    driverName: "k10temp",
    chip: "hwmon0",
    channel: 1,
    value: "Tctl",
    type: "label",
  },
  {
    driverName: "k10temp",
    chip: "hwmon0",
    channel: 1,
    value: "45000",
    type: "input",
  },
  {
    driverName: "k10temp",
    chip: "hwmon0",
    channel: 2,
    value: "Tccd1",
    type: "label",
  },
  {
    driverName: "k10temp",
    chip: "hwmon0",
    channel: 2,
    value: "42500",
    type: "input",
  },
  {
    driverName: "nvme",
    chip: "hwmon1",
    channel: 1,
    value: "Composite",
    type: "label",
  },
  {
    driverName: "nvme",
    chip: "hwmon1",
    channel: 1,
    value: "38000",
    type: "input",
  },
  {
    driverName: "nvme",
    chip: "hwmon1",
    channel: 2,
    value: "Sensor 1",
    type: "label",
  },
  {
    driverName: "nvme",
    chip: "hwmon1",
    channel: 2,
    value: "36000",
    type: "input",
  },
];

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
console.log(groupSensors(mockSensors));

async function loadSensors() {
  const response = fetch(backendAPI + "/sensor")
    .then((r) => r.json())
    .then((data) => {
      console.log(data);
      data.reduce((acc, item) => {
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
    });
}

