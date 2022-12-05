dunit = 0;
const GROUP_SWITCH = 1
const GROUP_HT = 2
const GROUP_MOTION =  3
sensor_category = 0;

const CBLUE = "#33c5ff"
const CYELLOW = "#FFD333"
const CRED = "#FF6D33"

sensor_data_array = [];
sensor_info = [];
sensors_name = [];

function loadSensors() {
  
  getSystemStatus();
  if( document.getElementById("lista").innerHTML == "") return;
  const xhttp = new XMLHttpRequest();
  xhttp.addEventListener('progress', handleSensorLoading);
  xhttp.open("GET", "/raw", true);
  xhttp.send();
  
  xhttp.onload = function() {
    if(this.responseText){
      clearPage();
      var sensors = this.responseText.split('\n');
      sensors.forEach( function(item) {
        AddSensorBlock(item);
      });
    }else{
      document.getElementById("lista").innerHTML = "<div class='pt-3 text-center' style='width:100%!important'><p>No sensors have been detected.</p></div>";
    }
  }
}

function loadSensorsName(){

  const xhttp = new XMLHttpRequest();
  xhttp.open("GET", "/names", true);
  xhttp.send();
  
  xhttp.onload = function() {
    if(this.responseText){
      sensors_name = [];
      var sensors = this.responseText.split('\n');
      sensors.forEach( function(item) {
        const [sid,sname] = item.split(','); 
        if( sid && sname && sname != "") sensors_name[sid] = sname.substring(0,15).toUpperCase();
      });
    }else{
      document.getElementById("lista").innerHTML = "<div class='pt-3 text-center' style='width:100%!important'><p>No sensors have been detected.</p></div>";
    }
  } 
}

function getSensorReadableName(id){

  if( sensors_name[id] && sensors_name[id].length > 1 ) return sensors_name[id];
  else return id;
}

function deleteSensor(id){

  if (confirm("Delete?")) {
    const xhttp = new XMLHttpRequest();
   xhttp.open("GET", "/delete?id="+id, true);
   xhttp.send();
  
   xhttp.onload = function() {
     if(this.responseText == "1") loadSensor(id);
     else alert('Error deleting file!');
    } 
  }
}

function recheckSDCard(id){

  const xhttp = new XMLHttpRequest();
  xhttp.open("GET", "/retry_sd", true);
  xhttp.send();
  xhttp.onload = function() {
    if(this.responseText == "1"){
      getSystemStatus();
      loadSensors();
    }
  }
}


function reboot(){
  
  if (confirm("Reboot?")) {
    const xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/reboot", true);
    xhttp.send();
    document.getElementsByTagName("main")[0].innerHTML = "<div class='col-12 mt-5' style='width:100%!important;text-align:center;color:#aaa;'>restarting  ...</div>";
  }
  return false;
}

function enableReceiverOTA(){

  if (confirm("Enable Receiver OTA?")) {
    const xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/rota_enable", true);
    xhttp.send();
  
    xhttp.onload = function() {
      getSystemStatus();
    }
  }
  return false;
}

function getSystemStatus(){
  
  const xhttp = new XMLHttpRequest();
  xhttp.open("GET", "/status", true);
  xhttp.send();
    
  xhttp.onload = function() {
    if(this.responseText){
      const [status_sd_card,status_mqtt,status_ota] = this.responseText.split(','); 

     if(status_sd_card == 0) document.getElementById("sdcard_status").classList.remove("d-none");
     else document.getElementById("sdcard_status").classList.add("d-none");  

     if(status_mqtt == 0) document.getElementById("mqtt_alert").classList.remove("d-none");
     else document.getElementById("mqtt_alert").classList.add("d-none");  

     if(status_ota == 0)document.getElementById("top_bar").style.backgroundColor = "#ff0000";
     else if(status_ota == 2) document.getElementById("top_bar").style.backgroundColor = "#ffbf00"; 
     else document.getElementById("top_bar").style.backgroundColor = "#33C5FF";
     
    }

  }
}

function clearList(){
  
  document.getElementById("lista").innerHTML = "";
}

function clearPage(){
  
  document.getElementById("lista").innerHTML = "";
  document.getElementById("listh").innerHTML = "";
}

