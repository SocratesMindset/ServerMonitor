import { backendAPI } from "../config.js";

export async function loadPayload() {
  let req = await fetch(backendAPI + "/payload");
  req = await req.json();
  return req;
}
