function showFallAlert() {
  const alert = document.getElementById("fallAlert");
  alert.classList.remove("hidden");

  ["accelXBox", "accelYBox", "accelZBox"].forEach((id) => {
    document
      .getElementById(id)
      .classList.add("ring-4", "ring-red-400", "animate-pulse");
  });

  const li = document.createElement("li");
  li.innerText = "Fall detected at " + new Date().toLocaleString();
  document.getElementById("fallHistoryList").prepend(li);

  setTimeout(() => {
    alert.classList.add("hidden");
    ["accelXBox", "accelYBox", "accelZBox"].forEach((id) => {
      document
        .getElementById(id)
        .classList.remove("ring-4", "ring-red-400", "animate-pulse");
    });
  }, 10000);
}