function AddSensorBlock(item){

     const [sid,scategory,sstatus,stemperature,shumidity,sunit,sbattery,stimetamp] = item.split(',');  
     if(!sid) return;
     
     var perc = (sbattery - 3.3) / 0.006 | 0; 
          
     s = "";
     if(scategory==0) s = "view history"; 
     if(scategory==1 && sstatus == 1)   s = "OPEN"; 
     if(scategory==1 && sstatus == 0)   s = "CLOSED"; 
     if(scategory==3 && sstatus == 1)   s = "MOTION"; 
     if(scategory==3 && sstatus == 0)   s = "CLEAR"; 
     if(scategory==2)  s = parseFloat(stemperature).toFixed(1) + sunit;
     
     if( sunit == "°F") dunit = 1;

     if(sbattery >= 3.75)  b = "<svg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='currentColor' class='bi bi-battery-full' viewBox='0 0 16 16'><path d='M2 6h10v4H2V6z'/><path d='M2 4a2 2 0 0 0-2 2v4a2 2 0 0 0 2 2h10a2 2 0 0 0 2-2V6a2 2 0 0 0-2-2H2zm10 1a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H2a1 1 0 0 1-1-1V6a1 1 0 0 1 1-1h10zm4 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";  
     else if(sbattery >= 3.4) b = "<svg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='currentColor' class='bi bi-battery-half' viewBox='0 0 16 16'><path d='M2 6h5v4H2V6z'/><path d='M2 4a2 2 0 0 0-2 2v4a2 2 0 0 0 2 2h10a2 2 0 0 0 2-2V6a2 2 0 0 0-2-2H2zm10 1a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H2a1 1 0 0 1-1-1V6a1 1 0 0 1 1-1h10zm4 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";
     else b = "<svg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='currentColor' class='bi bi-battery text-danger' viewBox='0 0 16 16'><path d='M0 6a2 2 0 0 1 2-2h10a2 2 0 0 1 2 2v4a2 2 0 0 1-2 2H2a2 2 0 0 1-2-2V6zm2-1a1 1 0 0 0-1 1v4a1 1 0 0 0 1 1h10a1 1 0 0 0 1-1V6a1 1 0 0 0-1-1H2zm14 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";

     if(sbattery < 3.4) bgc = "text-danger";
     else bgc = "";
       
     if(scategory==1)       icon = "<svg xmlns='http://www.w3.org/2000/svg' width='32' height='32' fill='currentColor' class='bi bi-door-closed' style='margin-top:-8px' viewBox='0 0 16 16'><path d='M3 2a1 1 0 0 1 1-1h8a1 1 0 0 1 1 1v13h1.5a.5.5 0 0 1 0 1h-13a.5.5 0 0 1 0-1H3V2zm1 13h8V2H4v13z'/><path d='M9 9a1 1 0 1 0 2 0 1 1 0 0 0-2 0z'/></svg>";  
     else if(scategory==2)  icon = "<svg xmlns='http://www.w3.org/2000/svg' width='32' height='32' fill='currentColor' class='bi bi-thermometer-half' style='margin-top:-8px' viewBox='0 0 16 16'><path d='M9.5 12.5a1.5 1.5 0 1 1-2-1.415V6.5a.5.5 0 0 1 1 0v4.585a1.5 1.5 0 0 1 1 1.415z'/><path d='M5.5 2.5a2.5 2.5 0 0 1 5 0v7.55a3.5 3.5 0 1 1-5 0V2.5zM8 1a1.5 1.5 0 0 0-1.5 1.5v7.987l-.167.15a2.5 2.5 0 1 0 3.333 0l-.166-.15V2.5A1.5 1.5 0 0 0 8 1z'/></svg>";
     else if(scategory==3)  icon = "<svg xmlns='http://www.w3.org/2000/svg' width='32' height='32' fill='currentColor' class='bi bi-walk' style='margin-top:-8px' viewBox='0 0 320 512 '><path d='M208 96c26.5 0 48-21.5 48-48S234.5 0 208 0s-48 21.5-48 48 21.5 48 48 48zm94.5 149.1l-23.3-11.8-9.7-29.4c-14.7-44.6-55.7-75.8-102.2-75.9-36-.1-55.9 10.1-93.3 25.2-21.6 8.7-39.3 25.2-49.7 46.2L17.6 213c-7.8 15.8-1.5 35 14.2 42.9 15.6 7.9 34.6 1.5 42.5-14.3L81 228c3.5-7 9.3-12.5 16.5-15.4l26.8-10.8-15.2 60.7c-5.2 20.8.4 42.9 14.9 58.8l59.9 65.4c7.2 7.9 12.3 17.4 14.9 27.7l18.3 73.3c4.3 17.1 21.7 27.6 38.8 23.3 17.1-4.3 27.6-21.7 23.3-38.8l-22.2-89c-2.6-10.3-7.7-19.9-14.9-27.7l-45.5-49.7 17.2-68.7 5.5 16.5c5.3 16.1 16.7 29.4 31.7 37l23.3 11.8c15.6 7.9 34.6 1.5 42.5-14.3 7.7-15.7 1.4-35.1-14.3-43zM73.6 385.8c-3.2 8.1-8 15.4-14.2 21.5l-50 50.1c-12.5 12.5-12.5 32.8 0 45.3s32.7 12.5 45.2 0l59.4-59.4c6.1-6.1 10.9-13.4 14.2-21.5l13.5-33.8c-55.3-60.3-38.7-41.8-47.4-53.7l-20.7 51.5z'></path></svg>";
     else icon = "";

     if(scategory == 0) c = 'color:#dfdfdf;';
     else c = '';

     html = "<div class='col p-sm-3' onclick=\"loadSensor('"+sid+".log')\">";
     html += " <div class='pointer card mb-4 rounded-3 shadow-sm'>";
     html += "     <div class='card-header py-3 sensor_header'><p class='my-0 fw-normal'> "+getSensorReadableName(sid)+"</p></div>";
     html += "     <div class='card-body'>";
     html += "       <h2 class='card-title pricing-card-title mt-3' style='"+c+"'>"+icon+" "+s+"</h2>";
     if(scategory != 0) html += "       <ul class='list-unstyled mt-3 mb-3'><li>"+sbattery+"v  "+b+"</li><li><small>"+getFormatedDuration(stimetamp)+"</small></li></ul>";
     else html += "       <ul class='list-unstyled mt-3 mb-3'><li>&nbsp;</li><li><small style='"+c+"'>"+readableSize(stimetamp)+"</small></li></ul>";
     html += "     </div>";
     html += "   </div>";
     html += " </div>";
     
     document.getElementById("lista").innerHTML += html; 
}


