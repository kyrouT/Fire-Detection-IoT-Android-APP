<template>
  <base-layout page-title="Sensors Map" page-default-back-link="/homepage">
  <template v-slot:actions-end>
      <ion-button  @click="openModal">
        <ion-icon slot="icon-only"  :icon="helpCircle"></ion-icon>
      </ion-button>
  </template> 
    <GMapMap
      :center="center"
      :zoom="13"
      map-type-id="terrain"
      style="width: 100px; height: 200px"
  >
    <GMapCluster>
      <GMapMarker
          :key="index"
          v-for="(m, index) in markers"
          :position="m.position"
          :clickable="true"
          :icon="m.icon"
          :draggable="false"
          @click="center=m.position"
      >
      <GMapInfoWindow :opened="true">
        <div>{{m.info}} {{m.horizon}}<MyComponent/>
        </div>
      </GMapInfoWindow>
      </GMapMarker>
        
    </GMapCluster>
  </GMapMap>
  
  <ion-card  color="primary">
      <ion-row class="ion-justify-content-center">
        <ion-img @click="putSensor" style="width:150px" src="https://cdn-icons-png.flaticon.com/512/2540/2540201.png" />
        <ion-card-header>
          <ion-card-subtitle style="text-align:center">Add a Sensor</ion-card-subtitle>
          <ion-card-title style="text-align:center">Click the Sensor Icon when you are at the Sensor Location! </ion-card-title>
        </ion-card-header>  
      </ion-row>
      
      
  </ion-card>
  
          

  
  </base-layout>
  
</template>
<script>
import { Geolocation } from '@capacitor/geolocation';
import {IonImg, IonCard, IonRow,alertController, IonIcon, modalController} from '@ionic/vue';
import ModalMap from '../components/ModalMap.vue';
import { helpCircle } from 'ionicons/icons';

export default {
  setup() {
    const openModal = async () => {
      const modal = await modalController.create({
        component: ModalMap, //Modal is name of the component to render inside ionic modal
      });
      return modal.present();
    };

    return { openModal };
  },
  name: 'App',
  data() {
    return {
      // 40.6388436016183, 22.94852686894588
      helpCircle,
      center: {lat: 40.6388, lng: 22.9485},
      markers: [
        {
          position: {
            lat: 40.6388, lng: 22.9485
          },
          icon: {
                url:"https://cdn-icons-png.flaticon.com/512/25/25694.png",
                scaledSize: {width: 30, height: 30},
                labelOrigin: {x: 16, y: -10}
          },
          info:"Your Home",
          horizon: ""
        },
        {  
          position: {
            lat: 40.6381, lng: 22.9588
          },
          icon: "./assets/yellow-dot.png",
          info: "40.6381 22.9588 ",
          horizon:"SouthEast"
          
        }
        , // Along list of clusters
      ]
    }
  },
  components: {IonImg, IonCard, IonRow, IonIcon},
  methods: {
    async presentAlert() {
      const alert = await alertController
        .create({
          cssClass: 'my-custom-class',
          header: 'Out of Range',
          message: 'You are more than 5km from your home sensor, move closer and try again.',
          buttons: ['OK'],
        });
      await alert.present();

      const { role } = await alert.onDidDismiss();
      console.log('onDidDismiss resolved with role', role);
    },
    async putSensor() {
        const coordinates = await Geolocation.getCurrentPosition();

        console.log('Current position:', coordinates);
        console.log(coordinates.coords.latitude,coordinates.coords.longitude);
        const lat = coordinates.coords.latitude;
        const lon = coordinates.coords.longitude;
        let horizon = "";
        //Horizon Points
        if (lat==this.center.lat&&lon==this.center.lng) {
          horizon = ""
        } else if (lat==this.center.lat&&lon<this.center.lng) {
          horizon = "West"
        }  else if (lat==this.center.lat&&lon> this.center.lng) {
          horizon = "East"
        } else if (lat>this.center.lat&&lon==this.center.lng) {
          horizon = "North"
        }else if (lat<this.center.lat&&lon==this.center.lng) {
          horizon = "South"
        }else if (lat<this.center.lat&&lon<this.center.lng) {
          horizon = "SouthWest"
        }  else if (lat<this.center.lat&&lon> this.center.lng) {
          horizon = "SouthEast"
        } else if (lat>this.center.lat&&lon>this.center.lng) {
          horizon = "NorthEast"
        }else if(lat>this.center.lat&&lon<this.center.lng) {
          horizon = "NorthWest"
        }
        
        var stringgg = ""
        stringgg += lat.toString();
        stringgg += " "
        stringgg += lon.toString();

        let newPointer =  {
          position: {
            lat: coordinates.coords.latitude, lng: coordinates.coords.longitude
          },
          horizon: horizon,
          icon: "./assets/blue-dot.png",
          info: stringgg
            
        };
        console.log(newPointer);
        this.markers.push(newPointer);
        this.distance(coordinates.coords.latitude, coordinates.coords.longitude);
    },
    distance(lat2, lon2) { 
      var lat1 = this.center.lat;
      var lon1 = this.center.lng;
      var R = 6371; // Radius of the earth in km
      var dLat = this.deg2rad(lat2-lat1);  // deg2rad below
      var dLon = this.deg2rad(lon2-lon1); 
      var a = 
        Math.sin(dLat/2) * Math.sin(dLat/2) +
        Math.cos(this.deg2rad(lat1)) * Math.cos(this.deg2rad(lat2)) * 
        Math.sin(dLon/2) * Math.sin(dLon/2)
        ; 
      var c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a)); 
      var d = R * c; // Distance in km
      console.log(d);
      if (d > 5.00) {
        this.markers.pop();
        this.presentAlert();
      }
      // outOfRange();
    },
    deg2rad(deg) {
      return deg * (Math.PI/180);
    },
    pointColor() {
      const color = this.$store.getters.memories[0].status;
      this.markers[1].status = `http://maps.google.com/mapfiles/ms/icons/${color}-dot.png`
    }
  },
  created() {
    this.pointColor();
  }      

}

</script>

<style scoped>
.vue-map-container {
  height: 400px;
}
</style>