function loadSensor(id) {
  
  sensor_data_array = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
  sensor_data_array["min"] = 1000;
  sensor_data_array["max"] = 0;
  sensor_info = [];
  sensor_info['filename'] = id;
  
  cursorLoading();
  const xhttp = new XMLHttpRequest();
  xhttp.addEventListener('progress', handleSensorLoading);
  xhttp.open("GET", "/sensor?id="+ id, true);
  xhttp.send();
  
  xhttp.onload = function() {
    cursorDone();
    document.getElementById("lista").innerHTML = "<div class='col-12 mt-5' style='width:100%!important;text-align:center;color:#cccccc;'>loading ... 100%</div>";  
    if(this.responseText && this.responseText != "No SD card found."){
      clearPage();
      html = " <div class=''>";
      html += "     <div class='row alert mb-4' style='padding:25px!important;background-color:#33c5ff;margin-top:-27px;color:white;border-top-right-radius:0rem;border-top-left-radius:0rem;border-bottom-left-radius:0.5rem;border-bottom-right-radius:0.6rem;'><div id='icon' class='col-1'></div><div class='my-0 fw-normal col-2' style='text-align:left'>"+getSensorReadableName(id.substring(0, id.length-4))+"</div><div id='scount' class='col-4'>"+id+"</div><div id='scount' class='col-3'></div><div id='sbattery' class='col-2'></div></div><div id='sgraph'></div><div id='sdata' class='p-2' style='color:#666666'></div>";

      document.getElementById("listh").innerHTML += html; 
      var sensors = this.responseText.split('\n');
      sensors.forEach( function(item) {
        AddSensorLine(item);
        collectSensorData(item);
      });
       html = " </div>";
      document.getElementById("listh").innerHTML += html; 
      if( sensor_info['count'] > 1){
        showLatestData();
        plotSensorData();
      }else{
        document.getElementById("listh").innerHTML += "<div class='col-12 mt-5' style='width:100%!important;text-align:center;color:#cccccc;'>No data</div>";
      }
    }else{
      document.getElementById("listh").innerHTML += "<div class='col-12 mt-5' style='width:100%!important;text-align:center;color:#cccccc;'>No file found</div>";
    }
  }
}

function handleSensorLoading(e){

  if (e.lengthComputable)
    document.getElementById("lista").innerHTML = "<div class='col-12 mt-5' style='width:100%!important;text-align:center;color:#cccccc;'>loading ... "+ parseInt((e.loaded / e.total) * 100) +"%</div>";  
}

function AddSensorLine(item){

    const [ltimestamp,lcategory,lstatus,ltemperature,lhumidity,lbattery] = item.split(',');  
    if(!ltimestamp || !lcategory || !lbattery) return;

    sensor_category = lcategory;
    sensor_info['category'] = lcategory;
    if( sensor_info['count'] > 0 ) sensor_info['count'] = sensor_info['count'] + 1;
    else sensor_info['count'] = 1;
    sensor_info['battery'] = lbattery;
    sensor_info['timestamp'] = ltimestamp;
    
    const date = new Date(ltimestamp * 1000);

     if(lcategory==1)       document.getElementById("icon").innerHTML = "<svg xmlns='http://www.w3.org/2000/svg' width='32' height='32' fill='currentColor' class='bi bi-door-closed' style='margin-top:-8px' viewBox='0 0 16 16'><path d='M3 2a1 1 0 0 1 1-1h8a1 1 0 0 1 1 1v13h1.5a.5.5 0 0 1 0 1h-13a.5.5 0 0 1 0-1H3V2zm1 13h8V2H4v13z'/><path d='M9 9a1 1 0 1 0 2 0 1 1 0 0 0-2 0z'/></svg>";  
     else if(lcategory==2)  document.getElementById("icon").innerHTML = "<svg xmlns='http://www.w3.org/2000/svg' width='32' height='32' fill='currentColor' class='bi bi-thermometer-half' style='margin-top:-8px' viewBox='0 0 16 16'><path d='M9.5 12.5a1.5 1.5 0 1 1-2-1.415V6.5a.5.5 0 0 1 1 0v4.585a1.5 1.5 0 0 1 1 1.415z'/><path d='M5.5 2.5a2.5 2.5 0 0 1 5 0v7.55a3.5 3.5 0 1 1-5 0V2.5zM8 1a1.5 1.5 0 0 0-1.5 1.5v7.987l-.167.15a2.5 2.5 0 1 0 3.333 0l-.166-.15V2.5A1.5 1.5 0 0 0 8 1z'/></svg>";
     else if(lcategory==3)  document.getElementById("icon").innerHTML = "<svg xmlns='http://www.w3.org/2000/svg' width='32' height='32' fill='currentColor' class='bi bi-walk' style='margin-top:-8px' viewBox='0 0 320 512 '><path d='M208 96c26.5 0 48-21.5 48-48S234.5 0 208 0s-48 21.5-48 48 21.5 48 48 48zm94.5 149.1l-23.3-11.8-9.7-29.4c-14.7-44.6-55.7-75.8-102.2-75.9-36-.1-55.9 10.1-93.3 25.2-21.6 8.7-39.3 25.2-49.7 46.2L17.6 213c-7.8 15.8-1.5 35 14.2 42.9 15.6 7.9 34.6 1.5 42.5-14.3L81 228c3.5-7 9.3-12.5 16.5-15.4l26.8-10.8-15.2 60.7c-5.2 20.8.4 42.9 14.9 58.8l59.9 65.4c7.2 7.9 12.3 17.4 14.9 27.7l18.3 73.3c4.3 17.1 21.7 27.6 38.8 23.3 17.1-4.3 27.6-21.7 23.3-38.8l-22.2-89c-2.6-10.3-7.7-19.9-14.9-27.7l-45.5-49.7 17.2-68.7 5.5 16.5c5.3 16.1 16.7 29.4 31.7 37l23.3 11.8c15.6 7.9 34.6 1.5 42.5-14.3 7.7-15.7 1.4-35.1-14.3-43zM73.6 385.8c-3.2 8.1-8 15.4-14.2 21.5l-50 50.1c-12.5 12.5-12.5 32.8 0 45.3s32.7 12.5 45.2 0l59.4-59.4c6.1-6.1 10.9-13.4 14.2-21.5l13.5-33.8c-55.3-60.3-38.7-41.8-47.4-53.7l-20.7 51.5z'></path></svg>";
     else document.getElementById("icon").innerHTML = "";
     
     html  = "<div class='row mb-0' style='font-size:0.8rem;'><div class='col-3 text-left'>"+date.toDateString()+"</div><div class='col-3 text-left'>"+date.toLocaleTimeString('en-US')+"</div>";
     if( lcategory == 1){
        if(lstatus == 0) html += "<div class='col-4 text-left'>CLOSED</div>"; 
        else html += "<div class='col-4 text-left'>OPEN</div>";       
     }
     if( lcategory == 2){
        if(lhumidity > 0){
            html += "<div class='col-2 text-left'>"+getFormatedTemperature(ltemperature,dunit) + "</div>"; 
            html += "<div class='col-2 text-left'>"+lhumidity+"%</div>";   
        }else{
            html += "<div class='col-4 text-left'>"+getFormatedTemperature(ltemperature,dunit) + "</div>"; 
        }
     } 
     if( lcategory == 3){
        if(lstatus == 1) html += "<div class='col-4 text-left'>MOTION</div>"; 
        else html += "<div class='col-4 text-left'>CLEAR</div>";     
     } 
     
     if(lbattery >= 3.75)  b = "<svg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='currentColor' class='bi bi-battery-full' viewBox='0 0 16 16'><path d='M2 6h10v4H2V6z'/><path d='M2 4a2 2 0 0 0-2 2v4a2 2 0 0 0 2 2h10a2 2 0 0 0 2-2V6a2 2 0 0 0-2-2H2zm10 1a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H2a1 1 0 0 1-1-1V6a1 1 0 0 1 1-1h10zm4 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";  
     else if(lbattery >= 3.4) b = "<svg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='currentColor' class='bi bi-battery-half' viewBox='0 0 16 16'><path d='M2 6h5v4H2V6z'/><path d='M2 4a2 2 0 0 0-2 2v4a2 2 0 0 0 2 2h10a2 2 0 0 0 2-2V6a2 2 0 0 0-2-2H2zm10 1a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H2a1 1 0 0 1-1-1V6a1 1 0 0 1 1-1h10zm4 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";
     else b = "<svg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='currentColor' class='bi bi-battery text-danger' viewBox='0 0 16 16'><path d='M0 6a2 2 0 0 1 2-2h10a2 2 0 0 1 2 2v4a2 2 0 0 1-2 2H2a2 2 0 0 1-2-2V6zm2-1a1 1 0 0 0-1 1v4a1 1 0 0 0 1 1h10a1 1 0 0 0 1-1V6a1 1 0 0 0-1-1H2zm14 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";

     html += "<div class='col-2 text-right'>"+ b + " " + lbattery+"volt</div></div>"; 
    
     var sdata = document.getElementById("sdata");
     sdata.innerHTML = html + sdata.innerHTML; 
     if(sensor_info['count'] > 200)  sdata.removeChild(sdata.lastChild);
}


function showLatestData(){

     if(sensor_info['battery']  >= 3.75)  b = "<svg xmlns='http://www.w3.org/2000/svg' width='36' height='20' fill='currentColor' class='bi bi-battery-full' viewBox='0 0 16 16'><path d='M2 6h10v4H2V6z'/><path d='M2 4a2 2 0 0 0-2 2v4a2 2 0 0 0 2 2h10a2 2 0 0 0 2-2V6a2 2 0 0 0-2-2H2zm10 1a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H2a1 1 0 0 1-1-1V6a1 1 0 0 1 1-1h10zm4 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";  
     else if(sensor_info['battery']  >= 3.4) b = "<svg xmlns='http://www.w3.org/2000/svg' width='36' height='20' fill='currentColor' class='bi bi-battery-half' viewBox='0 0 16 16'><path d='M2 6h5v4H2V6z'/><path d='M2 4a2 2 0 0 0-2 2v4a2 2 0 0 0 2 2h10a2 2 0 0 0 2-2V6a2 2 0 0 0-2-2H2zm10 1a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H2a1 1 0 0 1-1-1V6a1 1 0 0 1 1-1h10zm4 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";
     else b = "<svg xmlns='http://www.w3.org/2000/svg' width='36' height='20' fill='currentColor' class='bi bi-battery text-danger' viewBox='0 0 16 16'><path d='M0 6a2 2 0 0 1 2-2h10a2 2 0 0 1 2 2v4a2 2 0 0 1-2 2H2a2 2 0 0 1-2-2V6zm2-1a1 1 0 0 0-1 1v4a1 1 0 0 0 1 1h10a1 1 0 0 0 1-1V6a1 1 0 0 0-1-1H2zm14 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";
    
    document.getElementById("scount").innerHTML = sensor_info['count'] + " records <a style='color:yellow;font-size:12px;text-decoration: none;' href='#' onclick=\"deleteSensor('"+sensor_info['filename']+"');return false;\"> X</a>";
    document.getElementById("sbattery").innerHTML = b + sensor_info['battery'] + "V";   
}


function plotSensorData(){
  
    if(sensor_category == GROUP_SWITCH) plotSensorDataMotion();
    else if(sensor_category == GROUP_HT) plotSensorDataHT(); 
    else if(sensor_category == GROUP_MOTION) plotSensorDataMotion();  
}

function plotSensorDataSwitch(){}

function plotSensorDataHT(){

  html = "<div class='row m-5 mb-0' style='margin-left: 0px;margin-right: 0px;'><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;margin-left: 0px;padding-right: 0px;margin-right: 0px;'>";
  for(var i=0; i<24;i++){
    if(sensor_data_array[i] != 0) t = sensor_data_array[i];
    else t = "-";
    html += "<div class='col-1' style='font-size:8px;padding-left:0!important;padding-right:0!important;'>"+t+"</div>";  
    if(i==11)  html += "</div><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;padding-left: 0px;margin-left: 0px;margin-right: 0px;'>";
  }  
  html += "</div></div>"; 
  height = sensor_data_array["max"]-sensor_data_array["min"];
  if( height < 20) height = 20;
  html += "<div class='m-5 mb-0 mt-4'><svg id='svg' class='chart' viewBox='0 0 230 "+height+"'><polyline id='poly' fill='none' stroke='#d03535' stroke-width='0.5' points=''></polyline></svg></div>";
  html += "<div class='row m-5 mt-0' style='margin-left: 0px;margin-right: 0px;'><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;margin-left: 0px;padding-right: 0px;margin-right: 0px;'>";
  for(var i=0; i<24;i++){
    html += "<div class='col-1' style='font-size:8px;padding-left:0!important;padding-right:0!important;'>"+(i)+":00</div>";  
    if(i==11)  html += "</div><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;padding-left: 0px;margin-left: 0px;margin-right: 0px;'>";
  } 
  html += "</div></div>"; 
  document.getElementById("sgraph").innerHTML = html;
  var svg = document.getElementById('svg');
  var polyline= document.getElementById('poly');
  for(var i=0; i<23;i++){
     if( sensor_data_array[i] > 0 ){
        point = svg.createSVGPoint();
        if(i==23) point.x = i*10 - 5;
        else point.x = parseInt(5+i*9.86);
        point.y = sensor_data_array["max"] - sensor_data_array[i];
        polyline.points.appendItem(point);
     }
     
     if( true == false ){
        if(i==23) point.x = i*10 - 5;
        else point.x = parseInt(5+i*9.86);

        if( sensor_data_array["max"]-sensor_data_array["min"] <= 5 ) point.y =  sensor_data_array["max"] - sensor_data_array[i] ;
        else point.y = 20 / (sensor_data_array["max"]-sensor_data_array["min"] ) * ( sensor_data_array["max"] - sensor_data_array[i] );        
      }

  }

}

function plotSensorDataMotion(){
  
  html = "<div class='row mt-5' style='margin-left: 0px;margin-right: 0px;'><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;margin-left: 0px;padding-right: 0px;margin-right: 0px;'>";
  for(var i=0; i<24;i++){
    mid_point = (sensor_data_array["max"] - sensor_data_array["min"]) / 2 + sensor_data_array["min"];
    if( sensor_data_array[i] >= mid_point ) c = "background-color:" + CRED;
    else if( sensor_data_array[i] >= sensor_data_array["min"] ) c = "background-color:" + CYELLOW;
    else c = "";
    if(i==0) l = "border-left:solid 1px #3d568a;";
    else l = "";
    if(i==23) r = "border-right:solid 1px #3d568a;";
    else r = "";
    html += "<div class='col-1' style='padding-left:0!important;padding-right: 0!important;border-top:solid 1px #3d568a;border-bottom:solid 1px #3d568a;border-right:solid 1px #b2b7c1;"+l+r+c+"'>&nbsp;</div>";  
    if(i==11)  html += "</div><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;padding-left: 0px;margin-left: 0px;margin-right: 0px;'>";
  }  
  html += "</div></div>";

  html += "<div class='row mb-5' style='margin-left: 0px;margin-right: 0px;'><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;margin-left: 0px;padding-right: 0px;margin-right: 0px;'>";
  for(var i=0; i<24;i++){

    html += "<div class='col-1' style='font-size:8px;padding-left:0!important;padding-right:0!important;'>"+(i)+":00</div>";  
    if(i==11)  html += "</div><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;padding-left: 0px;margin-left: 0px;margin-right: 0px;'>";
  }  
  html += "</div></div>";  
  document.getElementById("sgraph").innerHTML = html;
}


function collectSensorData(item){

    if(sensor_category == GROUP_SWITCH) collectSensorDataMotion(item);
    else if(sensor_category == GROUP_HT) collectSensorDataHT(item); 
    else if(sensor_category == GROUP_MOTION) collectSensorDataMotion(item); 
}

function collectSensorDataSwitch(item){}

function collectSensorDataHT(item){
  
     const [ltimestamp,lcategory,lstatus,ltemperature,lhumidity,lbattery] = item.split(',');  
     if(!ltimestamp) return;

     var d = new Date(ltimestamp*1000);
     var current_date = new Date();
     var current_day = current_date.getDate();
     if(d.getDate() == current_day){
        tlocal = getFormatedTemperatureNoUnit(ltemperature,dunit);
        sensor_data_array[d.getHours()] = tlocal;
        if( tlocal > sensor_data_array["max"]) sensor_data_array["max"] = tlocal;
        if( tlocal < sensor_data_array["min"]) sensor_data_array["min"] = tlocal;
     }  
}

function collectSensorDataMotion(item){

     const [ltimestamp,lcategory,lstatus,ltemperature,lhumidity,lbattery] = item.split(',');  
     if(!ltimestamp) return;

     var d = new Date(ltimestamp*1000);
     var current_date = new Date();
     var current_day = current_date.getDate();
     if(d.getDate() == current_day){
        sensor_data_array[d.getHours()] += 1;   
        if( sensor_data_array[d.getHours()] > sensor_data_array["max"]) sensor_data_array["max"] = sensor_data_array[d.getHours()];
        if( sensor_data_array[d.getHours()] < sensor_data_array["min"]) sensor_data_array["min"] = sensor_data_array[d.getHours()];
     }
}

        
function getFormatedDuration(stimestamp){

  duration = Math.floor(Date.now() / 1000) - stimestamp;
  if (duration >= 86400){
    d = parseInt(duration/86400);
    if( d == 1 ) return d + " day ago";
    else return d + " days ago";
  }
  if (duration >= 3600){
    h = parseInt(duration/3600);
    if( h == 1 ) return h + " hour ago";
    else return h + " hours ago";
  }
  if (duration >= 60) {
    m = parseInt(duration/60);
    if( m == 1 ) return m + " minute ago";
    else return m + " minutes ago";    
  }
  if( duration == 1) return duration + " second ago";  
  else return duration + " seconds ago"; 
}


function getFormatedTemperature(t,u){
     
  if (u == 0 ) return (parseFloat(t).toFixed(1)) + "°C";
  else return (parseFloat(t*1.8+32).toFixed(1)) + "°F";
}

function getFormatedTemperatureNoUnit(t,u){
     
  if (u == 0 ) return parseFloat(parseFloat(t).toFixed(1));
  else return parseFloat(parseFloat(t*1.8+32).toFixed(1));
}

function readableSize(a, b, c, d, e) {
    return (b = Math, c = b.log, d = 1000, e = c(a) / c(d) | 0, a / b.pow(d, e)).toFixed(0) + '' + (e ? 'kMGTPEZY' [--e] + 'B' : 'B')
}

function cursorLoading(){
  document.body.style.cursor = 'progress';
  document.getElementById("lista").innerHTML = "<div class='col-12 mt-5' style='width:100%!important;text-align:center;color:#cccccc;'>loading ...</div>";
}

function cursorDone(){
  document.body.style.cursor = 'default';
}